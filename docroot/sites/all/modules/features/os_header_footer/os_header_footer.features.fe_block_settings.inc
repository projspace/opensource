<?php
/**
 * @file
 * os_header_footer.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function os_header_footer_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['bean-copyrigt-block'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'copyrigt-block',
    'module' => 'bean',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'opensource' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'opensource',
        'weight' => -12,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['bean-social-media'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'social-media',
    'module' => 'bean',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'opensource' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'opensource',
        'weight' => 11,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-about-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-about-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'opensource' => array(
        'region' => 'navigation_top',
        'status' => 1,
        'theme' => 'opensource',
        'weight' => -10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-footer'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'opensource' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'opensource',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'opensource' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'opensource',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'opensource' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opensource',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-user-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'user-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'opensource' => array(
        'region' => 'navigation_top',
        'status' => 1,
        'theme' => 'opensource',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
