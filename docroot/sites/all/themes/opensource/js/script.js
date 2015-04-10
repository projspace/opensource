(function(window, $) {
	$(document).ready(function() {
		$('#search-block-form #edit-search-block-form--2')
			.attr('placeholder', 'Search opensource.com');

		var addthis_config = addthis_config||{};
		addthis_config.data_track_clickback = false;
		$menuItems =  $('.sf-main-menu > li');
		$mainMenu = $('.sf-main-menu');

		if ($menuItems.size() == 5) {
			$mainMenu.addClass("sf-menu-5");
		}
	});
})(window, jQuery)