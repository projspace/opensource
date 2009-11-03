Module: Omniture Integration
Author: Greg Knaddison http://knaddison.com
Co-Maintainer: Matthew Tucker http://pingv.com
Based on Google Analytics module by Mike Carter <www.ixis.co.uk/contact>


Description
===========
Adds the Omniture statistics system to your website.

Requirements
============

* Omniture user account


Installation
============
* Copy the 'omniture' module directory in to your Drupal
modules directory as usual.

Customization
============
* You can customize the module to your site to create variables
more suited to tracking your needs by utilizing hook_omniture_variables.
For an implementation example, see http://drupal.org/node/182201#comment-1046683 


Usage
=====
You will also need to define what user roles should be tracked.
Simply tick the roles you would like to monitor.

You can also add JavaScript code in the "Advanced" section of the settings.

All pages will now have the required JavaScript added to the
HTML footer can confirm this by viewing the page source from
your browser.

'admin/' pages are automatically ignored by this module.


$Id: README.txt,v 1.4 2008/10/07 03:03:36 ultimateboy Exp $
