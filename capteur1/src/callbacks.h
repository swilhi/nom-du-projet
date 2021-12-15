#include <gtk/gtk.h>


void
on_treeview_capt_row_activated         (GtkTreeView     *treeview,
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







