<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('ReliefWeb'),
  'description' => t('Display content from ReliefWeb APIs.'),
  'category' => t('Humanitarianresponse'),
  'edit form' => 'hr_layout_reliefweb_edit_form',
  'render callback' => 'hr_layout_reliefweb_render',
  'all contexts' => TRUE,
  'defaults' => array(
    'api_path' => '',
    'no_of_items' => '',
  ),
);

/**
 * 'Edit form' callback for the content type.
 */

function hr_layout_reliefweb_edit_form($form, &$form_state){
  $options = range(1, 50);
  $conf = $form_state['conf'];
  $form['api_path'] = array(
    '#type' => 'select',
    '#options' => hr_layout_reliefweb_api_path(),
    '#title' => 'Title to ReliefWeb API path',
    '#description' => t('Choose what you want to display, for instance Job to get a listing of jobs from the ReliefWeb API.'),

  );
  $form['no_of_items'] = array(
    '#type' => 'select',
    '#options' => $options,
    '#required' => TRUE,
    '#title' => 'Number of items to display',
    '#description' => t('Select the number of items you would like to display'),

  );
  return $form;
}

/**
 * Edit form submit handler.
 */

function hr_layout_reliefweb_edit_form_submit($form, &$form_state) {
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

function hr_layout_reliefweb_render($subtype, $conf, $panel_args, $context = NULL){
  $block = new stdClass();
  $block->title = t('ReliefWeb');
  $api_path = $conf['api_path'];
  $no_of_items  = $conf['no_of_items'];

  $api_data = hr_layout_reliefweb_content($api_path);
  $content = '';
  if (isset($no_of_items)) {
    $result = array_slice($api_data, 0, $no_of_items + 1, true);
    $content .= '<ul>';
    foreach ($result as $key => $value) {
      $content .= '<li><a href = '.$value.'> '.$key . '</a></li>';
    }
    $content .= '</ul>';
  }
  $block->content = $content;
  return $block;
}

/**
*  Function to return ReliefWeb Api paths.
*/

function hr_layout_reliefweb_api_path() {
  $source_url = 'http://api.reliefweb.int/v1';
  $api_endpoints = array();
  $request = drupal_http_request($source_url);
  if (isset($request->data)) {
    $data = drupal_json_decode($request->data);
    $api = $data['data'];
    foreach ($api as $value) {
      foreach ($value as $subvalue) {
        $api_endpoints[$value['href']] = $value['title'];
      }
    }
    return $api_endpoints;
  }
  else{
    drupal_set_message("Could not return ReliefWeb API Paths. Please consult the site administrator");
  }
}

/**
*  Function to return content given an api path.
*/

function hr_layout_reliefweb_content($path) {
  //Get 50 items from the API. An option to choose the number of items to display will also be set.
  $path .= '?offset=0&limit=50&preset=minimal&fields[include][]=url';
  $request = drupal_http_request($path);
  if (isset($request->data)) {
    $response = drupal_json_decode($request->data);
    $data = $response['data'];
    $data_array = array();
    foreach ($data as $value) {
      foreach ($value as $subvalue) {
        $url = $value['fields']['url'];
        $title = isset($value['fields']['title']) ? $value['fields']['title'] : $value['fields']['name'];
        $data_array[$title] = $url;
      }
    }
    return $data_array;
  }
  else{
    drupal_set_message('Could not fetch content for the given API path, please consult your site administrator');
  }
}