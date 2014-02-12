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
  }
}

/**
 * Implements hook_panelizer_defaults_override_alter().
 */
function os_user_panelizer_defaults_override_alter(&$data) {
  if (isset($data['user:user:default'])) {
    $data['user:user:default']->display->content['new-2']->panel = 'column1'; /* WAS: 'column2' */
    $data['user:user:default']->display->content['new-2']->position = 1; /* WAS: 0 */
    $data['user:user:default']->display->content['new-2']->subtype = 'user:flag_spotlight'; /* WAS: 'user:field_user_picture' */
    $data['user:user:default']->display->content['new-2']->type = 'entity_field_extra'; /* WAS: 'entity_field' */
    $data['user:user:default']->display->content['new-3'] = (object) array(
          'pid' => 'new-3',
          'panel' => 'column2',
          'type' => 'entity_field',
          'subtype' => 'user:field_user_picture',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'label' => 'hidden',
            'formatter' => 'image',
            'delta_limit' => 0,
            'delta_offset' => 0,
            'delta_reversed' => FALSE,
            'formatter_settings' => array(
              'image_style' => 'panopoly_image_full',
              'image_link' => '',
            ),
            'context' => 'panelizer',
            'override_title' => 1,
            'override_title_text' => '',
            'view_mode' => NULL,
            'widget_title' => NULL,
            'items_per_page' => NULL,
            'exposed' => array(
              'sort_by' => NULL,
              'sort_order' => NULL,
            ),
            'use_pager' => NULL,
            'pager_id' => NULL,
            'offset' => NULL,
            'link_to_view' => NULL,
            'more_link' => NULL,
            'path' => NULL,
          ),
          'cache' => array(),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
        ); /* WAS: '' */
    $data['user:user:default']->display->panels['column1']['1'] = 'new-2'; /* WAS: '' */
    $data['user:user:default']->display->panels['column2']['0'] = 'new-3'; /* WAS: 'new-2' */
    unset($data['user:user:default']->display->content['new-2']->configuration);
  }
  if (isset($data['user:user:default:default'])) {
    $data['user:user:default:default']->display->content['new-4']->configuration['formatter'] = 'image'; /* WAS: 'text_default' */
    $data['user:user:default:default']->display->content['new-4']->configuration['formatter_settings']['image_link'] = ''; /* WAS: '' */
    $data['user:user:default:default']->display->content['new-4']->configuration['formatter_settings']['image_style'] = 'panopoly_image_half'; /* WAS: '' */
    $data['user:user:default:default']->display->content['new-4']->position = 0; /* WAS: 1 */
    $data['user:user:default:default']->display->content['new-4']->subtype = 'user:field_user_picture'; /* WAS: 'user:field_user_about' */
    $data['user:user:default:default']->display->content['new-5']->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => 0,
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '',
    ); /* WAS: '' */
    $data['user:user:default:default']->display->content['new-5']->position = 1; /* WAS: 2 */
    $data['user:user:default:default']->display->content['new-5']->subtype = 'user:field_user_about'; /* WAS: 'user:summary' */
    $data['user:user:default:default']->display->content['new-5']->type = 'entity_field'; /* WAS: 'entity_field_extra' */
    $data['user:user:default:default']->display->content['new-6'] = (object) array(
          'pid' => 'new-6',
          'panel' => 'contentmain',
          'type' => 'entity_field_extra',
          'subtype' => 'user:summary',
          'shown' => TRUE,
          'access' => array(),
          'cache' => array(),
          'css' => array(),
          'extras' => array(),
          'position' => 2,
          'locks' => array(),
        ); /* WAS: '' */
    $data['user:user:default:default']->display->panels['contentmain']['0'] = 'new-4'; /* WAS: 'new-3' */
    $data['user:user:default:default']->display->panels['contentmain']['1'] = 'new-5'; /* WAS: 'new-4' */
    $data['user:user:default:default']->display->panels['contentmain']['2'] = 'new-6'; /* WAS: 'new-5' */
    unset($data['user:user:default:default']->display->content['new-3']);
  }
  if (isset($data['user:user:default:featured'])) {
    $data['user:user:default:featured']->display->content['new-7']->configuration['delta_limit'] = 0; /* WAS: '' */
    $data['user:user:default:featured']->display->content['new-7']->configuration['delta_offset'] = 0; /* WAS: '' */
    $data['user:user:default:featured']->display->content['new-7']->configuration['delta_reversed'] = FALSE; /* WAS: '' */
    $data['user:user:default:featured']->display->content['new-7']->configuration['formatter'] = 'image'; /* WAS: '' */
    $data['user:user:default:featured']->display->content['new-7']->configuration['formatter_settings'] = array(
      'image_style' => 'panopoly_image_half',
      'image_link' => 'content',
    ); /* WAS: '' */
    $data['user:user:default:featured']->display->content['new-7']->configuration['label'] = 'hidden'; /* WAS: '' */
    $data['user:user:default:featured']->display->content['new-7']->panel = 'column1'; /* WAS: 'column2' */
    $data['user:user:default:featured']->display->content['new-7']->subtype = 'user:field_user_picture'; /* WAS: 'user:name' */
    $data['user:user:default:featured']->display->content['new-7']->type = 'entity_field'; /* WAS: 'token' */
    $data['user:user:default:featured']->display->content['new-8']->configuration['sanitize'] = 1; /* WAS: '' */
    $data['user:user:default:featured']->display->content['new-8']->position = 0; /* WAS: 1 */
    $data['user:user:default:featured']->display->content['new-8']->subtype = 'user:name'; /* WAS: 'user:field_user_about' */
    $data['user:user:default:featured']->display->content['new-8']->type = 'token'; /* WAS: 'entity_field' */
    $data['user:user:default:featured']->display->content['new-9'] = (object) array(
          'pid' => 'new-9',
          'panel' => 'column2',
          'type' => 'entity_field',
          'subtype' => 'user:field_user_about',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'label' => 'hidden',
            'formatter' => 'text_summary_or_trimmed',
            'delta_limit' => 0,
            'delta_offset' => 0,
            'delta_reversed' => FALSE,
            'formatter_settings' => array(
              'trim_length' => 300,
            ),
            'context' => 'panelizer',
            'override_title' => 1,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'css' => array(),
          'extras' => array(),
          'position' => 1,
          'locks' => array(),
        ); /* WAS: '' */
    $data['user:user:default:featured']->display->panels['column1']['0'] = 'new-7'; /* WAS: 'new-6' */
    $data['user:user:default:featured']->display->panels['column2']['0'] = 'new-8'; /* WAS: 'new-7' */
    $data['user:user:default:featured']->display->panels['column2']['1'] = 'new-9'; /* WAS: 'new-8' */
    unset($data['user:user:default:featured']->display->content['new-6']);
    unset($data['user:user:default:featured']->display->content['new-7']->configuration['sanitize']);
    unset($data['user:user:default:featured']->display->content['new-8']->configuration['delta_limit']);
    unset($data['user:user:default:featured']->display->content['new-8']->configuration['delta_offset']);
    unset($data['user:user:default:featured']->display->content['new-8']->configuration['delta_reversed']);
    unset($data['user:user:default:featured']->display->content['new-8']->configuration['formatter']);
    unset($data['user:user:default:featured']->display->content['new-8']->configuration['formatter_settings']);
    unset($data['user:user:default:featured']->display->content['new-8']->configuration['label']);
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
