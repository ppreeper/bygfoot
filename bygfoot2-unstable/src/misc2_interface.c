/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "misc2_callbacks.h"
#include "misc2_interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_window_job_offer (void)
{
  GtkWidget *window_job_offer;
  GtkWidget *vbox5;
  GtkWidget *label_text;
  GtkWidget *hseparator5;
  GtkWidget *hbox5;
  GtkWidget *vbox6;
  GtkWidget *label15;
  GtkWidget *label16;
  GtkWidget *label17;
  GtkWidget *label18;
  GtkWidget *label19;
  GtkWidget *label14;
  GtkWidget *vseparator3;
  GtkWidget *vbox7;
  GtkWidget *label_name;
  GtkWidget *label_league;
  GtkWidget *label_rank;
  GtkWidget *label_money;
  GtkWidget *label_cap;
  GtkWidget *label_saf;
  GtkWidget *hseparator6;
  GtkWidget *label28;
  GtkWidget *hbox17;
  GtkWidget *label42;
  GtkWidget *label_average_skill;
  GtkWidget *scrolledwindow1;
  GtkWidget *treeview_players;
  GtkWidget *hseparator7;
  GtkWidget *label_text2;
  GtkWidget *hbox6;
  GtkWidget *button_ok;
  GtkWidget *alignment5;
  GtkWidget *hbox9;
  GtkWidget *image5;
  GtkWidget *label31;
  GtkWidget *button_cancel;
  GtkWidget *alignment4;
  GtkWidget *hbox8;
  GtkWidget *image4;
  GtkWidget *label30;

  window_job_offer = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width (GTK_CONTAINER (window_job_offer), 6);
  gtk_window_set_title (GTK_WINDOW (window_job_offer), _("Job offer"));
  gtk_window_set_position (GTK_WINDOW (window_job_offer), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size (GTK_WINDOW (window_job_offer), -1, 600);

  vbox5 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox5);
  gtk_container_add (GTK_CONTAINER (window_job_offer), vbox5);

  label_text = gtk_label_new (_("label20"));
  gtk_widget_show (label_text);
  gtk_box_pack_start (GTK_BOX (vbox5), label_text, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label_text), GTK_JUSTIFY_LEFT);
  gtk_label_set_line_wrap (GTK_LABEL (label_text), TRUE);

  hseparator5 = gtk_hseparator_new ();
  gtk_widget_show (hseparator5);
  gtk_box_pack_start (GTK_BOX (vbox5), hseparator5, FALSE, TRUE, 0);
  gtk_widget_set_size_request (hseparator5, 1, 10);

  hbox5 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox5);
  gtk_box_pack_start (GTK_BOX (vbox5), hbox5, FALSE, TRUE, 0);

  vbox6 = gtk_vbox_new (FALSE, 3);
  gtk_widget_show (vbox6);
  gtk_box_pack_start (GTK_BOX (hbox5), vbox6, FALSE, TRUE, 0);

  label15 = gtk_label_new (_("Name"));
  gtk_widget_show (label15);
  gtk_box_pack_start (GTK_BOX (vbox6), label15, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label15), GTK_JUSTIFY_LEFT);
  gtk_misc_set_alignment (GTK_MISC (label15), 2.23517e-10, 0.5);

  label16 = gtk_label_new (_("League"));
  gtk_widget_show (label16);
  gtk_box_pack_start (GTK_BOX (vbox6), label16, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label16), GTK_JUSTIFY_LEFT);
  gtk_misc_set_alignment (GTK_MISC (label16), 2.23517e-10, 0.5);

  label17 = gtk_label_new (_("Rank"));
  gtk_widget_show (label17);
  gtk_box_pack_start (GTK_BOX (vbox6), label17, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label17), GTK_JUSTIFY_LEFT);
  gtk_misc_set_alignment (GTK_MISC (label17), 2.23517e-10, 0.5);

  label18 = gtk_label_new (_("Money (approx.)"));
  gtk_widget_show (label18);
  gtk_box_pack_start (GTK_BOX (vbox6), label18, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label18), GTK_JUSTIFY_LEFT);
  gtk_misc_set_alignment (GTK_MISC (label18), 2.23517e-10, 0.5);

  label19 = gtk_label_new (_("Stadium capacity"));
  gtk_widget_show (label19);
  gtk_box_pack_start (GTK_BOX (vbox6), label19, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label19), GTK_JUSTIFY_LEFT);
  gtk_misc_set_alignment (GTK_MISC (label19), 2.23517e-10, 0.5);

  label14 = gtk_label_new (_("Stadium safety"));
  gtk_widget_show (label14);
  gtk_box_pack_start (GTK_BOX (vbox6), label14, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label14), GTK_JUSTIFY_LEFT);
  gtk_misc_set_alignment (GTK_MISC (label14), 0, 0.5);

  vseparator3 = gtk_vseparator_new ();
  gtk_widget_show (vseparator3);
  gtk_box_pack_start (GTK_BOX (hbox5), vseparator3, FALSE, TRUE, 0);
  gtk_widget_set_size_request (vseparator3, 10, 1);

  vbox7 = gtk_vbox_new (FALSE, 3);
  gtk_widget_show (vbox7);
  gtk_box_pack_start (GTK_BOX (hbox5), vbox7, TRUE, TRUE, 0);

  label_name = gtk_label_new (_("label21"));
  gtk_widget_show (label_name);
  gtk_box_pack_start (GTK_BOX (vbox7), label_name, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label_name), GTK_JUSTIFY_LEFT);

  label_league = gtk_label_new (_("label22"));
  gtk_widget_show (label_league);
  gtk_box_pack_start (GTK_BOX (vbox7), label_league, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label_league), GTK_JUSTIFY_LEFT);

  label_rank = gtk_label_new (_("label23"));
  gtk_widget_show (label_rank);
  gtk_box_pack_start (GTK_BOX (vbox7), label_rank, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label_rank), GTK_JUSTIFY_LEFT);

  label_money = gtk_label_new (_("label24"));
  gtk_widget_show (label_money);
  gtk_box_pack_start (GTK_BOX (vbox7), label_money, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label_money), GTK_JUSTIFY_LEFT);

  label_cap = gtk_label_new (_("label25"));
  gtk_widget_show (label_cap);
  gtk_box_pack_start (GTK_BOX (vbox7), label_cap, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label_cap), GTK_JUSTIFY_LEFT);

  label_saf = gtk_label_new (_("label26"));
  gtk_widget_show (label_saf);
  gtk_box_pack_start (GTK_BOX (vbox7), label_saf, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label_saf), GTK_JUSTIFY_LEFT);

  hseparator6 = gtk_hseparator_new ();
  gtk_widget_show (hseparator6);
  gtk_box_pack_start (GTK_BOX (vbox5), hseparator6, FALSE, TRUE, 0);
  gtk_widget_set_size_request (hseparator6, 1, 10);

  label28 = gtk_label_new (_("Player list"));
  gtk_widget_show (label28);
  gtk_box_pack_start (GTK_BOX (vbox5), label28, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label28), GTK_JUSTIFY_LEFT);

  hbox17 = gtk_hbox_new (FALSE, 5);
  gtk_widget_show (hbox17);
  gtk_box_pack_start (GTK_BOX (vbox5), hbox17, FALSE, FALSE, 0);

  label42 = gtk_label_new (_("Average skill:"));
  gtk_widget_show (label42);
  gtk_box_pack_start (GTK_BOX (hbox17), label42, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label42), GTK_JUSTIFY_LEFT);

  label_average_skill = gtk_label_new (_("label43"));
  gtk_widget_show (label_average_skill);
  gtk_box_pack_start (GTK_BOX (hbox17), label_average_skill, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label_average_skill), GTK_JUSTIFY_LEFT);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow1);
  gtk_box_pack_start (GTK_BOX (vbox5), scrolledwindow1, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (scrolledwindow1), 4);

  treeview_players = gtk_tree_view_new ();
  gtk_widget_show (treeview_players);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), treeview_players);

  hseparator7 = gtk_hseparator_new ();
  gtk_widget_show (hseparator7);
  gtk_box_pack_start (GTK_BOX (vbox5), hseparator7, FALSE, TRUE, 0);
  gtk_widget_set_size_request (hseparator7, 1, 10);

  label_text2 = gtk_label_new (_("label27"));
  gtk_widget_show (label_text2);
  gtk_box_pack_start (GTK_BOX (vbox5), label_text2, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label_text2), GTK_JUSTIFY_LEFT);
  gtk_misc_set_padding (GTK_MISC (label_text2), 0, 5);

  hbox6 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox6);
  gtk_box_pack_start (GTK_BOX (vbox5), hbox6, FALSE, TRUE, 0);

  button_ok = gtk_button_new ();
  gtk_widget_show (button_ok);
  gtk_box_pack_start (GTK_BOX (hbox6), button_ok, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (button_ok), 2);

  alignment5 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment5);
  gtk_container_add (GTK_CONTAINER (button_ok), alignment5);

  hbox9 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox9);
  gtk_container_add (GTK_CONTAINER (alignment5), hbox9);

  image5 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image5);
  gtk_box_pack_start (GTK_BOX (hbox9), image5, FALSE, FALSE, 0);

  label31 = gtk_label_new_with_mnemonic (_("OK"));
  gtk_widget_show (label31);
  gtk_box_pack_start (GTK_BOX (hbox9), label31, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label31), GTK_JUSTIFY_LEFT);

  button_cancel = gtk_button_new ();
  gtk_widget_show (button_cancel);
  gtk_box_pack_start (GTK_BOX (hbox6), button_cancel, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (button_cancel), 2);

  alignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment4);
  gtk_container_add (GTK_CONTAINER (button_cancel), alignment4);

  hbox8 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox8);
  gtk_container_add (GTK_CONTAINER (alignment4), hbox8);

  image4 = gtk_image_new_from_stock ("gtk-cancel", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image4);
  gtk_box_pack_start (GTK_BOX (hbox8), image4, FALSE, FALSE, 0);

  label30 = gtk_label_new_with_mnemonic (_("Cancel"));
  gtk_widget_show (label30);
  gtk_box_pack_start (GTK_BOX (hbox8), label30, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label30), GTK_JUSTIFY_LEFT);

  g_signal_connect ((gpointer) button_ok, "clicked",
                    G_CALLBACK (on_button_offer_ok_clicked),
                    NULL);
  g_signal_connect ((gpointer) button_cancel, "clicked",
                    G_CALLBACK (on_button_offer_cancel_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window_job_offer, window_job_offer, "window_job_offer");
  GLADE_HOOKUP_OBJECT (window_job_offer, vbox5, "vbox5");
  GLADE_HOOKUP_OBJECT (window_job_offer, label_text, "label_text");
  GLADE_HOOKUP_OBJECT (window_job_offer, hseparator5, "hseparator5");
  GLADE_HOOKUP_OBJECT (window_job_offer, hbox5, "hbox5");
  GLADE_HOOKUP_OBJECT (window_job_offer, vbox6, "vbox6");
  GLADE_HOOKUP_OBJECT (window_job_offer, label15, "label15");
  GLADE_HOOKUP_OBJECT (window_job_offer, label16, "label16");
  GLADE_HOOKUP_OBJECT (window_job_offer, label17, "label17");
  GLADE_HOOKUP_OBJECT (window_job_offer, label18, "label18");
  GLADE_HOOKUP_OBJECT (window_job_offer, label19, "label19");
  GLADE_HOOKUP_OBJECT (window_job_offer, label14, "label14");
  GLADE_HOOKUP_OBJECT (window_job_offer, vseparator3, "vseparator3");
  GLADE_HOOKUP_OBJECT (window_job_offer, vbox7, "vbox7");
  GLADE_HOOKUP_OBJECT (window_job_offer, label_name, "label_name");
  GLADE_HOOKUP_OBJECT (window_job_offer, label_league, "label_league");
  GLADE_HOOKUP_OBJECT (window_job_offer, label_rank, "label_rank");
  GLADE_HOOKUP_OBJECT (window_job_offer, label_money, "label_money");
  GLADE_HOOKUP_OBJECT (window_job_offer, label_cap, "label_cap");
  GLADE_HOOKUP_OBJECT (window_job_offer, label_saf, "label_saf");
  GLADE_HOOKUP_OBJECT (window_job_offer, hseparator6, "hseparator6");
  GLADE_HOOKUP_OBJECT (window_job_offer, label28, "label28");
  GLADE_HOOKUP_OBJECT (window_job_offer, hbox17, "hbox17");
  GLADE_HOOKUP_OBJECT (window_job_offer, label42, "label42");
  GLADE_HOOKUP_OBJECT (window_job_offer, label_average_skill, "label_average_skill");
  GLADE_HOOKUP_OBJECT (window_job_offer, scrolledwindow1, "scrolledwindow1");
  GLADE_HOOKUP_OBJECT (window_job_offer, treeview_players, "treeview_players");
  GLADE_HOOKUP_OBJECT (window_job_offer, hseparator7, "hseparator7");
  GLADE_HOOKUP_OBJECT (window_job_offer, label_text2, "label_text2");
  GLADE_HOOKUP_OBJECT (window_job_offer, hbox6, "hbox6");
  GLADE_HOOKUP_OBJECT (window_job_offer, button_ok, "button_ok");
  GLADE_HOOKUP_OBJECT (window_job_offer, alignment5, "alignment5");
  GLADE_HOOKUP_OBJECT (window_job_offer, hbox9, "hbox9");
  GLADE_HOOKUP_OBJECT (window_job_offer, image5, "image5");
  GLADE_HOOKUP_OBJECT (window_job_offer, label31, "label31");
  GLADE_HOOKUP_OBJECT (window_job_offer, button_cancel, "button_cancel");
  GLADE_HOOKUP_OBJECT (window_job_offer, alignment4, "alignment4");
  GLADE_HOOKUP_OBJECT (window_job_offer, hbox8, "hbox8");
  GLADE_HOOKUP_OBJECT (window_job_offer, image4, "image4");
  GLADE_HOOKUP_OBJECT (window_job_offer, label30, "label30");

  return window_job_offer;
}

