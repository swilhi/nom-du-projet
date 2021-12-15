#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"
#include "parametres.h"

int x;
int check=0;

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

/////////////////////////////////////////////////////////////////////////////////

void
on_treeview_alarm_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)

{
	GtkTreeIter iter;
	gint* id;
	gfloat *valeur;


	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &valeur  -1);

afficher_alarmantes(treeview);
}
}

////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////

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
////////////////////////////////////////////////////////////////////////////////

void
on_supprimer_capt_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	
 	GtkWidget *gestion_capteur1;
	GtkWidget *supprimer_capteur1;
	GtkWidget *combo;
	FILE *f;
	char id[30];
	gestion_capteur1=lookup_widget(objet,"gestion_capteur");
	gtk_widget_destroy(gestion_capteur1);
	supprimer_capteur1 = create_supprimer_capteur();
	gtk_widget_show(supprimer_capteur1);
	combo=lookup_widget(supprimer_capteur1,"combobox_supp");
	f=fopen("capteur.txt","r");
	while(fscanf(f,"%s %*s %*s %*s %*d %*d\n",id)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combo),id);
	}
	fclose(f);
	gtk_widget_show(supprimer_capteur1);

}

////////////////////////////////////////////////////////////////////////////////////////

void
on_parametre_capt_clicked              (GtkWidget     *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_capteur;
GtkWidget *parametres;
GtkWidget *treeview_param;
gestion_capteur=lookup_widget(objet,"gestion_capteur");

gtk_widget_destroy(parametres);
parametres=lookup_widget(objet,"parametres");
parametres=create_parametres_();

gtk_widget_show(parametres);

treeview_param=lookup_widget(parametres,"treeview_param");

afficher_parametres(treeview_param);

}

/////////////////////////////////////////////////////////////////////////////////////////////

void
on_Ajout_ok_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
capteur capt;
	
GtkWidget *marque,*type,*id;
GtkWidget *output3;
GtkWidget *output;


output3=lookup_widget(objet,"label20");
int b;
output=lookup_widget(objet,"message_robot");

if(check==0)
{
	gtk_label_set_text(GTK_LABEL(output),"caucher la case precedente!");
}
else 
	{
	marque= lookup_widget(objet,"entry_marque");
	id= lookup_widget(objet,"entry_id");
	strcpy(capt.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
	printf(gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	if(x==0)
	{strcpy(capt.type,"temperature");}
	else
	if(x==1)
	{strcpy(capt.type,"Humidite");}
	strcpy(capt.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(capt.etat_def,"N/A");
	b=1;
	gtk_label_set_text(GTK_LABEL(output3),"Ajout Réussie !");
	ajouter_capteur(capt);
	}
	

}

/////////////////////////////////////////////////////////////////////////////////

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
gestion_capteur=create_gestion_capteur();
gtk_widget_show(gestion_capteur);

treeview_capt=lookup_widget(gestion_capteur,"treeview_capt");

afficher_capteurs(treeview_capt);
}

///////////////////////////////////////////////////////////////////////////////////

void
on_modif_ok_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	capteur capt;
	
GtkWidget *marque,*type,*id;
GtkWidget *output2;
output2=lookup_widget(objet,"label27");
int b;
id= lookup_widget(objet,"cb_id_modif");
marque= lookup_widget(objet,"entry_marque_modif");
type= lookup_widget(objet,"cb_type_modif");
strcpy(capt.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id)));
strcpy(capt.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
strcpy(capt.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
b=1;
gtk_label_set_text(GTK_LABEL(output2),"Modification Réussie !");

modifier_capteur(capt);
}

/////////////////////////////////////////////////////////////////////////////////////

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
gestion_capteur=create_gestion_capteur();
gtk_widget_show(gestion_capteur);

treeview_capt=lookup_widget(gestion_capteur,"treeview_capt");

afficher_capteurs(treeview_capt);
}

////////////////////////////////////////////////////////////////////////////////////////

void
on_supprim_ok_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{	capteur capt;
GtkWidget *input;
GtkWidget *output;
output=lookup_widget(objet,"label18");
int b;
input= lookup_widget(objet,"combobox_supp");
strcpy(capt.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
supprimer_capteur(capt);
b=1;
gtk_label_set_text(GTK_LABEL(output),"Suppression Réussie !");
}


///////////////////////////////////////////////////////////////////////////////////

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
gestion_capteur=create_gestion_capteur();
gtk_widget_show(gestion_capteur);

treeview_capt=lookup_widget(gestion_capteur,"treeview_capt");

afficher_capteurs(treeview_capt);

}

