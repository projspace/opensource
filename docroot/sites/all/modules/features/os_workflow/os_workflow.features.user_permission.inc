<?php
/**
 * @file
 * os_workflow.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function os_workflow_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access workflow summary views'.
  $permissions['access workflow summary views'] = array(
    'name' => 'access workflow summary views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workflow_views',
  );

  // Exported permission: 'administer workflow'.
  $permissions['administer workflow'] = array(
    'name' => 'administer workflow',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workflow_admin_ui',
  );

  // Exported permission: 'participate in workflow'.
  $permissions['participate in workflow'] = array(
    'name' => 'participate in workflow',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'community moderator' => 'community moderator',
      'editor' => 'editor',
      'mollom admin' => 'mollom admin',
    ),
    'module' => 'workflow_admin_ui',
  );

  // Exported permission: 'revert workflow'.
  $permissions['revert workflow'] = array(
    'name' => 'revert workflow',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workflow_revert',
  );

  // Exported permission: 'schedule workflow transitions'.
  $permissions['schedule workflow transitions'] = array(
    'name' => 'schedule workflow transitions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workflow',
  );

  // Exported permission: 'show workflow state form'.
  $permissions['show workflow state form'] = array(
    'name' => 'show workflow state form',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workflow',
  );

  return $permissions;
}
