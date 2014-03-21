<?php
/**
 * @file
 * os_user.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_user_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_field_group_info_alter().
 */
function os_user_field_group_info_alter(&$data) {
  if (isset($data['group_user_profile|user|user|form'])) {
    $data['group_user_profile|user|user|form']->data['children']['1'] = 'field_display_name'; /* WAS: '' */
    $data['group_user_profile|user|user|form']->data['children']['2'] = 'field_location'; /* WAS: '' */
    $data['group_user_profile|user|user|form']->data['children']['3'] = 'field_website'; /* WAS: '' */
    $data['group_user_profile|user|user|form']->data['children']['4'] = 'field_community_description'; /* WAS: '' */
    $data['group_user_profile|user|user|form']->data['children']['5'] = 'field_profile_point_notification'; /* WAS: '' */
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
