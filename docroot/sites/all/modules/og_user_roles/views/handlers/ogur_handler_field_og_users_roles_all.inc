<?php
// $Id: ogur_handler_field_og_users_roles_all.inc,v 1.1.2.1 2009/04/10 17:16:19 somebodysysop Exp $
/**
 * Field handler to provide a list of roles.
 */
class ogur_handler_field_og_users_roles_all extends views_handler_field_prerender_list {
  function construct() {
    parent::construct();
    $this->additional_fields['uid'] = array('table' => 'users', 'field' => 'uid');
    $this->additional_fields['gid'] = array('table' => 'og', 'field' => 'nid');
  }

  function query() {
    $this->add_additional_fields();
    $this->field_alias = $this->aliases['gid'];
  }

  function pre_render($values) {
    global $user;
	// If there are args for the user, use them, else use the current user info.
	if ($this->view->args[0]) {
	  $uid = $this->view->args[0];
	} else {
	  $uid = $user->uid;
	}
    
    $this->items = array();

    foreach ($values as $result) {
      $path = "";
      // Check to see if user has access to configure member roles site-wide
      if (user_access('configure restricted member roles')) $path = 'restricted_roles';
      if (user_access('configure member roles')) $path = 'roles';
      
      $group_id = $result->{$this->aliases['gid']};

      // Check to see if user has access to group-limited configure member roles
      if (og_user_roles_user_access('configure restricted member roles', $group_id, $user->uid)) $path = 'restricted_roles';
      if (og_user_roles_user_access('configure member roles', $group_id, $user->uid)) $path = 'roles';
      
      $result = db_query("SELECT u.uid, u.rid, u.gid, r.name FROM {role} r INNER JOIN {og_users_roles} u ON u.rid = r.rid WHERE u.uid = $uid AND u.gid = {$group_id} ORDER BY r.name");
      while ($role = db_fetch_object($result)) {
        $this->items[$role->gid][$role->rid] = l(t($role->name), "og/users/$group_id/$path", array('query' => drupal_get_destination()));
      }
    }

  }
}
