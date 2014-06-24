<?php
/**
 * @file
 * os_user.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function os_user_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-user-registration-links_create-new-account:user/register
  $menu_links['menu-user-registration-links_create-new-account:user/register'] = array(
    'menu_name' => 'menu-user-registration-links',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Create New Account',
    'options' => array(
      'attributes' => array(),
      'menu_icon' => array(
        'enable' => 0,
        'path' => 'sites/all/modules/contrib/menu_icons/images/default_icon.png',
        'image_style' => 'menu_icon',
      ),
      'identifier' => 'menu-user-registration-links_create-new-account:user/register',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-user-registration-links_login:user
  $menu_links['menu-user-registration-links_login:user'] = array(
    'menu_name' => 'menu-user-registration-links',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Login',
    'options' => array(
      'attributes' => array(),
      'menu_icon' => array(
        'enable' => 0,
        'path' => 'sites/all/modules/contrib/menu_icons/images/default_icon.png',
        'image_style' => 'menu_icon',
      ),
      'identifier' => 'menu-user-registration-links_login:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-user-registration-links_request-new-password:user/password
  $menu_links['menu-user-registration-links_request-new-password:user/password'] = array(
    'menu_name' => 'menu-user-registration-links',
    'link_path' => 'user/password',
    'router_path' => 'user/password',
    'link_title' => 'Request New Password',
    'options' => array(
      'attributes' => array(),
      'menu_icon' => array(
        'enable' => 0,
        'path' => 'sites/all/modules/contrib/menu_icons/images/default_icon.png',
        'image_style' => 'menu_icon',
      ),
      'identifier' => 'menu-user-registration-links_request-new-password:user/password',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Create New Account');
  t('Login');
  t('Request New Password');


  return $menu_links;
}
