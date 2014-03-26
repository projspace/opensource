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
  $overrides["field_group.group_user_profile|user|user|form.data|children|5"] = 'field_profile_point_notification';
  $overrides["field_group.group_user_profile|user|user|form.data|format_settings|formatter"] = 'open';
  $overrides["field_group.group_user_profile|user|user|form.data|format_settings|label"] = 'User Profile';

  // Exported overrides for: field_instance
  $overrides["field_instance.user-user-field_user_picture.settings|min_resolution"] = '';

  // Exported overrides for: page_manager_handlers
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|display|content|new-1|configuration|0"]["DELETED"] = TRUE;
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|display|content|new-1|configuration|task_id"]["DELETED"] = TRUE;
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|display|content|new-1|subtype"] = 'menu-menu-user-registration-links';
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|display|content|new-1|type"] = 'block';
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|display|content|new-2"] = (object) array(
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
    );
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|display|content|new-3"] = (object) array(
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
    );
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|display|panels|contentmain|1"] = 'new-2';
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|display|panels|sidebar"] = array(
    0 => 'new-3',
  );
  $overrides["page_manager_handlers.pm_existing_pages_user_password_panel_context.conf|display|content|new-2"]["DELETED"] = TRUE;
  $overrides["page_manager_handlers.pm_existing_pages_user_password_panel_context.conf|display|content|new-4"] = (object) array(
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
      'css' => array(),
      'extras' => array(),
      'position' => 0,
      'locks' => array(),
    );
  $overrides["page_manager_handlers.pm_existing_pages_user_password_panel_context.conf|display|content|new-5"] = (object) array(
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
      'css' => array(),
      'extras' => array(),
      'position' => 1,
      'locks' => array(),
    );
  $overrides["page_manager_handlers.pm_existing_pages_user_password_panel_context.conf|display|content|new-6"] = (object) array(
      'pid' => 'new-6',
      'panel' => 'sidebar',
      'type' => 'panels_mini',
      'subtype' => 'common_1',
      'shown' => TRUE,
      'access' => array(),
      'cache' => array(),
      'css' => array(),
      'extras' => array(),
      'position' => 0,
      'locks' => array(),
    );
  $overrides["page_manager_handlers.pm_existing_pages_user_password_panel_context.conf|display|panels|contentmain|0"] = 'new-4';
  $overrides["page_manager_handlers.pm_existing_pages_user_password_panel_context.conf|display|panels|contentmain|1"] = 'new-5';
  $overrides["page_manager_handlers.pm_existing_pages_user_password_panel_context.conf|display|panels|sidebar"] = array(
    0 => 'new-6',
  );
  $overrides["page_manager_handlers.pm_existing_pages_user_password_panel_context.conf|display|title"] = 'User account';
  $overrides["page_manager_handlers.pm_existing_pages_user_register_panel_context.conf|display|content|new-3"]["DELETED"] = TRUE;
  $overrides["page_manager_handlers.pm_existing_pages_user_register_panel_context.conf|display|content|new-7"] = (object) array(
      'pid' => 'new-7',
      'panel' => 'contentmain',
      'type' => 'block',
      'subtype' => 'menu-menu-user-registration-links',
      'shown' => TRUE,
      'access' => array(),
      'cache' => array(),
      'css' => array(),
      'extras' => array(),
      'position' => 0,
      'locks' => array(),
    );
  $overrides["page_manager_handlers.pm_existing_pages_user_register_panel_context.conf|display|content|new-8"] = (object) array(
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
    );
  $overrides["page_manager_handlers.pm_existing_pages_user_register_panel_context.conf|display|content|new-9"] = (object) array(
      'pid' => 'new-9',
      'panel' => 'sidebar',
      'type' => 'panels_mini',
      'subtype' => 'common_1',
      'shown' => TRUE,
      'access' => array(),
      'cache' => array(),
      'css' => array(),
      'extras' => array(),
      'position' => 0,
      'locks' => array(),
    );
  $overrides["page_manager_handlers.pm_existing_pages_user_register_panel_context.conf|display|panels|contentmain|0"] = 'new-7';
  $overrides["page_manager_handlers.pm_existing_pages_user_register_panel_context.conf|display|panels|contentmain|1"] = 'new-8';
  $overrides["page_manager_handlers.pm_existing_pages_user_register_panel_context.conf|display|panels|sidebar"] = array(
    0 => 'new-9',
  );
  $overrides["page_manager_handlers.pm_existing_pages_user_register_panel_context.conf|display|title"] = 'User account';

 return $overrides;
}
