<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function related_content_block_imagecache_default_presets() {
  module_load_include('inc', 'related_content_block', 'related_content_block.defaults');
  $args = func_get_args();
  return call_user_func_array('_related_content_block_imagecache_default_presets', $args);
}
