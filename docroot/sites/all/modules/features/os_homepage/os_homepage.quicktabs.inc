<?php
/**
 * @file
 * os_homepage.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function os_homepage_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'homepage_tabs';
  $quicktabs->ajax = 1;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Homepage Tabs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'homepage',
      'display' => 'panel_pane_recent',
      'args' => '',
      'title' => 'Featured',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'homepage',
      'display' => 'panel_pane_comments',
      'args' => '',
      'title' => 'Most Comments',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Featured');
  t('Homepage Tabs');
  t('Most Comments');

  $export['homepage_tabs'] = $quicktabs;

  return $export;
}
