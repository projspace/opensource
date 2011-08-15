(function($){
  Drupal.behaviors.sitetheme = function(context) {
    $('#search-theme-form .form-text').val(Drupal.t('Search opensource.com')).focus(function() {
      $(this).val(Drupal.t(''));
    }).blur(function() {
      $(this).val(Drupal.t('Search opensource.com'));
    });

    // with forms.css hides default filefield source from content editor
    $('a.filefield-source-imce').trigger('click');

  }

})(jQuery)
