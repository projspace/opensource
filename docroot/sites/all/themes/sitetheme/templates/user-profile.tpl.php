<?php
// $Id: user-profile.tpl.php,v 1.2.2.2 2009/10/06 11:50:06 goba Exp $

/**
 * @file user-profile.tpl.php
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * By default, all user profile data is printed out with the $user_profile
 * variable. If there is a need to break it up you can use $profile instead.
 * It is keyed to the name of each category or other data attached to the
 * account. If it is a category it will contain all the profile items. By
 * default $profile['summary'] is provided which contains data on the user's
 * history. Other data can be included by modules. $profile['user_picture'] is
 * available by default showing the account picture.
 *
 * Also keep in mind that profile items and their categories can be defined by
 * site administrators. They are also available within $profile. For example,
 * if a site is configured with a category of "contact" with
 * fields for of addresses, phone numbers and other related info, then doing a
 * straight print of $profile['contact'] will output everything in the
 * category. This is useful for altering source order and adding custom
 * markup for the group.
 *
 * To check for all available data within $profile, use the code below.
 * @code
 *   print '<pre>'. check_plain(print_r($profile, 1)) .'</pre>';
 * @endcode
 *
 * Available variables:
 *   - $user_profile: All user profile data. Ready for print.
 *   - $profile: Keyed array of profile categories and their items or other data
 *     provided by modules.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 */
?>
<div class="profile">
  <div class="profile-left">
    <div class="inner">
      <?php print $profile['user_picture']; ?>
      <?php print $profile['user_badges']; ?>
    </div>
  </div>
  <div class="profile-right">
    <div class="inner">
      <div class='profile-personal'>
        <h3 class="profile-display-name"><?php print $profile_display_name; ?></h3>
        <div class="profile-points"><?php print $points ?></div>
        <?php if(): ?>
          <div class='profile-location'><?php print $profile_location; ?></div>
        <?php endif; ?>
        <?php if($profile_website): ?>
          <div class='profile-website'><?php print $profile_website; ?></div>
        <?php endif; ?>
        <?php if($profile_bio): ?>
          <div class='profile-bio'><?php print $profile_bio; ?></div>
        <?php endif; ?>
        <?php if($profile_nodisplay): ?>
          <div class='profile-nodisplay'><?php print $profile_nodisplay; ?></div>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>