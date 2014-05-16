<?php
/**
 * @file
 * Migration support for comments.
 */

/**
 * Mapping for comments on various content types.
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

/**
 * Mapping for comments on polls.
 */
class OsMigratePollCommentMigration extends OsMigrateCommentMigration {
  /**
   * Query.
   */
  protected function query() {
    $query = parent::query();
    $query->innerJoin('content_field_poll', 'p', 'p.vid = n.vid');
    $query->isNotNull('p.field_poll_question');
    $query->condition('p.field_poll_question', "' '", '<>');

    return $query;
  }
}
