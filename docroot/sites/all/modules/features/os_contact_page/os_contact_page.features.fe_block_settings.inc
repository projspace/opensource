<?php
/**
 * @file
 * os_contact_page.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function os_contact_page_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['bean-contact-block'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'contact-block',
    'module' => 'bean',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'opensource' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opensource',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
