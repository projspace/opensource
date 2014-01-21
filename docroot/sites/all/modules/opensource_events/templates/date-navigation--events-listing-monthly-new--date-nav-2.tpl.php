<?php
/**
 * @file
 * Template to display date navigation links.
 *
 * $nav_title
 *   The formatted title for this view. In the case of block
 *   views, it will be a link to the full view, otherwise it will
 *   be the formatted name of the year, month, day, or week.
 *
 * $prev_url
 * $next_url
 *   Urls for the previous and next calendar pages. The links are
 *   composed in the template to make it easier to change the text,
 *   add images, etc.
 *
 * $prev_options
 * $next_options
 *   Query strings and other options for the links that need to
 *   be used in the l() function, including rel=nofollow.
 *
 * $block:
 *   Whether or not this view is in a block.
 *
 * $view
 *   The view object for this navigation.
 *
 * The &nbsp; in the prev and next divs is to be sure they are never
 * completely empty, needed in some browsers to prop the header open
 * so the title stays centered.
 *
 */
?>
<?php
$months = array('January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December');
$title_parts = explode(" ", $nav_title);
$current_month = array_search($title_parts[0], $months);
$next_month = ($current_month == 11 ? 0 : $current_month + 1);
$prev_month = ($current_month == 0 ? 11 : $current_month - 1);
?>
<div class="date-nav clear-block">
  <div class="date-prev">
    <?php if (!empty($prev_url)) : ?>
      <span class="next views-summary"> <?php print l(substr($months[$prev_month], 0, 3), $prev_url, $prev_options); ?></span>
    <?php endif; ?>
  &nbsp;</div>
  <div class="date-heading">
    <h3><?php print $nav_title; ?></h3>
  </div>
  <div class="date-next">&nbsp;
    <?php if (!empty($next_url)) : ?>
      <span class="next views-summary"> <?php print l(substr($months[$next_month], 0, 3), $next_url, $next_options); ?></span>
    <?php endif; ?>
  </div>
</div>
