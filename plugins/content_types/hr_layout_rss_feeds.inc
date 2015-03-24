<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Rss Feeds'),
  'description' => t('Display RSS Feeds in Humanitarianresponse'),
  'category' => t('Humanitarianresponse'),
  'edit form' => 'hr_layout_rss_feeds_edit_form',
  'render callback' => 'hr_layout_rss_feeds_render',
  'all contexts' => TRUE,
  'defaults' => array(
    'feed_url' => '',
    'no_of_items' => '',
  ),
);

/**
 * 'Edit form' callback for the content type.
 */

function hr_layout_rss_feeds_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $options = range(1, 50);

  $form['feed_url'] = array(
    '#type' => 'textfield',
    '#title' => 'Feed URL',
    '#description' => t('Enter the Feed URL for which you want to display content'),
    '#default_value' => $conf['feed_url'],
  );
  $form['no_of_items'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#options' => $options,
    '#title' => 'Number of items to display',
    '#description' => t('Select the number of feed items you would like to display'),
    '#default_value' => $conf['no_of_items'],
  );

  return $form;
}

/**
 * Edit form submit handler.
 */

function hr_layout_rss_feeds_edit_form_submit($form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */

function hr_layout_rss_feeds_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();
  $block->title = 'RSS Feeds';
  $feed_url = $conf['feed_url'];
  $no_of_items = $conf['no_of_items'];
  $feeds = hr_layout_rss_feeds_load($feed_url);
  $content = '';
  if(isset($no_of_items)){
    $items_to_display = array_slice($feeds, 0, intval($no_of_items + 1), true);
    $content .= '<ul>';
    foreach ($items_to_display as $feed) {
      $content .= '<li><a href = '.$feed->link.'> '.$feed->title . '</a></li>';
    }
    $content .= '</ul>';
  }
  $block->content = $content;
  return $block;
}

/**
*  Function to get feed items given a feed url. This function uses the class Feeds.php adopted from
*  https://github.com/dg/rss-php.
*/

function hr_layout_rss_feeds_load($url){
  $feed = array();
  $rss = Feed::loadRss($url);
  foreach ($rss->item as $item) {
    array_push($feed, $item);
  }
  return $feed;
}

/**
 * RSS for PHP - small and easy-to-use library for consuming an RSS Feed
 *
 * @author     David Grudl
 * @copyright  Copyright (c) 2008 David Grudl
 * @license    New BSD License
 * @link       http://phpfashion.com/
 * @version    1.1
 */
class Feed
{
  /** @var int */
  public static $cacheExpire = 86400; // 1 day

  /** @var string */
  public static $cacheDir;

  /** @var SimpleXMLElement */
  protected $xml;


  /**
   * Loads RSS channel.
   * @param  string  RSS feed URL
   * @param  string  optional user name
   * @param  string  optional password
   * @return Feed
   * @throws FeedException
   */
  public static function loadRss($url, $user = NULL, $pass = NULL)
  {
    $xml = new SimpleXMLElement(self::httpRequest($url, $user, $pass), LIBXML_NOWARNING | LIBXML_NOERROR);
    if (!$xml->channel) {
      throw new FeedException('Invalid channel.');
    }

    self::adjustNamespaces($xml->channel);

    foreach ($xml->channel->item as $item) {
      // converts namespaces to dotted tags
      self::adjustNamespaces($item);

      // generate 'timestamp' tag
      if (isset($item->{'dc:date'})) {
        $item->timestamp = strtotime($item->{'dc:date'});
      } elseif (isset($item->pubDate)) {
        $item->timestamp = strtotime($item->pubDate);
      }
    }

    $feed = new self;
    $feed->xml = $xml->channel;
    return $feed;
  }


