#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>


void ajouter_produit( produit c){
FILE*f=NULL;
f=fopen("produits.txt","a+");//(+) creation du fichier sil nexsite pas
fprintf(f,"%s %s %s %s %s %s %s %s\n",c.id,c.nom,c.prix,c.date_entree,c.date_expiration,c.fournisseur,c.rangement,c.quantity);
fclose(f);

}

int exist_produit(char*id){
FILE*f=NULL;
 produit c;
f=fopen("produits.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",c.id,c.nom,c.prix,c.date_entree,c.date_expiration,c.fournisseur,c.rangement,c.quantity)!=EOF){
if(strcmp(c.id,id)==0)return 1;
}
fclose(f);
return 0;
}


void supprimer_produit(char*id){
FILE*f=NULL;
FILE*f1=NULL;
produit c ;
f=fopen("produits.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",c.id,c.nom,c.prix,c.date_entree,c.date_expiration,c.fournisseur,c.rangement,c.quantity)!=EOF){
if(strcmp(id,c.id)!=0)fprintf(f1,"%s %s %s %s %s %s %s %s\n",c.id,c.nom,c.prix,c.date_entree,c.date_expiration,c.fournisseur,c.rangement,c.quantity);
}
fclose(f);
fclose(f1);
remove("produits.txt");
rename("ancien.txt","produits.txt");
}















