(function(window, $) {
	$(document).ready(function() {

		$('#search-block-form #edit-search-block-form--2')
			.attr('placeholder', 'Search opensource.com');

		var addthis_config = addthis_config || {};
		addthis_config.data_track_clickback = false;

		$menuItems =  $('.sf-main-menu > li');
		$mainMenu = $('.sf-main-menu');

		if ($menuItems.size() == 5) {
			$mainMenu.addClass("sf-menu-5");
		}
		if ($menuItems.size() == 6) {
			$mainMenu.addClass("sf-menu-6");
		}
    var store = 0;
    var whole = 960;
    var list = jQuery('.sf-menu li.sf-depth-1');
    var count = jQuery('.sf-menu li.sf-depth-1').length;

    jQuery.each(list, function(index, item) {
      store += jQuery(item).width();
    });

    var diff = 960 - (store + (6 * (count -1)));

    jQuery.each(list, function(index, item) {
      jQuery(item).find('.menuparent').css('padding', '12px ' + (diff/(count * 2)) + 'px');
    });

  });
})(window, jQuery)
