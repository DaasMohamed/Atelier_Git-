

#include<gtk/gtk.h>

typedef struct
{
    char id[200];
    char nom[20];
    char prenom[20];
    char type[20];
    char description[1000];
    char date_reclamation[30] ;
    char heure_reclamation[30] ;
} reclamation;


void ajouter(reclamation r);
void afficher(GtkWidget *liste);
int recherche (char id[]);
void supprimer(reclamation r, char *recl);
void sercive(char texte[]);





