/*********************************************************
 * Functions creating windows                            *
 *********************************************************/

#include "callback_func.h"
#include "editor_defs.h"
#include "editor_callback_func.h"
#include "finance.h"
#include "gui.h"
#include "interface.h"
#include "maths.h"
#include "misc.h"
#include "misc_interface.h"
#include "misc2_interface.h"
#include "options_interface.h"
#include "editor_interface.h"
#include "support.h"
#include "files.h"
#include "treeview.h"
#include "window.h"

/* create the live window and return the pointer */
GtkWidget*
return_live_window(void)
{
    return create_live_window();
}

/* create the main window and return the pointer */
GtkWidget*
return_main_window(void)
{
    GtkWidget *window = create_main_window();
    gchar buf[SMALL];
    
    sprintf(buf, "Bygfoot Football Manager %s", VERS);
    gtk_window_set_title(GTK_WINDOW(window), buf);

    return window;
}

/* create options window */
void
show_opt_window(void)
{
    GtkWidget *opt_window =
	create_opt_window();
    gchar buf[SMALL];
    
    sprintf(buf, "Bygfoot %s -- Options", VERS);
    gtk_window_set_title(GTK_WINDOW(opt_window), buf);

    set_up_options_window(opt_window, 1);

    change_popups_active(1);
    
    gtk_widget_show(opt_window);
}

void
get_fire_text(GtkWidget *popup_label, GtkWidget **radiobuttons,
	      gint *status)
{
    gint i;
    gchar buf[3][SMALL];
    
    sprintf(buf[0], "You'd like to fire %s. You can",
	    teams[status[1]].players[status[2]].name);
    
    sprintf(buf[1], "pay a one-time compensation of ");
    print_grouped_int(round_integer(teams[status[1]].players[status[2]].value * 0.25, 2),
		      buf[1], 1);
    
    sprintf(buf[2], "pay his wage (");
    print_grouped_int(teams[status[1]].players[status[2]].wage,
		      buf[2], 1);
    strcat(buf[2], ") for another 8 months");

    gtk_label_set_text(GTK_LABEL(popup_label), buf[0]);

    for(i=0;i<2;i++)
	gtk_button_set_label(GTK_BUTTON(radiobuttons[i]), buf[i + 1]);
}

/* show a popup window with 'text' and adjust the
   window buttons according to the 'status' integers */
void
show_popup_window(gchar *text, gint *status)
{
    gint i;
    gint local_status[3];
    GtkWidget *popup_window = 
	create_popup_window();
    GtkWidget *label_popup_text =
	lookup_widget(popup_window, "label_popup_text");
    GtkWidget *radiobuttons[2];
    GtkWidget *button_popup_ok =
	lookup_widget(popup_window, "button_popup_ok");
    GtkWidget *button_popup_cancel =
	lookup_widget(popup_window, "button_popup_cancel");
    GtkWidget *button_popup_close =
	lookup_widget(popup_window, "button_popup_close");
    GtkWidget *image_popup_question =
	lookup_widget(popup_window, "image_popup_question");
    GtkWidget *image_popup_warning =
	lookup_widget(popup_window, "image_popup_warning");
    GtkWidget *check_popup =
	lookup_widget(popup_window, "check_popup");
    GtkWidget *label_popup_status[3];
    gchar buf[SMALL];
    
    radiobuttons[0] = 
	lookup_widget(popup_window, "radiobutton0");
    radiobuttons[1] = 
	lookup_widget(popup_window, "radiobutton1");

    label_popup_status[0] = 
	lookup_widget(popup_window, "label_popup_status");
    label_popup_status[1] = 
	lookup_widget(popup_window, "label_popup_status2");
    label_popup_status[2] = 
	lookup_widget(popup_window, "label_popup_status3");

    sprintf(buf, "Bygfoot %s", VERS);
    gtk_window_set_title(GTK_WINDOW(popup_window), buf);

    if(status == NULL)
	for(i=0;i<3;i++)
	    local_status[i] = -1;
    else
	for(i=0;i<3;i++)
	    local_status[i] = status[i];
    
    for(i=0;i<3;i++)
	label_set_text_from_int(GTK_LABEL(label_popup_status[i]),
				local_status[i], 0);
    
    label_set_text(GTK_LABEL(label_popup_text), text, 0);

    if(local_status[0] == 60 ||
       local_status[0] == 61)
    {
	get_fire_text(label_popup_text, radiobuttons, local_status);
	for(i=0;i<2;i++)
	    gtk_widget_show(radiobuttons[i]);

	if(local_status[0] == 61)
	    gtk_widget_set_sensitive(radiobuttons[1], FALSE);
    }

    if((local_status[0] >= 100 && local_status[0] < 200) || 
       local_status[0] == 500000 || local_status[0] == 0)
	gtk_widget_show(check_popup);

    if(local_status[0] > 0)
    {
	gtk_widget_show(image_popup_question);
	gtk_widget_show(button_popup_cancel);
	gtk_widget_show(button_popup_ok);
    }
    else
    {
	if(options[OPT_PREFER_MESS])
	{
	    gtk_widget_destroy(popup_window);
	    print_message(text);
	    return;
	}

	gtk_widget_show(image_popup_warning);
	gtk_widget_show(button_popup_close);
    }
	
    change_popups_active(1);

    gtk_widget_show(popup_window);
}

