#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"
#include "parametres.h"
#include"tree.h"
#include"CRUD.h"
#include "reclamation.h"
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
FILE*f=NULL;
void
on_AcceuilGestion_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p;
GtkWidget *p1;
GtkWidget *p2;
gtk_widget_hide (acceuil);
gestion = create_gestion ();
p=lookup_widget(gestion,"treeview1");
p1=lookup_widget(gestion,"treeview2");
//p2=lookup_widget(gestion,"treeview3");
i=0;
j=0;
k=0;
Afficherproduit(p,"produits.txt");
Afficherproduit1(p1,"produits.txt");
gtk_widget_show (gestion);
}


void
on_Ajouterproduit_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
 produit c;
GtkWidget *entryNom;
GtkWidget *entryid;
GtkWidget *entryprix;
GtkWidget *entrydate_entree;
GtkWidget *entrydate_expiration;
GtkWidget *labelid;
GtkWidget *labelnom;
GtkWidget *labelprix;
GtkWidget *labeldate_entree;
GtkWidget *labeldate_expiration;
GtkWidget *existe;
GtkWidget* success;
GtkWidget *entryrangement;
GtkWidget *entryfour;
GtkWidget *labelfour;
int b=1;
 GtkWidget *cal;
 GtkWidget *cal2;
GtkWidget *calendar1 ; 
GtkWidget *calendar2 ; 
GtkWidget *input7;
GtkWidget *input8;
GtkWidget *input9;
GtkWidget *input10;
GtkWidget *input11;
GtkWidget *input12;
GtkWidget *input13;

int jj, mm, aa;
int jj1, mm1, aa1;
int quantite; 
char q[20];

entryid=lookup_widget(gestion,"entry5"); //lookup tlawej 3la entry "entry5" fil window w t'affectiha ll ll entryid
entryNom=lookup_widget(gestion,"entry1");
entryprix=lookup_widget(gestion,"entry2");
entrydate_entree=lookup_widget(gestion,"entry4");
entrydate_expiration=lookup_widget(gestion,"entry3");
entryfour=lookup_widget(gestion,"entryfour");

labelfour=lookup_widget(gestion,"labelfour");
labelid=lookup_widget(gestion,"label13");
labelnom=lookup_widget(gestion,"label7");
labelprix=lookup_widget(gestion,"label8");
labeldate_entree=lookup_widget(gestion,"label9");
labeldate_expiration=lookup_widget(gestion,"label10");
existe=lookup_widget(gestion,"label34");
success=lookup_widget(gestion,"label35");
input7=lookup_widget(button,"spinbuttonquantity"); 
        
	
	quantite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7)); 
	sprintf(q,"%d",quantite); // tconverti men entier l char
        strcpy(c.quantity,q);

        strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(entryid) ) );
        strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(entryNom) ) );
        strcpy(c.prix,gtk_entry_get_text(GTK_ENTRY(entryprix) ) );
strcpy(c.fournisseur,gtk_entry_get_text(GTK_ENTRY(entryfour) ) );


entryrangement=lookup_widget(gestion,"combobox1");
strcpy(c.rangement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryrangement)));


		


  input8=lookup_widget(button,"spinbuttonjoure"); 
input9=lookup_widget(button,"spinbuttonmoise");
input10=lookup_widget(button,"spinbuttonanneee");

  input11=lookup_widget(button,"spinbuttonjourex"); 
input12=lookup_widget(button,"spinbuttonmoisex");
input13=lookup_widget(button,"spinbuttonanneeex");



        c.date1.jour  = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
	c.date1.mois  = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
	c.date1.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input10)); 

c.date2.jour  = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input11));
	c.date2.mois  = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input12));
	c.date2.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input13)); 



 gtk_widget_hide (success);
// controle saisie
if(strcmp(c.id,"")==0){
		  gtk_widget_show (labelid);
b=0;
}
else {
		  gtk_widget_hide(labelid);
}

if(strcmp(c.nom,"")==0){
		  gtk_widget_show (labelnom);
b=0;
}
else {
		  gtk_widget_hide(labelnom);
}
if(strcmp(c.prix,"")==0){
		  gtk_widget_show (labelprix);
b=0;
}
else {
		  gtk_widget_hide(labelprix);
}
/*if(strcmp(c.date_entree,"")==0){
		  gtk_widget_show (labeldate_entree);
b=0;
}
else {
		  gtk_widget_hide(labeldate_entree);
}
if(strcmp(c.date_expiration,"")==0){
		  gtk_widget_show (labeldate_expiration);
b=0;
}
else {
		  gtk_widget_hide(labeldate_expiration);
}


*/

