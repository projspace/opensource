(function($){
  Drupal.behaviors.sitetheme = function(context) {
    $('#search-theme-form .form-text').val(Drupal.t('Search opensource.com')).focus(function() {
      $(this).val(Drupal.t(''));
    }).blur(function() {
      $(this).val(Drupal.t('Search opensource.com'));
    });

    $openidLegal = $(".openid-legal-checkbox");
    $openidLegal.hide();
  }
})(jQuery)