/* pop up the help window */
void
show_help(gint customization)
{
    GtkWidget *help_window = create_help_window();
    GtkWidget *text_view_help =
	lookup_widget(help_window, "text_view_help");
    GtkTextBuffer *text_buffer_help =
	gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view_help));
    PangoFontDescription *font_desc;
    
    gchar buf[SMALL];
    gchar trash[SMALL];
    FILE *fil;

    sprintf(buf, "Bygfoot %s -- Help", VERS);
    gtk_window_set_title(GTK_WINDOW(help_window), buf);

    text_file_number_to_char(FILES_HELP, buf, TRUE);
    fil = fopen(buf, "r");

    if(fil == NULL)
    {
	show_popup_window("Could not find help file.", NULL);
	return;
    }

    if(strcmp(font_name, "0") != 0)
    {
	font_desc = pango_font_description_from_string(font_name);
	gtk_widget_modify_font(text_view_help, font_desc);
    }

    fscanf(fil, "%[^\n]", buf);

    if(customization == 1)
	while(strncmp(buf, "Customization Guide", strlen("Customization Guide")) != 0 &&
	      feof(fil) == 0)
	{
	    fscanf(fil, "%[\n \t]*", buf);
	    fscanf(fil, "%[^\n]", buf);
	}

    while(feof(fil) == 0)
    {
	gtk_text_buffer_insert_at_cursor(text_buffer_help,
					 buf, -1);
	fscanf(fil,"%[\n]*", trash);
	gtk_text_buffer_insert_at_cursor(text_buffer_help,
					 trash, -1);

	fscanf(fil, "%[^\n]", buf);
    }
    
    fclose(fil);

    gtk_widget_show(help_window);
}

/* show the file selection window */
void
show_file_selection(gint save)
{
    GtkWidget *fsel_window =
	create_fsel_window();
    gchar buf[SMALL];
    gchar buf2[SMALL];

    sprintf(buf, "Bygfoot %s", VERS);
    gtk_window_set_title(GTK_WINDOW(fsel_window), buf);

    sprintf(buf, "%s/.bygfoot/text_files/", getenv("HOME"));
    sprintf(buf2, "test -d %s", buf);
    
    status = 800000 + save;

    change_popups_active(1);

    if(save < 10)
	gtk_file_selection_set_filename(
	    GTK_FILE_SELECTION(fsel_window), save_file->str);
    else if(system(buf2) == 0)
	gtk_file_selection_set_filename(
	    GTK_FILE_SELECTION(fsel_window), buf);

    gtk_widget_show(fsel_window);
}

/* show the team selection window at the beginning of the game */
void
show_team_selection(void)
{
    GtkWidget *team_selection_window;
    GtkWidget *team_selection_treeview;

    team_selection_window = create_team_selection();
    team_selection_treeview = lookup_widget(team_selection_window,
					    "team_selection_treeview");
    
    show_team_list(team_selection_treeview, 0);

    gtk_widget_show(team_selection_window);
}

void
show_font_sel_window(void)
{
    GtkWidget *font_sel_window =
	create_font_sel_window();
    gchar buf[SMALL];
    
    sprintf(buf, "Bygfoot %s", VERS);
    gtk_window_set_title(GTK_WINDOW(font_sel_window), buf);
    
    change_popups_active(1);
    gtk_widget_show(font_sel_window);
}

