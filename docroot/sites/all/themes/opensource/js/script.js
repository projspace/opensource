(function(window, $) {
	$(document).ready(function() {
$( ".burr-flipped-content-inner .pane-1 p:nth-child(3)" ).addClass( "show-read-more" );
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
      jQuery(item).find('.sf-depth-1').css('padding', '12px ' + (diff/(count * 2)) + 'px');
    });


// //////////Read More
var maxLength = 540;

	$(".show-read-more").each(function(){
		var myStr = $(this).text();
		if($.trim(myStr).length > maxLength){
			var newStr = myStr.substring(0, maxLength);
			var removedStr = myStr.substring(maxLength, $.trim(myStr).length);
			$(this).empty().html(newStr);
			$(this).append(' <a href="javascript:void(0);" class="read-more">Read more  ></a>');
			$(this).append('<span class="more-text">' + removedStr + '</span>');
		}
	});
	$(".read-more").click(function(){
		$(this).siblings(".more-text").contents().unwrap();
		$(this).remove();
	});


  });
})(window, jQuery)
