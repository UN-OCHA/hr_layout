<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Humanitarianresponse Operation'),
  'description' => t('Shows a standard block for your operation home page.'),
  'category' => t('Humanitarianresponse'),
  'edit form' => 'hr_layout_standard_edit_form',
  'render callback' => 'hr_layout_standard_render',
  'defaults' => array(),
);

/**
 * 'Edit form' callback for the content type.
 */
function hr_layout_standard_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  return $form;
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function hr_layout_standard_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  $gid = arg(1);
  $humanitarian_bulletin = _hr_layout_get_latest($gid, 'Humanitarian Bulletin', 'hr_document');
  $humanitarian_bulletin_pdfpreview = _hr_layout_get_pdfpreview($humanitarian_bulletin);
  $humanitarian_bulletin_image = theme_image(array('path' => $humanitarian_bulletin_pdfpreview, 'alt' => $humanitarian_bulletin->title, 'title' => $humanitarian_bulletin->title, 'attributes' => array('class' => array('img-responsive'))));
  $humanitarian_bulletin_link = l($humanitarian_bulletin_image, 'node/'.$humanitarian_bulletin->nid, array('html' => TRUE));
 
  // initial content is blank
  $block->title = '';
  $block->content = '';

  $block->content = '<div class="clearfix hr-layout-operation-standard">
  <ul class="nav nav-tabs" role="tablist">
    <li class="active"><a href="#hpc" role="tab" data-toggle="tab">Humanitarian Programme Cycle</a></li>
    <li><a href="#ocha" role="tab" data-toggle="tab">OCHA Products</a></li>
  </ul>
  
  <!-- Tab panes -->
  <div class="tab-content">
    <div class="tab-pane active" id="hpc">
      <div class="row">
        <div class="col-xs-4">
          <div id="hno-thumbnail" class="hr-thumbnail show"><a href="http://www.humanitarianresponse.info/operations/iraq/document/iraq-humanitarian-needs-overview-arabic"><img class="img-responsive" src="http://www.humanitarianresponse.info/sites/www.humanitarianresponse.info/files/pdfpreview/125dd902eefb691fb00bb047e83ea751.jpg" alt="HNO thumbnail" /></a></div>
          <div id="srp-thumbnail" class="hr-thumbnail hidden"><a href="http://www.humanitarianresponse.info/operations/iraq/document/immediate-response-plan-irp-idps-crisis-kr-i-15-sept-15-nov-2014"><img class="img-responsive" src="http://www.humanitarianresponse.info/sites/www.humanitarianresponse.info/files/pdfpreview/00cbaa7410c0557a567dbce25151bd47.jpg" alt="SRP thumbnail" /></a></div>
          <div id="monr-thumbnail" class="hr-thumbnail hidden"><a href="http://www.humanitarianresponse.info/operations/philippines/document/typhoon-haiyanyolanda-final-periodic-montoring-report-pmr-22oct2014"><img class="img-responsive" src="http://www.humanitarianresponse.info/sites/www.humanitarianresponse.info/files/pdfpreview/0d26bfd6850937d430a0f6157e66d88e.jpg" alt="Monitoring Report thumbnail" /></a></div>
        </div>
        <div class="col-xs-8 hr-layout-operation-standard-links">
          <div class="list-group">
            <a class="list-group-item" id="hno">Humanitarian Needs Overview - JUL / 07 / 2014</a>
            <a class="list-group-item" id="srp">Strategic Response Plan - SEP / 23 / 2014</a>
            <a class="list-group-item" id="monr">Monitoring Report - OCT / 23 /2014</a>
          </div>
        </div>
      </div>
    </div>
    <div class="tab-pane" id="ocha">
      <div class="col-xs-4">
        <div id="sitrep-thumbnail" class="hr-thumbnail show"><a href="http://www.humanitarianresponse.info/operations/central-african-republic/document/car-situation-report-no-40-23-october-2014"><img class="img-responsive" src="http://www.humanitarianresponse.info/sites/www.humanitarianresponse.info/files/pdfpreview/61cf826ef6cd0363f3172680f713e62c.jpg" alt="HNO thumbnail" /></a></div>
        <div id="humbul-thumbnail" class="hr-thumbnail hidden">'.$humanitarian_bulletin_link.'</div>
        <div id="humsnap-thumbnail" class="hr-thumbnail hidden"><a href="http://www.humanitarianresponse.info/operations/kenya/infographic/kenya-inter-communal-conflict-district-january-june-2014-ocha-8-july"><img class="img-responsive" src="http://www.humanitarianresponse.info/sites/www.humanitarianresponse.info/files/pdfpreview/0cb6a56f7243a16be661441855e64003.jpg" alt="Monitoring Report thumbnail" /></a></div>
        <div id="humdash-thumbnail" class="hr-thumbnail hidden"><a href="http://www.humanitarianresponse.info/operations/kenya/infographic/kenya-humanitarian-dashboard-november-2012"><img class="img-responsive" src="http://www.humanitarianresponse.info/sites/www.humanitarianresponse.info/files/pdfpreview/539ec0c9e0af2e79b1ad7638e5ebcfe0.jpg" alt="Humanitarian Dashboard thumbnail" /></a></div>
      </div>
      <div class="col-xs-8 hr-layout-operation-standard-links">
        <div class="list-group">
          <a class="list-group-item" id="sitrep">Latest Situation Report</a>
          <a class="list-group-item" id="humbul">Latest Humanitarian Bulletin</a>
          <a class="list-group-item" id="humsnap">Latest Humanitarian Snapshot</a>
          <a class="list-group-item" id="humdash">Latest Humanitarian Dashboard</a>
        </div>
      </div>
    </div>
  </div>
  </div>

  <script type="text/javascript">
    (function($) {
      $(".hr-layout-operation-standard-links a").hover(
        function () {
          $(".hr-layout-operation-standard-links a").removeClass("active");
          $(".hr-layout-operation-standard .hr-thumbnail").removeClass("show");
          $(".hr-layout-operation-standard .hr-thumbnail").addClass("hidden");
          $( this ).addClass("active");
          var selector = "#" + $( this ).attr("id") + "-thumbnail";
          $(selector).removeClass("hidden");
          $(selector).addClass("show");
        },
        function() { });
    })(jQuery);
  </script>';
  
  return $block;
}

