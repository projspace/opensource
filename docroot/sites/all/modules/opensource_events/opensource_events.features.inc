<?php

/**
 * Implementation of hook_content_default_fields().
 */
function opensource_events_content_default_fields() {
  module_load_include('inc', 'opensource_events', 'opensource_events.defaults');
  $args = func_get_args();
  return call_user_func_array('_opensource_events_content_default_fields', $args);
}

/**
 * Implementation of hook_node_info().
 */
function opensource_events_node_info() {
  module_load_include('inc', 'opensource_events', 'opensource_events.features.node');
  $args = func_get_args();
  return call_user_func_array('_opensource_events_node_info', $args);
}

/**
 * Implementation of hook_rules_defaults().
 */
function opensource_events_rules_defaults() {
  module_load_include('inc', 'opensource_events', 'opensource_events.defaults');
  $args = func_get_args();
  return call_user_func_array('_opensource_events_rules_defaults', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function opensource_events_user_default_permissions() {
  module_load_include('inc', 'opensource_events', 'opensource_events.defaults');
  $args = func_get_args();
  return call_user_func_array('_opensource_events_user_default_permissions', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function opensource_events_views_default_views() {
  module_load_include('inc', 'opensource_events', 'opensource_events.features.views');
  $args = func_get_args();
  return call_user_func_array('_opensource_events_views_default_views', $args);
}
