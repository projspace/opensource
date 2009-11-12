<?php
// $Id: template.php,v 1.21 2009/08/12 04:25:15 johnalbin Exp $

/**
 * @file
 * Contains theme override functions and preprocess functions for the theme.
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. You can add new regions for block content, modify
 *   or override Drupal's theme functions, intercept or make additional
 *   variables available to your theme, and create custom PHP logic. For more
 *   information, please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/theme-guide
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   The Drupal theme system uses special theme functions to generate HTML
 *   output automatically. Often we wish to customize this HTML output. To do
 *   this, we have to override the theme function. You have to first find the
 *   theme function that generates the output, and then "catch" it and modify it
 *   here. The easiest way to do it is to copy the original function in its
 *   entirety and paste it here, changing the prefix from theme_ to STARTERKIT_.
 *   For example:
 *
 *     original: theme_breadcrumb()
 *     theme override: STARTERKIT_breadcrumb()
 *
 *   where STARTERKIT is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_breadcrumb() function.
 *
 *   If you would like to override any of the theme functions used in Zen core,
 *   you should first look at how Zen core implements those functions:
 *     theme_breadcrumbs()      in zen/template.php
 *     theme_menu_item_link()   in zen/template.php
 *     theme_menu_local_tasks() in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called template suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node-forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and template suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440
 *   and http://drupal.org/node/190815#template-suggestions
 */


/**
 * Implementation of HOOK_theme().
 */
function sitetheme_theme(&$existing, $type, $theme, $path) {
  $hooks = zen_theme($existing, $type, $theme, $path);
  // @TODO: Needs detailed comments. Patches welcome!
  return $hooks;
}

/**
 * Override or insert variables into all templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered (name of the .tpl.php file.)
 */
