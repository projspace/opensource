(function($){
  Drupal.behaviors.sitetheme = function(context) {
    $('#search-theme-form .form-text').focus(function() {
      $(this).value = Drupal.t('');
    }).blur(function() {
      $(this).value = Drupal.t('Search opensource.com');
    });
  }
})(jQuery)