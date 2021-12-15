#ifdef HAVE_CONGIG_H
# include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "capteur.h"
#include <gtk/gtk.h>
enum { //enum is created wherein the different columns are enumerated
EID,// identifiant 
EMARQUE, // nom
ETYPE, // humidité ou température 
EDEF, 
EMIN,
EMAX,
COLUMNS // affichage en colonne 
};
// tree view is composed with 3 objects GtkTreeView ,GtkTreeViewColumn, GtkCellRenderer


void afficher_capteurs(GtkWidget *liste) //gtkwidget : nouveau widget 
{
	GtkCellRenderer *renderer;// pour le treeview: permet d'afficher la liste
//renderer:The purpose of the cell renderers is to provide extensibility to the widget and to allow multiple ways of rendering the same type of data
	GtkTreeViewColumn *column;// the view column:is the object that GtkTreeView uses to organize the vertical columns in the tree view
	GtkTreeIter iter;
	GtkListStore *store;//is used to model list widgets
// treeview pour l'affichage des paramétres:dans la 2éme tache je vais lier les treeview ensemble pour qu'elle actualise automatiquement 
  char id[30];
  char marque[30];
  char type[30];
  char etat_def[30];
  int val_min;
  int val_max;
  
 
  store= NULL;
FILE *f; // f variable de type file
store=gtk_tree_view_get_model(liste);// multiple views can be created of a single model

if (store==NULL) 
{

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("etat_def",renderer,"text",EDEF, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("val_min",renderer,"text",EMIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("val_max",renderer,"text",EMAX, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

}
store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT);
 


f=fopen("capteur.txt","r");// ouverture d'un fichier texte en lecture (doit exister)
if (f==NULL)
{
return;
}
else
 {
	f= fopen("capteur.txt","a+");// création d'un fichier: les données seront ajoutées a la fin du fichier précedente 
	while (fscanf(f,"%s %s %s %s %d %d\n",id,marque,type,etat_def,&val_min,&val_max)!=EOF)// parcourir un fichier texte
	{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, EID, id, EMARQUE, marque, ETYPE, type, EDEF, etat_def, EMIN, val_min, EMAX, val_max,-1);
	}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
}
}


void ajouter_capteur(capteur capt)
{
	
    FILE *f; // f variable de type file
	if(strcmp(capt.type,"Humidite")==0){
		capt.val_min=10;
		capt.val_max=90;	
	}
	else{
		capt.val_min=0;
		capt.val_max=45;
	}
	
    	f=fopen("capteur.txt","a+b"); // chemin:chemin d'acces,mode lecture et ecriture : caractére mode d'acces: ouvrir un fichier en mode ajout 
  	if(f!=NULL) // si le fichier est ouvert 
    	{
     	fprintf(f,"%s %s %s %s %d %d\n",capt.id,capt.marque,capt.type,capt.etat_def,capt.val_min,capt.val_max);
	
        fclose(f);// annulation entre le fichier et le lot de données
   	}
}

void modifier_capteur(capteur c)
{
	capteur capt;
	FILE *f, *tempo;
	f=fopen("capteur.txt","a+");// ouverture d'un fichier txt : peut ne pas exister
	tempo=fopen("tempo.txt","a+");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %d\n",capt.id,capt.marque,capt.type,capt.etat_def,&capt.val_min,&capt.val_max)!=EOF) // la fin de fichier est detecter par le end of file : parcours de fichier 
		{
			if(strcmp(capt.id,c.id)==0) // faire le comparaison entre tempo( type c) w capteur(type capt)
			{
				if(strcmp(c.type,"Humidite")==0){
					c.val_min=10;
					c.val_max=90;	
				}
				else{
					c.val_min=0;
					c.val_max=45;
				}
  				strcpy(c.etat_def,capt.etat_def);// copie une chaine de caractére dans une autre chaine 
     				fprintf(tempo,"%s %s %s %s %d %d\n",c.id,c.marque,c.type,c.etat_def,c.val_min,c.val_max);
   			
			}
			else{
				fprintf(tempo,"%s %s %s %s %d %d\n",capt.id,capt.marque,capt.type,capt.etat_def,capt.val_min,capt.val_max);
			}
		}
	}
	fclose(f);
	fclose(tempo);
	remove("capteur.txt");
	rename("tempo.txt","capteur.txt");
}

void supprimer_capteur(capteur capt)
{
	FILE *f=NULL, *tempo;
	capteur c;
	f=fopen("capteur.txt","a+");
	tempo=fopen("tempo.txt","a+");
	if (f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %d\n",c.id,c.marque,c.type,c.etat_def,&c.val_min,&c.val_max)!=EOF)
	
		{
			if(strcmp(c.id,capt.id)!=0)
			{
				fprintf(tempo,"%s %s %s %s %d %d\n",c.id,c.marque,c.type,c.etat_def,c.val_min,c.val_max);
	
			}
		}
	}
fclose(f);
fclose(tempo); // fermeture de fichier 
remove("capteur.txt");// supprimer le fichier capteur.txt
rename("tempo.txt","capteur.txt");//renommer le fichier tempo.txt en capteur.txt
	
}






