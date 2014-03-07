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

 return $overrides;
}
