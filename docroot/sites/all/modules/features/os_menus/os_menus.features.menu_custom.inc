<?php
/**
 * @file
 * os_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function os_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-monthly-favorites.
  $menus['menu-monthly-favorites'] = array(
    'menu_name' => 'menu-monthly-favorites',
    'title' => 'Monthly favorites',
    'description' => 'The top 5 articles from each month',
  );
  // Exported menu: menu-opensource-resources.
  $menus['menu-opensource-resources'] = array(
    'menu_name' => 'menu-opensource-resources',
    'title' => 'OpenSource Resources',
    'description' => 'OpenSource menu for /resource navigation.',
  );
  // Exported menu: menu-opensource-resources-homepa.
  $menus['menu-opensource-resources-homepa'] = array(
    'menu_name' => 'menu-opensource-resources-homepa',
    'title' => 'OpenSource Resources Homepage',
    'description' => 'OpenSource resources for listing on homepage.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Monthly favorites');
  t('OpenSource Resources');
  t('OpenSource Resources Homepage');
  t('OpenSource menu for /resource navigation.');
  t('OpenSource resources for listing on homepage.');
  t('The top 5 articles from each month');


  return $menus;
}
