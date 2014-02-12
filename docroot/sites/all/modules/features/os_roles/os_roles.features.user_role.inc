<?php
/**
 * @file
 * os_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function os_roles_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 5,
  );

  // Exported role: community moderator.
  $roles['community moderator'] = array(
    'name' => 'community moderator',
    'weight' => 3,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 2,
  );

  // Exported role: mollom admin.
  $roles['mollom admin'] = array(
    'name' => 'mollom admin',
    'weight' => 4,
  );

  return $roles;
}
