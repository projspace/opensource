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
  $items['generate-main-menu-links'] = array(
    'description' => "Generate menu items.",
    'arguments' => array(
      'level' => dt('Hierarchy level of menu items to be created.'),
    ),
    'examples' => array(
      'generate-main-menu-links level-0' => 'Generates links for top level. Available options: level-1, level-2',
    ),
  );
  return $items;
}

function drush_os_core_generate_main_menu_links($level) {
  if ($level == 'level-0' || $level == 'all') {
    // Delete existing main menu items before creating new links
    $menu_data = menu_tree_all_data('main-menu', NULL, 4);
    array_walk_recursive($menu_data, '_os_core_delete_menu_links');
  }
  switch ($level) {
    case 'level-0':
      os_core_generate_main_menu_items($level);
      menu_rebuild();
      break;

    case 'all':
      os_core_generate_main_menu_items('level-0');
      menu_rebuild();
      os_core_generate_main_menu_items('level-1');
      menu_rebuild();
      os_core_generate_main_menu_items('level-2');
      menu_rebuild();
      break;

    default:
      os_core_generate_main_menu_items($level);
      menu_rebuild();
      break;
  }
}

/**
 * Generates main menu items for specified level.
 */
function os_core_generate_main_menu_items($level) {
  module_load_include('inc', 'menu', 'menu.admin');
  $args = array('build_info' => array('args' => array('add', array(), array())));
  $menu_items = _os_core_get_main_menu_items($level);
  foreach ($menu_items as $menu_item) {
    // If this is a child item, get parent's mlid and assign parent to menu item.
    if ($menu_item['values']['parent'] != 'main-menu:0') {

      //  Get parent's mlid.
      $parent_mlid = _os_core_get_mlid($menu_item['values']['parent']);

      if (!empty($parent_mlid)) {
        // Set parent attrib to create hierarchy.
        $menu_item['values']['parent'] = 'main-menu:' . $parent_mlid;
      }
    }
    $menu_item += $args;
    // Create menu item.
    drupal_form_submit('menu_edit_item', $menu_item);
  }
}

/**
 * Returns mlid of main menu item by title.
 */
function _os_core_get_mlid($title) {
  $mlid = db_select('menu_links', 'ml')
    ->fields('ml', array('mlid'))
    ->condition('menu_name', 'main-menu', '=')
    ->condition('link_title', $title, '=')
    ->orderBy('mlid', 'DESC')
    ->execute()
    ->fetchField();
  return $mlid;
}

/**
 * Deletes all menu items under main menu.
 */
function _os_core_delete_menu_links($item, $key) {
  if ($key == 'mlid') {
    menu_link_delete($item);
  }
}

/**
 * Returns menu link items array according to hierarchy level.
 */
