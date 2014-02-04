<?php
/**
 * @file
 * hr_layout.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hr_layout_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'clusters';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'values' => array(
        '_none_' => '_none_',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
    'path' => array(
      'values' => array(
        'clusters' => 'clusters',
        'clusters/*' => 'clusters/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-secondary-nav' => array(
          'module' => 'menu_block',
          'delta' => 'secondary-nav',
          'region' => 'navigation',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['clusters'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'outside_space';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'values' => array(
        '_none_' => '_none_',
      ),
      'options' => array(
        'node_form' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'navigation',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['outside_space'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'top',
          'weight' => '-10',
        ),
        'hr_layout-hr_layout_login' => array(
          'module' => 'hr_layout',
          'delta' => 'hr_layout_login',
          'region' => 'top',
          'weight' => '-8',
        ),
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'top',
          'weight' => '-6',
        ),
        'og_menu-og_single_menu_block' => array(
          'module' => 'og_menu',
          'delta' => 'og_single_menu_block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['sitewide'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'within_space';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'values' => array(
        '_any_' => '_any_',
      ),
      'options' => array(
        'node_form' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'hr_layout-hr_layout_checkin' => array(
          'module' => 'hr_layout',
          'delta' => 'hr_layout_checkin',
          'region' => 'top',
          'weight' => '2',
        ),
        'og_extras-node_links' => array(
          'module' => 'og_extras',
          'delta' => 'node_links',
          'region' => 'top',
          'weight' => '0',
        ),
        'og_menu_single-menu' => array(
          'module' => 'og_menu_single',
          'delta' => 'menu',
          'region' => 'navigation',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['within_space'] = $context;

  return $export;
}
