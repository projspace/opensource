<?php
/**
 * @file
 * os_common_config.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function os_common_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access vote up/down statistics'.
  $permissions['access vote up/down statistics'] = array(
    'name' => 'access vote up/down statistics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'vud',
  );

  // Exported permission: 'administer vote up/down'.
  $permissions['administer vote up/down'] = array(
    'name' => 'administer vote up/down',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'vud',
  );

  // Exported permission: 'administer vote up/down on comments'.
  $permissions['administer vote up/down on comments'] = array(
    'name' => 'administer vote up/down on comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'vud_comment',
  );

  // Exported permission: 'flag comment_abuse'.
  $permissions['flag comment_abuse'] = array(
    'name' => 'flag comment_abuse',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'reset vote up/down votes'.
  $permissions['reset vote up/down votes'] = array(
    'name' => 'reset vote up/down votes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'vud',
  );

  // Exported permission: 'unflag comment_abuse'.
  $permissions['unflag comment_abuse'] = array(
    'name' => 'unflag comment_abuse',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use vote up/down'.
  $permissions['use vote up/down'] = array(
    'name' => 'use vote up/down',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'vud',
  );

  // Exported permission: 'use vote up/down on comments'.
  $permissions['use vote up/down on comments'] = array(
    'name' => 'use vote up/down on comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'vud_comment',
  );

  // Exported permission: 'view vote up/down count on comments'.
  $permissions['view vote up/down count on comments'] = array(
    'name' => 'view vote up/down count on comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'vud_comment',
  );

  return $permissions;
}
