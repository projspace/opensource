<?php
/**
 * @file
 * os_user.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_user_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_field_group_info_alter().
 */
function os_user_field_group_info_alter(&$data) {
  if (isset($data['group_user_profile|user|user|form'])) {
    $data['group_user_profile|user|user|form']->data['children']['1'] = 'field_community_description'; /* WAS: '' */
    $data['group_user_profile|user|user|form']->data['children']['2'] = 'field_display_name'; /* WAS: '' */
    $data['group_user_profile|user|user|form']->data['children']['3'] = 'field_location'; /* WAS: '' */
    $data['group_user_profile|user|user|form']->data['children']['4'] = 'field_website'; /* WAS: '' */
    $data['group_user_profile|user|user|form']->data['children']['5'] = 'field_profile_point_notification'; /* WAS: '' */
    $data['group_user_profile|user|user|form']->data['format_settings']['formatter'] = 'open'; /* WAS: 'collapsible' */
    $data['group_user_profile|user|user|form']->data['format_settings']['label'] = 'User Profile'; /* WAS: '' */
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function os_user_field_default_field_instances_alter(&$data) {
  if (isset($data['user-user-field_user_picture'])) {
    $data['user-user-field_user_picture']['settings']['min_resolution'] = ''; /* WAS: '300x200' */
  }
}

/**
 * Implements hook_default_page_manager_handlers_alter().
 */
function os_user_default_page_manager_handlers_alter(&$data) {
  if (isset($data['pm_existing_pages_user_login_panel_context'])) {
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-1']->configuration['admin_title'] = ''; /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-1']->configuration['depth'] = 0; /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-1']->configuration['expanded'] = 0; /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-1']->configuration['follow'] = 0; /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-1']->configuration['level'] = 1; /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-1']->configuration['menu_name'] = 'menu-user-registration-links'; /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-1']->configuration['parent_mlid'] = 'menu-user-registration-links:0'; /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-1']->configuration['sort'] = 0; /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-1']->configuration['title_link'] = 0; /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-1']->subtype = 'menu-user-registration-links'; /* WAS: 'pm_existing_pages' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-1']->type = 'menu_tree'; /* WAS: 'pm_existing_pages' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-2'] = (object) array(
          'pid' => 'new-2',
          'panel' => 'contentmain',
          'type' => 'pm_existing_pages',
          'subtype' => 'pm_existing_pages',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            0 => 'task_id',
            'task_id' => 'user_login',
            'override_title' => 1,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'css' => array(),
          'extras' => array(),
          'position' => 1,
          'locks' => array(),
        ); /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-3'] = (object) array(
          'pid' => 'new-3',
          'panel' => 'sidebar',
          'type' => 'panels_mini',
          'subtype' => 'common_1',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'override_title' => 0,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
        ); /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->panels['contentmain']['1'] = 'new-2'; /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->panels['sidebar'] = array(
      0 => 'new-3',
    ); /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->title = 'User account'; /* WAS: 'Log in' */
    unset($data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-1']->configuration['0']);
    unset($data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-1']->configuration['task_id']);
  }
  if (isset($data['pm_existing_pages_user_password_panel_context'])) {
    $data['pm_existing_pages_user_password_panel_context']->conf['display']->content['new-4'] = (object) array(
          'pid' => 'new-4',
          'panel' => 'contentmain',
          'type' => 'menu_tree',
          'subtype' => 'menu-user-registration-links',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'menu_name' => 'menu-user-registration-links',
            'parent_mlid' => 'menu-user-registration-links:0',
            'title_link' => 0,
            'admin_title' => '',
            'level' => 1,
            'follow' => 0,
            'depth' => 0,
            'expanded' => 0,
            'sort' => 0,
            'override_title' => 1,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'style' => '',
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
        ); /* WAS: '' */
    $data['pm_existing_pages_user_password_panel_context']->conf['display']->content['new-5'] = (object) array(
          'pid' => 'new-5',
          'panel' => 'contentmain',
          'type' => 'pm_existing_pages',
          'subtype' => 'pm_existing_pages',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            0 => 'task_id',
            'task_id' => 'user_password',
            'override_title' => 1,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'style' => '',
          'css' => array(),
          'extras' => array(),
          'position' => 1,
          'locks' => array(),
        ); /* WAS: '' */
    $data['pm_existing_pages_user_password_panel_context']->conf['display']->content['new-6'] = (object) array(
          'pid' => 'new-6',
          'panel' => 'sidebar',
          'type' => 'panels_mini',
          'subtype' => 'common_1',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => '',
          'cache' => array(),
          'style' => '',
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
        ); /* WAS: '' */
    $data['pm_existing_pages_user_password_panel_context']->conf['display']->panels['contentmain']['0'] = 'new-4'; /* WAS: 'new-2' */
    $data['pm_existing_pages_user_password_panel_context']->conf['display']->panels['contentmain']['1'] = 'new-5'; /* WAS: '' */
    $data['pm_existing_pages_user_password_panel_context']->conf['display']->panels['sidebar'] = array(
      0 => 'new-6',
    ); /* WAS: '' */
    $data['pm_existing_pages_user_password_panel_context']->conf['display']->title = 'User account'; /* WAS: '' */
    unset($data['pm_existing_pages_user_password_panel_context']->conf['display']->content['new-2']);
  }
  if (isset($data['pm_existing_pages_user_register_panel_context'])) {
    $data['pm_existing_pages_user_register_panel_context']->conf['display']->content['new-7'] = (object) array(
          'pid' => 'new-7',
          'panel' => 'contentmain',
          'type' => 'menu_tree',
          'subtype' => 'menu-user-registration-links',
          'shown' => TRUE,
          'access' => array(),
          'cache' => array(),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
        ); /* WAS: '' */
    $data['pm_existing_pages_user_register_panel_context']->conf['display']->content['new-8'] = (object) array(
          'pid' => 'new-8',
          'panel' => 'contentmain',
          'type' => 'pm_existing_pages',
          'subtype' => 'pm_existing_pages',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            0 => 'task_id',
            'task_id' => 'user_register',
            'override_title' => 1,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'css' => array(),
          'extras' => array(),
          'position' => 1,
          'locks' => array(),
        ); /* WAS: '' */
    $data['pm_existing_pages_user_register_panel_context']->conf['display']->content['new-9'] = (object) array(
          'pid' => 'new-9',
          'panel' => 'sidebar',
          'type' => 'panels_mini',
          'subtype' => 'common_1',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => '',
          'cache' => array(),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
        ); /* WAS: '' */
    $data['pm_existing_pages_user_register_panel_context']->conf['display']->panels['contentmain']['0'] = 'new-7'; /* WAS: 'new-3' */
    $data['pm_existing_pages_user_register_panel_context']->conf['display']->panels['contentmain']['1'] = 'new-8'; /* WAS: '' */
    $data['pm_existing_pages_user_register_panel_context']->conf['display']->panels['sidebar'] = array(
      0 => 'new-9',
    ); /* WAS: '' */
    $data['pm_existing_pages_user_register_panel_context']->conf['display']->title = 'User account'; /* WAS: 'Create an Account' */
    unset($data['pm_existing_pages_user_register_panel_context']->conf['display']->content['new-3']);
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function os_user_flag_default_flags() {
  $flags = array();
  // Exported flag: "Spotlighted".
  $flags['spotlight'] = array(
    'entity_type' => 'user',
    'title' => 'Spotlighted',
    'global' => 1,
    'types' => array(),
    'flag_short' => 'Spotlight this user',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remove from spotlight',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'featured' => 'featured',
      'token' => 'token',
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'show_on_profile' => 1,
    'access_uid' => '',
    'flag_confirmation' => 'Are you sure you want to put this user in spotlight?',
    'unflag_confirmation' => 'Are you sure you want to remove this user from spotlight?',
    'module' => 'os_user',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
