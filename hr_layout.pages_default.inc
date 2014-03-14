<?php
/**
 * @file
 * hr_layout.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function hr_layout_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'hr_clusters';
  $page->task = 'page';
  $page->admin_title = 'Clusters';
  $page->admin_description = '';
  $page->path = 'clusters';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Clusters',
    'name' => 'main-menu',
    'weight' => '4',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clusters_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'hr_clusters';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => array(
        'column_type' => 'col-sm',
        'column_size' => '6',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'right' => array(
        'column_type' => 'col-sm',
        'column_size' => '6',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'bottom' => NULL,
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd4221dbc-34fc-4b55-9af5-da36c1017271';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'clusters text',
      'title' => '',
      'body' => '<p>When emergencies occur coordination is necessary. Good coordination means less gaps and overlaps in the assistance delivered by humanitarian organizations.</p>

<p>The foundations of the current international humanitarian coordination system were set by General Assembly resolution 46/182 in December 1991. Almost 15 years later, in 2005, a major reform of humanitarian coordination, known as the Humanitarian Reform Agenda, introduced a number of new elements to enhance predictability, accountability and partnership. The Cluster Approach was one of these new elements.</p>

<p>Clusters are groups of humanitarian organizations, both UN and non-UN, in each of the main sectors of humanitarian action, e.g. water, health and logistics. They are designated by the Inter-Agency Standing Committee (IASC) and have clear responsibilities for coordination.</p>

<p class="text-center"><a class="btn btn-primary" href="https://clusters.humanitarianresponse.info">Read all the information about clusters</a></p>',
      'format' => 'panopoly_html_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2532dff5-41bf-471e-a491-cee72a7612f5';
    $display->content['new-2532dff5-41bf-471e-a491-cee72a7612f5'] = $pane;
    $display->panels['left'][0] = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
    $pane = new stdClass();
    $pane->pid = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<img src="/sites/all/themes/humanitarianresponse/assets/images/clusters.png" class="img-responsive" alt="Cluster Approach" />',
      'format' => 'panopoly_html_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
    $display->content['new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e'] = $pane;
    $display->panels['right'][0] = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hr_clusters'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'hr_home';
  $page->task = 'page';
  $page->admin_title = 'Home';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Home',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'hr_home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => array(
        'column_type' => 'col-sm',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'left' => array(
        'column_type' => 'col-sm',
        'column_size' => '9',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'right' => array(
        'column_type' => 'col-sm',
        'column_size' => '3',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'bottom' => array(
        'column_type' => 'col-sm',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'top' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'bottom' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = 'Home';
  $display->uuid = 'b4f0cdd8-1e4b-4d49-b201-90e3bbd936dc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-194e17c4-1bd0-4d8e-b92d-e722ea2c4e1f';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<br /><br />
<div class="row">
  <div class="col-sm-1"></div>
  <div class="col-sm-2">
    <div class="thumbnail">
      <a href="operations"><img src="http://placehold.it/150x130" alt="Operations" /></a>
      <div class="caption">Operations</div>
    </div>
  </div>
  <div class="col-sm-2">
   <div class="thumbnail">
      <a href="clusters"><img src="http://placehold.it/150x130" alt="Clusters" /></a>
      <div class="caption">Clusters</div>
    </div>
  </div>
  <div class="col-sm-2">
    <div class="thumbnail">
      <a href="programme-cycle"><img src="http://placehold.it/150x130" alt="Programme Cycle" /></a>
      <div class="caption">Programme Cycle</div>
    </div>
  </div>
  <div class="col-sm-2">
    <div class="thumbnail">
      <a href="topics"><img src="http://placehold.it/150x130" alt="Topics" /></a>
      <div class="caption">Topics</div>
    </div>
  </div>
  <div class="col-sm-2">
    <div class="thumbnail">
      <a href="applications"><img src="http://placehold.it/150x130" alt="Applications"></a>
      <div class="caption">Applications</div>
    </div>
  </div>
  <div class="col-sm-1"></div>
</div>',
      'format' => 'panopoly_html_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '194e17c4-1bd0-4d8e-b92d-e722ea2c4e1f';
    $display->content['new-194e17c4-1bd0-4d8e-b92d-e722ea2c4e1f'] = $pane;
    $display->panels['bottom'][0] = 'new-194e17c4-1bd0-4d8e-b92d-e722ea2c4e1f';
    $pane = new stdClass();
    $pane->pid = 'new-c4587b0c-f9a2-4d54-ba97-faaf9e39561c';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>HumanitarianResponse.info has been developed by OCHA as the inter-cluster coordination site in support of the endorsed ‘Inter-Agency Standing Committee (IASC) Operational Guidance on Responsibilities Of Cluster/Sector Leads & OCHA In Information Management’ and at the request of the IASC Working Group.</p>

<p>The new version ‘HR2.0’ is complete new design of our exisitng Humanitarianresponse.info platform which comes with newly added features such as Humanitarian ID for emergency check-in, fresh new look with easy to navigate site content and next coming features i.e. global search across all our sites to serve information needs of the audience.</p>

<p>In the next coming months, we will be working with OCHA country and regional offices,  Global clusters and other Humanitarian thematic areas (cross cutting issues and Humanitarian Programme Cycle, etc) to integrate all the sites and make sure that we provide the humanitarian community with one-stop solution through one single interface.</p>

<p>Don\'t know where to start ? Take the <a href="/?tour=introduction">Introduction tour</a> !</p>',
      'format' => 'panopoly_html_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c4587b0c-f9a2-4d54-ba97-faaf9e39561c';
    $display->content['new-c4587b0c-f9a2-4d54-ba97-faaf9e39561c'] = $pane;
    $display->panels['left'][0] = 'new-c4587b0c-f9a2-4d54-ba97-faaf9e39561c';
    $pane = new stdClass();
    $pane->pid = 'new-93e272b5-ba0f-4fc0-ae81-e764444fb2d2';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Latest Operations',
      'body' => '<div class="row">
  <div class="col-sm-6 text-center">
    <img src="/sites/all/themes/humanitarianresponse/assets/images/icons/75/Disasters/DIS_conflict.png" alt="Conflict" />
  </div>
  <div class="col-sm-6">
    <strong>Central African Republic</strong>
    <p>NOV / 26 / 2013</p>
  </div>
</div>
<br />
<div class="row">
  <div class="col-sm-6 text-center">
    <img src="/sites/all/themes/humanitarianresponse/assets/images/icons/75/Disasters/DIS_cyclon.png" alt="Cyclon" />
  </div>
  <div class="col-sm-6">
    <strong>Philippines</strong>
    <p>NOV / 7 / 2013</p>
  </div>
</div>',
      'format' => 'panopoly_html_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '93e272b5-ba0f-4fc0-ae81-e764444fb2d2';
    $display->content['new-93e272b5-ba0f-4fc0-ae81-e764444fb2d2'] = $pane;
    $display->panels['right'][0] = 'new-93e272b5-ba0f-4fc0-ae81-e764444fb2d2';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-c4587b0c-f9a2-4d54-ba97-faaf9e39561c';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hr_home'] = $page;

  return $pages;

}
