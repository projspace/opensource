(function($){
  Drupal.behaviors.legalOpenID = function(context) {
    $openidLegal = $(".openid-legal-checkbox", context);
    $openidLegal.hide();
    $("li.openid-link:not(.openid-legal-processed)", context)
    .addClass('openid-legal-processed')
    .click( function() {
      $(".openid-legal-checkbox", context).show();
      return false;
    });
    $("li.user-link:not(.openid-legal-processed)", context)
    .addClass('openid-legal-processed')
    .click(function() {
      $(".openid-legal-checkbox", context).hide();
      return false;
    });
  }
})(jQuery)