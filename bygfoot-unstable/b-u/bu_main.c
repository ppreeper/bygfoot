/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "bygfoot-update.h"
#include "bu_interface.h"
#include "bu_support.h"
#include "bu_functions.h"

void
bu_init(void)
{
    GtkWidget *textview = 
	lookup_widget(update_window, "textview");
    GtkTextBuffer *textbuffer =
        gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
    GtkWidget *entry_packdir = 
	lookup_widget(update_window, "entry_packdir");
    GtkWidget *entry_tmpdir = 
	lookup_widget(update_window, "entry_tmpdir");
    GtkWidget *entry_countrydir = 
	lookup_widget(update_window, "entry_countrydir");
    GString *text = 
	g_string_new("");
    gchar buf[SMALL];
    
    g_string_printf(text, "NOTE: This GUI uses the 'bygfoot-update' shell script to manage things, an since mixing the shell and the GUI is a rather messy thing, I recommend you use the script itself to manage your updates.\n\n");
    
    g_string_append_printf(text, "NOTE 2: If the program hangs for a long while, the reason could be that wget can't establish connection to the website. Check http://bygfoot.sourceforge.net to find out.\n");

    gtk_text_buffer_insert_at_cursor(textbuffer,
				     text->str, -1);
    g_string_free(text, TRUE);

    sprintf(buf, "%s", getenv("PWD"));
    gtk_entry_set_text(GTK_ENTRY(entry_packdir), buf);
    gtk_entry_set_text(GTK_ENTRY(entry_tmpdir), "/tmp");

    sprintf(buf, "%s/.bygfoot/text_files", getenv("HOME"));
    gtk_entry_set_text(GTK_ENTRY(entry_countrydir), buf);   
    
    gtk_widget_show(update_window);

    status = STATUS_NORMAL;
}

gint
main (gint argc, gchar *argv[])
{

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  update_script = g_string_new("");
  command_line = g_string_new("");

  if(g_file_test("./bygfoot-update", G_FILE_TEST_EXISTS))
      g_string_printf(update_script, "%s/bygfoot-update", g_getenv("PWD"));
  else
      g_string_printf(update_script, "bygfoot-update");
  
  gtk_set_locale ();
  gtk_init (&argc, &argv);

  update_window = create_update_window();

  bu_init();

  gtk_main ();

  g_string_free(update_script, TRUE);
  g_string_free(command_line, TRUE);

  return 0;
}
