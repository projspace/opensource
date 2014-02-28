<?php
/**
 * @file
 * os_workflow.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_workflow_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function os_workflow_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_workflow_default_workflows().
 */
function os_workflow_workflow_default_workflows() {
  $workflows = array();

  // Exported workflow: Article Workflow
  $workflows['Article Workflow'] = array(
    'name' => 'Article Workflow',
    'tab_roles' => 'administrator',
    'options' => array(
      'name_as_title' => 0,
      'options' => 'radios',
      'schedule' => 1,
      'schedule_timezone' => 1,
      'comment_log_node' => 0,
      'comment_log_tab' => 0,
      'watchdog_log' => 0,
      'history_tab_show' => 1,
    ),
    'states' => array(
      1 => array(
        'weight' => -50,
        '' . "\0" . '*' . "\0" . 'sysid' => 1,
        '' . "\0" . '*' . "\0" . 'state' => '(creation)',
        'status' => 1,
        '' . "\0" . '*' . "\0" . 'workflow' => NULL,
        'name' => '(creation)',
      ),
      2 => array(
        'weight' => -20,
        '' . "\0" . '*' . "\0" . 'sysid' => 0,
        '' . "\0" . '*' . "\0" . 'state' => 'Review',
        'status' => 1,
        '' . "\0" . '*' . "\0" . 'workflow' => NULL,
        'name' => 'Review',
      ),
      3 => array(
        'weight' => -20,
        '' . "\0" . '*' . "\0" . 'sysid' => 0,
        '' . "\0" . '*' . "\0" . 'state' => 'Published',
        'status' => 1,
        '' . "\0" . '*' . "\0" . 'workflow' => NULL,
        'name' => 'Published',
      ),
    ),
    'transitions' => array(
      0 => array(
        'state_name' => '(creation)',
        'target_state_name' => 'Review',
        'roles' => 'workflow_features_author_name',
      ),
      1 => array(
        'state_name' => '(creation)',
        'target_state_name' => 'Published',
        'roles' => 'administrator',
      ),
      2 => array(
        'state_name' => 'Review',
        'target_state_name' => 'Published',
        'roles' => 'administrator',
      ),
      3 => array(
        'state_name' => 'Published',
        'target_state_name' => 'Review',
        'roles' => 'administrator',
      ),
    ),
    'node_types' => array(
      0 => 'article',
      1 => 'event',
      2 => 'page',
      3 => 'panopoly_page',
    ),
  );

  return $workflows;
}
