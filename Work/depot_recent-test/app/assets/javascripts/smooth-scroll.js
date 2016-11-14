// Plugin: jQuery.scrollSpeed
// Source: github.com/nathco/jQuery.scrollSpeed
// Author: Nathan Rutzky
// Update: 1.0.2

(function($) {

  if (window.addEventListener) window.addEventListener('DOMMouseScroll', wheel, false);
  window.onmousewheel = document.onmousewheel = wheel;

  function wheel(event) {
      var delta = 0;
      if (event.wheelDelta) delta = event.wheelDelta / 120;
      else if (event.detail) delta = -event.detail / 3;

      handle(delta);
      if (event.preventDefault) event.preventDefault();
      event.returnValue = false;
  }

  function handle(delta) {
      var time = 5;
  	var distance = 20;

      $('html, body').stop().animate({
          scrollTop: $(window).scrollTop() - (distance * delta)
      }, time );
  }

})(jQuery);
