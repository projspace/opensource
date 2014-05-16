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

  // Exported overrides for: image
  $overrides["image.panopoly_image_featured.effects|0|weight"] = -10;
  $overrides["image.panopoly_image_featured.effects|1|weight"] = -8;
  $overrides["image.panopoly_image_featured.effects|2"] = array(
    'data' => array(
      'RGB' => array(
        'HEX' => '#ffffff',
      ),
      'exact' => array(
        'height' => 260,
        'width' => 480,
        'xpos' => 'center',
        'ypos' => 'center',
      ),
      'relative' => array(
        'bottomdiff' => '',
        'leftdiff' => '',
        'rightdiff' => '',
        'topdiff' => '',
      ),
      'under' => 1,
    ),
    'dimensions callback' => 'canvasactions_definecanvas_dimensions',
    'effect callback' => 'canvasactions_definecanvas_effect',
    'form callback' => 'canvasactions_definecanvas_form',
    'help' => 'Define the size of the working canvas and background color, this controls the dimensions of the output image.',
    'label' => 'Define canvas',
    'module' => 'imagecache_canvasactions',
    'name' => 'canvasactions_definecanvas',
    'summary theme' => 'canvasactions_definecanvas_summary',
    'weight' => -9,
  );
  $overrides["image.profile_pictures.effects|0|weight"] = -10;
  $overrides["image.profile_pictures.effects|1|weight"] = -8;
  $overrides["image.profile_pictures.effects|2"] = array(
    'data' => array(
      'RGB' => array(
        'HEX' => '#ffffff',
      ),
      'exact' => array(
        'height' => 100,
        'width' => 100,
        'xpos' => 'center',
        'ypos' => 'center',
      ),
      'relative' => array(
        'bottomdiff' => '',
        'leftdiff' => '',
        'rightdiff' => '',
        'topdiff' => '',
      ),
      'under' => 1,
    ),
    'dimensions callback' => 'canvasactions_definecanvas_dimensions',
    'effect callback' => 'canvasactions_definecanvas_effect',
    'form callback' => 'canvasactions_definecanvas_form',
    'help' => 'Define the size of the working canvas and background color, this controls the dimensions of the output image.',
    'label' => 'Define canvas',
    'module' => 'imagecache_canvasactions',
    'name' => 'canvasactions_definecanvas',
    'summary theme' => 'canvasactions_definecanvas_summary',
    'weight' => -9,
  );

  // Exported overrides for: page_manager_handlers
  $overrides["page_manager_handlers.user_view_panelizer.weight"] = 0;

 return $overrides;
}
