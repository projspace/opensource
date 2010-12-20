<?php
// $Id: comment.tpl.php,v 1.4.2.1 2008/03/21 21:58:28 goba Exp $

/**
 * @file comment.tpl.php
 * Default theme implementation for comments.
 *
 * Available variables:
 * - $author: Comment author. Can be link or plain text.
 * - $content: Body of the post.
 * - $date: Date and time of posting.
 * - $links: Various operational links.
 * - $new: New comment marker.
 * - $picture: Authors picture.
 * - $signature: Authors signature.
 * - $status: Comment status. Possible values are:
 *   comment-unpublished, comment-published or comment-preview.
 * - $submitted: By line with date and time.
 * - $title: Linked title.
 *
 * These two variables are provided for context.
 * - $comment: Full comment object.
 * - $node: Node object the comments are attached to.
 *
 * @see template_preprocess_comment()
 * @see theme_comment()
 */


global $user;
  if ($user->uid == 1928) {
    
    //print '<pre>'; print_r($comment); print '</pre>';
    //print '<pre>'; print_r($vote_up_down); print '</pre>';
  }


?>
<div class="comment<?php print ($comment->new) ? ' comment-new' : ''; print ' '. $status ?> clear-block">
  <div class="comment-picture-wrapper">
  <?php print $picture ?>
  </div>

  <div class="comment-meta-wrapper">
    <?php if ($comment->new): ?>
      <span class="new"><?php print $new ?></span>
    <?php endif; ?>
  
    <h3><?php print $title ?></h3>
    
  
    <div class="submitted">
      <?php print $submitted ?>
    </div>
  </div>
  <div class="content">
    <?php print $content ?>
    <?php if ($signature): ?>
    <div class="user-signature clear-block">
      <?php print $signature ?>
    </div>
    <?php endif; ?>
  </div>

  <div class="comment-bottom">
  <?php print $vote_up_down; ?>
  <?php print $links ?>
  </div>
  
</div>
