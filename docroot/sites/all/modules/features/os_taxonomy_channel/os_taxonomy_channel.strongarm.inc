<?php
/**
 * @file
 * os_taxonomy_channel.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function os_taxonomy_channel_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_channel_pattern';
  $strongarm->value = '[term:name]';
  $export['pathauto_taxonomy_term_channel_pattern'] = $strongarm;

  return $export;
}
