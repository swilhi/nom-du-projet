#ifdef HAVE_CONGIG_H
# include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parametres.h"
#include "capteur.h"
#include <gtk/gtk.h>

enum {
EID,
EDATE,
EHORAIRE,
EVALEUR,
COLUMNS
};


void afficher_parametres(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	date date_param;
	horaire horaire_param;
	char id[30];
	char date[30];
	char horaire[30];
	float valeur;

  	store= NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);

if (store==NULL) 
{

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("date",renderer,"text",EDATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("horaire",renderer,"text",EHORAIRE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",EVALEUR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

}
store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_FLOAT);
 
f=fopen("parametres.txt","r");
if (f==NULL)
{
return;
}
else
 {
	f= fopen("parametres.txt","a+");
	while (fscanf(f," %s %s %s %f \n",id,date,horaire,&valeur)!=EOF)
	{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,EID, id, EDATE, date, EHORAIRE, horaire,EVALEUR, valeur, -1);
	}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
}
}

void ajouter_parametres(parametres param)
{
	FILE *f;
	FILE *c;
	capteur capt;
	FILE *tempo;
	char date[30];
	char horaire[30];
	tempo=fopen("tempo.txt","a+");
	c=fopen("capteur.txt","a+b");
	while(fscanf(c,"%s %s %s %s %d %d\n",capt.id,capt.marque,capt.type,capt.etat_def,&capt.val_min,&capt.val_max)!=EOF)
	{
		if(strcmp(capt.id,param.id)==0)
		{
			if((param.valeur<capt.val_min) || (param.valeur>capt.val_max))
			{
				strcpy(capt.etat_def,"Alarmantes");
			}
			else
			{
				strcpy(capt.etat_def,"Correct");
			}
		}
		fprintf(tempo,"%s %s %s %s %d %d\n",capt.id,capt.marque,capt.type,capt.etat_def,capt.val_min,capt.val_max);
		
	}
	fclose(c);
	fclose(tempo);
	remove("capteur.txt");
	rename("tempo.txt","capteur.txt");
	sprintf(date,"%d/%d/%d", param.dateE.jour,param.dateE.mois,param.dateE.annee);
	if(param.horaireE.minute<10){
		sprintf(horaire,"%d:0%d",param.horaireE.heure,param.horaireE.minute);
	}
	else
	{
	sprintf(horaire,"%d:%d",param.horaireE.heure,param.horaireE.minute);
	}
	
    	f=fopen("parametres.txt","a+b");
  	if(f!=NULL)
    	{
     	fprintf(f,"%s %s %s %f\n",param.id,date,horaire,param.valeur);
	
        fclose(f);
   	}
}

void afficher_alarmantes(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
}