GtkWidget*
create_window_progress (void)
{
  GtkWidget *window_progress;
  GtkWidget *progressbar;

  window_progress = gtk_window_new (GTK_WINDOW_POPUP);
  gtk_window_set_title (GTK_WINDOW (window_progress), _("window1"));
  gtk_window_set_position (GTK_WINDOW (window_progress), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (window_progress), TRUE);

  progressbar = gtk_progress_bar_new ();
  gtk_widget_show (progressbar);
  gtk_container_add (GTK_CONTAINER (window_progress), progressbar);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window_progress, window_progress, "window_progress");
  GLADE_HOOKUP_OBJECT (window_progress, progressbar, "progressbar");

  return window_progress;
}

GtkWidget*
create_window_warning (void)
{
  GtkWidget *window_warning;
  GtkWidget *vbox13;
  GtkWidget *image7;
  GtkWidget *label_warning;
  GtkWidget *button_warning;

  window_warning = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width (GTK_CONTAINER (window_warning), 10);
  gtk_window_set_title (GTK_WINDOW (window_warning), _("window1"));
  gtk_window_set_position (GTK_WINDOW (window_warning), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (window_warning), TRUE);

  vbox13 = gtk_vbox_new (FALSE, 10);
  gtk_widget_show (vbox13);
  gtk_container_add (GTK_CONTAINER (window_warning), vbox13);

  image7 = gtk_image_new_from_stock ("gtk-dialog-warning", GTK_ICON_SIZE_DIALOG);
  gtk_widget_show (image7);
  gtk_box_pack_start (GTK_BOX (vbox13), image7, FALSE, TRUE, 0);

  label_warning = gtk_label_new (_("label42"));
  gtk_widget_show (label_warning);
  gtk_box_pack_start (GTK_BOX (vbox13), label_warning, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label_warning), GTK_JUSTIFY_LEFT);
  gtk_label_set_line_wrap (GTK_LABEL (label_warning), TRUE);

  button_warning = gtk_button_new_from_stock ("gtk-close");
  gtk_widget_show (button_warning);
  gtk_box_pack_start (GTK_BOX (vbox13), button_warning, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) window_warning, "delete_event",
                    G_CALLBACK (on_button_warning_clicked),
                    NULL);
  g_signal_connect ((gpointer) window_warning, "destroy_event",
                    G_CALLBACK (on_button_warning_clicked),
                    NULL);
  g_signal_connect ((gpointer) button_warning, "clicked",
                    G_CALLBACK (on_button_warning_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window_warning, window_warning, "window_warning");
  GLADE_HOOKUP_OBJECT (window_warning, vbox13, "vbox13");
  GLADE_HOOKUP_OBJECT (window_warning, image7, "image7");
  GLADE_HOOKUP_OBJECT (window_warning, label_warning, "label_warning");
  GLADE_HOOKUP_OBJECT (window_warning, button_warning, "button_warning");

  return window_warning;
}