if(strcmp(c.fournisseur,"")==0){
		  gtk_widget_show (labelfour);
b=0;
}
else {
		  gtk_widget_hide(labelfour);
}



if(b==1){

        if(exist_produit(c.id)==1)
        {

				  gtk_widget_show (existe);
        }
        else {
						  gtk_widget_hide(existe);

                        f = fopen("produits.txt", "a+");
                        fprintf(f, "%s %s %s %d/%d/%d %d/%d/%d %s %s %s\n", c.id,c.nom,c.prix,c.date1.annee,c.date1.mois,c.date1.jour,c.date2.annee,c.date2.mois,c.date2.jour,c.fournisseur,c.rangement,c.quantity);
                        fclose(f);
                       

                        gtk_widget_show(success);

                   
        }
//mise a jour du treeView
        GtkWidget* p=lookup_widget(gestion,"treeview1");

        Afficherproduit(p,"produits.txt");
}

}





void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)//signale du treeView (Double click)
{
	gchar *id;
        gchar *nom;
        gchar *prix;
        gchar *date_entree;
        gchar *date_expiration;
        gchar *fournisseur;
	gchar *rangement;
        gchar *quantity;
        int x;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestion,"treeview1");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
		gtk_widget_hide(lookup_widget(gestion,"label37"));//cacher label modifier avec succees
		
                gtk_tree_model_get (model,&iter,0,&id,1,&nom,2,&prix,3,&date_entree,4,&date_expiration,5,&fournisseur,6,&rangement,7,&quantity,-1);//recuperer les information de la ligne selectionneé
		//remplir les champs de entry
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entry6")),nom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entry7")),prix);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entry9")),date_entree);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entry8")),date_expiration);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entry_modif_four")),fournisseur);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entry_modif_quantity")),quantity);
          


                GtkWidget* msgid=lookup_widget(gestion,"label20");
                GtkWidget* msg1=lookup_widget(gestion,"label36");
                gtk_label_set_text(GTK_LABEL(msgid),id);
                gtk_widget_show(msgid);
                gtk_widget_show(msg1);
                gtk_widget_show(lookup_widget(gestion,"button4n"));//afficher le bouton modifier
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(gestion,"notebook1")));//redirection vers la page precedente
        }



}


void
on_Supprimerproduit_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        label=lookup_widget(gestion,"label23");
        p=lookup_widget(gestion,"treeview1");




        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_produit(id);// supprimer la ligne du fichier

           gtk_widget_hide (label);}
else{
                gtk_widget_show (label);
        }

}


void
on_chercherproduit_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelnom;
GtkWidget *nbResultat;
GtkWidget *message;
char nom[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(gestion,"entry10");
labelnom=lookup_widget(gestion,"label28");
p1=lookup_widget(gestion,"treeview2");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(entry)));

if(strcmp(nom,"")==0){
  gtk_widget_show (labelnom);b=0;
}else{
b=1;
gtk_widget_hide (labelnom);}

if(b==0){return;}else{

nb=Chercherproduit(p1,"produits.txt",nom);
/* afficher le nombre de resultats obtenue par la recherche */
sprintf(chnb,"%d",nb);//conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
nbResultat=lookup_widget(gestion,"label27");
message=lookup_widget(gestion,"label26");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

gtk_widget_show (nbResultat);
gtk_widget_show (message);



}

}



void
on_Modifierproduit_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
     GtkWidget *combobox2;
     combobox2=lookup_widget(button,"combobox2");
 produit c;
int quantite ; 
char q[20];

        strcpy(c.id,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion,"label20"))));
        strcpy(c.rangement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion,"combobox2")))); 
        strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry6"))));
        strcpy(c.prix,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry7"))));
        strcpy(c.date_entree,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry9"))));
        strcpy(c.date_expiration,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry8"))));
        strcpy(c.fournisseur,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry_modif_four"))));
strcpy(c.quantity,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry_modif_quantity"))));
        //quantite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(gestion,"spinbuttonquantity2"))); 
	

        // sprintf(q,"%d",quantite);
       // strcpy(c.quantity,q);
        supprimer_produit(c.id);
        ajouter_produit(c);
//mise ajour du tree view 
        Afficherproduit(lookup_widget(gestion,"treeview1"),"produits.txt");
		gtk_widget_show(lookup_widget(gestion,"label37"));

}

void
on_GestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
gtk_widget_destroy (gestion);

}


int x;
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


void
on_Ajout_ok_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
capteur capt;
	
GtkWidget *marque,*type,*id;
GtkWidget *output3;
output3=lookup_widget(objet,"label20");
int b;
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
GtkWidget *output;
output=lookup_widget(objet,"label18");
int b;
input= lookup_widget(objet,"combobox_supp");
strcpy(capt.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
supprimer_capteur(capt);
b=1;
gtk_label_set_text(GTK_LABEL(output),"Suppression Réussie !");
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


void
on_temperature_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=0;
}
}


void
on_humidite_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=1;
}
}


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
on_capt_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *acceuil;
GtkWidget *ajouter_capteur;
ajouter_capteur = create_ajouter_capteur ();
gtk_widget_show (ajouter_capteur);
gtk_widget_destroy (acceuil);

}

