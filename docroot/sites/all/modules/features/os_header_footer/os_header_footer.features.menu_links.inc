<?php
/**
 * @file
 * os_header_footer.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function os_header_footer_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_open:<front>
  $menu_links['main-menu_open:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Open*',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'menu_icon' => array(
        'enable' => 0,
        'path' => 'sites/all/modules/contrib/menu_icons/images/default_icon.png',
        'image_style' => 'menu_icon',
      ),
      'identifier' => 'main-menu_open:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: user-menu_feed:rss.xml
  $menu_links['user-menu_feed:rss.xml'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'rss.xml',
    'router_path' => 'rss.xml',
    'link_title' => 'Feed',
    'options' => array(
      'attributes' => array(
        'title' => 'Feeds',
      ),
      'identifier' => 'user-menu_feed:rss.xml',
      'menu_icon' => array(
        'enable' => 0,
        'path' => 'sites/all/modules/contrib/menu_icons/images/default_icon.png',
        'image_style' => 'menu_icon',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 50,
    'customized' => 1,
  );
  // Exported menu link: user-menu_log-in:user/login
  $menu_links['user-menu_log-in:user/login'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Log in',
    'options' => array(
      'identifier' => 'user-menu_log-in:user/login',
    ),
    'module' => 'system',
    'hidden' => -1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'user-menu_my-account:user',
  );
  // Exported menu link: user-menu_sign-up:user/register
  $menu_links['user-menu_sign-up:user/register'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Sign Up',
    'options' => array(
      'attributes' => array(
        'title' => 'Sign Up',
      ),
      'identifier' => 'user-menu_sign-up:user/register',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 30,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Feed');
  t('Log in');
  t('Open*');
  t('Sign Up');


  return $menu_links;
}