GtkWidget*
create_window_digits (void)
{
  GtkWidget *window_digits;
  GtkWidget *vbox14;
  GtkWidget *label_main;
  GtkWidget *hbox15;
  GtkWidget *vbox15;
  GtkWidget *label_1;
  GtkObject *spinbutton1_adj;
  GtkWidget *spinbutton1;
  GtkWidget *vbox16;
  GtkWidget *label_2;
  GtkObject *spinbutton2_adj;
  GtkWidget *spinbutton2;
  GtkWidget *hbox16;
  GtkWidget *button_digits_ok;
  GtkWidget *button_digits_cancel;
  GtkAccelGroup *accel_group;
  GtkTooltips *tooltips;

  tooltips = gtk_tooltips_new ();

  accel_group = gtk_accel_group_new ();

  window_digits = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width (GTK_CONTAINER (window_digits), 5);
  gtk_window_set_title (GTK_WINDOW (window_digits), _("window1"));
  gtk_window_set_position (GTK_WINDOW (window_digits), GTK_WIN_POS_CENTER);

  vbox14 = gtk_vbox_new (FALSE, 10);
  gtk_widget_show (vbox14);
  gtk_container_add (GTK_CONTAINER (window_digits), vbox14);

  label_main = gtk_label_new (_("label42"));
  gtk_widget_show (label_main);
  gtk_box_pack_start (GTK_BOX (vbox14), label_main, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label_main), GTK_JUSTIFY_LEFT);
  gtk_label_set_line_wrap (GTK_LABEL (label_main), TRUE);

  hbox15 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox15);
  gtk_box_pack_start (GTK_BOX (vbox14), hbox15, FALSE, TRUE, 0);

  vbox15 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox15);
  gtk_box_pack_start (GTK_BOX (hbox15), vbox15, TRUE, TRUE, 0);

  label_1 = gtk_label_new (_("label43"));
  gtk_widget_show (label_1);
  gtk_box_pack_start (GTK_BOX (vbox15), label_1, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label_1), GTK_JUSTIFY_LEFT);

  spinbutton1_adj = gtk_adjustment_new (1, 0, 1e+08, 10, 1000, 10);
  spinbutton1 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton1_adj), 1, 0);
  gtk_widget_show (spinbutton1);
  gtk_box_pack_start (GTK_BOX (vbox15), spinbutton1, FALSE, FALSE, 0);
  gtk_spin_button_set_numeric (GTK_SPIN_BUTTON (spinbutton1), TRUE);

  vbox16 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox16);
  gtk_box_pack_start (GTK_BOX (hbox15), vbox16, TRUE, TRUE, 0);

  label_2 = gtk_label_new (_("label44"));
  gtk_widget_show (label_2);
  gtk_box_pack_start (GTK_BOX (vbox16), label_2, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label_2), GTK_JUSTIFY_LEFT);

  spinbutton2_adj = gtk_adjustment_new (1, 0, 1e+08, 1, 100, 10);
  spinbutton2 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton2_adj), 1, 0);
  gtk_widget_show (spinbutton2);
  gtk_box_pack_start (GTK_BOX (vbox16), spinbutton2, FALSE, FALSE, 0);
  gtk_spin_button_set_numeric (GTK_SPIN_BUTTON (spinbutton2), TRUE);

  hbox16 = gtk_hbox_new (FALSE, 3);
  gtk_widget_show (hbox16);
  gtk_box_pack_start (GTK_BOX (vbox14), hbox16, FALSE, TRUE, 0);

  button_digits_ok = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (button_digits_ok);
  gtk_box_pack_start (GTK_BOX (hbox16), button_digits_ok, TRUE, TRUE, 0);
  gtk_tooltips_set_tip (tooltips, button_digits_ok, _("Return"), NULL);
  gtk_widget_add_accelerator (button_digits_ok, "clicked", accel_group,
                              GDK_Return, 0,
                              GTK_ACCEL_VISIBLE);

  button_digits_cancel = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (button_digits_cancel);
  gtk_box_pack_start (GTK_BOX (hbox16), button_digits_cancel, TRUE, TRUE, 0);
  gtk_tooltips_set_tip (tooltips, button_digits_cancel, _("Esc"), NULL);
  gtk_widget_add_accelerator (button_digits_cancel, "clicked", accel_group,
                              GDK_Escape, 0,
                              GTK_ACCEL_VISIBLE);

  g_signal_connect ((gpointer) button_digits_ok, "clicked",
                    G_CALLBACK (on_button_digits_ok_clicked),
                    NULL);
  g_signal_connect ((gpointer) button_digits_cancel, "clicked",
                    G_CALLBACK (on_button_digits_cancel_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window_digits, window_digits, "window_digits");
  GLADE_HOOKUP_OBJECT (window_digits, vbox14, "vbox14");
  GLADE_HOOKUP_OBJECT (window_digits, label_main, "label_main");
  GLADE_HOOKUP_OBJECT (window_digits, hbox15, "hbox15");
  GLADE_HOOKUP_OBJECT (window_digits, vbox15, "vbox15");
  GLADE_HOOKUP_OBJECT (window_digits, label_1, "label_1");
  GLADE_HOOKUP_OBJECT (window_digits, spinbutton1, "spinbutton1");
  GLADE_HOOKUP_OBJECT (window_digits, vbox16, "vbox16");
  GLADE_HOOKUP_OBJECT (window_digits, label_2, "label_2");
  GLADE_HOOKUP_OBJECT (window_digits, spinbutton2, "spinbutton2");
  GLADE_HOOKUP_OBJECT (window_digits, hbox16, "hbox16");
  GLADE_HOOKUP_OBJECT (window_digits, button_digits_ok, "button_digits_ok");
  GLADE_HOOKUP_OBJECT (window_digits, button_digits_cancel, "button_digits_cancel");
  GLADE_HOOKUP_OBJECT_NO_REF (window_digits, tooltips, "tooltips");

  gtk_window_add_accel_group (GTK_WINDOW (window_digits), accel_group);

  return window_digits;
}