////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
/*

void
on_button4fr_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_buttonferyel_retour_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button3_rec_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonsafa_retour_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_buttonkalthoum_retour_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_checkbutton1fr_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_buttonother_retour_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_fr_retour_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}

*/
///////////////////////////////////////////////////////////////////////
/////////////////////   feryel   ///////////////////////////////////////


int x1;
int x2;
int choix[]={0};




///////////////////////////////////////////////////////
void
on_button1_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *windowAjout ;
windowAjout=create_fenetre_ajouter();
gtk_widget_show(windowAjout);

GtkWidget *fenetre_menu;
fenetre_menu=lookup_widget(objet,"fenetre_menu");
gtk_widget_destroy(fenetre_menu);

}

////////////////////////////////////////

void
on_button7_add_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
reclamation r;
GtkWidget *fenetre_ajouter;
GtkWidget *output66;

GtkWidget *input1;
GtkWidget *input2;
char texte1[100];
char texte2[100];



output66=lookup_widget(objet_graphique,"label30fr");

input1=lookup_widget(objet_graphique,"entry11");
input2=lookup_widget(objet_graphique,"entry12");
if(x1==1)
strcpy(texte1,"Nutrition");
else 
strcpy(texte1,"Hebergement");

if(x2==1)
strcpy(texte2,"approuvée");
else
strcpy(texte2,"non_approuvée");


strcpy(r.msg,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.type,texte1);
strcpy(r.etat,texte2);
strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(input2)));


ajouter_reclamation( r);//ajout de reclamation
gtk_label_set_text(GTK_LABEL(output66),"votre réclamation est bien ajoutée");


}


void
on_radiobutton3_valide_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x2=1;}
}


void
on_radiobutton2_heb_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x1=2;}
}


void
on_radiobutton1_nut_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x1=1;}
}


void
on_radiobutton4_n_valide_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x2=2;}
}

///////////////////////AFFICHER////////////////////////////////////////



void
on_button2_afficher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAfficher;
GtkWidget *treeview3;

windowAfficher=lookup_widget(objet,"fenetre_afficher");
windowAfficher=create_fenetre_afficher();

gtk_widget_show(windowAfficher);

GtkWidget *fenetre_menu;
fenetre_menu=lookup_widget(objet,"fenetre_menu");
gtk_widget_destroy(fenetre_menu);



treeview3=lookup_widget(windowAfficher,"treeview3");

afficher_reclamation(treeview3);


}





void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* msg;
	gchar* type;
	gchar* etat;
	gchar* id;
	reclamation r;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
		//obtenir des valeurs de la ligne selectionnée

		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&msg,1,&type,2,&etat,3,&id,-1);
		//copie
		strcpy(r.msg,msg);
		strcpy(r.type,type);
		strcpy(r.etat,etat);
		strcpy(r.id,id);
		//appel de la fct suppression
		supprimer_reclamation(r);
		//mise a jour
		afficher_reclamation(treeview);
	}
}

////////////////////////////////////////////////////////

void
on_button1_retour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
fenetre_afficher=lookup_widget(button,"fenetre_afficher");
gtk_widget_destroy(fenetre_afficher);
}

///////////////////////////////SUPPRIMER/////////////////////////////////

void
on_button3_supprimer_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowAfficher;
GtkWidget *treeview3;

windowAfficher=lookup_widget(objet,"fenetre_afficher");
windowAfficher=create_fenetre_afficher();

gtk_widget_show(windowAfficher);


GtkWidget *fenetre_menu;
fenetre_menu=lookup_widget(objet,"fenetre_menu");
gtk_widget_destroy(fenetre_menu);

treeview3=lookup_widget(windowAfficher,"treeview3");

afficher_reclamation(treeview3);
}



//////////////////////////RECHERCHER//////////////////////////////////

void
on_button2_recherche_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowRecherche;
windowRecherche=create_fenetre_rechercher1 ();
gtk_widget_show(windowRecherche);



