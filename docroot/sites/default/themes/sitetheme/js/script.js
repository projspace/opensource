(function($){
  Drupal.behaviors.sitetheme = function(context) {
    $('#search-theme-form .form-text').val(Drupal.t('Search opensource.com')).focus(function() {
      $(this).val(Drupal.t(''));
    }).blur(function() {
      $(this).val(Drupal.t('Search opensource.com'));
    });

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