/* -- Delete this line if you want to use this function
function STARTERKIT_preprocess(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function sitetheme_preprocess_page(&$vars, $hook) {
  if (!empty($vars['navbar'])) {
    $vars['classes_array'][] = 'with-channel-header';
  }
  if (module_exists('og') && $group = og_get_group_context()) {
    $vars['page_feed'] = l('Feed', $group->path .'/feed', array('attributes' => array('class' => 'page-feed')));
  }
  else {
    $vars['page_feed'] = l('Feed', 'feed', array('attributes' => array('class' => 'page-feed')));
  }

  // Remove the file browsing tab.
  if (arg(0) == 'user' && is_numeric(arg(1))) {
    sitetheme_remove_tab('File browser', $vars);
    sitetheme_remove_tab('Your votes', $vars);
  }
}

function sitetheme_preprocess_node(&$vars) {
  if ($vars['node']->type == 'channel') {
    $vars['links'] = '';
  }
  elseif ($vars['node']->type == 'post' && !$vars['page']) {
    $vars['links_all'] = '<div class="article-visitor-links clear-block">';
    if ($vars['node']->comment_count > 0) {
      $vars['links_all'] .= '<span class="article-comment-count">'. l(format_plural($vars['node']->comment_count, '1 Comment', '@count Comments', array('@count' => $vars['node']->comment_count)), 'node/'. $vars['node']->nid, array('fragment' => 'comments')) .'</span>';
    }
    $account = user_load(array('uid' => $vars['node']->uid));
    $vars['links_all'] .= '<span class="article-author-info">'. t('Posted !date by !author', array('!date' => format_date($vars['node']->created, 'custom', 'j M Y'), '!author' => l($account->profile_display_name, 'user/'. $vars['node']->uid))) .'<a href="/user/'. $vars['node']->uid .'/feed" class="article-author-feed"></a></span>';
    $vars['links_all'] .= '<span class="article-node-link">'. l('Read more', 'node/'. $vars['node']->nid) .'</span>';
    $vars['links_all'] .= '</div>';

    static $first_image = TRUE;
    if (!$first_image) {
      $vars['content'] = '<div class="node-teaser-image">'. theme('imagecache', 'image-half-size', sitetheme_get_imceimage_filepath($vars['node']->field_image[0]['imceimage_path']), $vars['node']->field_image[0]['imceimage_alt']) .'</div>'. $vars['content'];
    }
    else {
      $vars['content'] = '<div class="node-main-image">'.theme('imagecache', 'image-full-size', sitetheme_get_imceimage_filepath($vars['node']->field_image[0]['imceimage_path']), $vars['node']->field_image[0]['imceimage_alt']) .'</div>'. $vars['content'];
      $first_image = FALSE;
    }
  }
  elseif ($vars['node']->type == 'post' && $vars['page']) {
    $account = user_load(array('uid' => $vars['node']->uid));
    $vars['submitted'] = t('Posted !date by !author', array('!date' => format_date($vars['node']->created, 'custom', 'j M Y'), '!author' => l($account->profile_display_name, 'user/'. $vars['node']->uid))) .'<a href="/user/'. $vars['node']->uid .'/feed" class="article-author-feed"></a>';

    $vars['content'] = '<div class="node-main-image">'.theme('imagecache', 'image-full-size', sitetheme_get_imceimage_filepath($vars['node']->field_image[0]['imceimage_path']), $vars['node']->field_image[0]['imceimage_alt']) .'</div>'. $vars['content'];
  }
}

function sitetheme_preprocess_views_view_fields__channel_description__block_1(&$vars) {
  $vars['about_url'] = '';
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    // All the about pages are at [channel name]/about.
    $node = node_load(arg(1));
    $vars['about_url'] = '<div class="channel-about-link"><a href="'. $node->path .'/about" title="About '. $node->title .'">About &raquo</a></div>';
  }
}

function sitetheme_preprocess_views_view_field__value(&$vars) {
  if (isset($vars['row']->users_uid)) {
    $vars['output'] .= '<a href="/user/'. $vars['row']->users_uid .'/feed" class="article-author-feed"></a>';
  }
}

function sitetheme_links($links, $attributes = array('class' => 'links')) {
  $output = '';

  if (count($links) > 0) {
    $output = '<ul'. drupal_attributes($attributes) .'>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = $key;

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class .= ' first';
      }
      if ($i == $num_links) {
        $class .= ' last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))) {
        $class .= ' active';
      }

      if (isset($link['href'])) {
        // add active class for containing <li> and <a> if active-trail is set on the link itself
        if (strpos($link['attributes']['class'], 'active-trail') !== FALSE && strpos($class, 'active') === FALSE) {
           $class .= ' active';
           $link['attributes']['class'] .= ' active';
         }
         elseif (strpos($class, 'active-trail') !== FALSE) {
           $link['attributes']['class'] .= ' active-trail';
         }
        // Pass in $link as $options, they share the same keys.
        $link = l($link['title'], $link['href'], $link);
      }
      else if (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $link = '<span'. $span_attributes .'>'. $link['title'] .'</span>';
      }

      $i++;
      $output .= '<li'. drupal_attributes(array('class' => $class)) .'>';
      $output .= $link;
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }
  return $output;
}

function sitetheme_box($title, $content, $region = 'main') {
  if ($region == 'main' && $title == t('Post new comment')) {
    $title = t('Comment now');
  }
  $output = '<h2 class="title">'. $title .'</h2><div>'. $content .'</div>';
  return $output;
}

/**
 * Override or insert variables into the node templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
/* -- Delete this line if you want to use this function
function STARTERKIT_preprocess_node(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');

  // Optionally, run node-type-specific preprocess functions, like
  // STARTERKIT_preprocess_node_page() or STARTERKIT_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $vars['node']->type;
  if (function_exists($function)) {
    $function($vars, $hook);
  }
}
// */

/**
 * Override or insert variables into the comment templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
function sitetheme_preprocess_comment(&$vars, $hook) {
  sitetheme_remove_link('report to Mollom', $vars);
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function STARTERKIT_preprocess_block(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Format the "Submitted by username on date/time" for each node
 *
 * @ingroup themeable
 */