function _os_core_get_main_menu_items($level) {

  $menu_items['level-0'][] = array(
    'values' => array(
      'link_title' => 'Articles',
      'link_path' => '<front>',
      'menu_name' => 'main-menu',
      'parent' => 'main-menu:0',
      'weight' => -10,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Business',
      'link_path' => 'business',
      'menu_name' => 'main-menu',
      'parent' => 'Articles',
      'weight' => -30,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Education',
      'link_path' => 'education',
      'menu_name' => 'main-menu',
      'parent' => 'Articles',
      'weight' => -29,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Government',
      'link_path' => 'government',
      'menu_name' => 'main-menu',
      'parent' => 'Articles',
      'weight' => -28,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Health',
      'link_path' => 'health',
      'menu_name' => 'main-menu',
      'parent' => 'Articles',
      'weight' => -27,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Law',
      'link_path' => 'law',
      'menu_name' => 'main-menu',
      'parent' => 'Articles',
      'weight' => -26,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Life',
      'link_path' => 'life',
      'menu_name' => 'main-menu',
      'parent' => 'Articles',
      'weight' => -25,
    ),
  );
  $menu_items['level-0'][] = array(
    'values' => array(
      'link_title' => 'Community',
      'link_path' => 'should-be',
      'menu_name' => 'main-menu',
      'parent' => 'main-menu:0',
      'weight' => -9,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Editorial calendar',
      'link_path' => 'resources/editorial-calendar',
      'menu_name' => 'main-menu',
      'parent' => 'Community',
      'weight' => -30,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Contributor spotlight',
      'link_path' => 'should-be/spotlight',
      'menu_name' => 'main-menu',
      'parent' => 'Community',
      'weight' => -29,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Guides for writers',
      'link_path' => 'writers',
      'menu_name' => 'main-menu',
      'parent' => 'Community',
      'weight' => -28,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'Article submission and style guide',
      'link_path' => 'submission-style-guide',
      'menu_name' => 'main-menu',
      'parent' => 'Guides for writers',
      'weight' => -30,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'How to conduct an interview',
      'link_path' => 'how-conduct-interview-opensourcecom',
      'menu_name' => 'main-menu',
      'parent' => 'Guides for writers',
      'weight' => -29,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'How to enter an article',
      'link_path' => 'article-entering-and-editing-guidelines',
      'menu_name' => 'main-menu',
      'parent' => 'Guides for writers',
      'weight' => -28,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Meet the moderators',
      'link_path' => 'opensourcecom-team',
      'menu_name' => 'main-menu',
      'parent' => 'Community',
      'weight' => -27,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Participate',
      'link_path' => 'participate',
      'menu_name' => 'main-menu',
      'parent' => 'Community',
      'weight' => -26,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'Community Moderator program',
      'link_path' => 'community-moderator-program',
      'menu_name' => 'main-menu',
      'parent' => 'Participate',
      'weight' => -30,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'Points and badges',
      'link_path' => 'points-and-badges',
      'menu_name' => 'main-menu',
      'parent' => 'Participate',
      'weight' => -29,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'Rules for comments and discussions',
      'link_path' => 'rules-comments-and-discussions',
      'menu_name' => 'main-menu',
      'parent' => 'Participate',
      'weight' => -28,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Register',
      'link_path' => 'user/register',
      'menu_name' => 'main-menu',
      'parent' => 'Community',
      'weight' => -25,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Submit your story',
      'link_path' => 'how-submit-article',
      'menu_name' => 'main-menu',
      'parent' => 'Community',
      'weight' => -24,
    ),
  );
  $menu_items['level-0'][] = array(
    'values' => array(
      'link_title' => 'About',
      'link_path' => 'about',
      'menu_name' => 'main-menu',
      'parent' => 'main-menu:0',
      'weight' => -8,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'The Open Source Way',
      'link_path' => 'open-source-way',
      'menu_name' => 'main-menu',
      'parent' => 'About',
      'weight' => -24,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'colophon',
      'link_path' => 'colophon',
      'menu_name' => 'main-menu',
      'parent' => 'About',
      'weight' => -23,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Contact',
      'link_path' => 'contact',
      'menu_name' => 'main-menu',
      'parent' => 'About',
      'weight' => -22,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Media kit',
      'link_path' => 'media-kit',
      'menu_name' => 'main-menu',
      'parent' => 'About',
      'weight' => -21,
    ),
  );
  $menu_items['level-0'][] = array(
    'values' => array(
      'link_title' => 'Resources',
      'link_path' => 'resources',
      'menu_name' => 'main-menu',
      'parent' => 'main-menu:0',
      'weight' => -7,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'eBooks',
      'link_path' => 'resources/ebooks',
      'menu_name' => 'main-menu',
      'parent' => 'Resources',
      'weight' => -30,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'Bits and bolts: The past, present, and future of open hardware',
      'link_path' => 'resources/ebook/open-hardware',
      'menu_name' => 'main-menu',
      'parent' => 'eBooks',
      'weight' => -30,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'Open source talks: OSCON 2014 speaker interviews',
      'link_path' => 'resources/ebook/oscon-2014-interviews',
      'menu_name' => 'main-menu',
      'parent' => 'eBooks',
      'weight' => -29,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'Experimenting with open science: Open source in the field and in the lab',
      'link_path' => 'resources/ebook/open-science',
      'menu_name' => 'main-menu',
      'parent' => 'eBooks',
      'weight' => -28,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'Open source in the library: A guide for open-minded bibliophiles',
      'link_path' => 'resources/ebook/open-source-libraryguide',
      'menu_name' => 'main-menu',
      'parent' => 'eBooks',
      'weight' => -27,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'How to get started with open source',
      'link_path' => 'resources/ebook/how-get-started-open-source',
      'menu_name' => 'main-menu',
      'parent' => 'eBooks',
      'weight' => -26,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'How women are shaping the open source landscape',
      'link_path' => 'resources/ebook/women-in-open-source',
      'menu_name' => 'main-menu',
      'parent' => 'eBooks',
      'weight' => -25,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'Getting youth involved in open source',
      'link_path' => 'resources/ebook/youth-in-open-source',
      'menu_name' => 'main-menu',
      'parent' => 'eBooks',
      'weight' => -24,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'Open always wins: A Michael Tiemann collection',
      'link_path' => 'resources/ebook/open-always-wins',
      'menu_name' => 'main-menu',
      'parent' => 'eBooks',
      'weight' => -23,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'All Things Open conference interview series',
      'link_path' => 'resources/ebook/all-things-open-2013',
      'menu_name' => 'main-menu',
      'parent' => 'eBooks',
      'weight' => -22,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'Open source video editing for beginners: Kdenlive series',
      'link_path' => 'resources/ebook/video-editing',
      'menu_name' => 'main-menu',
      'parent' => 'eBooks',
      'weight' => -21,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'Applying open source principles to government',
      'link_path' => 'resources/ebook/opengov',
      'menu_name' => 'main-menu',
      'parent' => 'eBooks',
      'weight' => -20,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'An open world: Stories from the open source community',
      'link_path' => 'resources/ebook/best',
      'menu_name' => 'main-menu',
      'parent' => 'eBooks',
      'weight' => -19,
    ),
  );
  $menu_items['level-2'][] = array(
    'values' => array(
      'link_title' => 'Open minded CEOs',
      'link_path' => 'resources/ebook/ceo',
      'menu_name' => 'main-menu',
      'parent' => 'eBooks',
      'weight' => -18,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Projects and applications',
      'link_path' => 'resources/projects-and-applications',
      'menu_name' => 'main-menu',
      'parent' => 'Resources',
      'weight' => -29,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Organizations',
      'link_path' => 'resources/organizations',
      'menu_name' => 'main-menu',
      'parent' => 'Resources',
      'weight' => -28,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Conferences and events',
      'link_path' => 'resources/conferences-and-events-monthly',
      'menu_name' => 'main-menu',
      'parent' => 'Resources',
      'weight' => -27,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Webcasts',
      'link_path' => 'webcast',
      'menu_name' => 'main-menu',
      'parent' => 'Resources',
      'weight' => -26,
    ),
  );
  $menu_items['level-1'][] = array(
    'values' => array(
      'link_title' => 'Editorial calendar',
      'link_path' => 'resources/editorial-calendar',
      'menu_name' => 'main-menu',
      'parent' => 'Resources',
      'weight' => -25,
    ),
  );
  return $menu_items[$level];
}

