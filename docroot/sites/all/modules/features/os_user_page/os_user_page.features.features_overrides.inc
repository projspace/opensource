<?php
/**
 * @file
 * os_user_page.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function os_user_page_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: page_manager_handlers
  $overrides["page_manager_handlers.user_view_panelizer.weight"] = 0;

 return $overrides;
}
