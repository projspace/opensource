(function($){
  Drupal.behaviors.sitetheme = function(context) {
    $('#search-theme-form .form-text').focus(function() {
      $(this).val(Drupal.t(''));
    }).blur(function() {
      $(this).val(Drupal.t('Search opensource.com'));
    });
  }
})(jQuery)