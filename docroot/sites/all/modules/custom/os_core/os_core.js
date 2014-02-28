(function ($) {
  $(function () {
    tinyMCE.init({
      mode: "none",
      theme: "advanced",
      plugins : "autolink,lists,spellchecker,pagebreak,style,layer,table,save,advhr,advimage,advlink,emotions,iespell,inlinepopups,insertdatetime,preview,media,searchreplace,print,contextmenu,paste,directionality,fullscreen,noneditable,visualchars,nonbreaking,xhtmlxtras,template",
      theme_advanced_buttons1 : "bold,italic,underline,strikethrough,|,bullist,numlist,blockquote,|,justifyleft,justifycenter,justifyright,justifyfull,|,link,unlink,pagebreak,|,fullscreen,spellchecker,media,",
      skin : "cirkuit",
      width: "100%"
    });
    tinyMCE.execCommand("mceAddControl", false, "edit-field-default-license-und-other");
  })
})(jQuery);
