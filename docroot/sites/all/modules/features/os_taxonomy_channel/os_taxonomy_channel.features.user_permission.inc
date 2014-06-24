<?php
/**
 * @file
 * os_taxonomy_channel.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function os_taxonomy_channel_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete terms in channel'.
  $permissions['delete terms in channel'] = array(
    'name' => 'delete terms in channel',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in channel'.
  $permissions['edit terms in channel'] = array(
    'name' => 'edit terms in channel',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
