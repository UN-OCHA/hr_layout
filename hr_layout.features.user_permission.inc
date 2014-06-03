<?php
/**
 * @file
 * hr_layout.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hr_layout_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create any fts_visualization bean'.
  $permissions['create any fts_visualization bean'] = array(
    'name' => 'create any fts_visualization bean',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any fts_visualization bean'.
  $permissions['delete any fts_visualization bean'] = array(
    'name' => 'delete any fts_visualization bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any fts_visualization bean'.
  $permissions['edit any fts_visualization bean'] = array(
    'name' => 'edit any fts_visualization bean',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any fts_visualization bean'.
  $permissions['view any fts_visualization bean'] = array(
    'name' => 'view any fts_visualization bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