GtkWidget*
create_window_yesno (void)
{
  GtkWidget *window_yesno;
  GtkWidget *vbox17;
  GtkWidget *image8;
  GtkWidget *label_yesno;
  GtkWidget *checkbutton_yesno;
  GtkWidget *hbox18;
  GtkWidget *button_yesno_yes;
  GtkWidget *button_yesno_no;

  window_yesno = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width (GTK_CONTAINER (window_yesno), 5);
  gtk_window_set_title (GTK_WINDOW (window_yesno), _("window1"));
  gtk_window_set_position (GTK_WINDOW (window_yesno), GTK_WIN_POS_CENTER);

  vbox17 = gtk_vbox_new (FALSE, 3);
  gtk_widget_show (vbox17);
  gtk_container_add (GTK_CONTAINER (window_yesno), vbox17);

  image8 = gtk_image_new_from_stock ("gtk-dialog-question", GTK_ICON_SIZE_DIALOG);
  gtk_widget_show (image8);
  gtk_box_pack_start (GTK_BOX (vbox17), image8, FALSE, FALSE, 0);

  label_yesno = gtk_label_new (_("label43"));
  gtk_widget_show (label_yesno);
  gtk_box_pack_start (GTK_BOX (vbox17), label_yesno, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label_yesno), GTK_JUSTIFY_LEFT);
  gtk_label_set_line_wrap (GTK_LABEL (label_yesno), TRUE);

  checkbutton_yesno = gtk_check_button_new_with_mnemonic (_("Don't bother me with this next time."));
  gtk_widget_show (checkbutton_yesno);
  gtk_box_pack_start (GTK_BOX (vbox17), checkbutton_yesno, FALSE, FALSE, 0);

  hbox18 = gtk_hbox_new (FALSE, 3);
  gtk_widget_show (hbox18);
  gtk_box_pack_start (GTK_BOX (vbox17), hbox18, FALSE, FALSE, 0);

  button_yesno_yes = gtk_button_new_from_stock ("gtk-yes");
  gtk_widget_show (button_yesno_yes);
  gtk_box_pack_start (GTK_BOX (hbox18), button_yesno_yes, TRUE, TRUE, 0);

  button_yesno_no = gtk_button_new_from_stock ("gtk-no");
  gtk_widget_show (button_yesno_no);
  gtk_box_pack_start (GTK_BOX (hbox18), button_yesno_no, TRUE, TRUE, 0);

  g_signal_connect ((gpointer) window_yesno, "delete_event",
                    G_CALLBACK (on_window_yesno_delete_event),
                    NULL);
  g_signal_connect ((gpointer) checkbutton_yesno, "toggled",
                    G_CALLBACK (on_checkbutton_yesno_toggled),
                    NULL);
  g_signal_connect ((gpointer) button_yesno_yes, "clicked",
                    G_CALLBACK (on_button_yesno_yes_clicked),
                    NULL);
  g_signal_connect ((gpointer) button_yesno_no, "clicked",
                    G_CALLBACK (on_button_yesno_no_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window_yesno, window_yesno, "window_yesno");
  GLADE_HOOKUP_OBJECT (window_yesno, vbox17, "vbox17");
  GLADE_HOOKUP_OBJECT (window_yesno, image8, "image8");
  GLADE_HOOKUP_OBJECT (window_yesno, label_yesno, "label_yesno");
  GLADE_HOOKUP_OBJECT (window_yesno, checkbutton_yesno, "checkbutton_yesno");
  GLADE_HOOKUP_OBJECT (window_yesno, hbox18, "hbox18");
  GLADE_HOOKUP_OBJECT (window_yesno, button_yesno_yes, "button_yesno_yes");
  GLADE_HOOKUP_OBJECT (window_yesno, button_yesno_no, "button_yesno_no");

  return window_yesno;
}

