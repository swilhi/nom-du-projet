#include<gtk/gtk.h>


typedef struct date {
int jour;
int mois;
int annee;
}date;
typedef struct horaire {
int heure;
int minute;
}horaire;
typedef struct parametres{
char id[30];
date dateE;
horaire horaireE;
float valeur;
}parametres;


void afficher_parametres(GtkWidget *liste);
void ajouter_parametres(parametres);

void afficher_alarmantes(GtkWidget *liste);
