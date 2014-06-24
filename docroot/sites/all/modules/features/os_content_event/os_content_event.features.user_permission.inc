<?php
/**
 * @file
 * os_content_event.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function os_content_event_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create event content'.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'community moderator' => 'community moderator',
      'editor' => 'editor',
      'mollom admin' => 'mollom admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own event content'.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      'administrator' => 'administrator',
      'community moderator' => 'community moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own event content'.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      'administrator' => 'administrator',
      'community moderator' => 'community moderator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
