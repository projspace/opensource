<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */


/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
function opensource_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  opensource_preprocess_html($variables, $hook);
  opensource_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
/* -- Delete this line if you want to use this function
function opensource_preprocess_html(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // The body tag's classes are controlled by the $classes_array variable. To
  // remove a class from $classes_array, use array_diff().
  //$variables['classes_array'] = array_diff($variables['classes_array'], array('class-to-remove'));
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
/* -- Delete this line if you want to use this function
function opensource_preprocess_page(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
/* -- Delete this line if you want to use this function
function opensource_preprocess_node(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');

  // Optionally, run node-type-specific preprocess functions, like
  // opensource_preprocess_node_page() or opensource_preprocess_node_story().
  $function = __FUNCTION__ . '_' . $variables['node']->type;
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}
// */

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function opensource_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
function opensource_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  //if (strpos($variables['region'], 'sidebar_') === 0) {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('region__sidebar'));
  //}
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function opensource_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  // $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  //if ($variables['block_html_id'] == 'block-system-main') {
  //  $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  //}
}
// */

/**
 * Override or insert variables into the username.
 */
function opensource_preprocess_username(&$vars) {
  // $vars['account'] is not always the user account.
  $account = user_load($vars['uid']);
  $mail = explode('@', $account->mail);
  if (count($mail) == 2 && strcasecmp($mail[1], 'redhat.com') == 0) {
    $username = isset($account->field_display_name[LANGUAGE_NONE][0]['value']) ? l($account->field_display_name[LANGUAGE_NONE][0]['value'], 'user/' . $account->uid, array('attributes' => array('class' => array('username')))) : l($vars['name'], $vars['link_path']);;
    $vars['name'] = $username . ' <span class="redhat-employee">('. t('Red Hat') .')</span>';
  }
  else {
    $username = isset($account->field_display_name[LANGUAGE_NONE][0]['value']) ? l($account->field_display_name[LANGUAGE_NONE][0]['value'], 'user/' . $account->uid, array('attributes' => array('class' => array('username')))) : l($vars['name'], $vars['link_path']);;
    $vars['name'] = $username;
  }
}

function opensource_preprocess_comment(&$vars) {
  // If no image is present then show the default image.
  $commentauthor = user_load($vars['elements']['#comment']->uid);
  $default_image = variable_get('user_picture_default', '');
  $default_image = str_replace("sites/default/files/", "", $default_image);
  $filepath = empty($commentauthor->field_user_picture[LANGUAGE_NONE][0]['uri']) ? $default_image : $commentauthor->field_user_picture[LANGUAGE_NONE][0]['uri'];
  //$filepath = empty($commentauthor->field_user_picture[LANGUAGE_NONE][0]['uri']) ? variable_get('user_picture_default', '') : $commentauthor->field_user_picture[LANGUAGE_NONE][0]['uri'];
  $image_item = array(
    'style_name' => 'comment_avatar', // style name of imagecache preset.
    'path' => $filepath,
    'alt' => $vars['elements']['#comment']->name, // optional
    'title' => $vars['elements']['#comment']->name, // optional
  );
  $vars['picture'] = theme('image_style', $image_item);

  if (isset($commentauthor->badges) && count($commentauthor->badges)) {
    $badgeimgs = array();
    $display_badge = '';
    foreach ($commentauthor->badges as $badge) {
      //$badgeimgs[] = theme('user_badge', array('badge' => $badge, 'account' => $commentauthor, 'comment_page' => TRUE));
      if($badge->weight > 190) {
        if (isset($vars['badge_role'])) break; //seeing the next role badge. should only display the highest ordered.
        $badgerollimgs[] = '<div class="badge_role">' . theme('user_badge', array('badge' => $badge, 'account' => $commentauthor, 'comment_page' => TRUE)) . '</div>';
      } elseif($badge->weight == -20) {
        $badgeimgs[] = '<div class="badge_green">' . theme('user_badge', array('badge' => $badge, 'account' => $commentauthor, 'comment_page' => TRUE)) . '</div>';
      } elseif($badge->weight == -30) {
        $badgeimgs[] = '<div class="badge_blue">' . theme('user_badge', array('badge' => $badge, 'account' => $commentauthor, 'comment_page' => TRUE)) . '</div>';
      } elseif($badge->weight == -40) {
        $badgeimgs[] = '<div class="badge_blue">' . theme('user_badge', array('badge' => $badge, 'account' => $commentauthor, 'comment_page' => TRUE)) . '</div>';
      }
    }

    $badges['user_badges']['badges'] = array(
      '#type' => 'user_profile_item',
      '#title' => '',
      '#markup' => theme('user_badge_group', array('badgeimages' => $badgeimgs)),
      '#attributes' => array('class' => array('badges')),
    );
    $badgerollimages['user_badges']['badges'] = array(
      '#type' => 'user_profile_item',
      '#title' => '',
      '#markup' => theme('user_badge_group', array('badgeimages' => $badgerollimgs)),
      '#attributes' => array('class' => array('badges')),
    );
  }
  $vars['rollbadges'] = render($badgerollimages);
  $vars['badges'] = render($badges);
  $commenttime = format_date($vars['elements']['#comment']->created, $type = 'medium', $format = '', $timezone = NULL, $langcode = NULL);

  // Display field_display_name instead of username, if field_display_name is
  // written.
  $vars['author'] = isset($commentauthor->field_display_name[LANGUAGE_NONE][0]['value']) ? l($commentauthor->field_display_name[LANGUAGE_NONE][0]['value'], 'user/' . $commentauthor->uid, array('attributes' => array('class' => array('username')))) : $vars['author'];
  $vars['submitted'] = $vars['author'] .t(' on '). $commenttime;

  if (user_access('administer comments')) {
    $vars['mark_as_inappropriate'] = l(t('Report to Mollom'), 'mollom/report/comment/' . $vars['elements']['#comment']->cid, array('query' => array('destination' => current_path())));
  }
  else {
    $vars['mark_as_inappropriate'] = '';
  }
}

