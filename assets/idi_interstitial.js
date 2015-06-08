//Js to initiate two separate colorbox interstitials or disclaimer boxes with gtm link tracking
//interstitial one for any external link
//interstitial_iframe applies only when the class "interstitial-iframe" is applied to the link.
// if the client requests an exception external link that does not need the interstitial you can either
// add the class "interstitial-exception" or add the http full address to the commented out if statement below


/**------------------------------------------------------------------------------------------------------------**/

// add external link event tracking to GA
/**
 * @see https://developers.google.com/analytics/devguides/collection/analyticsjs/events for new Universal GA tracking
 * @see https://support.google.com/analytics/answer/1136920?hl=en for the older GA tracking
 * @param {type} link
 * @param {type} category
 * @param {type} action
 * @returns {undefined}
 */
function trackOutboundLink(link, category, action) {
    //alert('trackOutboundLink(' + link.href + ')');
    try {
        //Older method
        //https://support.google.com/analytics/answer/1136920?hl=en
        _gaq.push(['_trackEvent', category, action, link.href]);
    } catch (err) {
    }

    setTimeout(function () {
        //do nothing
        //document.location.href = link.href;
    }, 300);
}

/**
 * only used by the colorbox link
 * @param {type} link
 * @param {type} category
 * @param {type} action
 * @returns {undefined}
 */
function trackOutboundLinkColorbox(link, category, action) {
    //alert('trackOutboundLink(' + link.href + ')');
    try {
        //Older method
        //https://support.google.com/analytics/answer/1136920?hl=en
        _gaq.push(['_trackEvent', category, action, link.href]);
    } catch (err) {
    }

    setTimeout(function () {
        //do nothing in this one
    }, 100);
}


/**------------------------------------------------------------------------------------------------------------**/

//console.log('testing');
(function ($) {
    Drupal.behaviors.idi_interstitial = {
        attach: function (context, settings) {
            $('.block--bean-interstitial a.external, .block--bean-interstitial-iframe a.external ').click(function () {
                $.colorbox.close();
                return true;
            });
            $('.block--bean-interstitial .internal, .block--bean-interstitial-iframe .internal').click(function () {
                $.colorbox.close();
                return false;
            });

            var external = RegExp('^((f|ht)tps?:)?//(?!' + location.host + ')');
            $('a:not(.external, .internal, .interstitial-exception)').click(function () {
                var $txt = $(this).attr('href');
                if (external.test($(this).attr('href')) == true) {
                    //alert('this is an external link');

                    //console.log("text equals " + txt);
                    //--if client requests external links that exception to the colorbox rule--//
                    //if (txt.indexOf('http://www.placeholder.com') == -1
                    //  && txt.indexOf('http://www.placeholder2.com') == -1
                    // )
                    {
                        colorboxInterstitial('.block--bean-interstitial', $txt);
                    }
                    trackOutboundLink(this, 'Outbound links', 'click');
                    return false;
                }
                else if ($(this).hasClass('interstitial-iframe')) {
                    $('.block--bean-interstitial-iframe').find('a.external').removeAttr('target');
                    colorboxInterstitial('.block--bean-interstitial-iframe', $txt);
                    return false;
                }
                return true;
            });


            function colorboxInterstitial($beanSelector, $href) {
                $($beanSelector).find('a.external').attr('href', $href);
                //evt.preventDefault();
                //alert('TEST EXTERNAL LINK');
                //trackOutboundLink(this, 'Outbound links', 'click');
                $.colorbox({
                    width: "100%",
                    height: "40%",
                    inline: true,
                    ajax: true,
                    scrolling: false,
                    closeButton: false,
                    top: 0,
                    href: $beanSelector
                });
            }
        }

    };

//change colorbox size on resize
    var cboxOptions = {
        width: '100%',
      //  height: '95%',
        maxWidth: '1200px',
        maxHeight: '1200px'
    }

    $('.cbox-link').colorbox(cboxOptions);

    $(window).resize(function(){
        $.colorbox.resize({
            width: window.innerWidth > parseInt(cboxOptions.maxWidth) ? cboxOptions.maxWidth : cboxOptions.width,
            height: window.innerHeight > parseInt(cboxOptions.maxHeight) ? cboxOptions.maxHeight : cboxOptions.height
        });
    });

}(jQuery));