GtkWidget*
create_window_contract (void)
{
  GtkWidget *window_contract;
  GtkWidget *vbox18;
  GtkWidget *image9;
  GtkWidget *label_contract;
  GtkWidget *table1;
  GtkWidget *radiobutton_contract1;
  GSList *radiobutton_contract1_group = NULL;
  GtkWidget *radiobutton_contract3;
  GtkWidget *radiobutton_contract4;
  GtkWidget *radiobutton_contract2;
  GtkObject *spinbutton_contract1_adj;
  GtkWidget *spinbutton_contract1;
  GtkObject *spinbutton_contract2_adj;
  GtkWidget *spinbutton_contract2;
  GtkObject *spinbutton_contract3_adj;
  GtkWidget *spinbutton_contract3;
  GtkObject *spinbutton_contract4_adj;
  GtkWidget *spinbutton_contract4;
  GtkWidget *hseparator8;
  GtkWidget *hbox19;
  GtkWidget *button_contract_offer;
  GtkWidget *alignment6;
  GtkWidget *hbox20;
  GtkWidget *image10;
  GtkWidget *label44;

  window_contract = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width (GTK_CONTAINER (window_contract), 5);
  gtk_window_set_title (GTK_WINDOW (window_contract), _("window1"));
  gtk_window_set_position (GTK_WINDOW (window_contract), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (window_contract), TRUE);

  vbox18 = gtk_vbox_new (FALSE, 3);
  gtk_widget_show (vbox18);
  gtk_container_add (GTK_CONTAINER (window_contract), vbox18);

  image9 = gtk_image_new_from_stock ("gtk-new", GTK_ICON_SIZE_DIALOG);
  gtk_widget_show (image9);
  gtk_box_pack_start (GTK_BOX (vbox18), image9, FALSE, FALSE, 0);

  label_contract = gtk_label_new (_("label43"));
  gtk_widget_show (label_contract);
  gtk_box_pack_start (GTK_BOX (vbox18), label_contract, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label_contract), GTK_JUSTIFY_LEFT);
  gtk_label_set_line_wrap (GTK_LABEL (label_contract), TRUE);

  table1 = gtk_table_new (4, 2, FALSE);
  gtk_widget_show (table1);
  gtk_box_pack_start (GTK_BOX (vbox18), table1, FALSE, FALSE, 0);
  gtk_table_set_col_spacings (GTK_TABLE (table1), 3);

  radiobutton_contract1 = gtk_radio_button_new_with_mnemonic (NULL, _("1 year"));
  gtk_widget_show (radiobutton_contract1);
  gtk_table_attach (GTK_TABLE (table1), radiobutton_contract1, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton_contract1), radiobutton_contract1_group);
  radiobutton_contract1_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton_contract1));

  radiobutton_contract3 = gtk_radio_button_new_with_mnemonic (NULL, _("3 years"));
  gtk_widget_show (radiobutton_contract3);
  gtk_table_attach (GTK_TABLE (table1), radiobutton_contract3, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton_contract3), radiobutton_contract1_group);
  radiobutton_contract1_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton_contract3));

  radiobutton_contract4 = gtk_radio_button_new_with_mnemonic (NULL, _("4 years"));
  gtk_widget_show (radiobutton_contract4);
  gtk_table_attach (GTK_TABLE (table1), radiobutton_contract4, 0, 1, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton_contract4), radiobutton_contract1_group);
  radiobutton_contract1_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton_contract4));

  radiobutton_contract2 = gtk_radio_button_new_with_mnemonic (NULL, _("2 years"));
  gtk_widget_show (radiobutton_contract2);
  gtk_table_attach (GTK_TABLE (table1), radiobutton_contract2, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton_contract2), radiobutton_contract1_group);
  radiobutton_contract1_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton_contract2));
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (radiobutton_contract2), TRUE);

  spinbutton_contract1_adj = gtk_adjustment_new (1, 1, 100000, 1, 100, 10);
  spinbutton_contract1 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton_contract1_adj), 1, 0);
  gtk_widget_show (spinbutton_contract1);
  gtk_table_attach (GTK_TABLE (table1), spinbutton_contract1, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_spin_button_set_numeric (GTK_SPIN_BUTTON (spinbutton_contract1), TRUE);

  spinbutton_contract2_adj = gtk_adjustment_new (1, 1, 100000, 1, 100, 10);
  spinbutton_contract2 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton_contract2_adj), 1, 0);
  gtk_widget_show (spinbutton_contract2);
  gtk_table_attach (GTK_TABLE (table1), spinbutton_contract2, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  spinbutton_contract3_adj = gtk_adjustment_new (1, 1, 100000, 1, 100, 10);
  spinbutton_contract3 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton_contract3_adj), 1, 0);
  gtk_widget_show (spinbutton_contract3);
  gtk_table_attach (GTK_TABLE (table1), spinbutton_contract3, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  spinbutton_contract4_adj = gtk_adjustment_new (1, 1, 100000, 1, 100, 10);
  spinbutton_contract4 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton_contract4_adj), 1, 0);
  gtk_widget_show (spinbutton_contract4);
  gtk_table_attach (GTK_TABLE (table1), spinbutton_contract4, 1, 2, 3, 4,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  hseparator8 = gtk_hseparator_new ();
  gtk_widget_show (hseparator8);
  gtk_box_pack_start (GTK_BOX (vbox18), hseparator8, FALSE, FALSE, 0);
  gtk_widget_set_size_request (hseparator8, 1, 10);

  hbox19 = gtk_hbox_new (FALSE, 3);
  gtk_widget_show (hbox19);
  gtk_box_pack_start (GTK_BOX (vbox18), hbox19, FALSE, FALSE, 0);

  button_contract_offer = gtk_button_new ();
  gtk_widget_show (button_contract_offer);
  gtk_box_pack_start (GTK_BOX (hbox19), button_contract_offer, TRUE, TRUE, 0);

  alignment6 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment6);
  gtk_container_add (GTK_CONTAINER (button_contract_offer), alignment6);

  hbox20 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox20);
  gtk_container_add (GTK_CONTAINER (alignment6), hbox20);

  image10 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image10);
  gtk_box_pack_start (GTK_BOX (hbox20), image10, FALSE, FALSE, 0);

  label44 = gtk_label_new_with_mnemonic (_("Make offer"));
  gtk_widget_show (label44);
  gtk_box_pack_start (GTK_BOX (hbox20), label44, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label44), GTK_JUSTIFY_LEFT);

  g_signal_connect ((gpointer) window_contract, "delete_event",
                    G_CALLBACK (on_window_contract_delete_event),
                    NULL);
  g_signal_connect ((gpointer) button_contract_offer, "clicked",
                    G_CALLBACK (on_button_contract_offer_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window_contract, window_contract, "window_contract");
  GLADE_HOOKUP_OBJECT (window_contract, vbox18, "vbox18");
  GLADE_HOOKUP_OBJECT (window_contract, image9, "image9");
  GLADE_HOOKUP_OBJECT (window_contract, label_contract, "label_contract");
  GLADE_HOOKUP_OBJECT (window_contract, table1, "table1");
  GLADE_HOOKUP_OBJECT (window_contract, radiobutton_contract1, "radiobutton_contract1");
  GLADE_HOOKUP_OBJECT (window_contract, radiobutton_contract3, "radiobutton_contract3");
  GLADE_HOOKUP_OBJECT (window_contract, radiobutton_contract4, "radiobutton_contract4");
  GLADE_HOOKUP_OBJECT (window_contract, radiobutton_contract2, "radiobutton_contract2");
  GLADE_HOOKUP_OBJECT (window_contract, spinbutton_contract1, "spinbutton_contract1");
  GLADE_HOOKUP_OBJECT (window_contract, spinbutton_contract2, "spinbutton_contract2");
  GLADE_HOOKUP_OBJECT (window_contract, spinbutton_contract3, "spinbutton_contract3");
  GLADE_HOOKUP_OBJECT (window_contract, spinbutton_contract4, "spinbutton_contract4");
  GLADE_HOOKUP_OBJECT (window_contract, hseparator8, "hseparator8");
  GLADE_HOOKUP_OBJECT (window_contract, hbox19, "hbox19");
  GLADE_HOOKUP_OBJECT (window_contract, button_contract_offer, "button_contract_offer");
  GLADE_HOOKUP_OBJECT (window_contract, alignment6, "alignment6");
  GLADE_HOOKUP_OBJECT (window_contract, hbox20, "hbox20");
  GLADE_HOOKUP_OBJECT (window_contract, image10, "image10");
  GLADE_HOOKUP_OBJECT (window_contract, label44, "label44");

  return window_contract;
}

