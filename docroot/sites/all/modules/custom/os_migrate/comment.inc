<?php

/**
 * Handling specific to a Drupal 6 source for comments.
 */
class OSCommentMigration extends DrupalComment6Migration {

  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('comment_body:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('notify', 'notify');
    $this->addFieldMapping('notify_hash', 'notify_hash');
    $this->addFieldMapping('notified', 'notified');
  }

  /**
   * Implementation of DrupalCommentMigration::query().
   *
   * We join to {node} so that we can use separate comment migration classes
   * for each associated node type.
   *
   * @return SelectQueryInterface
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('comments', 'c')
             ->fields('c', array('cid', 'pid', 'nid', 'uid', 'subject',
               'comment', 'hostname', 'timestamp', 'status', 'thread', 'name',
               'mail', 'homepage', 'format'));
    $query->join('node', 'n', 'c.nid = n.nid');
    $query->condition('n.type', $this->sourceType);
    $query->leftJoin('comment_notify', 'cn', 'cn.cid = c.cid');
    $query->fields('cn', array('notify','notify_hash', 'notified'));

    return $query;
  }
}
