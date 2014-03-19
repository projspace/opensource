<?php
/**
 * @file
 * os_common_components.pm_existing_pages.inc
 */

/**
 * Implements hook_pm_existing_pages_info().
 */
function os_common_components_pm_existing_pages_info() {
  $export = array();

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'community_spotlight';
  $pm_existing_page->label = 'Community Spotlight';
  $pm_existing_page->context = '';
  $pm_existing_page->paths = 'should-be/spotlight';
  $export['community_spotlight'] = $pm_existing_page;

  return $export;
}
