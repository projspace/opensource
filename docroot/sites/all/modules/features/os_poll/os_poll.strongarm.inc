<?php
/**
 * @file
 * os_poll.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function os_poll_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_poll_pattern';
  $strongarm->value = 'poll/[node:title]';
  $export['pathauto_node_poll_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pollanon_threshold_count';
  $strongarm->value = 10;
  $export['pollanon_threshold_count'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pollanon_threshold_time';
  $strongarm->value = 600;
  $export['pollanon_threshold_time'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pollanon_use_ajah';
  $strongarm->value = FALSE;
  $export['pollanon_use_ajah'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pollanon_use_cookie_method';
  $strongarm->value = TRUE;
  $export['pollanon_use_cookie_method'] = $strongarm;

  return $export;
}
