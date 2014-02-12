<?php
/**
 * @file
 * os_user.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function os_user_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_group
  $overrides["field_group.group_user_profile|user|user|form.data|children|1"] = 'field_display_name';
  $overrides["field_group.group_user_profile|user|user|form.data|children|2"] = 'field_location';
  $overrides["field_group.group_user_profile|user|user|form.data|children|3"] = 'field_website';
  $overrides["field_group.group_user_profile|user|user|form.data|children|4"] = 'field_community_description';

  // Exported overrides for: panelizer_defaults
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|panel"] = 'column1';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|position"] = 1;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|subtype"] = 'user:flag_spotlight';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|type"] = 'entity_field_extra';
  $overrides["panelizer_defaults.user:user:default.display|content|new-3"] = (object) array(
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
    );
  $overrides["panelizer_defaults.user:user:default.display|panels|column1|1"] = 'new-2';
  $overrides["panelizer_defaults.user:user:default.display|panels|column2|0"] = 'new-3';
  $overrides["panelizer_defaults.user:user:default:default.display|content|new-3"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default:default.display|content|new-4|configuration|formatter"] = 'image';
  $overrides["panelizer_defaults.user:user:default:default.display|content|new-4|configuration|formatter_settings|image_link"] = '';
  $overrides["panelizer_defaults.user:user:default:default.display|content|new-4|configuration|formatter_settings|image_style"] = 'panopoly_image_half';
  $overrides["panelizer_defaults.user:user:default:default.display|content|new-4|position"] = 0;
  $overrides["panelizer_defaults.user:user:default:default.display|content|new-4|subtype"] = 'user:field_user_picture';
  $overrides["panelizer_defaults.user:user:default:default.display|content|new-5|configuration"] = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => 0,
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $overrides["panelizer_defaults.user:user:default:default.display|content|new-5|position"] = 1;
  $overrides["panelizer_defaults.user:user:default:default.display|content|new-5|subtype"] = 'user:field_user_about';
  $overrides["panelizer_defaults.user:user:default:default.display|content|new-5|type"] = 'entity_field';
  $overrides["panelizer_defaults.user:user:default:default.display|content|new-6"] = (object) array(
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
    );
  $overrides["panelizer_defaults.user:user:default:default.display|panels|contentmain|0"] = 'new-4';
  $overrides["panelizer_defaults.user:user:default:default.display|panels|contentmain|1"] = 'new-5';
  $overrides["panelizer_defaults.user:user:default:default.display|panels|contentmain|2"] = 'new-6';
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-6"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-7|configuration|delta_limit"] = 0;
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-7|configuration|delta_offset"] = 0;
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-7|configuration|delta_reversed"] = FALSE;
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-7|configuration|formatter"] = 'image';
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-7|configuration|formatter_settings"] = array(
    'image_style' => 'panopoly_image_half',
    'image_link' => 'content',
  );
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-7|configuration|label"] = 'hidden';
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-7|configuration|sanitize"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-7|panel"] = 'column1';
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-7|subtype"] = 'user:field_user_picture';
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-7|type"] = 'entity_field';
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-8|configuration|delta_limit"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-8|configuration|delta_offset"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-8|configuration|delta_reversed"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-8|configuration|formatter"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-8|configuration|formatter_settings"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-8|configuration|label"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-8|configuration|sanitize"] = 1;
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-8|position"] = 0;
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-8|subtype"] = 'user:name';
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-8|type"] = 'token';
  $overrides["panelizer_defaults.user:user:default:featured.display|content|new-9"] = (object) array(
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
    );
  $overrides["panelizer_defaults.user:user:default:featured.display|panels|column1|0"] = 'new-7';
  $overrides["panelizer_defaults.user:user:default:featured.display|panels|column2|0"] = 'new-8';
  $overrides["panelizer_defaults.user:user:default:featured.display|panels|column2|1"] = 'new-9';

 return $overrides;
}