/**
 * Preprocess function for Date pager template.
 */
function opensource_preprocess_date_views_pager(&$vars) {
  ctools_add_css('date_views', 'date_views');

  $plugin = $vars['plugin'];
  $input = $vars['input'];
  $view = $plugin->view;

  $vars['nav_title'] = '';
  $vars['next_url'] = '';
  $vars['prev_url'] = '';

  if (empty($view->date_info) || empty($view->date_info->min_date)) {
    return;
  }
  $date_info = $view->date_info;
  // Make sure we have some sort of granularity.
  $granularity = !empty($date_info->granularity) ? $date_info->granularity : 'month';
  $pos = $date_info->date_arg_pos;
  if (!empty($input)) {
    $id = $plugin->options['date_id'];
    if (array_key_exists($id, $input) && !empty($input[$id])) {
      $view->args[$pos] = $input[$id];
    }
  }

  $next_args = $view->args;
  $prev_args = $view->args;
  $min_date = $date_info->min_date;
  $max_date = $date_info->max_date;

  // Set up the pager link format. Setting the block identifier
  // will force pager style links.
  if ((isset($date_info->date_pager_format) && $date_info->date_pager_format != 'clean') || !empty($date_info->mini)) {
    if (empty($date_info->block_identifier)) {
      $date_info->block_identifier = $date_info->pager_id;
    }
  }

  if (empty($date_info->hide_nav)) {
    $prev_date = clone($min_date);
    date_modify($prev_date, '-1 ' . $granularity);
    $next_date = clone($min_date);
    date_modify($next_date, '+1 ' . $granularity);
    $format = array('year' => 'Y', 'month' => 'Y-m', 'day' => 'Y-m-d');
    switch ($granularity) {
      case 'week':
        $next_week = date_week(date_format($next_date, 'Y-m-d'));
        $prev_week = date_week(date_format($prev_date, 'Y-m-d'));
        $next_arg = date_format($next_date, 'Y-\W') . date_pad($next_week);
        $prev_arg = date_format($prev_date, 'Y-\W') . date_pad($prev_week);
        break;
      default:
        $next_arg = date_format($next_date, $format[$granularity]);
        $prev_arg = date_format($prev_date, $format[$granularity]);
    }
    $next_path = str_replace($date_info->date_arg, $next_arg, $date_info->url);
    $prev_path = str_replace($date_info->date_arg, $prev_arg, $date_info->url);
    $next_args[$pos] = $next_arg;
    $prev_args[$pos] = $prev_arg;
    $vars['next_url'] = date_pager_url($view, NULL, $next_arg);
    $vars['prev_url'] = date_pager_url($view, NULL, $prev_arg);
    $vars['next_options'] = $vars['prev_options'] = array();
  }
  else {
    $next_path = '';
    $prev_path = '';
    $vars['next_url'] = '';
    $vars['prev_url'] = '';
    $vars['next_options'] = $vars['prev_options'] = array();
  }

  // Check whether navigation links would point to
  // a date outside the allowed range.
  if (!empty($next_date) && !empty($vars['next_url']) && date_format($next_date, 'Y') > $date_info->limit[1]) {
    $vars['next_url'] = '';
  }
  if (!empty($prev_date) && !empty($vars['prev_url']) && date_format($prev_date, 'Y') < $date_info->limit[0]) {
    $vars['prev_url'] = '';
  }
  $vars['prev_options'] += array('attributes' => array());
  $vars['next_options'] += array('attributes' => array());
  $prev_title = '';
  $next_title = '';

  // Build next/prev link titles.
  switch ($granularity) {
    case 'year':
      $prev_title = t('Navigate to previous year');
      $next_title = t('Navigate to next year');
      break;
    case 'month':
      $prev_title = t('Navigate to previous month');
      $next_title = t('Navigate to next month');
      break;
    case 'week':
      $prev_title = t('Navigate to previous week');
      $next_title = t('Navigate to next week');
      break;
    case 'day':
      $prev_title = t('Navigate to previous day');
      $next_title = t('Navigate to next day');
      break;
  }
  $vars['prev_options']['attributes'] += array('title' => $prev_title);
  $vars['next_options']['attributes'] += array('title' => $next_title);

  // Add nofollow for next/prev links.
  $vars['prev_options']['attributes'] += array('rel' => 'nofollow');
  $vars['next_options']['attributes'] += array('rel' => 'nofollow');

  // Need this so we can use '&laquo;' or images in the links.
  $vars['prev_options'] += array('html' => TRUE);
  $vars['next_options'] += array('html' => TRUE);

  $link = FALSE;
  // Month navigation titles are used as links in the block view.
  if (!empty($date_info->mini) && $granularity == 'month') {
    $link = TRUE;
  }
  $params = array(
    'granularity' => $granularity,
    'view' => $view,
    'link' => $link,
  );
  $nav_title = theme('date_nav_title', $params);
  $vars['nav_title'] = $nav_title;
  $vars['mini'] = !empty($date_info->mini);

  // Get the date information from the view.
  $date_info = $view->date_info;

  // Choose the dislpay format of the month name.
  $format = 'M';

  // Get the previous month.
  $dateString = $date_info->min_date;
  $prev_month = new DateTime($dateString);
  $prev_month->modify('-1 month');
  $prev_pager_title = format_date($prev_month->getTimestamp(), 'custom', $format);
  if($view->name == 'event_calendar_list') {
    $vars['prev_title'] = 'Prev';
  }
  else {
    $vars['prev_title'] = $prev_pager_title . '.';
  }

  // Get the next month.
  $next_month = new DateTime($dateString);
  $next_month->modify('+1 month');
  $next_pager_title = format_date($next_month->getTimestamp(), 'custom', $format);
  if($view->name == 'event_calendar_list') {
    $vars['next_title'] = 'Next';
  }
  else {
    $vars['next_title'] = $next_pager_title . '.';
  }
}

