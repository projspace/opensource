<?php
/**
 * @file
 * os_workflow.features.workflow_access.inc
 */

/**
 * Implements hook_workflow_access_features_default_settings().
 */
function os_workflow_workflow_access_features_default_settings() {
  $workflows = array();

  $workflows['Article Workflow'] = array();
  $workflows['Article Workflow']['Review'] = array();
  $workflows['Article Workflow']['Review']['workflow_features_author_name'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Article Workflow']['Review']['anonymous user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Article Workflow']['Review']['authenticated user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Article Workflow']['Review']['administrator'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Article Workflow']['Review']['editor'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Article Workflow']['Review']['community moderator'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Article Workflow']['Review']['mollom admin'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Article Workflow']['Published'] = array();
  $workflows['Article Workflow']['Published']['workflow_features_author_name'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Article Workflow']['Published']['anonymous user'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Article Workflow']['Published']['authenticated user'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Article Workflow']['Published']['administrator'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Article Workflow']['Published']['editor'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 0,
  );
  $workflows['Article Workflow']['Published']['community moderator'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Article Workflow']['Published']['mollom admin'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );

  return $workflows;
}
