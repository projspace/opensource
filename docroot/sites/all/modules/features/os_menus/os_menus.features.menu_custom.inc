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
  // Translatables
  // Included for use with string extractors like potx.
  t('Monthly favorites');
  t('The top 5 articles from each month');


  return $menus;
}
