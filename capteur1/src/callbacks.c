#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"
#include "capteur.c"


void
on_treeview_capt_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* id;
	gchar* marque;
	gchar* type;
	gchar* etat_def;
	gint* val_min;
	gint* val_max;
	capteur capt;


	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &marque, 2, &type, 3, &etat_def, 4, &val_min, 5, &val_max, -1);
strcpy(capt.id,id);
strcpy(capt.marque,marque);
strcpy(capt.type,type);
strcpy(capt.etat_def,etat_def);
capt.val_min=val_min;
capt.val_max=val_max;
afficher_capteurs(treeview);
}
}





void
on_ajouter_capt_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *ajouter_capteur;
	GtkWidget *gestion_capteur;
	gestion_capteur=lookup_widget(objet,"gestion_capteur");
	gtk_widget_destroy(gestion_capteur);
	ajouter_capteur = create_ajouter_capteur();
	gtk_widget_show(ajouter_capteur);
}


void
on_modifier_capt_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
 	GtkWidget *gestion_capteur;
	GtkWidget *modifier_capteur;
	GtkWidget *combo;
	FILE *f;
	char id[30];
	gestion_capteur=lookup_widget(objet,"gestion_capteur");
	gtk_widget_destroy(gestion_capteur);
	modifier_capteur = create_modifier_capteur();
	combo=lookup_widget(modifier_capteur,"cb_id_modif");
	f=fopen("capteur.txt","r");
	while(fscanf(f,"%s %*s %*s %*s %*d %*d\n",id)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combo),id);
	}
	fclose(f);
	gtk_widget_show(modifier_capteur);
}

void
on_supprimer_capt_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	
 	GtkWidget *gestion_capteur;
	GtkWidget *supprimer_capteur;
	GtkWidget *combo;
	FILE *f;
	char id[30];
	gestion_capteur=lookup_widget(objet,"gestion_capteur");
	gtk_widget_destroy(gestion_capteur);
	supprimer_capteur = create_supprimer_capteur();
	combo=lookup_widget(supprimer_capteur,"combobox_supp");
	f=fopen("capteur.txt","r");
	while(fscanf(f,"%s %*s %*s %*s %*d %*d\n",id)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combo),id);
	}
	fclose(f);
	gtk_widget_show(supprimer_capteur);

}



void
on_Ajout_ok_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
capteur capt;
	
GtkWidget *marque,*type,*id;
marque= lookup_widget(objet,"entry_marque");
type= lookup_widget(objet,"cb_type_ajout");
id= lookup_widget(objet,"entry_id");
strcpy(capt.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
strcpy(capt.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
printf(gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
strcpy(capt.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(capt.etat_def,"N/A");

ajouter_capteur(capt);
}


void
on_retour_ajout_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter_capteur;
GtkWidget *gestion_capteur;
GtkWidget *treeview_capt;
ajouter_capteur=lookup_widget(objet,"ajouter_capteur");

gtk_widget_destroy(ajouter_capteur);
gestion_capteur=lookup_widget(objet,"gestion_capteur");
gestion_capteur=create_gestion_capteur_();
gtk_widget_show(gestion_capteur);

treeview_capt=lookup_widget(gestion_capteur,"treeview_capt");

afficher_capteurs(treeview_capt);
}


void
on_modif_ok_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	capteur capt;
	
GtkWidget *marque,*type,*id;
id= lookup_widget(objet,"cb_id_modif");
marque= lookup_widget(objet,"entry_marque_modif");
type= lookup_widget(objet,"cb_type_modif");
strcpy(capt.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id)));
strcpy(capt.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
strcpy(capt.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));


modifier_capteur(capt);
}


void
on_retour_modif_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
		
GtkWidget *modifier_capteur;
GtkWidget *gestion_capteur;
GtkWidget *treeview_capt;
modifier_capteur=lookup_widget(objet,"modifier_capteur");

gtk_widget_destroy(modifier_capteur);
gestion_capteur=lookup_widget(objet,"gestion_capteur");
gestion_capteur=create_gestion_capteur_();
gtk_widget_show(gestion_capteur);

treeview_capt=lookup_widget(gestion_capteur,"treeview_capt");

afficher_capteurs(treeview_capt);
}

void
on_supprim_ok_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{	capteur capt;
GtkWidget *input;
input= lookup_widget(objet,"combobox_supp");
strcpy(capt.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
supprimer_capteur(capt);
}



void
on_retour_supp_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimer_capteur;
GtkWidget *gestion_capteur;
GtkWidget *treeview_capt;
supprimer_capteur=lookup_widget(objet,"supprimer_capteur");

gtk_widget_destroy(supprimer_capteur);
gestion_capteur=lookup_widget(objet,"gestion_capteur");
gestion_capteur=create_gestion_capteur_();
gtk_widget_show(gestion_capteur);

treeview_capt=lookup_widget(gestion_capteur,"treeview_capt");

afficher_capteurs(treeview_capt);

}




