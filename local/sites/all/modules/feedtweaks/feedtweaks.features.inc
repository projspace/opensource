<?php

/**
 * Implementation of hook_views_default_views().
 */
function feedtweaks_views_default_views() {
  module_load_include('inc', 'feedtweaks', 'feedtweaks.features.views');
  $args = func_get_args();
  return call_user_func_array('_feedtweaks_views_default_views', $args);
}