  /**
   * Loads Atom channel.
   * @param  string  Atom feed URL
   * @param  string  optional user name
   * @param  string  optional password
   * @return Feed
   * @throws FeedException
   */
  public static function loadAtom($url, $user = NULL, $pass = NULL)
  {
    $xml = new SimpleXMLElement(self::httpRequest($url, $user, $pass), LIBXML_NOWARNING | LIBXML_NOERROR);
    if (!in_array('http://www.w3.org/2005/Atom', $xml->getDocNamespaces(), TRUE)) {
      throw new FeedException('Invalid channel.');
    }

    // generate 'timestamp' tag
    foreach ($xml->entry as $entry) {
      $entry->timestamp = strtotime($entry->updated);
    }

    $feed = new self;
    $feed->xml = $xml;
    return $feed;
  }


  /**
   * Returns property value. Do not call directly.
   * @param  string  tag name
   * @return SimpleXMLElement
   */
  public function __get($name)
  {
    return $this->xml->{$name};
  }


  /**
   * Sets value of a property. Do not call directly.
   * @param  string  property name
   * @param  mixed   property value
   * @return void
   */
  public function __set($name, $value)
  {
    throw new Exception("Cannot assign to a read-only property '$name'.");
  }


  /**
   * Converts a SimpleXMLElement into an array.
   * @param  SimpleXMLElement
   * @return array
   */
  public function toArray(SimpleXMLElement $xml = NULL)
  {
    if ($xml === NULL) {
      $xml = $this->xml;
    }

    if (!$xml->children()) {
      return (string) $xml;
    }

    $arr = array();
    foreach ($xml->children() as $tag => $child) {
      if (count($xml->$tag) === 1) {
        $arr[$tag] = $this->toArray($child);
      } else {
        $arr[$tag][] = $this->toArray($child);
      }
    }

    return $arr;
  }


  /**
   * Process HTTP request.
   * @param  string  URL
   * @param  string  user name
   * @param  string  password
   * @return string
   * @throws FeedException
   */
  private static function httpRequest($url, $user, $pass)
  {
    if (self::$cacheDir) {
      $cacheFile = self::$cacheDir . '/feed.' . md5($url) . '.xml';
      if (@filemtime($cacheFile) + self::$cacheExpire > time()) {
        return file_get_contents($cacheFile);
      }
    }

    if (extension_loaded('curl')) {
      $curl = curl_init();
      curl_setopt($curl, CURLOPT_URL, $url);
      if ($user !== NULL || $pass !== NULL) {
        curl_setopt($curl, CURLOPT_USERPWD, "$user:$pass");
      }
      curl_setopt($curl, CURLOPT_HEADER, FALSE);
      curl_setopt($curl, CURLOPT_TIMEOUT, 20);
      curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE); // no echo, just return result
      if (!ini_get('open_basedir')) {
        curl_setopt($curl, CURLOPT_FOLLOWLOCATION, TRUE); // sometime is useful :)
      }
      $result = trim(curl_exec($curl));
      $ok = curl_errno($curl) === 0 && curl_getinfo($curl, CURLINFO_HTTP_CODE) === 200;

    } elseif ($user === NULL && $pass === NULL) {
      $result = trim(file_get_contents($url));
      $ok = is_string($result);

    } else {
      throw new FeedException('PHP extension CURL is not loaded.');
    }

    if (!$ok) {
      if (isset($cacheFile)) {
        $result = @file_get_contents($cacheFile);
        if (is_string($result)) {
          return $result;
        }
      }
      throw new FeedException('Cannot load channel.');
    }

    if (isset($cacheFile)) {
      file_put_contents($cacheFile, $result);
    }

    return $result;
  }


  /**
   * Generates better accessible namespaced tags.
   * @param  SimpleXMLElement
   * @return void
   */
  private static function adjustNamespaces($el)
  {
    foreach ($el->getNamespaces(TRUE) as $prefix => $ns) {
      $children = $el->children($ns);
      foreach ($children as $tag => $content) {
        $el->{$prefix . ':' . $tag} = $content;
      }
    }
  }

}



/**
 * An exception generated by Feed.
 */
class FeedException extends Exception
{
}
