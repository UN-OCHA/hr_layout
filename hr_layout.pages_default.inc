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
  $display->layout = 'radix_phelan';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd4221dbc-34fc-4b55-9af5-da36c1017271';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
    $pane->panel = 'column1';
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

<p class="text-center"><a class="btn btn-primary" href="/clusters/space">Read all the information about clusters</a></p>',
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
    $display->panels['column1'][0] = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
    $pane = new stdClass();
    $pane->pid = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
    $pane->panel = 'column2';
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
    $display->panels['column2'][0] = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
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
  $display->layout = 'radix_moscone_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = 'Home';
  $display->uuid = 'b4f0cdd8-1e4b-4d49-b201-90e3bbd936dc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c4587b0c-f9a2-4d54-ba97-faaf9e39561c';
    $pane->panel = 'contentmain';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>The HumanitarianResponse.info platform is provided to the humanitairan community as a means to aid in coordination of operational information and related activities. The technical aspects have been developed and continued to be managed by <a href="http://www.unocha.org">OCHA</a> as per their responsibilities outlined in the Inter-Agency Standing Committee’s (IASC) <a href="https://www.humanitarianresponse.info/system/files/documents/files/IASC%20Operational%20Guidance%20on%20Responsibilities%20of%20Sector%20Cluster%20Leads%20and%20OCHA%20in%20Information%20Management.pdf">Operational Guidance on Responsibilities Of Cluster/Sector Leads & OCHA In Information Management</a>.</p>

<p>On 31 March 2014, OCHA released Version 2 (HR2.0) which came with a fresh design enabling easier navigation, a completely new technical infrastructure designed with future functionality in mind and several new features. Over the next three-to-four months, several existing HR.info sites (on the old platform) will be migrated and several new, major features will be added.</p>

<p>Over the coming months, features such global information management tools (e.g. Assessment Registry), cross emergency search, and humanitarian responder check-in/out will be enabled for use.  Once these features are implemented and the existing emergency operational sites are migrated to the new platform, the development team will begin working on additional functionality including email group integration, SMS notifications, data cleaning tools, improved interactive mapping, ReliefWeb (search) integration and cluster site search integration.</p>

<p>To keep yourself up-to-date with the very latest HR2.0 developments, <a href="http://eepurl.com/H37j1">subscribe to the update email list</a>.</p>

<p>Don\'t know where to start on this new site ? Take the <a href="/?tour=introduction">Introduction tour</a> !</p>',
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
    $display->panels['contentmain'][0] = 'new-c4587b0c-f9a2-4d54-ba97-faaf9e39561c';
    $pane = new stdClass();
    $pane->pid = 'new-194e17c4-1bd0-4d8e-b92d-e722ea2c4e1f';
    $pane->panel = 'footer';
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
      <a href="operations"><img src="/sites/all/themes/humanitarianresponse/assets/images/home/operations.png" alt="Operations" /></a>
      <div class="caption">Operations</div>
    </div>
  </div>
  <div class="col-sm-2">
   <div class="thumbnail">
      <a href="clusters"><img src="/sites/all/themes/humanitarianresponse/assets/images/home/clusters.png" alt="Clusters" /></a>
      <div class="caption">Clusters</div>
    </div>
  </div>
  <div class="col-sm-2">
    <div class="thumbnail">
      <a href="programme-cycle"><img src="/sites/all/themes/humanitarianresponse/assets/images/home/programmecycle.png" alt="Programme Cycle" /></a>
      <div class="caption">Programme Cycle</div>
    </div>
  </div>
  <div class="col-sm-2">
    <div class="thumbnail">
      <a href="topics"><img src="/sites/all/themes/humanitarianresponse/assets/images/home/topics.png" alt="Topics" /></a>
      <div class="caption">Topics</div>
    </div>
  </div>
  <div class="col-sm-2">
    <div class="thumbnail">
      <a href="applications"><img src="/sites/all/themes/humanitarianresponse/assets/images/home/applications.png" alt="Applications"></a>
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
    $display->panels['footer'][0] = 'new-194e17c4-1bd0-4d8e-b92d-e722ea2c4e1f';
    $pane = new stdClass();
    $pane->pid = 'new-93e272b5-ba0f-4fc0-ae81-e764444fb2d2';
    $pane->panel = 'sidebar';
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
    <strong><a href="https://southsudan.humanitarianresponse.info">South Sudan</a></strong>
    <p>&nbsp;</p>
  </div>
