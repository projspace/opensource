if (Drupal.jsEnabled) {
  $(document).ready(function () {
    $('#popup-ad').triggerHandler("click");
    $('a.popup-close').click(function() { Lightbox.end('forceClose'); return false; });
  });
}
