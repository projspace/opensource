<?php
/**
 * @file
 * os_user.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function os_user_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-user-registration-links.
  $menus['menu-user-registration-links'] = array(
    'menu_name' => 'menu-user-registration-links',
    'title' => 'User Registration Links',
    'description' => 'This menu has the links to be displayed on the user registration and log in page.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('This menu has the links to be displayed on the user registration and log in page.');
  t('User Registration Links');


  return $menus;
}