GtkWidget *fenetre_menu;
fenetre_menu=lookup_widget(objet,"fenetre_menu");
gtk_widget_destroy(fenetre_menu);

}


void
on_button3_rec_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_rechercher1;
GtkWidget *windowRechercher2;
GtkWidget *treeview4;
GtkWidget *input1;
reclamation r;
FILE *f1;
FILE *f2;

int d=0,i;
char c,msg[100],type[100],etat[100],id[100],ident[100];
reclamation rec[100];


input1=lookup_widget(objet,"entry13");
strcpy(ident,gtk_entry_get_text(GTK_ENTRY(input1)));

// rechercher
f1=fopen("reclamation.txt","r+");
while((c=fgetc(f1)) !=EOF )
 {
  if(c=='\n')
  d++;
 }
fclose(f1);

f1=fopen("reclamation.txt","r");
for (i=0;i<d;i++)
{
fscanf(f1,"%s %s %s %s\n",rec[i].msg,rec[i].type,rec[i].etat,&rec[i].id);
if (strcmp(ident,rec[i].id)==0)
{
strcpy(id,rec[i].id);
strcpy(msg,rec[i].msg);
strcpy(type,rec[i].type);
strcpy(etat,rec[i].etat);
}
}
if (strcmp(id,ident)==0)
	{
	strcpy(r.id,id);
	strcpy(r.msg,msg);
	strcpy(r.type,type);
	strcpy(r.etat,etat);

	ajouter_recherche(r);
	}
else
	{
	strcpy(r.id,"introuvable!");
	strcpy(r.msg,"introuvable!");
	strcpy(r.type,"introuvable!");
	strcpy(r.etat,"introuvable!");
	
	ajouter_recherche(r);

	
	}
	

windowRechercher2=lookup_widget(objet,"fenetre_rechercher2");
windowRechercher2=create_fenetre_rechercher2();

gtk_widget_show(windowRechercher2);

treeview4=lookup_widget(windowRechercher2,"treeview4");

chercher_reclamation(treeview4);


fenetre_rechercher1=lookup_widget(objet,"fenetre_rechercher1");
gtk_widget_destroy(fenetre_rechercher1);
}






void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* msg;
	gchar* type;
	gchar* etat;
	gchar* id;
	reclamation r;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
		//obtenir des valeurs de la ligne selectionnée

		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&msg,1,&type,2,&etat,3,&id,-1);
		//copie
		strcpy(r.msg,msg);
		strcpy(r.type,type);
		strcpy(r.etat,etat);
		strcpy(r.id,id);
		//appel de la fct suppression
		supprimer_reclamation(r);
		//mise a jour
		chercher_reclamation(treeview);

	}
}


void
on_button4fr_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter;
GtkWidget *fenetre_menu;
fenetre_ajouter=lookup_widget(objet,"fenetre_ajouter");
gtk_widget_destroy(fenetre_ajouter);
fenetre_menu=create_fenetre_menu();
gtk_widget_show(fenetre_menu);


}



///////////////////////MODIFIER /////////////////////////////////







void
on_checkbutton1fr_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{choix[0]=1;}

}


void
on_button4_modifier_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *output;
GtkWidget *input1,*input2,*combobox3,*combobox4;
FILE *f;

reclamation r;
int d=0,i;
char c,msg[100],type[100],etat[100],id[100],ident[100],message[100];
char text1[100],text2[100];
reclamation rec[100];

/// collect donné ////

input1=lookup_widget(objet_graphique,"entry4");
strcpy(ident,gtk_entry_get_text(GTK_ENTRY(input1)));

input2=lookup_widget(objet_graphique,"entry5");
strcpy(message,gtk_entry_get_text(GTK_ENTRY(input2)));

combobox3=lookup_widget(objet_graphique,"combobox3");

strcpy(text1,gtk_combo_box_get_active_text(combobox3));

combobox4=lookup_widget(objet_graphique,"combobox4");
strcpy(text2,gtk_combo_box_get_active_text(combobox4));
strcpy(r.msg,message);
strcpy(r.type,text1);
strcpy(r.etat,text2);
strcpy(r.id,ident);



output=lookup_widget(objet_graphique,"label26fr");

/// rechercher////

f=fopen("reclamation.txt","r+");
while((c=fgetc(f)) !=EOF )
 {
  if(c=='\n')
  d++;
 }
fclose(f);

f=fopen("reclamation.txt","r");
for (i=0;i<d;i++)
{
fscanf(f,"%s %s %s %s\n",rec[i].msg,rec[i].type,rec[i].etat,&rec[i].id);
if (strcmp(ident,rec[i].id)==0)
{
strcpy(id,rec[i].id);
}
}

