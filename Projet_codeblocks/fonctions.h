#ifndef _FONCTIONs_H_
#define _FONCTIONs_H_

int afficher_annuaire_client(const char *nom_fichier);
int trier_clients_par_nom(const char *nom_fichier);
int ecriture_annuaire_client(const char *nom_fichier);
int verifier_validite_annuaire_client(const char *nom_fichier);
void filtrer_client_donnees_manquantes(const char *filename);
int ajouter_client(const char *nom_fichier);
int modifier_mel_client(const char *nom_fichier);
int supprimer_client(const char *nomfichier);
int modifier_client_autre_que_mel(const char *nomfichier);

void Couleur(int ForgC);
#endif

