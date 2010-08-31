$Id: README.txt,v 1.6.2.1 2008/06/27 08:54:45 paulbooker Exp $

DESCRIPTION
-----------
This module allows you to specify that a block should be visible only within 
selected groups. This can be used for many purposes, from providing each
organic group with its own navigation menu, to allowing a group to highlight
its own featured content, etc.

REQUIREMENTS
------------
- Requires the organic groups module.
- Requires 'administer blocks' permissions.

INSTALLATION
------------
- Enable the module from administer >> modules.

USAGE
-----
- Go to administer >> blocks and click "Configure" next to a block.
- Expand the "Group visibility settings" fieldset.
- Check the "Show this block only within the following groups:" checkbox.
- Select one or more groups from the list.
- Save the form.
- To cancel using group-specific visibility on a block, uncheck the box 
  under "Group visibility settings" and save the form.

NOTES
-----
- This module updates a block's PHP visibility settings. It is _not_ 
  compatible with any other type of block view restriction.
- You can combine the PHP code og_block_visibility generates with other
  PHP code, but BE WARNED:  if you subsequently change the checked OG
  visibility settings, any additional PHP code added will be over-written and
  you will have to add it again, so make sure you preserve your additional PHP
  before changing the group visibility settings on any block.
- Blocks will show up publicly for open or moderated groups, and be
  visible to members only for invite-only or closed groups.

CREDITS
-------
Authored and by Angela Byron of CivicSpace Labs
Sponsored by Raven Brooks of BuyBlue.org
Multiple group functionality sponsored by Evan Leeson of Catalyst Creative, Inc.
Maintained by Paul Booker of Glaxstar

