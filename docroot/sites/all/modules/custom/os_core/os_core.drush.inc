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
  $items['mbp-iterate-folders'] = array(
    'description' => "Generate the folders for media terms.",
    'arguments' => array(
      'filling' => '',
    ),
    'aliases' => array('mif'),
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
/**
 * Implements drush_hook_COMMAND_validate().
 */
function drush_os_core_mbp_iterate_folders_validate() {
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

/**
 * Implements drush_HOOK_command().
 */
function drush_os_core_mbp_iterate_folders($filling = 'ascii') {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'file')
    ->propertyCondition('status', 1)
    ->addMetaData('account', user_load(1)); // Run the query as user 1.
  $result = $query->execute();
  foreach ($result['file'] as $file) {
    $file_entity = file_load($file->fid);
    $prefix = 'public://';
    $file_uri = $file_entity->uri;
    $file_name = basename($file_uri); //Find file name
    $file_uri = explode($file_name, $file_uri);
    if (substr($file_uri[0], 0, strlen($prefix)) == $prefix) {
      $str = substr($file_uri[0], strlen($prefix));
      $a = strstr($str, '//');
      if($a == '//') {
        $folder_heirarchical_name = explode('/', substr($str, 0, -2));
      }
      else {
        $folder_heirarchical_name = explode('/', $str);
      }
      $folder_names = array_filter($folder_heirarchical_name);

      /*$vid = taxonomy_vocabulary_machine_name_load('media_folders')->vid;
      $parent_term =  taxonomy_get_term_by_name('Media Root', 'media_folders');
      $term = taxonomy_get_term_by_name($folder_name[0], 'media_folders');
      if(empty($term) && sizeof($folder_name[0] > 1)) {
        $term = new stdClass();
        $term->vid = $vid;
        $term->name = $folder_name[0];
        $term->description = $folder_name[0];
        $term->parent = $parent_term->tid;
        taxonomy_term_save($term);
      }*/
      if(sizeof($folder_names) == 1) {
        $vid = taxonomy_vocabulary_machine_name_load('media_folders')->vid;
        $parent_term =  taxonomy_get_term_by_name('Media Root', 'media_folders');
        if (!empty($parent_term)) {
          $parent_term = array_shift($parent_term);
        }
        $folderterm = taxonomy_get_term_by_name($folder_names[0], 'media_folders');
        if(empty($folderterm) && (strlen($folder_names[0]) > 1)) {
          $term = new stdClass();
          $term->vid = $vid;
          $term->name = $folder_names[0];
          $term->description = $folder_names[0];
          $term->parent = $parent_term->tid;
          taxonomy_term_save($term);
          os_core_drush_move_file_entity($term->tid, $file_entity);
        }
        else {
          $folderterm = taxonomy_get_term_by_name($folder_names[0], 'media_folders');
          if (!empty($folderterm)) {
            $first_term = array_shift($folderterm);
          }
          os_core_drush_move_file_entity($first_term->tid, $file_entity);
        }
      }
      else {
        for($i = 0; $i < sizeof($folder_names); $i++) {
          if($i == 0) {
            $vid = taxonomy_vocabulary_machine_name_load('media_folders')->vid;
            $parent_term =  taxonomy_get_term_by_name('Media Root', 'media_folders');
            if (!empty($parent_term)) {
              $parent_term = array_shift($parent_term);
            }
            $folderterm = taxonomy_get_term_by_name($folder_names[$i], 'media_folders');
            if(empty($folderterm) && (strlen($folder_names[$i]) > 1)) {
              $term = new stdClass();
              $term->vid = $vid;
              $term->name = $folder_names[0];
              $term->description = $folder_names[0];
              $term->parent = $parent_term->tid;
              taxonomy_term_save($term);
              os_core_drush_move_file_entity($term->tid, $file_entity);
            }
            else {
              $folderterm = taxonomy_get_term_by_name($folder_names[0], 'media_folders');
              if (!empty($folderterm)) {
                $first_term = array_shift($folderterm);
              }
              os_core_drush_move_file_entity($first_term->tid, $file_entity);
            }
          }
          else {
            $vid = taxonomy_vocabulary_machine_name_load('media_folders')->vid;
            $parent_term =  taxonomy_get_term_by_name($folder_names[0], 'media_folders');
            if (!empty($parent_term)) {
              $parent_term = array_shift($parent_term);
            }
            $folderterm = taxonomy_get_term_by_name($folder_names[$i], 'media_folders');
            if(empty($folderterm) && (strlen($folder_names[$i]) > 1)) {
              $term = new stdClass();
              $term->vid = $vid;
              $term->name = $folder_names[$i];
              $term->description = $folder_names[$i];
              $term->parent = $parent_term->tid;
              taxonomy_term_save($term);
              os_core_drush_move_file_entity($term->tid, $file_entity);
            }
            else {
              $folderterm = taxonomy_get_term_by_name($folder_names[$i], 'media_folders');
              if (!empty($folderterm)) {
                $first_term = array_shift($folderterm);
              }
              os_core_drush_move_file_entity($first_term->tid, $file_entity);
            }
          }
        }
      }
    }
  }
}

/**
 * Attach the term id of the folder with file.
 */
function os_core_drush_move_file_entity($tid, $entity) {
  $entity->field_folder[LANGUAGE_NONE] = array(array('tid' => $tid));
  $entity->field_folder[LANGUAGE_NONE][0]['tid'] = $tid;
  file_save($entity);
}
