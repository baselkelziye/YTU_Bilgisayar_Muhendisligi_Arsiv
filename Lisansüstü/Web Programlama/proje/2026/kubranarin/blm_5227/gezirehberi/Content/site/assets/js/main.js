(function ($) {
	"use strict";


/*===========================================
	=            Windows Load          =
=============================================*/
var windowOn = $(window);

windowOn.on('load', function () {
	$("#loading").fadeOut(500);
});

/*===========================================
	=    		Mobile Menu			      =
=============================================*/
//SubMenu Dropdown Toggle
if ($('.tgmenu__wrap li.menu-item-has-children ul').length) {
	$('.tgmenu__wrap .navigation li.menu-item-has-children').append('<div class="dropdown-btn"><span class="plus-line"></span></div>');
}

// header-sticky
windowOn.on('scroll', function () {
	var scroll = windowOn.scrollTop();
	if (scroll < 200) {
		$("#header-sticky").removeClass("header-sticky");
	} else {
		$("#header-sticky").addClass("header-sticky");
	}
});

if ($('.tg-header-height').length > 0) {
	var headerHeight = document.querySelector(".tg-header-height");      
	var setHeaderHeight = headerHeight.offsetHeight;	
	$(".tg-header-height").each(function () {
		$(this).css({
			'height' : $(this).height()
		});
	});
}

//Mobile Nav Hide Show
if ($('.tgmobile__menu').length) {

	var mobileMenuContent = $('.tgmenu__wrap .tgmenu__main-menu').html();
	$('.tgmobile__menu .tgmobile__menu-box .tgmobile__menu-outer').append(mobileMenuContent);

	//Dropdown Button
	$('.tgmobile__menu li.menu-item-has-children .dropdown-btn').on('click', function () {
		$(this).toggleClass('open');
		$(this).prev('ul').slideToggle(300);
	});
	//Menu Toggle Btn
	$('.mobile-nav-toggler').on('click', function () {
		$('body').addClass('mobile-menu-visible');
	});

	//Menu Toggle Btn
	$('.tgmobile__menu-backdrop, .tgmobile__menu .close-btn').on('click', function () {
		$('body').removeClass('mobile-menu-visible');
	});
};


/*===========================================
	=     Menu sticky & Scroll to top      =
=============================================*/
$(window).on('scroll', function () {
	var scroll = $(window).scrollTop();
	if (scroll < 245) {
		$("#sticky-header").removeClass("sticky-menu");
		$('.scroll-to-target').removeClass('open');
        $("#header-fixed-height").removeClass("active-height");

	} else {
		$("#sticky-header").addClass("sticky-menu");
		$('.scroll-to-target').addClass('open');
        $("#header-fixed-height").addClass("active-height");
	}
});


/*===========================================
	=           Scroll Up  	         =
=============================================*/
if ($('.scroll-to-target').length) {
  $(".scroll-to-target").on('click', function () {
    var target = $(this).attr('data-target');
    // animate
    $('html, body').animate({
      scrollTop: $(target).offset().top
    }, 0);

  });
}


/*===========================================
	=          Data Background    =
=============================================*/
$("[data-background]").each(function () {
	$(this).css("background-image", "url(" + $(this).attr("data-background") + ")")
});

$("[data-bg-color]").each(function () {
	$(this).css("background-color", $(this).attr("data-bg-color"));
});

/*=============================================
	=            Header Search            =
=============================================*/
$(".search-open-btn").on("click", function () {
    $(".search__popup").addClass("search-opened");
    $(".search-popup-overlay").addClass("search-popup-overlay-open");
});
$(".search-close-btn").on("click", function () {
    $(".search__popup").removeClass("search-opened");
    $(".search-popup-overlay").removeClass("search-popup-overlay-open");
});

/*=============================================
=     Offcanvas Menu      =
=============================================*/
$(".menu-tigger").on("click", function () {
	$(".offCanvas__info, .offCanvas__overly").addClass("active");
	return false;
});
$(".menu-close, .offCanvas__overly").on("click", function () {
	$(".offCanvas__info, .offCanvas__overly").removeClass("active");
});



/*=============================================
	=    		Isotope	Active  	      =
=============================================*/
$('.project-active-two').imagesLoaded(function () {
	// init Isotope
	var $grid = $('.project-active-two').isotope({
		itemSelector: '.grid-item',
		percentPosition: true,
		masonry: {
			columnWidth: '.grid-item',
		}
	});
	// filter items on button click
	$('.project__menu-nav').on('click', 'button', function () {
		var filterValue = $(this).attr('data-filter');
		$grid.isotope({ filter: filterValue });
	});

});
//for menu active class
	$('.project__menu-nav button').on('click', function (event) {
	$(this).siblings('.active').removeClass('active');
	$(this).addClass('active');
	event.preventDefault();
});




/*===========================================
      =       Odometer Active    =
=============================================*/
$('.odometer').appear(function (e) {
	var odo = $(".odometer");
	odo.each(function () {
		var countNumber = $(this).attr("data-count");
		$(this).html(countNumber);
	});
});


/*===========================================
	=        Magnific Popup    =
=============================================*/
$('.popup-image').magnificPopup({
	type: 'image',
	gallery: {
		enabled: true
	}
});

/* magnificPopup video view */
$('.popup-video').magnificPopup({
	type: 'iframe'
});


/*===========================================
	=        Wow Active      =
=============================================*/
	new WOW().init();

/*===========================================
	=        tg-booking-quantity-toggle      =
=============================================*/
	$('.tg-booking-quantity-toggle').on('click', function (e) {
		e.stopPropagation(); 
		let toggle = $(this); 
		let container = toggle.parent('.tg-hero-quantity');

		if (toggle.hasClass('active')) {
			toggle.removeClass('active');
			toggle.next('.tg-booking-quantity-active').removeClass('tg-list-open');
		} else {
			$('.tg-booking-quantity-toggle').removeClass('active');
			$('.tg-booking-quantity-active').removeClass('tg-list-open');
			toggle.addClass('active');
			toggle.next('.tg-booking-quantity-active').addClass('tg-list-open');
		}
	});

	$(document).on('click', function (e) {
		if (!$(e.target).closest('.tg-hero-quantity').length) {
			$('.tg-booking-quantity-toggle').removeClass('active');
			$('.tg-booking-quantity-active').removeClass('tg-list-open');
		}
	});


/*=============================================
	=        Date and time js	      =
=============================================*/
	flatpickr("input[name='datetime-local']", {
		dateFormat: "Y-m-d",
		disableMobile: "true"
	});


	/*=============================================
		=        Date and time js	      =
	=============================================*/

	$('.decrement').on('click', function () {
		var $input = $(this).parent().find('input');
		var count = parseInt($input.val()) - 1;
		count = count < 1 ? 1 : count;
		$input.val(count);
		$input.change();
		return false;
	});

	$('.increment').on('click', function () {
		var $input = $(this).parent().find('input');
		$input.val(parseInt($input.val()) + 1);
		$input.change();
		return false;
	});


	/*=============================================
		=       Nice Select Js      =
	=============================================*/
	$('.select').niceSelect();


	var gridViewBtn = $(".grid-view");
	var	listViewBTn = $(".list-view");
  
	$(gridViewBtn).on("click", function () {
		$(this)
		.addClass("active")
		.parent(".list-switch-item")
		.siblings()
		.children()
		.removeClass("active");
		$(".list-card").removeClass("list-card-open");
	});

	$(listViewBTn).on("click", function () {
		$(this)
		.addClass("active")
		.parent(".list-switch-item")
		.siblings()
		.children()
		.removeClass("active");
		$(".list-card").addClass("list-card-open");
	});
  

	/*=============================================
		=        tg-hero-slider-active	      =
	=============================================*/
	var tg_hero_slider = new Swiper('.tg-hero-slider-active', {
		slidesPerView: 1,
		loop: true,
		autoplay: true,
		arrow: false,
		spaceBetween: 0,
		speed: 2000,
		effect: 'fade',
		a11y: false,
		navigation: {
			prevEl: '.tg-hero-prev',
			nextEl: '.tg-hero-next',
		},
		autoplay: {
			delay: 3500,
			disableOnInteraction: false
		},

	});


/*=============================================
	=       tg-testimonial-slider	      =
=============================================*/

	var slider = new Swiper('.tg-testimonial-slider', {
		spaceBetween: 25,
		loop: true,
		speed:500,
		autoplay: {
			delay: 4000,
		},
		pagination: {
			el: ".swiper-pagination",
		  },
		breakpoints: {
			'1200': {
				slidesPerView: 3,
			},
			'992': {
				slidesPerView: 2,
			},
			'768': {
				slidesPerView: 2,
			},
			'576': {
				slidesPerView: 1,
			},
			'0': {
				slidesPerView: 1,
			},
		},
	});

/*=============================================
	=       tg-brand-slide	      =
=============================================*/

	var slider = new Swiper('.tg-brand-slide', {
		loop: true,
		freemode: true,
		slidesPerView: 'auto',
		spaceBetween: 25,
		centeredSlides: true,
		allowTouchMove: false,
		speed: 4000,
		autoplay: {
		  delay: 1,
		  disableOnInteraction: true,
		},
	});


/*=============================================
	=       tg-testimonial-slider	      =
=============================================*/

	var slider = new Swiper('.tg-listing-slider', {
		spaceBetween: 24,
		loop: true,
		speed:500,
		autoplay: {
			delay: 4000,
		},
		pagination: {
			el: ".swiper-pagination",
		},
		breakpoints: {
			'1200': {
				slidesPerView: 4,
			},
			'992': {
				slidesPerView: 3,
			},
			'768': {
				slidesPerView: 2,
			},
			'576': {
				slidesPerView: 1,
			},
			'0': {
				slidesPerView: 1,
			},
		},
	});


	/*=============================================
		=        tg-testimonial-4-slide-active	      =
	=============================================*/
	var slider = new Swiper ('.tg-testimonial-4-slide-active', {
		slidesPerView: 1,
		centeredSlides: true,
		loop: true,
		loopedSlides: 6,
		navigation: {
			nextEl: '.tg-testimonial-4-slide-next',
			prevEl: '.tg-testimonial-4-slide-prev',
		},
	});
	var thumbs = new Swiper ('.tg-testimonial-4-thumb-active', {
		slidesPerView: 4,
		spaceBetween: 9,
		centeredSlides: false,
		loop: true,
		slideToClickedSlide: true,
	});
	
	slider.controller.control = thumbs;
	thumbs.controller.control = slider;

/*=============================================
	=       tg-testimonial-slider	      =
=============================================*/

	var slider = new Swiper('.tg-listing-slider-2', {
		spaceBetween: 24,
		loop: true,
		speed:500,
		autoplay: {
			delay: 4000,
		},
		navigation: {
			nextEl: '.tg-listing-5-slide-next',
			prevEl: '.tg-listing-5-slide-prev',
		},
		breakpoints: {
			'1200': {
				slidesPerView: 4,
			},
			'992': {
				slidesPerView: 3,
			},
			'768': {
				slidesPerView: 2,
			},
			'576': {
				slidesPerView: 2,
			},
			'0': {
				slidesPerView: 1,
			},
		},
	});

/*=============================================
	=       tg-testimonial-slider	      =
=============================================*/

	var slider = new Swiper('.tg-location-5-slider', {
		spaceBetween: 50,
		loop: true,
		speed:500,
		autoplay: {
			delay: 4000,
		},
		navigation: {
			nextEl: '.tg-listing-5-slide-next',
			prevEl: '.tg-listing-5-slide-prev',
		},
		breakpoints: {
			'1200': {
				slidesPerView: 4,
			},
			'992': {
				slidesPerView: 3,
				spaceBetween: 40,
			},
			'768': {
				slidesPerView: 2,
				spaceBetween: 30,
			},
			'576': {
				slidesPerView: 2,
				spaceBetween: 30,
			},
			'0': {
				slidesPerView: 1,
				spaceBetween: 30,
			},
		},
	});

/*=============================================
	=       tg-testimonial-slider	      =
=============================================*/
	var slider = new Swiper ('.tg-tour-details-gallery-active', {
		slidesPerView: 1,
		centeredSlides: true,
		loop: true,
		loopedSlides: 5,
		navigation: {
				nextEl: '.tg-tour-details-gallery-next',
				prevEl: '.tg-tour-details-gallery-prev',
		},
	});
	var thumbs = new Swiper ('.tg-tour-details-gallery-thumb-active', {
		slidesPerView: 5,
		spaceBetween: 20,
		centeredSlides: false,
		loop: true,
		slideToClickedSlide: true,
		breakpoints: {
			'768': {
				spaceBetween: 20,
			},
			'576': {
				spaceBetween: 10,
			},
			'0': {
				spaceBetween: 10,
			},
		},
	});
	
	slider.controller.control = thumbs;
	thumbs.controller.control = slider;

	/*=============================================
		=       tg-testimonial-slider	      =
	=============================================*/

	$('.tg-custom-accordion .accordion-item').on("click", function(){
		$(this).addClass('tg-faq-active').siblings().removeClass('tg-faq-active');
	});

	$("[data-width]").each(function () {
		$(this).css("width", $(this).attr("data-width"));
	});
	

/*=============================================
	=       tg-location-su-slider	      =
=============================================*/

var slider = new Swiper('.tg-location-su-slider', {
	spaceBetween: 30,
	loop: true,
	speed:500,
	autoplay: {
		delay: 4000,
	},
	navigation: {
		nextEl: '.tg-listing-5-slide-next',
		prevEl: '.tg-listing-5-slide-prev',
	},
	breakpoints: {
		'1200': {
			slidesPerView: 4,
		},
		'992': {
			slidesPerView: 3,
			spaceBetween: 40,
		},
		'768': {
			slidesPerView: 2,
			spaceBetween: 30,
		},
		'576': {
			slidesPerView: 2,
			spaceBetween: 30,
		},
		'0': {
			slidesPerView: 1,
			spaceBetween: 30,
		},
	},
});
})(jQuery);