function sitetheme_node_submitted($node) {
  return t('Posted @datetime by !username',
    array(
      '!username' => theme('username', $node),
      '@datetime' => format_date($node->created, 'custom', 'j M Y')
    ));
}
/**
 * Theme a "Submitted by ..." notice.
 *
 * @param $comment
 *   The comment.
 * @ingroup themeable
 */
function sitetheme_comment_submitted($comment) {
  return t('by !username on @datetime.',
    array(
      '!username' => theme('username', $comment),
      '@datetime' => format_date($comment->timestamp, 'custom', 'j M Y')
    ));
}

/**
 * Process variables for comment-wrapper.tpl.php.
 *
 * @see comment-wrapper.tpl.php
 * @see theme_comment_wrapper()
 */
function sitetheme_preprocess_comment_wrapper(&$variables) {

  //print_r($variables['node']);

  // Provide contextual information.
  $variables['display_mode']  = _comment_get_display_setting('mode', $variables['node']);
  $variables['display_order'] = _comment_get_display_setting('sort', $variables['node']);
  $variables['comment_controls_state'] = variable_get('comment_controls_'. $variables['node']->type, COMMENT_CONTROLS_HIDDEN);
  $variables['template_files'][] = 'comment-wrapper-'. $variables['node']->type;

  if ($variables['node']->comment_count > 0) {
      $variables['comment_count'] .= '<span class="comment-count">'. format_plural($variables['node']->comment_count, '1 Comment', '@count Comments', array('@count' => $variables['node']->comment_count)) .'</span>';
  }
}

/**
* Remove a tab
*
* @param  $label
* The label to remove
*
* @param  $vars
* $vars from _phptemplate_variables
*/
function sitetheme_remove_tab($label, &$vars) {
  $tabs = explode("\n", $vars['tabs']);
  $vars['tabs'] = '';

  foreach($tabs as $tab) {
    if(strpos($tab, '>'. $label .'<') === FALSE) {
      $vars['tabs'] .= $tab . "\n";
    }
  }
}

/**
* Remove a link
*
* @param  $label
* The label to remove
*
* @param  $vars
* $vars from a preprocess function.
*/
function sitetheme_remove_link($label, &$vars) {
  $tabs = explode("\n", $vars['links']);
  $vars['links'] = '';

  foreach($tabs as $tab) {
    if(strpos($tab, '>'. $label .'<') === FALSE) {
      $vars['links'] .= $tab . "\n";
    }
  }
}

/**
 * Theme the fivestar form element by adding necessary css and javascript.
 */
function sitetheme_fivestar($element) {
  if (empty($element['#description'])) {
    if ($element['#feedback_enable']) {
      $element['#description'] = '<div class="fivestar-summary fivestar-feedback-enabled">&nbsp;</div>';
    }
    elseif ($element['#labels_enable']) {
      $element['#description'] = '<div class="fivestar-summary">&nbsp;</div>';
    }
  }

  $output = theme('form_element', $element, $element['#children']);
  $output .= t('<div class="fivestar-total">(!num_votes votes)</div>', array('!num_votes' => $element['#vote_count']));

  return $output;
}

/**
 * Helper function to get the local path for an image when the full path is what we have.
 */
function sitetheme_get_imceimage_filepath($path) {
  $path_parts = parse_url($path);

  // $file_directory can be different for public / private download
  $file_directory = variable_get('file_downloads', '') == FILE_DOWNLOADS_PRIVATE ? 'system/files' : file_directory_path();

  $filename = basename($path);
  $subdir =  str_replace("/". $file_directory ."/", '', str_replace( '/'. $filename, '', $path_parts['path']));

  return $subdir .'/'. $filename;
}

/**
 * Overriding the file element to set the default size to 30 wide rather than 60.
 */
function sitetheme_file($element) {
  if ($element['#size'] == 60) {
    $element['#size'] = 30;
  }
  _form_set_class($element, array('form-file'));
  return theme('form_element', $element, '<input type="file" name="'. $element['#name'] .'"'. ($element['#attributes'] ? ' '. drupal_attributes($element['#attributes']) : '') .' id="'. $element['#id'] .'" size="'. $element['#size'] ."\" />\n");
}