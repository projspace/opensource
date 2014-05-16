<?php
/**
 * @file
 * os_homepage.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function os_homepage_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panopoly_admin_front_page_and_sticky';
  $strongarm->value = '1';
  $export['panopoly_admin_front_page_and_sticky'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'home';
  $export['site_frontpage'] = $strongarm;

  return $export;
}