/**
 * Theme the calendar title
 */
function opensource_date_nav_title($params) {
	$granularity = $params['granularity'];
	$view = $params['view'];
	$date_info = $view->date_info;
	$link = !empty($params['link']) ? $params['link'] : FALSE;
	$format = !empty($params['format']) ? $params['format'] : NULL;
	switch ($granularity) {
		case 'year':
			$title = $date_info->year;
			$date_arg = $date_info->year;
			break;
		case 'month':
			if($view->name == 'event_calendar_list') {
				$format = !empty($format) ? $format : (empty($date_info->mini) ? 'F' : 'F');
			}
			else {
				$format = !empty($format) ? $format : (empty($date_info->mini) ? 'F Y' : 'F');
			}
			$title = date_format_date($date_info->min_date, 'custom', $format);
			$date_arg = $date_info->year . '-' . date_pad($date_info->month);
			break;
		case 'day':
			$format = !empty($format) ? $format : (empty($date_info->mini) ? 'l, F j, Y' : 'l, F j');
			$title = date_format_date($date_info->min_date, 'custom', $format);
			$date_arg = $date_info->year . '-' . date_pad($date_info->month) . '-' . date_pad($date_info->day);
			break;
		case 'week':
			$format = !empty($format) ? $format : (empty($date_info->mini) ? 'F j, Y' : 'F j');
			$title = t('Week of @date', array('@date' => date_format_date($date_info->min_date, 'custom', $format)));
			$date_arg = $date_info->year . '-W' . date_pad($date_info->week);
			break;
	}
	if (!empty($date_info->mini) || $link) {
		// Month navigation titles are used as links in the mini view.
		$attributes = array('title' => t('View full page month'));
		$url = date_pager_url($view, $granularity, $date_arg, TRUE);
		return l($title, $url, array('attributes' => $attributes));
	}
	else {
		return $title;
	}
}

