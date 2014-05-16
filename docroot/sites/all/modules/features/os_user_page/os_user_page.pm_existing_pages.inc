<?php
/**
 * @file
 * os_user_page.pm_existing_pages.inc
 */

/**
 * Implements hook_pm_existing_pages_info().
 */
function os_user_page_pm_existing_pages_info() {
  $export = array();

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'user_content_pages';
  $pm_existing_page->label = 'User Content Pages';
  $pm_existing_page->context = '';
  $pm_existing_page->paths = 'user_articles/%views_arg
user_comments/%views_arg';
  $export['user_content_pages'] = $pm_existing_page;

  return $export;
}