///////////////////////////////////////////////////////////////////////////////////

void
on_treeview_param_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gint* id;
	date* date_enr;
	horaire* horaire_enr;
	gfloat *valeur;
	parametres param;


	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &date_enr, 2, &horaire_enr, 3, &valeur  -1);

afficher_parametres(treeview);
}
}

///////////////////////////////////////////////////////////////////////////////////////

void
on_ajout_param_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter_parametres, *parametres;
	GtkWidget *combo;
	FILE *f;
	char id[30];
	parametres=lookup_widget(objet,"parametres");
	gtk_widget_destroy(parametres);
	ajouter_parametres = create_ajouter_parametres();
	combo=lookup_widget(ajouter_parametres,"cb_id");
	f=fopen("capteur.txt","r");
	while(fscanf(f,"%s %*s %*s %*s %*d %*d\n",id)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combo),id);
	}
	fclose(f);
	gtk_widget_show(ajouter_parametres);
}

//////////////////////////////////////////////////////////////////////////////////////////

void
on_param_ok_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
parametres param;

	GtkWidget *id, *jour, *mois, *annee, *heure, *minute, *val;
	id=lookup_widget(objet,"cb_id");
	jour=lookup_widget(objet,"spinbutton_jour");
	mois=lookup_widget(objet,"spinbutton_mois");
	annee=lookup_widget(objet,"spinbutton_annee");
	heure=lookup_widget(objet,"spinbutton_heure");
	minute=lookup_widget(objet,"spinbutton_minute");
	val=lookup_widget(objet,"entry_val");
	
	strcpy(param.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id)));
param.dateE.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
param.dateE.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
param.dateE.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
param.horaireE.heure=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(heure));
param.horaireE.minute=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(minute));
param.valeur=atof(gtk_entry_get_text(GTK_ENTRY(val)));

ajouter_parametres(param);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void
on_retour_param_clicked                (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter_parametres;
GtkWidget *parametres;
GtkWidget *treeview_param;
ajouter_parametres=lookup_widget(objet,"ajouter_parametres");

gtk_widget_destroy(ajouter_parametres);
parametres=lookup_widget(objet,"parametres");
parametres=create_parametres_();
gtk_widget_show(parametres);

treeview_param=lookup_widget(parametres,"treeview_param");

afficher_parametres(treeview_param);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void
on_temperature_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=0;
}
}

///////////////////////////////////////////////////////////////////////////////////////////

void
on_humidite_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=1;
}
}

///////////////////////////////////////////////////////////////////////////////////////

void
on_alarmantes_clicked                      (GtkButton      *button,
                                        gpointer         user_data)

{
GtkWidget  *output ;
int nb=0,i;
char etat_def[30];
char texte [200]="";
FILE *f =NULL;
capteur capt; 
f= fopen ("capteur.txt","r");
if (f!= NULL)
{ 
while (fscanf (f," %s %s %s %s %d %d\n",capt.id,capt.marque,capt.type,capt.etat_def,&capt.val_min,&capt.val_max)!=EOF)
{ if (strcmp (capt.etat_def,"Alarmantes")==0)
nb+=1;
}
sprintf (texte,"Le nombre des capteurs ayant des valeurs alarmantes est: %d",nb);
output=lookup_widget(button,("label105"));
gtk_label_set_text(GTK_LABEL(output),texte);
fclose (f);
return (nb);
}
}

/*
void
on_defec_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *chemin;
FILE *f =NULL;
GtkWidget  *output;
char texte[200]="";
int i;
capteur capt;
while (fscanf (f," %s %s %s %s %d %d\n",capt.id,capt.marque,capt.type,capt.etat_def,&capt.val_min,&capt.val_max)!=EOF)
{sprintf(texte,"le capteur avec l identifiant %d est le plus defaillant\n",i);}
output=lookup_widget(objet,("label110"));
gtk_label_set_text(GTK_LABEL(output),texte);
defectueux(chemin);
fclose(f);
}*/


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{check=1;}

}

