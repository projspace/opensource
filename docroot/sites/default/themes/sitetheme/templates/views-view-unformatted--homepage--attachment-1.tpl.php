<?php
// $Id: views-view-unformatted.tpl.php,v 1.6 2008/10/01 20:52:11 merlinofchaos Exp $
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="content-inner-side-shadow"><div class="content-inner-right-shadow"><div class="content-inner-bottom-shadow"><div class="content-inner-border">
<?php //if (!empty($title)): ?>
  <h3>More featured content<?php print $title; ?></h3>
<?php //endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="<?php print $classes[$id]; ?>">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
</div></div></div></div>