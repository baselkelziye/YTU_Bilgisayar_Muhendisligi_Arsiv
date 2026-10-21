(function($) {
  'use strict';
  $(function() {
    $("#features-link").on("click", function() {
        $('html, body').animate({
            scrollTop: $("#features").offset().top
        }, 1000);
    });
  });
})(jQuery);