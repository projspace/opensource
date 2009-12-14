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

  $hooks['user_profile_form'] = array(
    'arguments' => array('form' => NULL),
  );
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
    $vars['links_all'] = '<div class="clearfix"></div><div class="article-visitor-links clear-block">';
    if ($vars['node']->comment_count > 0) {
      $vars['links_all'] .= '<span class="article-comment-count">'. l(format_plural($vars['node']->comment_count, '1 Comment', '@count Comments', array('@count' => $vars['node']->comment_count)), 'node/'. $vars['node']->nid, array('fragment' => 'comments')) .'</span>';
    }
    else {
      $vars['links_all'] .= '<span class="article-comment-count">'. l('0 Comments', 'node/'. $vars['node']->nid, array('fragment' => 'comments')) .'</span>';
    }
    $account = user_load(array('uid' => $vars['node']->uid));
    $vars['links_all'] .= '<span class="article-author-info">'. t('Posted !date by !author', array('!date' => format_date($vars['node']->created, 'custom', 'j M Y'), '!author' => l($account->profile_display_name, 'user/'. $vars['node']->uid))) .'<a href="/user/'. $vars['node']->uid .'/feed" class="article-author-feed"></a></span>';
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

  $vars['add_this'] = '';
  if ($vars['page'] && user_access('view addthis')) {
    $vars['add_this'] = _addthis_create_button($vars['node'], !$vars['page']);
  }
  
  if ($vars['node']->type == 'post' && $vars['page']) {
    //
  }
}

function sitetheme_preprocess_views_view_fields__channel_description__block_1(&$vars) {
  $vars['about_url'] = '';
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    // All the about pages are at [channel name]/about.
    $node = node_load(arg(1));
    $vars['about_url'] = '<div class="channel-about-link"><a href="'. $node->path .'/about" title="About '. $node->title .'">&raquo About</a></div>';
  }
}

function sitetheme_preprocess_views_view_field__value(&$vars) {
  if (isset($vars['row']->users_uid)) {
    $vars['output'] .= '<a href="/user/'. $vars['row']->users_uid .'/feed" class="article-author-feed"></a>';
  }
}

