<?php
/**
 * @file
 * os_workflow.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function os_workflow_defaultconfig_features() {
  return array(
    'os_workflow' => array(
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function os_workflow_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workflow_article';
  $strongarm->value = array(
    0 => 'node',
  );
  $export['workflow_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workflow_event';
  $strongarm->value = array(
    0 => 'node',
  );
  $export['workflow_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workflow_page';
  $strongarm->value = array();
  $export['workflow_page'] = $strongarm;

  return $export;
}
