#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"reclamation.h"
#include<gtk/gtk.h>

enum
{
    EID,
    ENOM,
    EPRENOM,
    ETYPE,
    EDESCRIPTION,
    EDATE_RECLAMATION,
    EHEURE_RECLAMATION,
    COLUMNS,
   
};





///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
void ajouter(reclamation r)
{
FILE  *f;
f=fopen("reclamation.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s  \n",r.id,r.nom,r.prenom,r.type,r.description,r.date_reclamation,r.heure_reclamation);
fclose(f);
}

}
///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

void afficher(GtkWidget *liste)
{

GtkCellRenderer *renderer;
GtkTreeViewColumn  *column;
GtkTreeIter *iter;
GtkListStore *store;

    char id[20];
    gchar nom[20];
    gchar prenom[20];
    gchar type[20];
    gchar description[1000];
    gchar date_reclamation[30];
    gchar heure_reclamation[40];
   
reclamation r;

FILE *f;

store=gtk_tree_view_get_model(liste);
if (store==NULL)
     {




 renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("id",renderer, "text", EID,NULL );
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
gtk_tree_view_column_set_expand(column,TRUE);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer, "text", ENOM , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
gtk_tree_view_column_set_expand(column,TRUE);
	

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer, "text", EPRENOM , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
gtk_tree_view_column_set_expand(column,TRUE);
	

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("type",renderer, "text", ETYPE , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
gtk_tree_view_column_set_expand(column,TRUE);
	

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("description",renderer, "text", EDESCRIPTION , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
gtk_tree_view_column_set_expand(column,TRUE);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("date_reclamation",renderer, "text", EDATE_RECLAMATION,NULL );
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
gtk_tree_view_column_set_expand(column,TRUE);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("heure_reclamation",renderer, "text", EHEURE_RECLAMATION,NULL );
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
gtk_tree_view_column_set_expand(column,TRUE);

}



store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("reclamation.txt","r");
if(f==NULL)
{ 
   return;
}
else
{           f=fopen("reclamation.txt","a+");
            while( fscanf(f,"%s %s %s %s %s %s %s  ",id, r.nom, r.prenom, r.type, r.description,r.date_reclamation,r.heure_reclamation)!= EOF)

   {   
         gtk_list_store_append(store ,&iter);
         gtk_list_store_set(store,&iter,EID,id,ENOM,r.nom,EPRENOM,r.prenom,ETYPE,r.type,EDESCRIPTION,r.description,EDATE_RECLAMATION,r.date_reclamation,EHEURE_RECLAMATION,r.heure_reclamation,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref(store);
   }
}





	

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////


 int recherche (char id[])
    {
        FILE*f=NULL;
        reclamation r;
	int x=0;
        f=fopen("reclamation.txt","r");
        while( fscanf(f,"%s %s %s %s %s %s %s  ",r.id, r.nom, r.prenom, r.type, r.description,r.date_reclamation,r.heure_reclamation)!= EOF)
        {
            if(strcmp(r.id,id)==0)
            {
                x=1;
            }
           
        }
        fclose(f);
	return x;
    }
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

void modifier()
    {
        FILE*f=NULL;
        FILE*f1=NULL;
        reclamation r,r1 ;
        
        f=fopen("reclamation.txt","r");
        f1=fopen("new.txt","w+");
        while( fscanf(f,"%s %s %s %s %s %s %s  ",r.id, r.nom, r.prenom, r.type, r.description,r.date_reclamation,r.heure_reclamation)!= EOF)
        {
            if( r.id == r1.id)
            {
                fprintf(f1,"%s %s %s %s %s %s %s   \n",r1.id, r1.nom, r1.prenom, r1.type, r1.description,r1.date_reclamation,r1.heure_reclamation);
            }
            else
            {
                fprintf(f1,"%s %s %s %s %s %s %s   \n",r.id, r.nom, r.prenom, r.type, r.description,r.date_reclamation,r.heure_reclamation);
            }

        }
        fclose(f);
        fclose(f1);

        remove("reclamation.txt");
        rename("new.txt","reclamation.txt");
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sercive(char texte[])
    {
        int p,h;
        FILE*f=NULL;
        reclamation r;
        f=fopen("reclamation.txt","r");
        p=0;
        h=0;
        while( fscanf(f,"%s %s %s %s %s %s %s  ",r.id, r.nom, r.prenom, r.type, r.description,r.date_reclamation,r.heure_reclamation)!= EOF)
        {
            if(strcmp("resto",r.type)==0)
            {
                p++;
            }
            if(strcmp("foyer",r.type)==0)
            {
                h++;
            }
            if(p>h)
            {
                strcpy(texte,"la restauration est le service le plus reclamé");
            }
            if(h>p)
            {
                strcpy(texte,"foyer est le service le plus reclamé");
            }
        }
    }
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

void supprimer(reclamation r, char *recl)

{
reclamation c;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(recl,"r");
g=fopen("aux.txt","w");
if(f!=NULL&&g!=NULL){
while( fscanf(f,"%s %s %s %s %s %s %s  ",r.id, r.nom, r.prenom, r.type, r.description,r.date_reclamation,r.heure_reclamation)!= EOF)
{
if(c.id!=r.id)
fprintf(f,"%s %s %s %s %s %s %s  \n",r.id,r.nom,r.prenom,r.type,r.description,r.date_reclamation,r.heure_reclamation);
}
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"l'utilisateur est supprimé avec succès");
switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(pInfo);
break;
}
fclose(f);
fclose(g);
remove(recl);
rename("aux.txt",recl);
}
}



