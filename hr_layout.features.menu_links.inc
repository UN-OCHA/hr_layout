<?php
/**
 * @file
 * hr_layout.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function hr_layout_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_about:clusters
  $menu_links['main-menu_about:clusters'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'clusters',
    'router_path' => 'clusters',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_about:clusters',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_clusters:clusters',
  );
  // Exported menu link: main-menu_global:clusters/global
  $menu_links['main-menu_global:clusters/global'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'clusters/global',
    'router_path' => 'clusters/global',
    'link_title' => 'Global',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_global:clusters/global',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
    'parent_identifier' => 'main-menu_clusters:clusters',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Global');


  return $menu_links;
}
