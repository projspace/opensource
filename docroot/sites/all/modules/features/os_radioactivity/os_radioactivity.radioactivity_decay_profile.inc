<?php
/**
 * @file
 * os_radioactivity.radioactivity_decay_profile.inc
 */

/**
 * Implements hook_default_radioactivity_decay_profile().
 */
function os_radioactivity_default_radioactivity_decay_profile() {
  $export = array();

  $radioactivity_decay_profile = new stdClass();
  $radioactivity_decay_profile->disabled = FALSE; /* Edit this to true to make a default radioactivity_decay_profile disabled initially */
  $radioactivity_decay_profile->api_version = 1;
  $radioactivity_decay_profile->machine_name = 'most_popular';
  $radioactivity_decay_profile->name = 'Most popular';
  $radioactivity_decay_profile->description = 'Give energy based on views and most other interactions, promoting older content from the 3 days.
259200 (s) = 3 days';
  $radioactivity_decay_profile->enable_decay = 2;
  $radioactivity_decay_profile->granularity = '60';
  $radioactivity_decay_profile->half_life = 259200;
  $radioactivity_decay_profile->cut_off = '10';
  $radioactivity_decay_profile->storage = 'Live';
  $export['most_popular'] = $radioactivity_decay_profile;

  return $export;
}
