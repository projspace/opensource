<?php
/**
 * Lovely filter handler which restricts posts to those in which the
 * user has group roles. 
 **/
class ogur_handler_filter_og_users_roles_ricg extends views_handler_filter {
  function query() {
	if ($this->view->args[0]) {
	  $uid = $this->view->args[0];
	} else {
	  $uid = '***CURRENT_USER***';
	}

    $table = $this->ensure_my_table();
    $this->query->add_where($this->options['group'], "$table.uid  = $uid");
  }
}