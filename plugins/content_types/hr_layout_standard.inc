<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Humanitarianresponse Operation'),
  'description' => t('Shows a standard block for your operation home page.'),
  'category' => t('Humanitarianresponse'),
  'edit form' => 'hr_layout_standard_edit_form',
  'render callback' => 'hr_layout_standard_render',
  'defaults' => array(),
);

/**
 * 'Edit form' callback for the content type.
 */
function hr_layout_standard_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  return $form;
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function hr_layout_standard_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();
 
  // initial content is blank
  $block->title = '';
  $block->content = '';

  $block->content = '<div class="clearfix hr-layout-operation-standard">
  <ul class="nav nav-tabs" role="tablist">
    <li class="active"><a href="#hpc" role="tab" data-toggle="tab">Humanitarian Programme Cycle</a></li>
    <li><a href="#ocha" role="tab" data-toggle="tab">OCHA Products</a></li>
  </ul>
  
  <!-- Tab panes -->
  <div class="tab-content">
    <div class="tab-pane active" id="hpc">
      <div class="row">
        <div class="col-md-4">
          <div id="hno-thumbnail" class="show"><img class="img-responsive" src="http://www.humanitarianresponse.info/sites/www.humanitarianresponse.info/files/pdfpreview/125dd902eefb691fb00bb047e83ea751.jpg" alt="HNO thumbnail" /></div>
          <div id="srp-thumbnail" class="hidden"><img class="img-responsive" src="http://www.humanitarianresponse.info/sites/www.humanitarianresponse.info/files/pdfpreview/00cbaa7410c0557a567dbce25151bd47.jpg" alt="SRP thumbnail" /></div>
          <div id="monr-thumbnail" class="hidden"><img class="img-responsive" src="http://www.humanitarianresponse.info/sites/www.humanitarianresponse.info/files/pdfpreview/0d26bfd6850937d430a0f6157e66d88e.jpg" alt="Monitoring Report thumbnail" /></div>
        </div>
        <div class="col-md-8">
          <div class="list-group">
            <a href="http://www.humanitarianresponse.info/operations/iraq/document/iraq-humanitarian-needs-overview-arabic" class="list-group-item" id="hno">Humanitarian Needs Overview - JUL / 07 / 2014</a>
            <a href="http://www.humanitarianresponse.info/operations/iraq/document/immediate-response-plan-irp-idps-crisis-kr-i-15-sept-15-nov-2014" class="list-group-item" id="srp">Strategic Response Plan - SEP / 23 / 2014</a>
            <a href="http://www.humanitarianresponse.info/operations/philippines/document/typhoon-haiyanyolanda-final-periodic-montoring-report-pmr-22oct2014" class="list-group-item" id="monr">Monitoring Report - OCT / 23 /2014</a>
          </div>
        </div>
      </div>
    </div>
    <div class="tab-pane" id="ocha">
      <div class="col-md-4">
        <div id="sitrep-thumbnail" class="show"><img class="img-responsive" src="http://www.humanitarianresponse.info/sites/www.humanitarianresponse.info/files/pdfpreview/61cf826ef6cd0363f3172680f713e62c.jpg" alt="HNO thumbnail" /></div>
        <div id="humbul-thumbnail" class="hidden"><img class="img-responsive" src="http://www.humanitarianresponse.info/sites/www.humanitarianresponse.info/files/pdfpreview/1d3c37cc1a50fe0749c1413cf75c9fef.jpg" alt="SRP thumbnail" /></div>
        <div id="humsnap-thumbnail" class="hidden"><img class="img-responsive" src="http://www.humanitarianresponse.info/sites/www.humanitarianresponse.info/files/pdfpreview/0cb6a56f7243a16be661441855e64003.jpg" alt="Monitoring Report thumbnail" /></div>
        <div id="humdash-thumbnail" class="hidden"><img class="img-responsive" src="http://www.humanitarianresponse.info/sites/www.humanitarianresponse.info/files/pdfpreview/539ec0c9e0af2e79b1ad7638e5ebcfe0.jpg" alt="Humanitarian Dashboard thumbnail" /></div>
      </div>
      <div class="col-md-8">
        <div class="list-group">
          <a href="http://www.humanitarianresponse.info/operations/central-african-republic/document/car-situation-report-no-40-23-october-2014" class="list-group-item" id="sitrep">Latest Situation Report</a>
          <a href="http://www.humanitarianresponse.info/operations/ethiopia/document/humanitarian-bulletin-20-october-2014" class="list-group-item" id="humbul">Latest Humanitarian Bulletin</a>
          <a href="http://www.humanitarianresponse.info/operations/kenya/infographic/kenya-inter-communal-conflict-district-january-june-2014-ocha-8-july" class="list-group-item" id="humsnap">Latest Humanitarian Snapshot</a>
          <a href="http://www.humanitarianresponse.info/operations/kenya/infographic/kenya-humanitarian-dashboard-november-2012" class="list-group-item" id="humdash">Latest Humanitarian Dashboard</a>
        </div>
      </div>
    </div>
  </div>
  </div>

  <script type="text/javascript">
    (function($) {
      $(".hr-layout-operation-standard a").hover(
        function () {
          $( this ).addClass("active");
          var selector = "#" + $( this ).attr("id") + "-thumbnail";
          $(selector).removeClass("hidden");
          $(selector).addClass("show");
        },
        function() {
          $( this ).removeClass("active");
          var selector = "#" + $( this ).attr("id") + "-thumbnail";
          $(selector).removeClass("show");
          $(selector).addClass("hidden");
        });
    })(jQuery);
  </script>';
  
  return $block;
}