/**
 * Implements drush_hook_COMMAND_validate().
 */
function drush_os_core_mbp_generate_term_validate() {
  if (!module_exists('media_browser_plus')) {
    return drush_set_error(dt('Media browser module is not enabled. Please enable it and try again.'));
  }
}
/**
 * Implements drush_hook_COMMAND_validate().
 */
function drush_os_core_mbp_iterate_folders_validate() {
  if (!module_exists('media_browser_plus')) {
    return drush_set_error(dt('Media browser module is not enabled. Please enable it and try again.'));
  }
}

/**
 * Callback function for mbp-generate-term.
 */
function drush_os_core_mbp_generate_term($filling = 'ascii') {
  $vid = taxonomy_vocabulary_machine_name_load('media_folders')->vid;
  $parent_term = taxonomy_get_term_by_name('Media Root', 'media_folders');
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
 * Implements drush_hook_COMMAND().
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
      if ($a == '//') {
        $folder_heirarchical_name = explode('/', substr($str, 0, -2));
      }
      else {
        $folder_heirarchical_name = explode('/', $str);
      }
      $folder_names = array_filter($folder_heirarchical_name);

      /*$vid = taxonomy_vocabulary_machine_name_load('media_folders')->vid;
      $parent_term =  taxonomy_get_term_by_name('Media Root', 'media_folders');
      $term = taxonomy_get_term_by_name($folder_name[0], 'media_folders');
      if (empty($term) && sizeof($folder_name[0] > 1)) {
        $term = new stdClass();
        $term->vid = $vid;
        $term->name = $folder_name[0];
        $term->description = $folder_name[0];
        $term->parent = $parent_term->tid;
        taxonomy_term_save($term);
      }*/
      if (sizeof($folder_names) == 1) {
        $vid = taxonomy_vocabulary_machine_name_load('media_folders')->vid;
        $parent_term =  taxonomy_get_term_by_name('Media Root', 'media_folders');
        if (!empty($parent_term)) {
          $parent_term = array_shift($parent_term);
        }
        $folderterm = taxonomy_get_term_by_name($folder_names[0], 'media_folders');
        if (empty($folderterm) && (strlen($folder_names[0]) > 1)) {
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
        for ($i = 0; $i < sizeof($folder_names); $i++) {
          if ($i == 0) {
            $vid = taxonomy_vocabulary_machine_name_load('media_folders')->vid;
            $parent_term = taxonomy_get_term_by_name('Media Root', 'media_folders');
            if (!empty($parent_term)) {
              $parent_term = array_shift($parent_term);
            }
            $folderterm = taxonomy_get_term_by_name($folder_names[$i], 'media_folders');
            if (empty($folderterm) && (strlen($folder_names[$i]) > 1)) {
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
            $parent_term = taxonomy_get_term_by_name($folder_names[0], 'media_folders');
            if (!empty($parent_term)) {
              $parent_term = array_shift($parent_term);
            }
            $folderterm = taxonomy_get_term_by_name($folder_names[$i], 'media_folders');
            if (empty($folderterm) && (strlen($folder_names[$i]) > 1)) {
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
