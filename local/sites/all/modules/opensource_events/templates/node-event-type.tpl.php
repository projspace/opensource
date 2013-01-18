<?php
// $Id: node.tpl.php,v 1.3 2009/08/14 06:31:11 johnalbin Exp $

/**
 * @file
 * Theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: Node body or teaser depending on $teaser flag.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $picture: DEPRECATED. This variable has been renamed $user_picture in Drupal 7.
 * - $date: Formatted creation date (use $created to reformat with
 *   format_date()).
 * - $links: Themed links like "Read more", "Add new comment", etc. output
 *   from theme_links().
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $submitted: themed submission information output from
 *   theme_node_submitted().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $build_mode: Build mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $build_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 */
?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"><div class="node-inner">

  <?php print $user_picture; ?>

  <?php if (!$page): ?>
  <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
<?php endif; ?>
<?php global $user; ?>
<?php if ($node->_workflow != 11 && $user->uid != 0): ?>
  <div class="unpublished"><?php print t('Unpublished'); ?></div>
<?php endif; ?>

<div class="content">
  <div class="event-summary" style="display: block;">

    <div class="views-field-field-event-summary-value">
      <div class="field-content"><?php print $node->field_event_summary['0']['view']; ?></div>
    </div>
    
    <div class="views-field-nothing">
      <label class="views-label-nothing">
        Event Details:
      </label>
      <span class="field-content"></span>
    </div>
    
    <div class="views-field-field-event-start-date-value">
      <label class="views-label-field-event-start-date-value">
        Date:
      </label>
      <span class="field-content"><span class="date-display-single"><?php print $node->field_event_start_date['0']['view']; ?></span></span>
    </div>
    
    <div class="views-field-field-event-location-value">
      <label class="views-label-field-event-location-value">
        Location:
      </label>
      <span class="field-content"><?php print $node->field_event_location['0']['view']; ?></span>
    </div>
    
    <div class="views-field-field-event-website-url">
      <label class="views-label-field-event-website-url">
        Link:
      </label>
      <span class="field-content"><?php print $node->field_event_website['0']['view']; ?> </span>
    </div>
  </div><br />
  <?php print t('Thank you! Your event has been submitted for review. Check out our ') . l(t('event listings'), 'resources/conferences-and-events-monthly') . t(' or ') . l(t('submit another event'), 'node/add/event') . '.'; ?>
  <br />
</div>

<?php print $links; ?>

<?php if ($terms): ?>
 <div class="clearfix"></div>
 <div class="terms terms-inline">Tags: <?php print $terms; ?></div>
<?php endif; ?>

</div></div> <!-- /node-inner, /node -->