void
show_stadium_window(void)
{
    gint i;
    gchar buf[SMALL];
    GtkWidget *stadium_window = create_stadium_window();
    GtkWidget *label_cost[4];

    sprintf(buf, "Bygfoot %s", VERS);
    gtk_window_set_title(GTK_WINDOW(stadium_window), buf);

    label_cost[0] = 
	lookup_widget(stadium_window, "label_cost0");
    label_cost[1] = 
	lookup_widget(stadium_window, "label_cost1");
    label_cost[2] = 
	lookup_widget(stadium_window, "label_cost2");
    label_cost[3] = 
	lookup_widget(stadium_window, "label_cost3");
    
    for(i=0;i<4;i++)
    {
	print_grouped_int(stadium_improve_costs(0, i), buf, 0);

	gtk_label_set_text(GTK_LABEL(label_cost[i]), buf);
    }
    
    change_popups_active(1);
    gtk_widget_show(stadium_window);
}

/* start the team editor */
void
start_editor(void)
{
    gchar buf[SMALL];
    GtkWidget *entry_definitions_file;

    main_window =
	create_editor_window();

    sprintf(buf, "Bygfoot %s -- Team Editor", VERS);
    gtk_window_set_title(GTK_WINDOW(main_window), buf);

    gtk_widget_show(main_window);

    entry_definitions_file = 
	lookup_widget(main_window, "entry_definitions_file");

    my_team = 114;
    selected_player = 0;
    
    check_home_dir();

    sprintf(buf, "test -e %s/.bygfoot/text_files/teams", getenv("HOME"));

    if(system(buf) == 0)
    {
	sprintf(buf, "%s/.bygfoot/text_files/teams", getenv("HOME"));
	gtk_entry_set_text(GTK_ENTRY(entry_definitions_file), buf);
    }
    else
    {
	sprintf(buf, "The default team definitions file $HOME/.bygfoot/teams could not be loaded. Please specify a custom team definitions file with read/write permissions.");
	show_popup_window(buf, NULL);
    }

    set_teams_file_pulldown();

    callback_load_team_file();
    callback_load_team();
    callback_change_player(0);
}

/* show a window with a job offer and some info on the possible new team */
void
show_job_offer_window(gchar text[][SMALL])
{
    gint i;
    gchar buf[SMALL];
    GtkWidget *job_offer_window = create_job_offer_window();
    GtkWidget *treeview_player_list =
	lookup_widget(job_offer_window, "treeview_player_list");
    GtkWidget *text_labels[JOB_OFFER_END];

    sprintf(buf, "Bygfoot %s - Job Offer", VERS);
    gtk_window_set_title(GTK_WINDOW(job_offer_window), buf);

    for(i=0;i<JOB_OFFER_END;i++)
    {
	sprintf(buf, "label%d", 20 + i);
	text_labels[i] = lookup_widget(job_offer_window, buf);
	gtk_label_set_text(GTK_LABEL(text_labels[i]), text[i]);
    }

    show_team_browse(status % 1000, treeview_player_list);

    change_popups_active(1);

    gtk_widget_show(job_offer_window);
}

/* show the frontend for the update script */
void
start_update(void)
{
    gchar buf[SMALL];
    gchar buf2[SMALL];
    gchar buf3[SMALL];

    strcpy(buf, "");
    text_file_number_to_char(FILES_UPDATE_GUI, buf, TRUE);
    text_file_number_to_char(FILES_UPDATE_SCRIPT, buf2, TRUE);

    if(strlen(buf) == 0)
    {
	sprintf(buf2,
		"\nDidn't find the update script frontend. Perhaps you don't have the Bygfoot source version installed. Please refer to the Bygfoot homepage http://www.bygfoot.com to see whether there are new versions in your favourite package format available.\n\n");
	if(main_window == NULL)
	    g_print("%s", buf2);
	else
	    show_popup_window(buf2, NULL);

	return;
    }

    sprintf(buf3, "%s %s", buf, buf2);

    g_spawn_command_line_async(buf3, NULL);

    if(main_window != NULL)
	gtk_main_quit();

    return;
}

/* show graph window */
GtkWidget*
show_graph_window(void)
{
    GtkWidget *window = create_graph_window();
    gchar buf[SMALL];
    
    sprintf(buf, "Bygfoot Football Manager %s", VERS);
    gtk_window_set_title(GTK_WINDOW(window), buf);

    change_popups_active(1);
    gtk_widget_show(window);

    return window;
}
