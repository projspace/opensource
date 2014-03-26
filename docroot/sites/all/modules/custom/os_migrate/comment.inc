<?php
/**
 * @file
 * Migration support for comments.
 */


/**
 * Handling specific to a Drupal 6 source for comments.
 */
class OsMigrateCommentMigration extends DrupalComment6Migration {

  /**
   * Constructor.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('comment_body:format', NULL, FALSE)
      ->defaultValue('plain_text');
    $this->addSimpleMappings(array(
      'notify',
      'notify_hash',
      'notified',
    ));
  }

  /**
   * Perform tasks post-save of comments.
   */
  public function complete(stdClass $comment, stdClass $row) {
    if (!isset($comment->notified) || $comment->notified) {
      comment_notify_mark_comment_as_notified($comment);
    }
  }

  /**
   * Implementation of DrupalCommentMigration::query().
   *
   * We join to {node} so that we can use separate comment migration classes
   * for each associated node type.
   */
  protected function query() {
    $query = parent::query();
    $query->leftJoin('comment_notify', 'cn', 'cn.cid = c.cid');
    $query->fields('cn', array('notify', 'notify_hash', 'notified'));
    return $query;
  }
}
