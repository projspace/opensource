<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<?php $alpabetic_event_path  =  $view->display['page']->display_options['path'] . '/' ; ?>
<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
    <div class="alpha-pager">
    <?php
      $array = range('a','z');
      $rolodex = filter_xss(arg(2));
      $digits_rolodex = filter_xss(arg(3));
      $alpha_pager = '';
      $current_alpha = ($rolodex != '' ? strtolower(substr($rolodex,0)) : 'a');
      $digits_active_class = ($digits_rolodex == '1') ? ' active' : '';
      foreach($array as $alpha) {
        $active_class = ($current_alpha == $alpha ? ' active' : '');
        $url = $alpabetic_event_path . $alpha;
        $alpha_pager .= '<a href="' . url($url) . '" class="alpha-pager' . $active_class . '">' . strtoupper($alpha) . '</a>  ';
      }
      $alpha_pager .= '<a href="' . url($alpabetic_event_path) . 'all/1" class="alpha-pager' . $digits_active_class . '">0-9</a>  ';
      print $alpha_pager;
      $glossary_title = ($digits_rolodex == '1') ? '0-9' : $current_alpha;
      print "<h2 class='alpha-title'>" . strtoupper($glossary_title) . "</h2>";
    ?>
    </div>
  <?php endif; ?>

  <?php if ($rows): ?>
    <div class="view-content">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <div class="clearfix">
    <div class="previous">
      <?php $previous = ($current_alpha == 'a') ? '/all/1' : (($digits_rolodex == '1') ? 'z' : chr(ord($current_alpha) - 1)); ?>
      <a href="<?php print url($alpabetic_event_path . $previous); ?>">Previous</a>
    </div>
  <div class="monthly">
  <a href="/resources/conferences-and-events-monthly">View monthly listing</a>
  </div>
    <div class="next">
      <?php $next = ($digits_rolodex == '1') ? 'a' : (($current_alpha == 'z') ? '/all/1' : chr(ord($current_alpha) + 1)); ?>
      <a href="<?php print url($alpabetic_event_path . $next); ?>">Next</a>
    </div>
  </div>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print 'hi' . $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>
