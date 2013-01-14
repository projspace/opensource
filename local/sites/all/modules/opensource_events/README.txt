INSTALLATION
============

Before enabling module
----------------------
1. Copy opensource_events/calendar-month-node.tpl.php to sites/all/themes/sitetheme/templates/

After enabling module
---------------------

1. Goto http://opensource.com/admin/content/node-type/event
   a. In "Node form settings", change "Submit button title" to "Submit"
   b. In "Comment settings", select "Disabled" for "Default comment seting"
   c. In "Workflow settings", uncheck "Published" & "Promoted to front page" under "Default options"
2. Goto admin/content/node-type/event/fields and drag "Event title" below "Your Email address"
3. Goto admin/build/workflow/list and under "Workflow" column for "Event", Choose "Article workflow" 
