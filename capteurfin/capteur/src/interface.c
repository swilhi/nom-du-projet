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

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_gestion_capteur (void)
{
  GtkWidget *gestion_capteur;
  GtkWidget *fixed1;
  GtkWidget *treeview_capt;
  GtkWidget *image14;
  GtkWidget *image15;
  GtkWidget *supprimer_capt;
  GtkWidget *alignment3;
  GtkWidget *hbox3;
  GtkWidget *image3;
  GtkWidget *label14;
  GtkWidget *modifier_capt;
  GtkWidget *alignment2;
  GtkWidget *hbox2;
  GtkWidget *image2;
  GtkWidget *label13;
  GtkWidget *ajouter_capt;
  GtkWidget *alignment1;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *label12;
  GtkWidget *parametre_capt;
  GtkWidget *alignment4;
  GtkWidget *hbox4;
  GtkWidget *image4;
  GtkWidget *label15;
  GtkWidget *defect;
  GtkWidget *label105;

  gestion_capteur = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (gestion_capteur, 992, 432);
  gtk_window_set_title (GTK_WINDOW (gestion_capteur), _("gestion capteur"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (gestion_capteur), fixed1);

  treeview_capt = gtk_tree_view_new ();
  gtk_widget_show (treeview_capt);
  gtk_fixed_put (GTK_FIXED (fixed1), treeview_capt, 70, 65);
  gtk_widget_set_size_request (treeview_capt, 470, 210);

  image14 = create_pixmap (gestion_capteur, "1.png");
  gtk_widget_show (image14);
  gtk_fixed_put (GTK_FIXED (fixed1), image14, 0, 0);
  gtk_widget_set_size_request (image14, 1, 432);

  image15 = create_pixmap (gestion_capteur, "ameni1.png");
  gtk_widget_show (image15);
  gtk_fixed_put (GTK_FIXED (fixed1), image15, 0, 0);
  gtk_widget_set_size_request (image15, 992, 432);

  supprimer_capt = gtk_button_new ();
  gtk_widget_show (supprimer_capt);
  gtk_fixed_put (GTK_FIXED (fixed1), supprimer_capt, 376, 298);
  gtk_widget_set_size_request (supprimer_capt, 105, 50);

  alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment3);
  gtk_container_add (GTK_CONTAINER (supprimer_capt), alignment3);

  hbox3 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox3);
  gtk_container_add (GTK_CONTAINER (alignment3), hbox3);

  image3 = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image3);
  gtk_box_pack_start (GTK_BOX (hbox3), image3, FALSE, FALSE, 0);

  label14 = gtk_label_new_with_mnemonic (_("Supprimer "));
  gtk_widget_show (label14);
  gtk_box_pack_start (GTK_BOX (hbox3), label14, FALSE, FALSE, 0);

  modifier_capt = gtk_button_new ();
  gtk_widget_show (modifier_capt);
  gtk_fixed_put (GTK_FIXED (fixed1), modifier_capt, 222, 297);
  gtk_widget_set_size_request (modifier_capt, 105, 52);

  alignment2 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment2);
  gtk_container_add (GTK_CONTAINER (modifier_capt), alignment2);

  hbox2 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox2);
  gtk_container_add (GTK_CONTAINER (alignment2), hbox2);

  image2 = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image2);
  gtk_box_pack_start (GTK_BOX (hbox2), image2, FALSE, FALSE, 0);

  label13 = gtk_label_new_with_mnemonic (_("Modifier"));
  gtk_widget_show (label13);
  gtk_box_pack_start (GTK_BOX (hbox2), label13, FALSE, FALSE, 0);

  ajouter_capt = gtk_button_new ();
  gtk_widget_show (ajouter_capt);
  gtk_fixed_put (GTK_FIXED (fixed1), ajouter_capt, 65, 298);
  gtk_widget_set_size_request (ajouter_capt, 105, 50);

  alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (ajouter_capt), alignment1);

  hbox1 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (alignment1), hbox1);

  image1 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox1), image1, FALSE, FALSE, 0);

  label12 = gtk_label_new_with_mnemonic (_("Ajouter"));
  gtk_widget_show (label12);
  gtk_box_pack_start (GTK_BOX (hbox1), label12, FALSE, FALSE, 0);

  parametre_capt = gtk_button_new ();
  gtk_widget_show (parametre_capt);
  gtk_fixed_put (GTK_FIXED (fixed1), parametre_capt, 218, 372);
  gtk_widget_set_size_request (parametre_capt, 110, 52);

  alignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment4);
  gtk_container_add (GTK_CONTAINER (parametre_capt), alignment4);

  hbox4 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox4);
  gtk_container_add (GTK_CONTAINER (alignment4), hbox4);

  image4 = gtk_image_new_from_stock ("gtk-properties", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image4);
  gtk_box_pack_start (GTK_BOX (hbox4), image4, FALSE, FALSE, 0);

  label15 = gtk_label_new_with_mnemonic (_("Param\303\250tres "));
  gtk_widget_show (label15);
  gtk_box_pack_start (GTK_BOX (hbox4), label15, FALSE, FALSE, 0);

  defect = gtk_button_new_with_mnemonic (_("Alarmantes"));
  gtk_widget_show (defect);
  gtk_fixed_put (GTK_FIXED (fixed1), defect, 687, 23);
  gtk_widget_set_size_request (defect, 200, 75);

  label105 = gtk_label_new ("");
  gtk_widget_show (label105);
  gtk_fixed_put (GTK_FIXED (fixed1), label105, 560, 120);
  gtk_widget_set_size_request (label105, 448, 56);

  g_signal_connect ((gpointer) treeview_capt, "row_activated",
                    G_CALLBACK (on_treeview_capt_row_activated),
                    NULL);
  g_signal_connect ((gpointer) treeview_capt, "row_activated",
                    G_CALLBACK (on_treeview_alarm_row_activated),
                    NULL);
  g_signal_connect ((gpointer) supprimer_capt, "clicked",
                    G_CALLBACK (on_supprimer_capt_clicked),
                    NULL);
  g_signal_connect ((gpointer) modifier_capt, "clicked",
                    G_CALLBACK (on_modifier_capt_clicked),
                    NULL);
  g_signal_connect ((gpointer) ajouter_capt, "clicked",
                    G_CALLBACK (on_ajouter_capt_clicked),
                    NULL);
  g_signal_connect ((gpointer) parametre_capt, "clicked",
                    G_CALLBACK (on_parametre_capt_clicked),
                    NULL);
  g_signal_connect ((gpointer) defect, "clicked",
                    G_CALLBACK (on_alarmantes_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (gestion_capteur, gestion_capteur, "gestion_capteur");
  GLADE_HOOKUP_OBJECT (gestion_capteur, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (gestion_capteur, treeview_capt, "treeview_capt");
  GLADE_HOOKUP_OBJECT (gestion_capteur, image14, "image14");
  GLADE_HOOKUP_OBJECT (gestion_capteur, image15, "image15");
  GLADE_HOOKUP_OBJECT (gestion_capteur, supprimer_capt, "supprimer_capt");
  GLADE_HOOKUP_OBJECT (gestion_capteur, alignment3, "alignment3");
  GLADE_HOOKUP_OBJECT (gestion_capteur, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (gestion_capteur, image3, "image3");
  GLADE_HOOKUP_OBJECT (gestion_capteur, label14, "label14");
  GLADE_HOOKUP_OBJECT (gestion_capteur, modifier_capt, "modifier_capt");
  GLADE_HOOKUP_OBJECT (gestion_capteur, alignment2, "alignment2");
  GLADE_HOOKUP_OBJECT (gestion_capteur, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (gestion_capteur, image2, "image2");
  GLADE_HOOKUP_OBJECT (gestion_capteur, label13, "label13");
  GLADE_HOOKUP_OBJECT (gestion_capteur, ajouter_capt, "ajouter_capt");
  GLADE_HOOKUP_OBJECT (gestion_capteur, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (gestion_capteur, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (gestion_capteur, image1, "image1");
  GLADE_HOOKUP_OBJECT (gestion_capteur, label12, "label12");
  GLADE_HOOKUP_OBJECT (gestion_capteur, parametre_capt, "parametre_capt");
  GLADE_HOOKUP_OBJECT (gestion_capteur, alignment4, "alignment4");
  GLADE_HOOKUP_OBJECT (gestion_capteur, hbox4, "hbox4");
  GLADE_HOOKUP_OBJECT (gestion_capteur, image4, "image4");
  GLADE_HOOKUP_OBJECT (gestion_capteur, label15, "label15");
  GLADE_HOOKUP_OBJECT (gestion_capteur, defect, "defect");
  GLADE_HOOKUP_OBJECT (gestion_capteur, label105, "label105");

  return gestion_capteur;
}

GtkWidget*
create_ajouter_capteur (void)
{
  GtkWidget *ajouter_capteur;
  GtkWidget *fixed2;
  GtkWidget *entry_id;
  GtkWidget *entry_marque;
  GtkWidget *image16;
  GtkWidget *image23;
  GtkWidget *label111;
  GtkWidget *id;
  GtkWidget *marque;
  GtkWidget *humidite;
  GSList *humidite_group = NULL;
  GtkWidget *temperature;
  GtkWidget *type;
  GtkWidget *checkbutton1;
  GtkWidget *message_robot;
  GtkWidget *label20;
  GtkWidget *Ajout_ok;
  GtkWidget *alignment5;
  GtkWidget *hbox5;
  GtkWidget *image5;
  GtkWidget *label16;
  GtkWidget *retour_ajout;
  GtkWidget *alignment6;
  GtkWidget *hbox6;
  GtkWidget *image6;
  GtkWidget *label17;

  ajouter_capteur = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (ajouter_capteur), _("Ajouter Capteur "));

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (ajouter_capteur), fixed2);
  gtk_widget_set_size_request (fixed2, 750, 550);

  entry_id = gtk_entry_new ();
  gtk_widget_show (entry_id);
  gtk_fixed_put (GTK_FIXED (fixed2), entry_id, 296, 152);
  gtk_widget_set_size_request (entry_id, 158, 38);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_id), 8226);

  entry_marque = gtk_entry_new ();
  gtk_widget_show (entry_marque);
  gtk_fixed_put (GTK_FIXED (fixed2), entry_marque, 500, 243);
  gtk_widget_set_size_request (entry_marque, 158, 38);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_marque), 8226);

  image16 = create_pixmap (ajouter_capteur, "aaaaaaaaa");
  gtk_widget_show (image16);
  gtk_fixed_put (GTK_FIXED (fixed2), image16, 7250, 184);
  gtk_widget_set_size_request (image16, 21, 21);

  image23 = create_pixmap (ajouter_capteur, "aaaaaaaaa");
  gtk_widget_show (image23);
  gtk_fixed_put (GTK_FIXED (fixed2), image23, 0, 0);
  gtk_widget_set_size_request (image23, 750, 550);

  label111 = gtk_label_new (_("AJOUTER UN CAPTEUR :"));
  gtk_widget_show (label111);
  gtk_fixed_put (GTK_FIXED (fixed2), label111, 312, 72);
  gtk_widget_set_size_request (label111, 254, 35);

  id = gtk_label_new (_("ID :"));
  gtk_widget_show (id);
  gtk_fixed_put (GTK_FIXED (fixed2), id, 240, 152);
  gtk_widget_set_size_request (id, 49, 41);

  marque = gtk_label_new (_("MARQUE :"));
  gtk_widget_show (marque);
  gtk_fixed_put (GTK_FIXED (fixed2), marque, 416, 240);
  gtk_widget_set_size_request (marque, 72, 40);

  humidite = gtk_radio_button_new_with_mnemonic (NULL, _("Humidit\303\251"));
  gtk_widget_show (humidite);
  gtk_fixed_put (GTK_FIXED (fixed2), humidite, 480, 328);
  gtk_widget_set_size_request (humidite, 144, 48);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (humidite), humidite_group);
  humidite_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (humidite));

  temperature = gtk_radio_button_new_with_mnemonic (NULL, _("Temp\303\251rature"));
  gtk_widget_show (temperature);
  gtk_fixed_put (GTK_FIXED (fixed2), temperature, 296, 328);
  gtk_widget_set_size_request (temperature, 144, 48);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (temperature), humidite_group);
  humidite_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (temperature));

  type = gtk_label_new (_("TYPE :"));
  gtk_widget_show (type);
  gtk_fixed_put (GTK_FIXED (fixed2), type, 168, 328);
  gtk_widget_set_size_request (type, 64, 48);

  checkbutton1 = gtk_check_button_new_with_mnemonic (_("je ne suis pas un robot"));
  gtk_widget_show (checkbutton1);
  gtk_fixed_put (GTK_FIXED (fixed2), checkbutton1, 312, 400);
  gtk_widget_set_size_request (checkbutton1, 194, 24);

  message_robot = gtk_label_new (_("message"));
  gtk_widget_show (message_robot);
  gtk_fixed_put (GTK_FIXED (fixed2), message_robot, 344, 440);
  gtk_widget_set_size_request (message_robot, 147, 37);

  label20 = gtk_label_new ("");
  gtk_widget_show (label20);
  gtk_fixed_put (GTK_FIXED (fixed2), label20, 224, 488);
  gtk_widget_set_size_request (label20, 168, 33);

  Ajout_ok = gtk_button_new ();
  gtk_widget_show (Ajout_ok);
  gtk_fixed_put (GTK_FIXED (fixed2), Ajout_ok, 88, 424);
  gtk_widget_set_size_request (Ajout_ok, 95, 55);

  alignment5 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment5);
  gtk_container_add (GTK_CONTAINER (Ajout_ok), alignment5);

  hbox5 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox5);
  gtk_container_add (GTK_CONTAINER (alignment5), hbox5);

  image5 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image5);
  gtk_box_pack_start (GTK_BOX (hbox5), image5, FALSE, FALSE, 0);

  label16 = gtk_label_new_with_mnemonic (_("Ok"));
  gtk_widget_show (label16);
  gtk_box_pack_start (GTK_BOX (hbox5), label16, FALSE, FALSE, 0);

  retour_ajout = gtk_button_new ();
  gtk_widget_show (retour_ajout);
  gtk_fixed_put (GTK_FIXED (fixed2), retour_ajout, 568, 432);
  gtk_widget_set_size_request (retour_ajout, 95, 55);

  alignment6 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment6);
  gtk_container_add (GTK_CONTAINER (retour_ajout), alignment6);

  hbox6 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox6);
  gtk_container_add (GTK_CONTAINER (alignment6), hbox6);

  image6 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image6);
  gtk_box_pack_start (GTK_BOX (hbox6), image6, FALSE, FALSE, 0);

  label17 = gtk_label_new_with_mnemonic (_("Retour"));
  gtk_widget_show (label17);
  gtk_box_pack_start (GTK_BOX (hbox6), label17, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) humidite, "toggled",
                    G_CALLBACK (on_humidite_toggled),
                    NULL);
  g_signal_connect ((gpointer) temperature, "toggled",
                    G_CALLBACK (on_temperature_toggled),
                    NULL);
  g_signal_connect ((gpointer) checkbutton1, "toggled",
                    G_CALLBACK (on_checkbutton1_toggled),
                    NULL);
  g_signal_connect ((gpointer) Ajout_ok, "clicked",
                    G_CALLBACK (on_Ajout_ok_clicked),
                    NULL);
  g_signal_connect ((gpointer) retour_ajout, "clicked",
                    G_CALLBACK (on_retour_ajout_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (ajouter_capteur, ajouter_capteur, "ajouter_capteur");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, entry_id, "entry_id");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, entry_marque, "entry_marque");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, image16, "image16");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, image23, "image23");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, label111, "label111");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, id, "id");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, marque, "marque");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, humidite, "humidite");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, temperature, "temperature");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, type, "type");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, checkbutton1, "checkbutton1");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, message_robot, "message_robot");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, label20, "label20");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, Ajout_ok, "Ajout_ok");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, alignment5, "alignment5");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, hbox5, "hbox5");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, image5, "image5");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, label16, "label16");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, retour_ajout, "retour_ajout");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, alignment6, "alignment6");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, hbox6, "hbox6");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, image6, "image6");
  GLADE_HOOKUP_OBJECT (ajouter_capteur, label17, "label17");

  return ajouter_capteur;
}

