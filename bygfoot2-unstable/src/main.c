/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#include <time.h>

#include "misc_callbacks.h"
#include "file.h"
#include "free.h"
#include "main.h"
#include "transfer_struct.h"
#include "variables.h"
#include "window.h"

/**
   Initialize some global variables. Most of them get nullified.
*/
void
main_init_variables(void)
{
    ligs = cps = NULL;
    country.name = country.symbol = country.sid = NULL;
    transfer_list = NULL;
    player_names = NULL;

    window.main = window.startup = window.startup_users =
	window.live = window.warning = NULL;
    
    live_game_temp.units = NULL;

    users = g_array_new(FALSE, FALSE, sizeof(User));
    transfer_list = g_array_new(FALSE, FALSE, sizeof(Transfer));

    constants.list = options.list = NULL;
    constants.datalist = options.datalist = NULL;

    popups_active = 0;
    selected_row[0] = selected_row[1] = -1;

    timeout_id = -1;

    file_load_conf_files();
}

/**
   Process the command line arguments and do some things
   that have to be done at the beginning (like initializing the
   random number generator).
   @param argc Number of command line arguments.
   @param argv Command line arguments array.
*/
void
main_init(gint argc, gchar *argv[])
{
    gchar buf[SMALL];
    gchar *pwd = g_get_current_dir();

    /* initialize the random nr generator */
    srandom((unsigned)time(NULL));

    file_add_support_directory_recursive(PACKAGE_DATA_DIR "/" PACKAGE "/support_files");  
    sprintf(buf, "%s/.bygfoot", g_get_home_dir());
    file_add_support_directory_recursive(buf);
    sprintf(buf, "%s/support_files", pwd);
    g_free(pwd);
    file_add_support_directory_recursive(buf);

    main_init_variables();
}

/**
   Initialize the GTK stuff and the gettext stuff.
   Start the game.
   @param argc Number of command line arguments.
   @param argv Command line arguments array.
*/
gint
main (gint argc, gchar *argv[])
{
    gint x_pos, y_pos;

#ifdef ENABLE_NLS
    bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
    bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
    textdomain (GETTEXT_PACKAGE);
#endif

    gtk_set_locale ();
    gtk_init (&argc, &argv);
  
    main_init(argc, argv);

    window_create(WINDOW_STARTUP_USERS);
    window_show_startup();
    gtk_window_get_position(GTK_WINDOW(window.startup), &x_pos, &y_pos);
    gtk_window_move(GTK_WINDOW(window.startup_users), x_pos,  y_pos);
    stat0 = STATUS_TEAM_SELECTION;
    /*d*/
    on_button_add_player_clicked(NULL, NULL);
    

    gtk_main ();

    main_exit_program(EXIT_OK, NULL);

    return 0;
}

/** Exit the program with the given exit code and message. Try to
    destroy all widgets and free all memory first.
    @param exit_code The number we return to the shell.
    @param exit_message The message we print.
    @return The exit code of the program. */
void
main_exit_program(gint exit_code, gchar *exit_message)
{
    if(gtk_main_level() > 0)
	gtk_main_quit();

    free_memory();
    
    if(exit_message != NULL)
	g_warning(exit_message);
    
    exit(exit_code);
}
