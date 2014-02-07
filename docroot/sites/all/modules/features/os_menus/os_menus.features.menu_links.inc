<?php
/**
 * @file
 * os_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function os_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-monthly-favorites_best-of-opensourcecom-top-10-open-source-projects-in-2013:http://opensource.com/life/13/12/top-open-source-projects-2013
  $menu_links['menu-monthly-favorites_best-of-opensourcecom-top-10-open-source-projects-in-2013:http://opensource.com/life/13/12/top-open-source-projects-2013'] = array(
    'menu_name' => 'menu-monthly-favorites',
    'link_path' => 'http://opensource.com/life/13/12/top-open-source-projects-2013',
    'router_path' => '',
    'link_title' => 'Best of Opensource.com: Top 10 open source projects in 2013',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-monthly-favorites_best-of-opensourcecom-top-10-open-source-projects-in-2013:http://opensource.com/life/13/12/top-open-source-projects-2013',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
  );
  // Exported menu link: menu-monthly-favorites_how-openstack-differs-from-amazon-and-must-rise-to-the-occasion:http://opensource.com/business/13/12/openstack-amazon-open-cloud
  $menu_links['menu-monthly-favorites_how-openstack-differs-from-amazon-and-must-rise-to-the-occasion:http://opensource.com/business/13/12/openstack-amazon-open-cloud'] = array(
    'menu_name' => 'menu-monthly-favorites',
    'link_path' => 'http://opensource.com/business/13/12/openstack-amazon-open-cloud',
    'router_path' => '',
    'link_title' => 'How OpenStack differs from Amazon and must rise to the occasion',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-monthly-favorites_how-openstack-differs-from-amazon-and-must-rise-to-the-occasion:http://opensource.com/business/13/12/openstack-amazon-open-cloud',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
  );
  // Exported menu link: menu-monthly-favorites_the-first-supercapacitor-powered-portable-speakers-are-open-source:http://opensource.com/life/13/12/interview-blueshift-sam-beck
  $menu_links['menu-monthly-favorites_the-first-supercapacitor-powered-portable-speakers-are-open-source:http://opensource.com/life/13/12/interview-blueshift-sam-beck'] = array(
    'menu_name' => 'menu-monthly-favorites',
    'link_path' => 'http://opensource.com/life/13/12/interview-blueshift-sam-beck',
    'router_path' => '',
    'link_title' => 'The first supercapacitor-powered portable speakers are open source',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-monthly-favorites_the-first-supercapacitor-powered-portable-speakers-are-open-source:http://opensource.com/life/13/12/interview-blueshift-sam-beck',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
  );
  // Exported menu link: menu-monthly-favorites_the-open-source-solution-to-the-bee-colony-collapse-problem:http://opensource.com/life/13/12/open-source-beehive
  $menu_links['menu-monthly-favorites_the-open-source-solution-to-the-bee-colony-collapse-problem:http://opensource.com/life/13/12/open-source-beehive'] = array(
    'menu_name' => 'menu-monthly-favorites',
    'link_path' => 'http://opensource.com/life/13/12/open-source-beehive',
    'router_path' => '',
    'link_title' => 'The open source solution to the bee colony collapse problem',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-monthly-favorites_the-open-source-solution-to-the-bee-colony-collapse-problem:http://opensource.com/life/13/12/open-source-beehive',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-monthly-favorites_why-python-is-perfect-for-startups:http://opensource.com/business/13/12/why-python-perfect-startups
  $menu_links['menu-monthly-favorites_why-python-is-perfect-for-startups:http://opensource.com/business/13/12/why-python-perfect-startups'] = array(
    'menu_name' => 'menu-monthly-favorites',
    'link_path' => 'http://opensource.com/business/13/12/why-python-perfect-startups',
    'router_path' => '',
    'link_title' => 'Why Python is perfect for startups',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-monthly-favorites_why-python-is-perfect-for-startups:http://opensource.com/business/13/12/why-python-perfect-startups',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Best of Opensource.com: Top 10 open source projects in 2013');
  t('How OpenStack differs from Amazon and must rise to the occasion');
  t('The first supercapacitor-powered portable speakers are open source');
  t('The open source solution to the bee colony collapse problem');
  t('Why Python is perfect for startups');


  return $menu_links;
}
