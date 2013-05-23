<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function opensource_related_content_imagecache_default_presets() {
  module_load_include('inc', 'opensource_related_content', 'opensource_related_content.defaults');
  $args = func_get_args();
  return call_user_func_array('_opensource_related_content_imagecache_default_presets', $args);
}

