<?php

/**
 * Drush commands for generating the taxonomy terms of media folders.
 */

/**
 * Implements hook_drush_command().
 */
function os_core_drush_command() {
  $items = array();

  // Generate the mediabrowser plus terms.
  $items['mbp-generate-term'] = array(
    'description' => "Generate the media browser plus terms.",
    'arguments' => array(
      'filling' => '',
    ),
    'aliases' => array('mgt'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL, // Initialize Drupal fully
  );
  return $items;
}

/**
 * Implements drush_hook_COMMAND_validate().
 */
function drush_os_core_mbp_generate_term_validate() {
  if(!module_exists('media_browser_plus')) {
    return drush_set_error(dt('Media browser module is not enabled. Please enable it and try again.'));
  }
}

function drush_os_core_mbp_generate_term($filling = 'ascii') {
  $vid = taxonomy_vocabulary_machine_name_load('media_folders')->vid;
  $parent_term =  taxonomy_get_term_by_name('Media Root', 'media_folders');
  $term_names = array(
    '0' => array('name' => 'education', 'description' => 'Education images.'),
    '1' => array('name' => 'about', 'description' => 'About Category images.'),
    '2' => array('name' => 'business', 'description' => 'Business Images'),
    '3' => array('name' => 'business-uploads', 'description' => 'Business Upload Images'),
    '4' => array('name' => 'ecards', 'description' => 'Ecards'),
    '5' => array('name' => 'education-uploads', 'description' => 'Education Images'),
    '6' => array('name' => 'government', 'description' => 'Government Images.'),
    '7' => array('name' => 'government-uploads', 'description' => 'Government Uploads.'),
    '8' => array('name' => 'health', 'description' => 'Health'),
    '9' => array('name' => 'health-uploads', 'description' => 'Health Uploads'),
    '10' => array('name' => 'law', 'description' => 'Law'),
    '11' => array('name' => 'law-uploads', 'description' => 'Law Uploads.'),
    '12' => array('name' => 'life', 'description' => 'Life'),
    '13' => array('name' => 'life-uploads', 'description' => 'Life Uploads.'),
    '14' => array('name' => 'nameplates', 'description' => 'Name Plates'),
    '15' => array('name' => 'promos', 'description' => 'Promotions.'),
    '16' => array('name' => 'resources', 'description' => 'Resources.'),
    '17' => array('name' => 'should-be', 'description' => 'should-be Images.'),
  );
  foreach ($term_names as $term_item) {
    $term = new stdClass();
    $term->vid = $vid;
    $term->name = $term_item['name'];
    $term->description = $term_item['description'];
    taxonomy_term_save($term);
  }
}
