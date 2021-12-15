#include <gtk/gtk.h>


void
on_treeview_capt_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview_alarm_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajouter_capt_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modifier_capt_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_supprimer_capt_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_parametre_capt_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Ajout_ok_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_ajout_clicked                (GtkWidget       *button,
                                        gpointer         user_data);


void
on_modif_ok_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_modif_clicked                (GtkWidget      *button,
                                        gpointer         user_data);

void
on_supprim_ok_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);


void
on_retour_supp_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview_param_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajout_param_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_param_ok_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_param_clicked                (GtkWidget       *button,
                                        gpointer         user_data);


void
on_temperature_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_humidite_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
