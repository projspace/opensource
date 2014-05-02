<?php
/**
 * @file
 * os_content_article.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function os_content_article_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'administrator' => 'administrator',
      'community moderator' => 'community moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'administrator' => 'administrator',
      'community moderator' => 'community moderator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
