<?php

/**
 * Implementation of hook_content_default_fields().
 */
function feedtweaks_content_default_fields() {
  module_load_include('inc', 'feedtweaks', 'feedtweaks.defaults');
  $args = func_get_args();
  return call_user_func_array('_feedtweaks_content_default_fields', $args);
}

/**
 * Implementation of hook_node_info().
 */
function feedtweaks_node_info() {
  module_load_include('inc', 'feedtweaks', 'feedtweaks.features.node');
  $args = func_get_args();
  return call_user_func_array('_feedtweaks_node_info', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function feedtweaks_views_default_views() {
  module_load_include('inc', 'feedtweaks', 'feedtweaks.features.views');
  $args = func_get_args();
  return call_user_func_array('_feedtweaks_views_default_views', $args);
}
