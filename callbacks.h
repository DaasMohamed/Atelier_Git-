#include <gtk/gtk.h>


void
on_button_ajouter_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_afficher_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview_afficher_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);





void
on_YM_recherche_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_YM_service_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_chercher_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonservice_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_gotoajoute_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_gotomodifier_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_gotochercher_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_YM_retour_ajout_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_YM_fenetre_ajouter_acceuil_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_YM_fenetre_afficher_acceuil_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_YM_fenetre_chercher_acceuil_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_YM_DE_AJOUT_VERS_ACCEUIL_clicked    (GtkButton       *button,
                                        gpointer         user_data);