/**
 * Helper function to retrieve latest document/infographic of a specific doc type
 */
function _hr_layout_get_latest($gid, $term, $type) {
  // Get term ID
  $terms = taxonomy_get_term_by_name($term, $type.'_type');
  $term = reset($terms);
  if ($term) {
    $field_type = 'field_document_type';
    if ($type == 'hr_infographic') {
      $field_type = 'field_infographic_type';
    }
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $type)
    ->fieldCondition($field_type, 'target_id', $term->tid, '=')
    ->fieldCondition(OG_AUDIENCE_FIELD, 'target_id', $gid, '=')
    ->fieldOrderBy('field_publication_date', 'value', 'DESC')
    ->range(0, 1);

    $result = $query->execute();
    if (isset($result['node'])) {
      $node = reset($result['node']);
      return node_load($node->nid);
    }
  }
}

/**
 * Retrieves link to the file image based on the node object
 */
function _hr_layout_get_pdfpreview($node) {
  $fcid = $node->field_files_collection[LANGUAGE_NONE][0]['value'];
  $entity = entity_load_single('field_collection_item', $fcid);
  $file = $entity->field_file[LANGUAGE_NONE][0];
  $file_uri = _pdfpreview_create_preview($file);
  return $file_uri;
  /*$wrapper = file_stream_wrapper_get_instance_by_uri($file_uri);
  if ($wrapper instanceof DrupalLocalStreamWrapper) {
    return $wrapper->getDirectoryPath() . '/' . file_uri_target($file_uri);
  }*/
} 