function opensource_preprocess_field(&$vars) {
  if($vars['element']['#field_name'] == 'field_default_license') {
    switch ($vars['element']['#object']->field_default_license[LANGUAGE_NONE][0]['value']) {
      case 'CC-BY-SA 4.0':
        $vars['items']['0']['#markup'] = '<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">
        <img alt="Creative Commons License" style="border-width:0" src="'. base_path() . path_to_theme() .'/images/cc-by-sa-4.png" title="This work is licensed under a Creative Commons Attribution-Share Alike 4.0 International License." /></a>';
        break;
      case 'CC-BY-SA 3.0':
        $vars['items']['0']['#markup'] = '<a rel="license" href="http://creativecommons.org/licenses/by-sa/3.0/">
        <img alt="Creative Commons License" style="border-width:0" src="'. base_path() . path_to_theme() .'/images/cc-by-sa-3.png" title="This work is licensed under a Creative Commons Attribution-Share Alike 3.0 Unported License." /></a>';
        break;
      case 'CC-BY 4.0':
        $vars['items']['0']['#markup'] = '<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">
        <img alt="Creative Commons License" style="border-width:0" src="'. base_path() . path_to_theme() .'/images/cc-by-4.png" title="This work is licensed under a Creative Commons Attribution 4.0 International License." /></a>';
        break;
      case 'CC-BY 3.0':
              $vars['items']['0']['#markup'] = '<a rel="license" href="http://creativecommons.org/licenses/by-sa/3.0/">
        <img alt="Creative Commons License" style="border-width:0" src="'. base_path() . path_to_theme() .'/images/cc-by-3.png" title="This work is licensed under a Creative Commons Attribution 3.0 Unported License." /></a>';
        break;

      default:
        $vars['items']['0']['#markup'] = $vars['element']['#object']->field_default_license[LANGUAGE_NONE][0]['value'];
        break;
    }
  }
}

function opensource_fivestar_summary($variables) {
  $microdata = $variables['microdata'];
  extract($variables, EXTR_SKIP);
  $output = '';
  $div_class = '';
  $average_rating_microdata = '';
  if (isset($user_rating)) {
    $div_class = isset($votes) ? 'user-count' : 'user';
    $user_stars = round(($user_rating * $stars) / 100, 1);
    $output .= '<span class="user-rating">'. t('Your rating: <span>!stars</span>', array('!stars' => $user_rating ? $user_stars : t('None'))) .'</span>';
  }
  if (isset($user_rating) && isset($average_rating)) {
    $output .= ' ';
  }
  if (isset($average_rating)) {
    $div_class = isset($votes) ? 'average-count' : 'average';
    $average_stars = round(($average_rating * $stars) / 100, 1);
    if (!empty($microdata['average_rating']['#attributes'])) {
      $average_rating_microdata = drupal_attributes($microdata['average_rating']['#attributes']);
    }
    //$output .= '<span class="average-rating">'. t('Average: <span !microdata>!stars</span>', array('!stars' => $average_stars, '!microdata' => $average_rating_microdata)) .'</span>';
  }
  if (isset($user_rating) && isset($average_rating)) {
    $div_class = 'combo';
  }

  if (isset($votes) && !(isset($user_rating) || isset($average_rating))) {
    $output .= ' <span class="total-votes">'. format_plural($votes, '<span>@count</span> vote', '<span>@count</span> votes') .'</span>';
    $div_class = 'count';
  }
  elseif (isset($votes)) {
    $output .= ' <span class="total-votes">('. format_plural($votes, '<span>@count</span> vote', '<span>@count</span> votes') .')</span>';
  }

  if ($votes === 0) {
    $output = '<span class="empty">'. t('No votes yet') .'</span>';
  }

  $output = '<div class="fivestar-summary fivestar-summary-'. $div_class . '">'. $output .'</div>';
  return $output;
}

