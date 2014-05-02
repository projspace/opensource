<?php
/**
 * @file
 * os_mollom.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function os_mollom_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer mollom'.
  $permissions['administer mollom'] = array(
    'name' => 'administer mollom',
    'roles' => array(
      'administrator' => 'administrator',
      'community moderator' => 'community moderator',
      'mollom admin' => 'mollom admin',
    ),
    'module' => 'mollom',
  );

  // Exported permission: 'bypass mollom protection'.
  $permissions['bypass mollom protection'] = array(
    'name' => 'bypass mollom protection',
    'roles' => array(
      'administrator' => 'administrator',
      'community moderator' => 'community moderator',
      'mollom admin' => 'mollom admin',
    ),
    'module' => 'mollom',
  );

  return $permissions;
}
