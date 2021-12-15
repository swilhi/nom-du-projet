#include <gtk/gtk.h>

  GtkWidget *acceuil;
  GtkWidget *gestion;




struct Date1
{
int jour;
int mois;
int annee;
}Date1;




struct Date2
{
int jour;
int mois;
int annee;
}Date2;



typedef struct produit produit;
struct produit{
char id[30];
char nom[30];
char prix[30];
char date_entree[30];
char date_expiration[30];
char fournisseur[30]; 
char rangement[30];
char quantity[30];
struct Date1 date1;
struct Date2 date2;
};

int i,j,k;
void
on_AcceuilGestion_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
void
on_GestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data);


void
on_Ajouterproduit_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifierproduit_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_Supprimerproduit_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercherproduit_clicked             (GtkButton       *button,
                                        gpointer         user_data);
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


void
on_alarmantes_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

/*void
on_defec_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);*/

void
on_capt_clicked                        (GtkButton       *button,
                                        gpointer         user_data);
/////////////////////////////////////////////////////////////////////////
/*
void
on_button4fr_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonferyel_retour_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_rec_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsafa_retour_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonkalthoum_retour_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton1fr_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonother_retour_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_fr_retour_clicked            (GtkButton       *button,
                                        gpointer         user_data);

*/
////////////////////////////////////////////////////////////////////

void
on_button3_supprimer_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_button1_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button7_add_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton3_valide_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_heb_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_nut_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_n_valide_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button2_afficher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

/*void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);*/

void
on_button1_retour_clicked              (GtkButton       *button,
                                        gpointer         user_data);


void
on_button2_recherche_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

/*void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data);*/

void
on_button4_modifier_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button6_modifier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button5_plus_reclamee_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


/*void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);*/



void
on_button_fr_retour_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button3_rec_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

/*void
on_checkbutton1fr_clicked              (GtkButton       *button,
                                        gpointer         user_data);*/

void
on_checkbutton1fr_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button4fr_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonferyel_retour_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsafa_retour_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonkalthoum_retour_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonother_retour_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button111_clicked                   (GtkButton       *button,
                                        gpointer         user_data);