function opensource_preprocess_panels_pane(&$vars) {
  $content = &$vars['content'];
  if(isset($content['#field_name']) && ($content['#field_name'] == 'field_file_image_caption')) {
    if((strpos($content['#items'][0]['value'], 'opensource.com') !== false) || (strpos($content['#items'][0]['value'], 'Opensource.com') !== false)) {
      $content['#title'] = t('Image by ');
    }
    else {
      $content['#title'] = t('Image credits ');
    }
  }
}

function opensource_preprocess_search_result(&$vars) {
  $allowed_types = array('article', 'event', 'resource', 'poll');
  $result_fields = $vars['result']['fields'];
  if ($result_fields['entity_type'] == 'node' && in_array($result_fields['bundle'], $allowed_types)) {
    $node = node_load($vars['result']['fields']['entity_id']);
    $vars['date'] = format_date(intval($node->changed), 'custom', 'm/d/Y - H:i', variable_get('date_default_timezone', date_default_timezone_get()));
    $vars['comment_count'] = format_plural($node->comment_count, '1 Comment', '@count Comments', array('@count' => $node->comment_count));

    // Find the attachment count.
    $attachments = field_get_items('node', $node, 'field_attachments');
    if($attachments == FALSE) {
      $vars['attachment_count'] = '0' . t(' attachments');
    }
    else {
      $vars['attachment_count'] = sizeof($attachments) . t(' attachments');
    }


    // Node author
    $vars['author'] = l(user_load($node->uid)->name, 'user/' . $node->uid);

    $vars['node_type'] = $node->type;
  }
}

/**
 * Return html representation of a badge image
 * (note: theme_image does the check_plaining)
 */
function opensource_user_badge($variables) {
  $badge = $variables['badge'];
  if(isset($variables['comment_page']) && $variables['comment_page'] == TRUE) {
    $image = _user_badges_build_image($badge);
    $image = str_replace('.png', '_sm.png', $image);
    $image = preg_replace('/_2[0-9]{3}\.png/', '_sm.png', $image);
  }
  else {
    $image = _user_badges_build_image($badge);
  }

  // We don't link the badge if there is no link and no default,
  // or if the default is overridden.
  if (!isset($badge->href) || ($badge->href == '' && !variable_get('user_badges_defaulthref', ''))
    || drupal_strtolower($badge->href) == '<none>'
  ) {
    return $image;
  }
  else {
    $href = $badge->href ? $badge->href : variable_get('user_badges_defaulthref', '');

    // Implement token replacement.
    if (module_exists('token')) {
      $vars = array('userbadge' => $badge);
      if (isset($variables['account'])) {
        $vars['user'] = $variables['account'];
      }
      $href = token_replace($href, $vars);
    }

    $pieces = parse_url($href);
    $pieces['html'] = TRUE;
    $pieces['path'] = isset($pieces['path']) ? $pieces['path'] : '';
    if (isset($pieces['scheme'])) {
      $pieces['path'] = $pieces['scheme'] . '://' . $pieces['host'] . $pieces['path'];
    }

    // We need to convert the query to an associative array before we pass it
    // to the l() function.
    if (isset($pieces['query'])) {
      $pieces['query'] = drupal_get_query_array($pieces['query']);
    }
    return l($image, $pieces['path'], $pieces);
  }
}

function opensource_preprocess_html(&$variables, $hook) {
  if(arg(0) == 'node' && !arg(1)) {
    $node = node_load(filter_xss(arg(1)));
    if ($node->type == 'article' && !$node->status) {
      $variables['classes_array'][] = 'node_unpublished';
    }
  }
}

function opensource_user_badge_group($variables) {
  $badgeimages = $variables['badgeimages'];
  if (!empty($badgeimages)) {
    $role_badge = array_pop($badgeimages);
    array_unshift($badgeimages,$role_badge);
    return '<div class="user_badges">'. implode('', $badgeimages) .'</div>';
  }
}
