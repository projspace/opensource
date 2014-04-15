<?php
/**
 * @file
 * os_user_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_user_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "pm_existing_pages" && $api == "pm_existing_pages") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function os_user_page_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_styles_alter().
 */
function os_user_page_image_styles_alter(&$data) {
  if (isset($data['panopoly_image_featured'])) {

  if ($data['panopoly_image_featured']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['panopoly_image_featured']['effects']['0']['weight'] = -10;
  }

  if ($data['panopoly_image_featured']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['panopoly_image_featured']['effects']['1']['weight'] = -8;
  }

  if ($data['panopoly_image_featured']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['panopoly_image_featured']['effects']['2'] = array(
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
  }
  }
  if (isset($data['profile_pictures'])) {

  if ($data['profile_pictures']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['profile_pictures']['effects']['0']['weight'] = -10;
  }

  if ($data['profile_pictures']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['profile_pictures']['effects']['1']['weight'] = -8;
  }

  if ($data['profile_pictures']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['profile_pictures']['effects']['2'] = array(
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
  }
  }
}

/**
 * Implements hook_default_page_manager_handlers_alter().
 */
function os_user_page_default_page_manager_handlers_alter(&$data) {
  if (isset($data['user_view_panelizer'])) {
    $data['user_view_panelizer']->weight = 0; /* WAS: -100 */
  }
}
