<?php

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _opensource_related_content_imagecache_default_presets() {
  $items = array(
    'related_content_lead_thumbnail' => array(
      'presetname' => 'related_content_lead_thumbnail',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_deprecated_scale',
          'data' => array(
            'fit' => 'inside',
            'width' => '140',
            'height' => '79',
          ),
        ),
      ),
    ),
  );
  return $items;
}

