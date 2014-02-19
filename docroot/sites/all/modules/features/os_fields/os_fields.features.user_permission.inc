<?php
/**
 * @file
 * os_fields.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function os_fields_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_community_description'.
  $permissions['create field_community_description'] = array(
    'name' => 'create field_community_description',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_community_description'.
  $permissions['edit field_community_description'] = array(
    'name' => 'edit field_community_description',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_community_description'.
  $permissions['edit own field_community_description'] = array(
    'name' => 'edit own field_community_description',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_community_description'.
  $permissions['view field_community_description'] = array(
    'name' => 'view field_community_description',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_community_description'.
  $permissions['view own field_community_description'] = array(
    'name' => 'view own field_community_description',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
