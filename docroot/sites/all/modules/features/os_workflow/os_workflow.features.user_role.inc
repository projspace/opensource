<?php
/**
 * @file
 * os_workflow.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function os_workflow_user_default_roles() {
  $roles = array();

  // Exported role: anonymous user.
  $roles['anonymous user'] = array(
    'name' => 'anonymous user',
    'weight' => 0,
  );

  // Exported role: authenticated user.
  $roles['authenticated user'] = array(
    'name' => 'authenticated user',
    'weight' => 1,
  );

  return $roles;
}
