<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Humanitarianresponse Operation'),
  'description' => t('Shows a standard block for your operation home page.'),
  'category' => t('Humanitarianresponse'),
  'edit form' => 'hr_layout_standard_edit_form',
  'render callback' => 'hr_layout_standard_render',
  'defaults' => array(
    'gid' => '',
    'hno' => '',
    'srp' => '',
    'monr' => '',
    'opr' => '',
  ),
);

/**
 * 'Edit form' callback for the content type.
 */
function hr_layout_standard_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['gid'] = array(
    '#type' => 'entityreference',
    '#title' => t('Operation'),
    '#era_entity_type' => 'node',
    '#era_bundles' => array('hr_operation'),
    '#default_value' => $conf['gid'],
    '#required' => TRUE,
  );

  $form['hno'] = array(
    '#type' => 'entityreference',
    '#title' => t('Humanitarian Needs Overview'),
    '#era_entity_type' => 'node',
    '#era_bundles' => array('hr_document'),
    '#default_value' => $conf['hno'],
  );

  $form['srp'] = array(
    '#type' => 'entityreference',
    '#title' => t('Strategic Response Plan'),
    '#era_entity_type' => 'node',
    '#era_bundles' => array('hr_document'),
    '#default_value' => $conf['srp'],
  );

  $form['monr'] = array(
    '#type' => 'entityreference',
    '#title' => t('Periodic Monitoring Report'),
    '#era_entity_type' => 'node',
    '#era_bundles' => array('hr_document'),
    '#default_value' => $conf['monr'],
  );

  $form['opr'] = array(
    '#type' => 'entityreference',
    '#title' => t('Operational Peer Review Summary'),
    '#era_entity_type' => 'node',
    '#era_bundles' => array('hr_document'),
    '#default_value' => $conf['opr'],
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function hr_layout_standard_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function hr_layout_standard_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  $gid = $conf['gid']['entity_id'];
  /*$hno = _hr_layout_get_list_item($gid, 'Humanitarian Needs Overview', 'hr_document', 'hno', 'show');
  $srp = _hr_layout_get_list_item($gid, 'Strategic Response Plan', 'hr_document', 'srp');
  $monr = _hr_layout_get_list_item($gid, 'Periodic Monitoring Report', 'hr_document', 'monr');
  $opr = _hr_layout_get_list_item($gid, 'Operational Peer Review Summary', 'hr_document', 'opr');*/

  $ocha_desc = array(
    'sitrep' => array('term' => 'Situation Report', 'type' => 'hr_document'),
    'humbul' => array('term' => 'Humanitarian Bulletin', 'type' => 'hr_document'),
    'humsnap' => array('term' => 'Humanitarian Snapshot', 'type' => 'hr_infographic'),
    'humdash' => array('term' => 'Humanitarian Dashboard', 'type' => 'hr_infographic'),
  );

  $ocha_products = array();
  $i = 0;
  foreach ($ocha_desc as $key => $value) {
    $initial_state = 'hidden';
    if ($i == 0) {
      $initial_state = 'show';
    }
    $node = _hr_layout_get_latest($gid, $value['term'], $value['type']);
    $ocha_products[$key] = _hr_layout_get_list_item($node, $value['term'], $value['type'], $key, $initial_state);
    $i++;
  }

  $hpc = array();
  if (!empty($conf['hno'])) {
    $node = node_load($conf['hno']['entity_id']);
    $hpc['hno'] = _hr_layout_get_list_item($node, 'Humanitarian Needs Overview', 'hr_document', 'hno', 'show');
  }

  if (!empty($conf['srp'])) {
    $node = node_load($conf['srp']['entity_id']);
    $hpc['srp'] = _hr_layout_get_list_item($node, 'Strategic Response Plan', 'hr_document', 'srp', 'hidden');
  }

  if (!empty($conf['monr'])) {
    $node = node_load($conf['monr']['entity_id']);
    $hpc['monr'] = _hr_layout_get_list_item($node, 'Periodic Monitoring Report', 'hr_document', 'monr', 'hidden');
  }


  
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
          '.$hpc['hno']['image'].'
          '.$hpc['srp']['image'].'
          '.$hpc['monr']['image'].'
        </div>
        <div class="col-xs-8 hr-layout-operation-standard-links">
          <div class="list-group">
            '.$hpc['hno']['link'].'
            '.$hpc['srp']['link'].'
            '.$hpc['monr']['link'].'
          </div>
        </div>
      </div>
    </div>
    <div class="tab-pane" id="ocha">
      <div class="col-xs-4">
        '.$ocha_products['sitrep']['image'].'
        '.$ocha_products['humbul']['image'].'
        '.$ocha_products['humsnap']['image'].'
        '.$ocha_products['humdash']['image'].'
      </div>
      <div class="col-xs-8 hr-layout-operation-standard-links">
        <div class="list-group">
          '.$ocha_products['sitrep']['link'].'
          '.$ocha_products['humbul']['link'].'
          '.$ocha_products['humsnap']['link'].'
          '.$ocha_products['humdash']['link'].'
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
}

/**
 * Creates the full list-item by calling the helper functions
 */
function _hr_layout_get_list_item($node, $term, $type, $prefix, $initial_state = 'hidden') {
  $out = array();
  $file = _hr_layout_get_pdfpreview($node);
  if ($file) {
    $image = theme_image(array('path' => $file, 'alt' => $node->title, 'title' => $node->title, 'attributes' => array('class' => array('img-responsive'))));
    $img_link = l($image, 'node/'.$node->nid, array('html' => TRUE));
    $img_link = '<div id="'.$prefix.'-thumbnail" class="hr-thumbnail '.$initial_state.'">'.$img_link.'</div>';
    $date_string = '';
    if (!empty($node->field_publication_date)) {
      $date = new DateObject($node->field_publication_date[LANGUAGE_NONE][0]['value'], $node->field_publication_date[LANGUAGE_NONE][0]['timezone_db']);
      $date_string = ' - '.date_format_date($date, 'custom', 'd M Y');
    }
    $active_link = '';
    if ($initial_state == 'show') {
      $active_link = 'class="active"';
    }
    $link = '<a class="list-group-item" id="'.$prefix.'" '.$active_link.'>'.$term.$date_string.'</a>';
    $out = array(
      'image' => $img_link,
      'link' => $link,
    );
  }
  return $out;
}
 