GtkWidget*
create_modifier_capteur (void)
{
  GtkWidget *modifier_capteur;
  GtkWidget *fixed3;
  GtkWidget *entry_marque_modif;
  GtkWidget *cb_id_modif;
  GtkWidget *image25;
  GtkWidget *retour_modif;
  GtkWidget *alignment8;
  GtkWidget *hbox8;
  GtkWidget *image8;
  GtkWidget *label19;
  GtkWidget *modif_ok;
  GtkWidget *alignment7;
  GtkWidget *hbox7;
  GtkWidget *image7;
  GtkWidget *label18;
  GtkWidget *type;
  GtkWidget *cb_type_modif;
  GtkWidget *marque;
  GtkWidget *id;
  GtkWidget *label112;
  GtkWidget *label27;

  modifier_capteur = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (modifier_capteur), _("Modifier Capteur "));

  fixed3 = gtk_fixed_new ();
  gtk_widget_show (fixed3);
  gtk_container_add (GTK_CONTAINER (modifier_capteur), fixed3);
  gtk_widget_set_size_request (fixed3, 700, 500);

  entry_marque_modif = gtk_entry_new ();
  gtk_widget_show (entry_marque_modif);
  gtk_fixed_put (GTK_FIXED (fixed3), entry_marque_modif, 400, 192);
  gtk_widget_set_size_request (entry_marque_modif, 155, 35);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_marque_modif), 8226);

  cb_id_modif = gtk_combo_box_new_text ();
  gtk_widget_show (cb_id_modif);
  gtk_fixed_put (GTK_FIXED (fixed3), cb_id_modif, 168, 56);
  gtk_widget_set_size_request (cb_id_modif, 152, 32);

  image25 = create_pixmap (modifier_capteur, "ui.png");
  gtk_widget_show (image25);
  gtk_fixed_put (GTK_FIXED (fixed3), image25, 16, 0);
  gtk_widget_set_size_request (image25, 650, 500);

  retour_modif = gtk_button_new ();
  gtk_widget_show (retour_modif);
  gtk_fixed_put (GTK_FIXED (fixed3), retour_modif, 360, 424);
  gtk_widget_set_size_request (retour_modif, 100, 45);

  alignment8 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment8);
  gtk_container_add (GTK_CONTAINER (retour_modif), alignment8);

  hbox8 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox8);
  gtk_container_add (GTK_CONTAINER (alignment8), hbox8);

  image8 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image8);
  gtk_box_pack_start (GTK_BOX (hbox8), image8, FALSE, FALSE, 0);

  label19 = gtk_label_new_with_mnemonic (_("Retour "));
  gtk_widget_show (label19);
  gtk_box_pack_start (GTK_BOX (hbox8), label19, FALSE, FALSE, 0);

  modif_ok = gtk_button_new ();
  gtk_widget_show (modif_ok);
  gtk_fixed_put (GTK_FIXED (fixed3), modif_ok, 74, 420);
  gtk_widget_set_size_request (modif_ok, 100, 45);

  alignment7 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment7);
  gtk_container_add (GTK_CONTAINER (modif_ok), alignment7);

  hbox7 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox7);
  gtk_container_add (GTK_CONTAINER (alignment7), hbox7);

  image7 = gtk_image_new_from_stock ("gtk-yes", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image7);
  gtk_box_pack_start (GTK_BOX (hbox7), image7, FALSE, FALSE, 0);

  label18 = gtk_label_new_with_mnemonic (_("Ok"));
  gtk_widget_show (label18);
  gtk_box_pack_start (GTK_BOX (hbox7), label18, FALSE, FALSE, 0);

  type = gtk_label_new (_("TYPE :"));
  gtk_widget_show (type);
  gtk_fixed_put (GTK_FIXED (fixed3), type, 168, 296);
  gtk_widget_set_size_request (type, 80, 25);

  cb_type_modif = gtk_combo_box_new_text ();
  gtk_widget_show (cb_type_modif);
  gtk_fixed_put (GTK_FIXED (fixed3), cb_type_modif, 312, 288);
  gtk_widget_set_size_request (cb_type_modif, 155, 35);
  gtk_combo_box_append_text (GTK_COMBO_BOX (cb_type_modif), _("Temp\303\251rature"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (cb_type_modif), _("Humidite"));

  marque = gtk_label_new (_("MARQUE :"));
  gtk_widget_show (marque);
  gtk_fixed_put (GTK_FIXED (fixed3), marque, 256, 192);
  gtk_widget_set_size_request (marque, 80, 25);

  id = gtk_label_new (_("ID :"));
  gtk_widget_show (id);
  gtk_fixed_put (GTK_FIXED (fixed3), id, 96, 64);
  gtk_widget_set_size_request (id, 80, 25);

  label112 = gtk_label_new (_("MODIFIER UN CAPTEUR :"));
  gtk_widget_show (label112);
  gtk_fixed_put (GTK_FIXED (fixed3), label112, 248, 8);
  gtk_widget_set_size_request (label112, 240, 35);

  label27 = gtk_label_new ("");
  gtk_widget_show (label27);
  gtk_fixed_put (GTK_FIXED (fixed3), label27, 200, 352);
  gtk_widget_set_size_request (label27, 168, 33);

  g_signal_connect ((gpointer) retour_modif, "clicked",
                    G_CALLBACK (on_retour_modif_clicked),
                    NULL);
  g_signal_connect ((gpointer) modif_ok, "clicked",
                    G_CALLBACK (on_modif_ok_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (modifier_capteur, modifier_capteur, "modifier_capteur");
  GLADE_HOOKUP_OBJECT (modifier_capteur, fixed3, "fixed3");
  GLADE_HOOKUP_OBJECT (modifier_capteur, entry_marque_modif, "entry_marque_modif");
  GLADE_HOOKUP_OBJECT (modifier_capteur, cb_id_modif, "cb_id_modif");
  GLADE_HOOKUP_OBJECT (modifier_capteur, image25, "image25");
  GLADE_HOOKUP_OBJECT (modifier_capteur, retour_modif, "retour_modif");
  GLADE_HOOKUP_OBJECT (modifier_capteur, alignment8, "alignment8");
  GLADE_HOOKUP_OBJECT (modifier_capteur, hbox8, "hbox8");
  GLADE_HOOKUP_OBJECT (modifier_capteur, image8, "image8");
  GLADE_HOOKUP_OBJECT (modifier_capteur, label19, "label19");
  GLADE_HOOKUP_OBJECT (modifier_capteur, modif_ok, "modif_ok");
  GLADE_HOOKUP_OBJECT (modifier_capteur, alignment7, "alignment7");
  GLADE_HOOKUP_OBJECT (modifier_capteur, hbox7, "hbox7");
  GLADE_HOOKUP_OBJECT (modifier_capteur, image7, "image7");
  GLADE_HOOKUP_OBJECT (modifier_capteur, label18, "label18");
  GLADE_HOOKUP_OBJECT (modifier_capteur, type, "type");
  GLADE_HOOKUP_OBJECT (modifier_capteur, cb_type_modif, "cb_type_modif");
  GLADE_HOOKUP_OBJECT (modifier_capteur, marque, "marque");
  GLADE_HOOKUP_OBJECT (modifier_capteur, id, "id");
  GLADE_HOOKUP_OBJECT (modifier_capteur, label112, "label112");
  GLADE_HOOKUP_OBJECT (modifier_capteur, label27, "label27");

  return modifier_capteur;
}

GtkWidget*
create_supprimer_capteur (void)
{
  GtkWidget *supprimer_capteur;
  GtkWidget *fixed4;
  GtkWidget *combobox_supp;
  GtkWidget *image24;
  GtkWidget *label18;
  GtkWidget *label113;
  GtkWidget *id;
  GtkWidget *supprim_ok;
  GtkWidget *alignment9;
  GtkWidget *hbox9;
  GtkWidget *image9;
  GtkWidget *label20;
  GtkWidget *retour_supp;
  GtkWidget *alignment10;
  GtkWidget *hbox10;
  GtkWidget *image10;
  GtkWidget *label21;

  supprimer_capteur = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (supprimer_capteur, 380, 379);
  gtk_window_set_title (GTK_WINDOW (supprimer_capteur), _("Supprimer Capteur "));

  fixed4 = gtk_fixed_new ();
  gtk_widget_show (fixed4);
  gtk_container_add (GTK_CONTAINER (supprimer_capteur), fixed4);
  gtk_widget_set_size_request (fixed4, 380, 380);

  combobox_supp = gtk_combo_box_new_text ();
  gtk_widget_show (combobox_supp);
  gtk_fixed_put (GTK_FIXED (fixed4), combobox_supp, 120, 112);
  gtk_widget_set_size_request (combobox_supp, 136, 31);

  image24 = create_pixmap (supprimer_capteur, "1212");
  gtk_widget_show (image24);
  gtk_fixed_put (GTK_FIXED (fixed4), image24, 0, 0);
  gtk_widget_set_size_request (image24, 382, 360);

  label18 = gtk_label_new ("");
  gtk_widget_show (label18);
  gtk_fixed_put (GTK_FIXED (fixed4), label18, 72, 208);
  gtk_widget_set_size_request (label18, 232, 47);

  label113 = gtk_label_new (_("supprimer un capteur "));
  gtk_widget_show (label113);
  gtk_fixed_put (GTK_FIXED (fixed4), label113, 120, 40);
  gtk_widget_set_size_request (label113, 160, 30);

  id = gtk_label_new (_("ID :"));
  gtk_widget_show (id);
  gtk_fixed_put (GTK_FIXED (fixed4), id, 48, 120);
  gtk_widget_set_size_request (id, 80, 17);

  supprim_ok = gtk_button_new ();
  gtk_widget_show (supprim_ok);
  gtk_fixed_put (GTK_FIXED (fixed4), supprim_ok, 56, 272);
  gtk_widget_set_size_request (supprim_ok, 95, 45);

  alignment9 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment9);
  gtk_container_add (GTK_CONTAINER (supprim_ok), alignment9);

  hbox9 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox9);
  gtk_container_add (GTK_CONTAINER (alignment9), hbox9);

  image9 = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image9);
  gtk_box_pack_start (GTK_BOX (hbox9), image9, FALSE, FALSE, 0);

  label20 = gtk_label_new_with_mnemonic (_("Supprimer "));
  gtk_widget_show (label20);
  gtk_box_pack_start (GTK_BOX (hbox9), label20, FALSE, FALSE, 0);

  retour_supp = gtk_button_new ();
  gtk_widget_show (retour_supp);
  gtk_fixed_put (GTK_FIXED (fixed4), retour_supp, 232, 272);
  gtk_widget_set_size_request (retour_supp, 95, 45);

  alignment10 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment10);
  gtk_container_add (GTK_CONTAINER (retour_supp), alignment10);

  hbox10 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox10);
  gtk_container_add (GTK_CONTAINER (alignment10), hbox10);

  image10 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image10);
  gtk_box_pack_start (GTK_BOX (hbox10), image10, FALSE, FALSE, 0);

  label21 = gtk_label_new_with_mnemonic (_("Retour"));
  gtk_widget_show (label21);
  gtk_box_pack_start (GTK_BOX (hbox10), label21, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) supprim_ok, "clicked",
                    G_CALLBACK (on_supprim_ok_clicked),
                    NULL);
  g_signal_connect ((gpointer) retour_supp, "clicked",
                    G_CALLBACK (on_retour_supp_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (supprimer_capteur, supprimer_capteur, "supprimer_capteur");
  GLADE_HOOKUP_OBJECT (supprimer_capteur, fixed4, "fixed4");
  GLADE_HOOKUP_OBJECT (supprimer_capteur, combobox_supp, "combobox_supp");
  GLADE_HOOKUP_OBJECT (supprimer_capteur, image24, "image24");
  GLADE_HOOKUP_OBJECT (supprimer_capteur, label18, "label18");
  GLADE_HOOKUP_OBJECT (supprimer_capteur, label113, "label113");
  GLADE_HOOKUP_OBJECT (supprimer_capteur, id, "id");
  GLADE_HOOKUP_OBJECT (supprimer_capteur, supprim_ok, "supprim_ok");
  GLADE_HOOKUP_OBJECT (supprimer_capteur, alignment9, "alignment9");
  GLADE_HOOKUP_OBJECT (supprimer_capteur, hbox9, "hbox9");
  GLADE_HOOKUP_OBJECT (supprimer_capteur, image9, "image9");
  GLADE_HOOKUP_OBJECT (supprimer_capteur, label20, "label20");
  GLADE_HOOKUP_OBJECT (supprimer_capteur, retour_supp, "retour_supp");
  GLADE_HOOKUP_OBJECT (supprimer_capteur, alignment10, "alignment10");
  GLADE_HOOKUP_OBJECT (supprimer_capteur, hbox10, "hbox10");
  GLADE_HOOKUP_OBJECT (supprimer_capteur, image10, "image10");
  GLADE_HOOKUP_OBJECT (supprimer_capteur, label21, "label21");

  return supprimer_capteur;
}

GtkWidget*
create_parametres_ (void)
{
  GtkWidget *parametres_;
  GtkWidget *fixed5;
  GtkWidget *treeview_param;
  GtkWidget *image20;
  GtkWidget *ajout_param;
  GtkWidget *alignment11;
  GtkWidget *hbox11;
  GtkWidget *image11;
  GtkWidget *label22;

  parametres_ = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (parametres_), _("Param\303\250tres "));

  fixed5 = gtk_fixed_new ();
  gtk_widget_show (fixed5);
  gtk_container_add (GTK_CONTAINER (parametres_), fixed5);
  gtk_widget_set_size_request (fixed5, 400, 400);

  treeview_param = gtk_tree_view_new ();
  gtk_widget_show (treeview_param);
  gtk_fixed_put (GTK_FIXED (fixed5), treeview_param, 60, 44);
  gtk_widget_set_size_request (treeview_param, 280, 210);

  image20 = create_pixmap (parametres_, "nn.png");
  gtk_widget_show (image20);
  gtk_fixed_put (GTK_FIXED (fixed5), image20, 0, 0);
  gtk_widget_set_size_request (image20, 400, 400);

  ajout_param = gtk_button_new ();
  gtk_widget_show (ajout_param);
  gtk_fixed_put (GTK_FIXED (fixed5), ajout_param, 62, 276);
  gtk_widget_set_size_request (ajout_param, 275, 45);

  alignment11 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment11);
  gtk_container_add (GTK_CONTAINER (ajout_param), alignment11);

  hbox11 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox11);
  gtk_container_add (GTK_CONTAINER (alignment11), hbox11);

  image11 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image11);
  gtk_box_pack_start (GTK_BOX (hbox11), image11, FALSE, FALSE, 0);

  label22 = gtk_label_new_with_mnemonic (_("Ajouter des param\303\251tres "));
  gtk_widget_show (label22);
  gtk_box_pack_start (GTK_BOX (hbox11), label22, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) treeview_param, "row_activated",
                    G_CALLBACK (on_treeview_param_row_activated),
                    NULL);
  g_signal_connect ((gpointer) ajout_param, "clicked",
                    G_CALLBACK (on_ajout_param_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (parametres_, parametres_, "parametres_");
  GLADE_HOOKUP_OBJECT (parametres_, fixed5, "fixed5");
  GLADE_HOOKUP_OBJECT (parametres_, treeview_param, "treeview_param");
  GLADE_HOOKUP_OBJECT (parametres_, image20, "image20");
  GLADE_HOOKUP_OBJECT (parametres_, ajout_param, "ajout_param");
  GLADE_HOOKUP_OBJECT (parametres_, alignment11, "alignment11");
  GLADE_HOOKUP_OBJECT (parametres_, hbox11, "hbox11");
  GLADE_HOOKUP_OBJECT (parametres_, image11, "image11");
  GLADE_HOOKUP_OBJECT (parametres_, label22, "label22");

  return parametres_;
}

GtkWidget*
create_ajouter_parametres (void)
{
  GtkWidget *ajouter_parametres;
  GtkWidget *scrolledwindow1;
  GtkWidget *viewport1;
  GtkWidget *fixed6;
  GtkObject *spinbutton_jour_adj;
  GtkWidget *spinbutton_jour;
  GtkObject *spinbutton_mois_adj;
  GtkWidget *spinbutton_mois;
  GtkObject *spinbutton_annee_adj;
  GtkWidget *spinbutton_annee;
  GtkObject *spinbutton_heure_adj;
  GtkWidget *spinbutton_heure;
  GtkObject *spinbutton_minute_adj;
  GtkWidget *spinbutton_minute;
  GtkWidget *entry_val;
  GtkWidget *image21;
  GtkWidget *label114;
  GtkWidget *id;
  GtkWidget *cb_id;
  GtkWidget *date;
  GtkWidget *horaire;
  GtkWidget *valeur;
  GtkWidget *param_ok;
  GtkWidget *alignment12;
  GtkWidget *hbox12;
  GtkWidget *image12;
  GtkWidget *label23;
  GtkWidget *retour_param;
  GtkWidget *alignment13;
  GtkWidget *hbox13;
  GtkWidget *image13;
  GtkWidget *label24;

  ajouter_parametres = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (ajouter_parametres, 600, 450);
  gtk_window_set_title (GTK_WINDOW (ajouter_parametres), _("Ajouter Param\303\250tres "));

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow1);
  gtk_container_add (GTK_CONTAINER (ajouter_parametres), scrolledwindow1);
  gtk_widget_set_size_request (scrolledwindow1, 400, 400);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow1), GTK_SHADOW_IN);

  viewport1 = gtk_viewport_new (NULL, NULL);
  gtk_widget_show (viewport1);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), viewport1);
  gtk_widget_set_size_request (viewport1, 520, 450);

  fixed6 = gtk_fixed_new ();
  gtk_widget_show (fixed6);
  gtk_container_add (GTK_CONTAINER (viewport1), fixed6);
  gtk_widget_set_size_request (fixed6, 500, 400);

  spinbutton_jour_adj = gtk_adjustment_new (1, 1, 31, 1, 10, 10);
  spinbutton_jour = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton_jour_adj), 1, 0);
  gtk_widget_show (spinbutton_jour);
  gtk_fixed_put (GTK_FIXED (fixed6), spinbutton_jour, 270, 165);
  gtk_widget_set_size_request (spinbutton_jour, 60, 27);

  spinbutton_mois_adj = gtk_adjustment_new (1, 1, 12, 1, 10, 10);
  spinbutton_mois = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton_mois_adj), 1, 0);
  gtk_widget_show (spinbutton_mois);
  gtk_fixed_put (GTK_FIXED (fixed6), spinbutton_mois, 365, 165);
  gtk_widget_set_size_request (spinbutton_mois, 60, 27);

  spinbutton_annee_adj = gtk_adjustment_new (1, 2015, 2022, 1, 10, 10);
  spinbutton_annee = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton_annee_adj), 1, 0);
  gtk_widget_show (spinbutton_annee);
  gtk_fixed_put (GTK_FIXED (fixed6), spinbutton_annee, 456, 165);
  gtk_widget_set_size_request (spinbutton_annee, 60, 27);

  spinbutton_heure_adj = gtk_adjustment_new (1, 0, 23, 1, 10, 10);
  spinbutton_heure = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton_heure_adj), 1, 0);
  gtk_widget_show (spinbutton_heure);
  gtk_fixed_put (GTK_FIXED (fixed6), spinbutton_heure, 270, 230);
  gtk_widget_set_size_request (spinbutton_heure, 60, 27);

  spinbutton_minute_adj = gtk_adjustment_new (1, 0, 59, 1, 10, 10);
  spinbutton_minute = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton_minute_adj), 1, 0);
  gtk_widget_show (spinbutton_minute);
  gtk_fixed_put (GTK_FIXED (fixed6), spinbutton_minute, 364, 230);
  gtk_widget_set_size_request (spinbutton_minute, 60, 27);

  entry_val = gtk_entry_new ();
  gtk_widget_show (entry_val);
  gtk_fixed_put (GTK_FIXED (fixed6), entry_val, 272, 290);
  gtk_widget_set_size_request (entry_val, 200, 30);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry_val), 8226);

  image21 = create_pixmap (ajouter_parametres, "lo.png");
  gtk_widget_show (image21);
  gtk_fixed_put (GTK_FIXED (fixed6), image21, 0, 0);
  gtk_widget_set_size_request (image21, 600, 450);

  label114 = gtk_label_new (_("AJOUTER DES PARAM\303\211TRES:"));
  gtk_widget_show (label114);
  gtk_fixed_put (GTK_FIXED (fixed6), label114, 208, 32);
  gtk_widget_set_size_request (label114, 220, 30);

  id = gtk_label_new (_("ID :"));
  gtk_widget_show (id);
  gtk_fixed_put (GTK_FIXED (fixed6), id, 152, 112);
  gtk_widget_set_size_request (id, 76, 35);

  cb_id = gtk_combo_box_new_text ();
  gtk_widget_show (cb_id);
  gtk_fixed_put (GTK_FIXED (fixed6), cb_id, 272, 110);
  gtk_widget_set_size_request (cb_id, 200, 30);
  gtk_combo_box_append_text (GTK_COMBO_BOX (cb_id), _("id"));

  date = gtk_label_new (_("DATE :"));
  gtk_widget_show (date);
  gtk_fixed_put (GTK_FIXED (fixed6), date, 152, 160);
  gtk_widget_set_size_request (date, 70, 35);

  horaire = gtk_label_new (_("HORAIRE :"));
  gtk_widget_show (horaire);
  gtk_fixed_put (GTK_FIXED (fixed6), horaire, 136, 224);
  gtk_widget_set_size_request (horaire, 100, 35);

  valeur = gtk_label_new (_("VALEUR :"));
  gtk_widget_show (valeur);
  gtk_fixed_put (GTK_FIXED (fixed6), valeur, 136, 288);
  gtk_widget_set_size_request (valeur, 100, 35);

  param_ok = gtk_button_new ();
  gtk_widget_show (param_ok);
  gtk_fixed_put (GTK_FIXED (fixed6), param_ok, 240, 387);
  gtk_widget_set_size_request (param_ok, 100, 45);

  alignment12 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment12);
  gtk_container_add (GTK_CONTAINER (param_ok), alignment12);

  hbox12 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox12);
  gtk_container_add (GTK_CONTAINER (alignment12), hbox12);

  image12 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image12);
  gtk_box_pack_start (GTK_BOX (hbox12), image12, FALSE, FALSE, 0);

  label23 = gtk_label_new_with_mnemonic (_("Ok "));
  gtk_widget_show (label23);
  gtk_box_pack_start (GTK_BOX (hbox12), label23, FALSE, FALSE, 0);

  retour_param = gtk_button_new ();
  gtk_widget_show (retour_param);
  gtk_fixed_put (GTK_FIXED (fixed6), retour_param, 455, 387);
  gtk_widget_set_size_request (retour_param, 100, 45);

  alignment13 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment13);
  gtk_container_add (GTK_CONTAINER (retour_param), alignment13);

  hbox13 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox13);
  gtk_container_add (GTK_CONTAINER (alignment13), hbox13);

  image13 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image13);
  gtk_box_pack_start (GTK_BOX (hbox13), image13, FALSE, FALSE, 0);

  label24 = gtk_label_new_with_mnemonic (_("Retour "));
  gtk_widget_show (label24);
  gtk_box_pack_start (GTK_BOX (hbox13), label24, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) param_ok, "clicked",
                    G_CALLBACK (on_param_ok_clicked),
                    NULL);
  g_signal_connect ((gpointer) retour_param, "clicked",
                    G_CALLBACK (on_retour_param_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (ajouter_parametres, ajouter_parametres, "ajouter_parametres");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, scrolledwindow1, "scrolledwindow1");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, viewport1, "viewport1");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, fixed6, "fixed6");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, spinbutton_jour, "spinbutton_jour");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, spinbutton_mois, "spinbutton_mois");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, spinbutton_annee, "spinbutton_annee");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, spinbutton_heure, "spinbutton_heure");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, spinbutton_minute, "spinbutton_minute");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, entry_val, "entry_val");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, image21, "image21");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, label114, "label114");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, id, "id");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, cb_id, "cb_id");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, date, "date");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, horaire, "horaire");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, valeur, "valeur");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, param_ok, "param_ok");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, alignment12, "alignment12");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, hbox12, "hbox12");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, image12, "image12");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, label23, "label23");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, retour_param, "retour_param");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, alignment13, "alignment13");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, hbox13, "hbox13");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, image13, "image13");
  GLADE_HOOKUP_OBJECT (ajouter_parametres, label24, "label24");

  return ajouter_parametres;
}