</div>
<br />
<div class="row">
  <div class="col-sm-6 text-center">
    <img src="/sites/all/themes/humanitarianresponse/assets/images/icons/75/Disasters/DIS_conflict.png" alt="Conflict" />
  </div>
  <div class="col-sm-6">
    <strong><a href="https://car.humanitarianresponse.info">Central African Republic</a></strong>
    <p>NOV / 26 / 2013</p>
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
    $display->panels['sidebar'][0] = 'new-93e272b5-ba0f-4fc0-ae81-e764444fb2d2';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-c4587b0c-f9a2-4d54-ba97-faaf9e39561c';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hr_home'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'hr_programme_cycle';
  $page->task = 'page';
  $page->admin_title = 'Programme Cycle';
  $page->admin_description = '';
  $page->path = 'programme-cycle';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Programme Cycle',
    'name' => 'main-menu',
    'weight' => '6',
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
  $handler->name = 'page_hr_programme_cycle_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'hr_programme_cycle';
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
  $display->layout = 'radix_phelan';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd4221dbc-34fc-4b55-9af5-da36c1017271';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
    $pane->panel = 'column1';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Programme Cycle text',
      'title' => '',
      'body' => '<p>The humanitarian programme cycle (HPC) is a coordinated series of actions undertaken to help prepare for, manage and deliver humanitarian response. It consists of five elements coordinated in a seamless manner, with one step logically building on the previous and leading to the next. Successful implementation of the humanitarian programme cycle is dependent on effective emergency preparedness, effective coordination with national/local authorities and humanitarian actors, and information management.&nbsp;</p><p>The HPC elements are as follows:</p><ol><li>needs assessment and analysis</li><li>strategic response planning</li><li>resource mobilization</li><li>implementation and monitoring</li><li>operational review and evaluation.</li></ol><p>Each of the five elements above will in due course have a page on this site. This content is currently being prepared.&nbsp;</p><p><strong>Aims and objectives</strong></p><p>This approach, agreed by IASC Principals as part of the Transformative Agenda,&nbsp;is based on innovations that have become good practice in the field and aims to achieve the following results:</p><ul><li>stronger emphasis on the needs of affected people;</li><li>improved targeting of the most vulnerable;</li><li>increased funding for humanitarian priorities; and</li><li>greater accountability of humanitarian actors and donors for collective results.&nbsp;</li></ul><p><strong>Background</strong></p><p>For protracted crises, most of these elements previously formed part of the consolidated appeal process (CAP). However, the CAP&nbsp;–&nbsp;both as a process and document&nbsp;–&nbsp;became too&nbsp;‘heavy’&nbsp;in an attempt to include all the programme cycle elements. Henceforth each response operation shall prepare two distinct but connected processes and products on a new and slightly expanded timeframe. Mid-year reviews of the CAP will be replaced by more regular, less labor-intensive response monitoring based on an agreed IASC framework.&nbsp;Separate guidance applies to sudden onset emergencies and will be included on the website in due course.</p>',
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
    $display->panels['column1'][0] = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
    $pane = new stdClass();
    $pane->pid = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
    $pane->panel = 'column2';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<img src="/sites/all/themes/humanitarianresponse/assets/images/programme-cycle.png" class="img-responsive" alt="Programme Cycle" />',
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
    $display->panels['column2'][0] = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
    $pane = new stdClass();
    $pane->pid = 'new-aae1a8c7-93d3-4578-8cc4-52f705db0898';
    $pane->panel = 'column2';
    $pane->type = 'views_panes';
    $pane->subtype = 'hr_spaces-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'aae1a8c7-93d3-4578-8cc4-52f705db0898';
    $display->content['new-aae1a8c7-93d3-4578-8cc4-52f705db0898'] = $pane;
    $display->panels['column2'][1] = 'new-aae1a8c7-93d3-4578-8cc4-52f705db0898';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hr_programme_cycle'] = $page;

  return $pages;

}
