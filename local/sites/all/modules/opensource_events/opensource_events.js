Drupal.behaviors.opensource_events = function (context) {
    
  var allPanels = $('.event-listing .event-summary').hide();
    
  $('#content-area .views-field-title').click(function() {
    allPanels.slideUp();
    title_object = $(this).next();
    if(title_object.is(":hidden")) $(title_object).slideDown();
    return false;
  });

  $('.month-map-event').click(function() {
    allPanels.slideUp();
    var event_id = "event-" + $(this).attr("id");
    title_object = $("#"+event_id).parent().parent().next();
    if(title_object.is(":hidden")) $(title_object).slideDown();
  });

  if($.ui) {
    $('#edit-field-event-start-date-0-value-datepicker-popup-0, #edit-field-event-start-date-0-value2-datepicker-popup-0').datepicker({   //Enter your field id
      showOn: "button",
      buttonImage: "/sites/all/modules/opensource_events/img/mini-cal.png",
      buttonImageOnly: true,
      buttonText: "Choose"
    });
  }
};
