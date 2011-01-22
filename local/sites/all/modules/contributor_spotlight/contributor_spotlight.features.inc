<?php

/**
 * Implementation of hook_content_default_fields().
 */
function contributor_spotlight_content_default_fields() {
  module_load_include('inc', 'contributor_spotlight', 'contributor_spotlight.defaults');
  $args = func_get_args();
  return call_user_func_array('_contributor_spotlight_content_default_fields', $args);
}

/**
 * Implementation of hook_node_info().
 */
function contributor_spotlight_node_info() {
  module_load_include('inc', 'contributor_spotlight', 'contributor_spotlight.features.node');
  $args = func_get_args();
  return call_user_func_array('_contributor_spotlight_node_info', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function contributor_spotlight_views_default_views() {
  module_load_include('inc', 'contributor_spotlight', 'contributor_spotlight.features.views');
  $args = func_get_args();
  return call_user_func_array('_contributor_spotlight_views_default_views', $args);
}
