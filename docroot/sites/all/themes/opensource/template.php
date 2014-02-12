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

function opensource_preprocess_comment(&$vars) {
  // If no image is present then show the default image.
  $commentauthor = user_load($vars['elements']['#comment']->uid);
  $filepath = empty($commentauthor->field_user_picture[LANGUAGE_NONE][0]['uri']) ? variable_get('user_picture_default', '') : $commentauthor->field_user_picture[LANGUAGE_NONE][0]['uri'];
  $image_item = array(
    'style_name' => 'comment_avatar', // style name of imagecache preset.
    'path' => $filepath,
    'alt' => $vars['elements']['#comment']->name, // optional
    'title' => $vars['elements']['#comment']->name, // optional
  );
  $vars['picture'] = theme('image_style', $image_item);

  $commenttime = format_date($vars['elements']['#comment']->created, $type = 'medium', $format = '', $timezone = NULL, $langcode = NULL);
  $vars['submitted'] = $vars['author'] .t(' on '). $commenttime;
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
    if($vars['element']['#object']->field_default_license[LANGUAGE_NONE][0]['value'] == '1') {
      $vars['items']['0']['#markup'] = '<a rel="license" href="http://creativecommons.org/licenses/by-sa/3.0/">
        <img alt="Creative Commons License" style="border-width:0" src="'. base_path() . path_to_theme() .'/images/cc-by-sa-3.png" title="This work is licensed under a Creative Commons Attribution-Share Alike 3.0 Unported License." /></a>';
    }
  }
}