if  ((strcmp(id,ident)==0)&&(choix[0]=1))
	{
	modifier_reclamation(r) ;// modifier 
	gtk_label_set_text(GTK_LABEL(output),"votre réclamation est bien modifiée");
	}





else
	
	gtk_label_set_text(GTK_LABEL(output),"pas de modification! veuillez réecrire votre identifiant correctement");
	

}




void
on_button6_modifier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowModifier;
windowModifier=create_fenetre_modifier ();
gtk_widget_show(windowModifier);


GtkWidget *fenetre_menu;
fenetre_menu=lookup_widget(objet,"fenetre_menu");
gtk_widget_destroy(fenetre_menu);

}


////////////////////////////PLUS RECLAMEE//////////////////////////

void
on_button5_plus_reclamee_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_plusreclame;



GtkWidget *fenetre_menu;
fenetre_menu=lookup_widget(objet_graphique,"fenetre_menu");
gtk_widget_destroy(fenetre_menu);

fenetre_plusreclame=lookup_widget(objet_graphique,"fenetre_plusreclame");
fenetre_plusreclame=create_fenetre_plusreclame();
gtk_widget_show(fenetre_plusreclame);
int i,d=0,h=0,n=0;
char c;
char choix_rec[100];
FILE *f;
reclamation rec[100];
GtkWidget *output25;
output25=lookup_widget(objet_graphique,"labelbest");





f=fopen("reclamation.txt","r+");
while((c=fgetc(f)) !=EOF )
 	{
  	if(c=='\n')
  	d++;
 	}
fclose(f);

f=fopen("reclamation.txt","r");
 for (i=0;i<d;i++)
	{
	fscanf(f,"%s %s %s %s\n",rec[i].msg,rec[i].type,rec[i].etat,&rec[i].id);
	if(strcmp(rec[i].type,"Nutrition")==0)
		n++;
	else
		h++;
	}
       
         if (n>h)
	{
	
	gtk_label_set_text(GTK_LABEL(output25),"Nutrition");
        

	}
	
         else if(n<h)
	{
	  

	gtk_label_set_text(GTK_LABEL(output25),"Hebergement");

	}
         else
	{
	  
	gtk_label_set_text(GTK_LABEL(output25),"heb/nut");
	 
	
	}}








/*
void
on_button_r_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter;
GtkWidget *fenetre_menu;
fenetre_ajouter=lookup_widget(button,"fenetre_ajouter");
gtk_widget_destroy(fenetre_ajouter);
fenetre_menu=create_fenetre_menu();
gtk_widget_show(fenetre_menu);

}
*/

void
on_button_fr_retour_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_plusreclame;
GtkWidget *fenetre_menu;
fenetre_plusreclame=lookup_widget(objet,"fenetre_plusreclame");
gtk_widget_destroy(fenetre_plusreclame);
fenetre_menu=create_fenetre_menu();
gtk_widget_show(fenetre_menu);
}

/*
void
on_button3_rec_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}



void
on_checkbutton1fr_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button4fr_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}
*/


void
on_buttonferyel_retour_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
GtkWidget *fenetre_menu;
fenetre_afficher=lookup_widget(button,"fenetre_afficher");
gtk_widget_destroy(fenetre_afficher);
fenetre_menu=create_fenetre_menu();
gtk_widget_show(fenetre_menu);
}


void
on_buttonsafa_retour_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_rechercher1;
GtkWidget *fenetre_menu;
fenetre_rechercher1=lookup_widget(button,"fenetre_rechercher1");
gtk_widget_destroy(fenetre_rechercher1);
fenetre_menu=create_fenetre_menu();
gtk_widget_show(fenetre_menu);
}


void
on_buttonkalthoum_retour_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_rechercher2;
GtkWidget *fenetre_menu;
fenetre_rechercher2=lookup_widget(button,"fenetre_rechercher2");
gtk_widget_destroy(fenetre_rechercher2);
fenetre_menu=create_fenetre_menu();
gtk_widget_show(fenetre_menu);
}


void
on_buttonother_retour_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier;
GtkWidget *fenetre_menu;
fenetre_modifier=lookup_widget(button,"fenetre_modifier");
gtk_widget_destroy(fenetre_modifier);
fenetre_menu=create_fenetre_menu();
gtk_widget_show(fenetre_menu);
}
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////




void
on_button111_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *acceuil;
GtkWidget *fenetre_menu;

gtk_widget_destroy(acceuil);
fenetre_menu=create_fenetre_menu();
gtk_widget_show(fenetre_menu);
}