function sitetheme_preprocess_view_view_field__featured_comment__value(&$vars) {

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
  // Drupal does not cache loaded users. To make for less loading we only load profiles
  // and we statically cache them here.
  static $account_profiles = array();

  // Remove the mollom link for comments on the comment gardner role. This is displayed even
  // though they don't have permission. A side effect of using og_user_roles.
  global $user;
  // Role 31 is the comment gardner.
  if (isset($user->roles[31])) {
    sitetheme_remove_link('report to Mollom', $vars);

    // The sitetheme_remove_link function is stripping out the ul tag in this case.
    // Adding it back.
    $vars['links'] = '<ul class="links">'. $vars['links'];
  }

  if ($vars['comment']->uid == 0) {
    $username = theme('username', $vars['comment']);
  }
  else {
    if (!isset($account_profiles[$vars['comment']->uid])) {
      $account = new stdClass();
      $account->uid = $vars['comment']->uid;
      profile_load_profile($account);
      $account_profiles[$account->uid] = $account;
    }
    $username = l($account_profiles[$vars['comment']->uid]->profile_display_name, 'user/'. $vars['comment']->uid);
  }

  $vars['submitted'] = t('by !author on !date', array('!author' => $username, '!date' => format_date($vars['comment']->timestamp, 'custom', 'j M Y')));
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

function sitetheme_preprocess_views_view_field__homepage__page_1__teaser(&$vars) {
  if (module_exists('ed_readmore')) {
    $display = variable_get('ed_readmore_placement', ED_READMORE_PLACEMENT_DEFAULT);
    $node = node_load($vars['view']->result[0]->nid);
    if (preg_match('!</?(?:p)[^>]*>$!i', $vars['output'], $match, PREG_OFFSET_CAPTURE)) {
      // Recalculate the position in $teaser. We do this because there may be extra CCK fields appended to the teaser.
      // Insert the link
      $vars['output'] = substr_replace($vars['output'], ed_readmore_link_render($node, $display), $match[0][1], 0);
    }
    else {
      $display = 'after';
      $vars['output'] .= ed_readmore_link_render($node, $display); // Not found, so just append it
    }
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

function sitetheme_user_profile_form($form) {
  // Removing the link to the personal contact form. If you are on your own contact form this takes you to a page
  // you do not have access to.
  if (isset($form['contact']['contact']['#description'])) {
    $form['contact']['contact']['#description'] = t('Allow other users to contact you by e-mail via your personal contact form. Note that while your e-mail address is not made public to other members of the community, privileged users such as site administrators are able to contact you even if you choose not to enable this feature.');
  }

  return drupal_render($form);
}

function sitetheme_textfield($element) {

  // If the size is 60 reduce it to 50. 60 is the standard size and 58 is the
  // size of OpenID.
  if (isset($element['#size']) && ($element['#size'] == 60 || $element['#size'] == 58)) {
    $element['#size'] = 50;
  }

  $size = empty($element['#size']) ? '' : ' size="'. $element['#size'] .'"';
  $maxlength = empty($element['#maxlength']) ? '' : ' maxlength="'. $element['#maxlength'] .'"';
  $class = array('form-text');
  $extra = '';
  $output = '';

  if ($element['#autocomplete_path'] && menu_valid_path(array('link_path' => $element['#autocomplete_path']))) {
    drupal_add_js('misc/autocomplete.js');
    $class[] = 'form-autocomplete';
    $extra =  '<input class="autocomplete" type="hidden" id="'. $element['#id'] .'-autocomplete" value="'. check_url(url($element['#autocomplete_path'], array('absolute' => TRUE))) .'" disabled="disabled" />';
  }
  _form_set_class($element, $class);

  if (isset($element['#field_prefix'])) {
    $output .= '<span class="field-prefix">'. $element['#field_prefix'] .'</span> ';
  }

  $output .= '<input type="text"'. $maxlength .' name="'. $element['#name'] .'" id="'. $element['#id'] .'"'. $size .' value="'. check_plain($element['#value']) .'"'. drupal_attributes($element['#attributes']) .' />';

  if (isset($element['#field_suffix'])) {
    $output .= ' <span class="field-suffix">'. $element['#field_suffix'] .'</span>';
  }

  return theme('form_element', $element, $output) . $extra;
}

function sitetheme_password($element) {
  // If the size is 60 reduce it to 50.
  if (isset($element['#size']) && $element['#size'] == 60) {
    $element['#size'] = 50;
  }

  $size = $element['#size'] ? ' size="'. $element['#size'] .'" ' : '';
  $maxlength = $element['#maxlength'] ? ' maxlength="'. $element['#maxlength'] .'" ' : '';

  _form_set_class($element, array('form-text'));
  $output = '<input type="password" name="'. $element['#name'] .'" id="'. $element['#id'] .'" '. $maxlength . $size . drupal_attributes($element['#attributes']) .' />';
  return theme('form_element', $element, $output);
}

function sitetheme_textarea($element) {
  // If the cols is 60 reduce it to 50.
  if (isset($element['#cols']) && $element['#cols'] == 60) {
    $element['#cols'] = 50;
  }

  $class = array('form-textarea');

  // Add teaser behavior (must come before resizable)
  if (!empty($element['#teaser'])) {
    drupal_add_js('misc/teaser.js');
    // Note: arrays are merged in drupal_get_js().
    drupal_add_js(array('teaserCheckbox' => array($element['#id'] => $element['#teaser_checkbox'])), 'setting');
    drupal_add_js(array('teaser' => array($element['#id'] => $element['#teaser'])), 'setting');
    $class[] = 'teaser';
  }

  // Add resizable behavior
  if ($element['#resizable'] !== FALSE) {
    drupal_add_js('misc/textarea.js');
    $class[] = 'resizable';
  }

  _form_set_class($element, $class);
  return theme('form_element', $element, '<textarea cols="'. $element['#cols'] .'" rows="'. $element['#rows'] .'" name="'. $element['#name'] .'" id="'. $element['#id'] .'" '. drupal_attributes($element['#attributes']) .'>'. check_plain($element['#value']) .'</textarea>');
}

/**
 * Removing the (not verified) attached to anonymous users.
 */
function sitetheme_username($object) {

  if ($object->uid && $object->name) {
    // Shorten the name when it is too long or it will break many tables.
    if (drupal_strlen($object->name) > 20) {
      $name = drupal_substr($object->name, 0, 15) .'...';
    }
    else {
      $name = $object->name;
    }

    if (user_access('access user profiles')) {
      $output = l($name, 'user/'. $object->uid, array('attributes' => array('title' => t('View user profile.'))));
    }
    else {
      $output = check_plain($name);
    }
  }
  else if ($object->name) {
    // Sometimes modules display content composed by people who are
    // not registered members of the site (e.g. mailing list or news
    // aggregator modules). This clause enables modules to display
    // the true author of the content.
    if (!empty($object->homepage)) {
      $output = l($object->name, $object->homepage, array('attributes' => array('rel' => 'nofollow')));
    }
    else {
      $output = check_plain($object->name);
    }

    //$output .= ' ('. t('not verified') .')';
  }
  else {
    $output = check_plain(variable_get('anonymous', t('Anonymous')));
  }

  return $output;
}