GtkWidget*
create_window_user_management (void)
{
  GtkWidget *window_user_management;
  GtkWidget *vbox19;
  GtkWidget *hbox23;
  GtkWidget *hpaned1;
  GtkWidget *vbox20;
  GtkWidget *label47;
  GtkWidget *scrolledwindow2;
  GtkWidget *viewport1;
  GtkWidget *treeview_user_management_users;
  GtkWidget *vbox21;
  GtkWidget *label46;
  GtkWidget *scrolledwindow3;
  GtkWidget *treeview_user_management_teams;
  GtkWidget *hbox21;
  GtkWidget *entry_user_management;
  GtkWidget *button_user_management_add;
  GtkWidget *alignment7;
  GtkWidget *hbox22;
  GtkWidget *image11;
  GtkWidget *label45;
  GtkWidget *hseparator9;
  GtkWidget *button_user_management_close;

  window_user_management = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width (GTK_CONTAINER (window_user_management), 5);
  gtk_window_set_title (GTK_WINDOW (window_user_management), _("window1"));
  gtk_window_set_position (GTK_WINDOW (window_user_management), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size (GTK_WINDOW (window_user_management), 600, 550);

  vbox19 = gtk_vbox_new (FALSE, 5);
  gtk_widget_show (vbox19);
  gtk_container_add (GTK_CONTAINER (window_user_management), vbox19);

  hbox23 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox23);
  gtk_box_pack_start (GTK_BOX (vbox19), hbox23, TRUE, TRUE, 0);

  hpaned1 = gtk_hpaned_new ();
  gtk_widget_show (hpaned1);
  gtk_box_pack_start (GTK_BOX (hbox23), hpaned1, TRUE, TRUE, 0);
  gtk_paned_set_position (GTK_PANED (hpaned1), 200);

  vbox20 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox20);
  gtk_paned_pack1 (GTK_PANED (hpaned1), vbox20, FALSE, TRUE);

  label47 = gtk_label_new (_("Users -- click to remove"));
  gtk_widget_show (label47);
  gtk_box_pack_start (GTK_BOX (vbox20), label47, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label47), GTK_JUSTIFY_LEFT);

  scrolledwindow2 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow2);
  gtk_box_pack_start (GTK_BOX (vbox20), scrolledwindow2, TRUE, TRUE, 0);

  viewport1 = gtk_viewport_new (NULL, NULL);
  gtk_widget_show (viewport1);
  gtk_container_add (GTK_CONTAINER (scrolledwindow2), viewport1);

  treeview_user_management_users = gtk_tree_view_new ();
  gtk_widget_show (treeview_user_management_users);
  gtk_container_add (GTK_CONTAINER (viewport1), treeview_user_management_users);

  vbox21 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox21);
  gtk_paned_pack2 (GTK_PANED (hpaned1), vbox21, TRUE, TRUE);

  label46 = gtk_label_new (_("Available teams"));
  gtk_widget_show (label46);
  gtk_box_pack_start (GTK_BOX (vbox21), label46, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label46), GTK_JUSTIFY_LEFT);

  scrolledwindow3 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow3);
  gtk_box_pack_start (GTK_BOX (vbox21), scrolledwindow3, TRUE, TRUE, 0);

  treeview_user_management_teams = gtk_tree_view_new ();
  gtk_widget_show (treeview_user_management_teams);
  gtk_container_add (GTK_CONTAINER (scrolledwindow3), treeview_user_management_teams);

  hbox21 = gtk_hbox_new (FALSE, 5);
  gtk_widget_show (hbox21);
  gtk_box_pack_start (GTK_BOX (vbox19), hbox21, FALSE, FALSE, 0);

  entry_user_management = gtk_entry_new ();
  gtk_widget_show (entry_user_management);
  gtk_box_pack_start (GTK_BOX (hbox21), entry_user_management, TRUE, TRUE, 0);

  button_user_management_add = gtk_button_new ();
  gtk_widget_show (button_user_management_add);
  gtk_box_pack_start (GTK_BOX (hbox21), button_user_management_add, FALSE, FALSE, 0);

  alignment7 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment7);
  gtk_container_add (GTK_CONTAINER (button_user_management_add), alignment7);

  hbox22 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox22);
  gtk_container_add (GTK_CONTAINER (alignment7), hbox22);

  image11 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image11);
  gtk_box_pack_start (GTK_BOX (hbox22), image11, FALSE, FALSE, 0);

  label45 = gtk_label_new_with_mnemonic (_("Add user"));
  gtk_widget_show (label45);
  gtk_box_pack_start (GTK_BOX (hbox22), label45, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label45), GTK_JUSTIFY_LEFT);

  hseparator9 = gtk_hseparator_new ();
  gtk_widget_show (hseparator9);
  gtk_box_pack_start (GTK_BOX (vbox19), hseparator9, FALSE, FALSE, 0);
  gtk_widget_set_size_request (hseparator9, 1, 10);

  button_user_management_close = gtk_button_new_from_stock ("gtk-close");
  gtk_widget_show (button_user_management_close);
  gtk_box_pack_start (GTK_BOX (vbox19), button_user_management_close, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) treeview_user_management_users, "button_press_event",
                    G_CALLBACK (on_treeview_user_management_users_button_press_event),
                    NULL);
  g_signal_connect ((gpointer) treeview_user_management_teams, "row_activated",
                    G_CALLBACK (on_treeview_user_management_teams_row_activated),
                    NULL);
  g_signal_connect ((gpointer) entry_user_management, "activate",
                    G_CALLBACK (on_entry_user_management_activate),
                    NULL);
  g_signal_connect ((gpointer) button_user_management_add, "clicked",
                    G_CALLBACK (on_button_user_management_add_clicked),
                    NULL);
  g_signal_connect ((gpointer) button_user_management_close, "clicked",
                    G_CALLBACK (on_button_user_management_close_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window_user_management, window_user_management, "window_user_management");
  GLADE_HOOKUP_OBJECT (window_user_management, vbox19, "vbox19");
  GLADE_HOOKUP_OBJECT (window_user_management, hbox23, "hbox23");
  GLADE_HOOKUP_OBJECT (window_user_management, hpaned1, "hpaned1");
  GLADE_HOOKUP_OBJECT (window_user_management, vbox20, "vbox20");
  GLADE_HOOKUP_OBJECT (window_user_management, label47, "label47");
  GLADE_HOOKUP_OBJECT (window_user_management, scrolledwindow2, "scrolledwindow2");
  GLADE_HOOKUP_OBJECT (window_user_management, viewport1, "viewport1");
  GLADE_HOOKUP_OBJECT (window_user_management, treeview_user_management_users, "treeview_user_management_users");
  GLADE_HOOKUP_OBJECT (window_user_management, vbox21, "vbox21");
  GLADE_HOOKUP_OBJECT (window_user_management, label46, "label46");
  GLADE_HOOKUP_OBJECT (window_user_management, scrolledwindow3, "scrolledwindow3");
  GLADE_HOOKUP_OBJECT (window_user_management, treeview_user_management_teams, "treeview_user_management_teams");
  GLADE_HOOKUP_OBJECT (window_user_management, hbox21, "hbox21");
  GLADE_HOOKUP_OBJECT (window_user_management, entry_user_management, "entry_user_management");
  GLADE_HOOKUP_OBJECT (window_user_management, button_user_management_add, "button_user_management_add");
  GLADE_HOOKUP_OBJECT (window_user_management, alignment7, "alignment7");
  GLADE_HOOKUP_OBJECT (window_user_management, hbox22, "hbox22");
  GLADE_HOOKUP_OBJECT (window_user_management, image11, "image11");
  GLADE_HOOKUP_OBJECT (window_user_management, label45, "label45");
  GLADE_HOOKUP_OBJECT (window_user_management, hseparator9, "hseparator9");
  GLADE_HOOKUP_OBJECT (window_user_management, button_user_management_close, "button_user_management_close");

  return window_user_management;
}

