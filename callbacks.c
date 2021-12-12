#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamation.h"


void
on_button_ajouter_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
 reclamation r;

 GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7;
 GtkWidget *fenetre_ajouter;

fenetre_ajouter=lookup_widget(objet,"fenetre_ajouter");

input1=lookup_widget(objet,"entry_id");
input2=lookup_widget(objet,"entry_nom");
input3=lookup_widget(objet,"entry_prenom");
input4=lookup_widget(objet,"entry_type");
input5=lookup_widget(objet,"entry_description");
input6=lookup_widget(objet,"entry_date_reclamation");
input7=lookup_widget(objet,"YM_combobox_heure");



strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(r.type,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(r.description,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(r.date_reclamation,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(r.heure_reclamation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));

ajouter(r);


}


void
on_button_afficher_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter;
GtkWidget *fenetre_afficher;
GtkWidget *treeview_afficher;

fenetre_ajouter=lookup_widget(objet,"fenetre_ajouter");

gtk_widget_destroy(fenetre_ajouter);
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);

treeview_afficher=lookup_widget(fenetre_afficher,"treeview_afficher");
afficher(treeview_afficher);


}


void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter,*fenetre_afficher;
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
gtk_widget_destroy(fenetre_afficher);
fenetre_ajouter=create_fenetre_ajouter();
gtk_widget_show(fenetre_ajouter);

}


void
on_treeview_afficher_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
 GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* prenom;
	gchar* type;
	gchar* description;
        gchar* date_reclamation;
	reclamation r;

       GtkWidget *pInfo;

   GtkTreeModel *model = gtk_tree_view_get_model(treeview);

 if(gtk_tree_model_get_iter(model,&iter,path))
{   
       //obtention des valeurs de la ligne selectionnée
  gtk_tree_model_get ( GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&prenom,3,&type,4,&description,5,&date_reclamation,-1);
       //copie des valeurs dans la variable p de type personne pour le passer a la fonction de suppression
strcpy(r.id,id);
strcpy(r.nom,nom);
strcpy(r.prenom,prenom);
strcpy(r.type,type);
strcpy(r.description,description);
strcpy(r.date_reclamation,date_reclamation);

pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous \nsupprimer cet utilisateur?");
switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
{
case GTK_RESPONSE_YES:
gtk_widget_destroy(pInfo);

supprimer(r,"reclamation.txt");
afficher(treeview);

break;
case GTK_RESPONSE_NO:
gtk_widget_destroy(pInfo);

break;
}
}
}
void
on_button_chercher_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id ;
GtkWidget *output ;
char id1[50];
int a ;
char ch [50];
id= lookup_widget (button, "entry_recherche");
strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id)));
a = recherche(id1);
if (a == 1)
{
output= lookup_widget (button, "labelchercher");
strcpy(ch,"Votre reclamation existe ");
gtk_label_set_text(GTK_LABEL(output),ch);
}
else
{
output= lookup_widget (button, "labelchercher");
strcpy(ch," Votre reclamation n'existe pas ");
gtk_label_set_text(GTK_LABEL(output),ch);
}

}
void
on_buttonservice_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
char texte [100];
sercive(texte);
output= lookup_widget (button, "label_service");
gtk_label_set_text(GTK_LABEL(output),texte);


}


void
on_gotoajoute_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter;
GtkWidget *fenetre_afficher;

fenetre_afficher = lookup_widget (button, "fenetre_afficher");

gtk_widget_destroy(fenetre_afficher);
fenetre_ajouter = lookup_widget (button, "fenetre_ajouter");
fenetre_ajouter = create_fenetre_ajouter();

gtk_widget_show(fenetre_ajouter);
}


void
on_gotomodifier_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *YM_fenetreModifier;
GtkWidget *fenetre_afficher;

fenetre_afficher = lookup_widget (button, "fenetre_afficher");

gtk_widget_destroy(fenetre_afficher);
YM_fenetreModifier = lookup_widget (button, "YM_fenetreModifier");
YM_fenetreModifier = create_YM_fenetreModifier();

gtk_widget_show(YM_fenetreModifier);
}


void
on_gotochercher_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_chercher;
GtkWidget *fenetre_afficher;

fenetre_afficher = lookup_widget (button, "fenetre_afficher");

gtk_widget_destroy(fenetre_afficher);
fenetre_chercher = lookup_widget (button, "fenetre_chercher");
fenetre_chercher = create_fenetre_chercher();

gtk_widget_show(fenetre_chercher);
}


void
on_YM_retour_ajout_clicked             (GtkButton       *button,
                                        gpointer         user_data)
                                         
{
GtkWidget *fenetre_chercher,*fenetre_ajouter;
fenetre_chercher=lookup_widget(button,"fenetre_chercher");
gtk_widget_destroy(fenetre_chercher);
fenetre_ajouter=create_fenetre_ajouter();
gtk_widget_show(fenetre_ajouter);

}
void
on_YM_fenetre_ajouter_acceuil_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter,*YM_acceuil;
YM_acceuil=lookup_widget(button,"YM_acceuil");
gtk_widget_destroy(YM_acceuil);
fenetre_ajouter=create_fenetre_ajouter();
gtk_widget_show(fenetre_ajouter);



}

void
on_YM_fenetre_afficher_acceuil_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*YM_acceuil;
YM_acceuil=lookup_widget(button,"YM_acceuil");
gtk_widget_destroy(YM_acceuil);
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);



}

void
on_YM_fenetre_chercher_acceuil_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_chercher,*YM_acceuil;
YM_acceuil=lookup_widget(button,"YM_acceuil");
gtk_widget_destroy(YM_acceuil);
fenetre_chercher=create_fenetre_chercher();
gtk_widget_show(fenetre_chercher);



}






void
on_YM_DE_AJOUT_VERS_ACCEUIL_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter,*YM_acceuil;
fenetre_ajouter=lookup_widget(button,"fenetre_ajouter");
gtk_widget_destroy(fenetre_ajouter);
YM_acceuil=create_YM_acceuil();
gtk_widget_show(YM_acceuil);



}
