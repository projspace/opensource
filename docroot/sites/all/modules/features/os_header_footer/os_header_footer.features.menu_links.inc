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

  // Exported menu link: main-menu_business:<front>
  $menu_links['main-menu_business:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Business',
    'options' => array(
      'attributes' => array(
        'title' => 'Business',
      ),
      'identifier' => 'main-menu_business:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: main-menu_education:<front>
  $menu_links['main-menu_education:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Education',
    'options' => array(
      'attributes' => array(
        'title' => 'Education',
      ),
      'identifier' => 'main-menu_education:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
  );
  // Exported menu link: main-menu_government:<front>
  $menu_links['main-menu_government:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Government',
    'options' => array(
      'attributes' => array(
        'title' => 'Government',
      ),
      'identifier' => 'main-menu_government:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -47,
  );
  // Exported menu link: main-menu_health:<front>
  $menu_links['main-menu_health:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Health',
    'options' => array(
      'attributes' => array(
        'title' => 'Health',
      ),
      'identifier' => 'main-menu_health:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -46,
  );
  // Exported menu link: main-menu_law:<front>
  $menu_links['main-menu_law:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Law',
    'options' => array(
      'attributes' => array(
        'title' => 'Law',
      ),
      'identifier' => 'main-menu_law:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: main-menu_life:<front>
  $menu_links['main-menu_life:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Life',
    'options' => array(
      'attributes' => array(
        'title' => 'Life',
      ),
      'identifier' => 'main-menu_life:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: main-menu_open:<front>
  $menu_links['main-menu_open:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Open*',
    'options' => array(
      'attributes' => array(
        'title' => 'Open*',
      ),
      'identifier' => 'main-menu_open:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-about-menu_about:<front>
  $menu_links['menu-about-menu_about:<front>'] = array(
    'menu_name' => 'menu-about-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'title' => 'About',
      ),
      'identifier' => 'menu-about-menu_about:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-about-menu_community:<front>
  $menu_links['menu-about-menu_community:<front>'] = array(
    'menu_name' => 'menu-about-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Community',
    'options' => array(
      'attributes' => array(
        'title' => 'Community',
      ),
      'identifier' => 'menu-about-menu_community:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
  );
  // Exported menu link: menu-about-menu_participate:<front>
  $menu_links['menu-about-menu_participate:<front>'] = array(
    'menu_name' => 'menu-about-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Participate',
    'options' => array(
      'attributes' => array(
        'title' => 'Participate',
      ),
      'identifier' => 'menu-about-menu_participate:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
  );
  // Exported menu link: menu-about-menu_resources:<front>
  $menu_links['menu-about-menu_resources:<front>'] = array(
    'menu_name' => 'menu-about-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Resources',
    'options' => array(
      'attributes' => array(
        'title' => 'Resources',
      ),
      'identifier' => 'menu-about-menu_resources:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: menu-about-menu_submit-your-story:<front>
  $menu_links['menu-about-menu_submit-your-story:<front>'] = array(
    'menu_name' => 'menu-about-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Submit your story',
    'options' => array(
      'attributes' => array(
        'title' => 'Submit your story',
      ),
      'identifier' => 'menu-about-menu_submit-your-story:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
  );
  // Exported menu link: menu-about-menu_the-open-source-way:<front>
  $menu_links['menu-about-menu_the-open-source-way:<front>'] = array(
    'menu_name' => 'menu-about-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'The open source way',
    'options' => array(
      'attributes' => array(
        'title' => 'The open source way',
      ),
      'identifier' => 'menu-about-menu_the-open-source-way:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
  );
  // Exported menu link: menu-about-menu_visit-opensourceorg:<front>
  $menu_links['menu-about-menu_visit-opensourceorg:<front>'] = array(
    'menu_name' => 'menu-about-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Visit opensource.org',
    'options' => array(
      'attributes' => array(
        'title' => 'Visit opensource.org',
      ),
      'identifier' => 'menu-about-menu_visit-opensourceorg:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
  );
  // Exported menu link: menu-footer_colophon:<front>
  $menu_links['menu-footer_colophon:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Colophon',
    'options' => array(
      'attributes' => array(
        'title' => 'Colophon',
      ),
      'identifier' => 'menu-footer_colophon:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
  );
  // Exported menu link: menu-footer_media-kit:<front>
  $menu_links['menu-footer_media-kit:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Media Kit',
    'options' => array(
      'attributes' => array(
        'title' => 'Media Kit',
      ),
      'identifier' => 'menu-footer_media-kit:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
  );
  // Exported menu link: menu-footer_meet-the-moderators:<front>
  $menu_links['menu-footer_meet-the-moderators:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Meet the Moderators',
    'options' => array(
      'attributes' => array(
        'title' => 'Meet the Moderators',
      ),
      'identifier' => 'menu-footer_meet-the-moderators:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
  );
  // Exported menu link: menu-footer_privacy-policy:<front>
  $menu_links['menu-footer_privacy-policy:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Privacy Policy',
    'options' => array(
      'attributes' => array(
        'title' => 'Privacy Policy',
      ),
      'identifier' => 'menu-footer_privacy-policy:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-footer_terms-of-use:<front>
  $menu_links['menu-footer_terms-of-use:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Terms of Use',
    'options' => array(
      'attributes' => array(
        'title' => 'Terms of Use',
      ),
      'identifier' => 'menu-footer_terms-of-use:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: user-menu_feed:<front>
  $menu_links['user-menu_feed:<front>'] = array(
    'menu_name' => 'user-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Feed',
    'options' => array(
      'attributes' => array(
        'title' => 'Feeds',
      ),
      'identifier' => 'user-menu_feed:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 50,
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
    'weight' => 11,
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
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Business');
  t('Colophon');
  t('Community');
  t('Education');
  t('Feed');
  t('Government');
  t('Health');
  t('Law');
  t('Life');
  t('Log in');
  t('Media Kit');
  t('Meet the Moderators');
  t('Open*');
  t('Participate');
  t('Privacy Policy');
  t('Resources');
  t('Sign Up');
  t('Submit your story');
  t('Terms of Use');
  t('The open source way');
  t('Visit opensource.org');


  return $menu_links;
}
