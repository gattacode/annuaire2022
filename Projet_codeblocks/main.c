#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Pour utiliser la fonction Sleep(x) et les couleurs
#include <windows.h>

#include "fonctions.h"


int main()
{
    int entree=0;
    char nomfichier[100];
    Couleur(1);
    printf("Entrer l'adresse du fichier contenant l'annuaire : ");
    Couleur(3);
    scanf("%s",nomfichier);
    Couleur(4);

        while(verif(nomfichier) == FALSE){
            Couleur(1);
            printf("\nEntrer l'adresse du fichier contenant l'annuaire : ");
            Couleur(3);
            scanf("%s",nomfichier);
            Couleur(4);
        }

        Couleur(15);
        printf("\n");
        printf("-------------------------Accueil----------------------------");
        printf("\n");
        printf("\t 1.Ajouter un nouveau client\n");
        printf("\t 2.Modification Mail client\n");
        printf("\t 3.Suppression client\n");
        printf("\t 4.Afficher la liste des clients\n");
        printf("\t 5.Afficher la liste des clients trier par nom\n");
        printf("\t 6.Afficher les clients avec des donnees manquantes\n");
        printf("\t 7.Ecrire dans l'annuaire des clients\n");
        printf("\t 8.Verifier la validite de l'annuaire\n");
        printf("\t 9.Modifier autre que mail\n");
        printf("\n");
        Couleur(1);
        printf("Saisissez une valeur : ");
        Couleur(3);
        scanf("%d", &entree);
        Couleur(15);
        printf("\n");
        switch (entree)
        {
            case 1: Couleur(2); printf("Vous avez choisi : Ajouter un nouveau client\n");printf("\n"); Couleur(15); ajouter_client(nomfichier);break;
            case 2: Couleur(2); printf("Vous avez choisi : Modification client\n"); printf("\n"); Couleur(15); modifier_mel_client(nomfichier);break;
            case 3: Couleur(2); printf("Vous avez choisi : Suppression client\n"); Couleur(15); supprimer_client(nomfichier); break;
            case 4: Couleur(2); printf("Vous avez choisi : Afficher la liste des clients\n"); printf("\n"); Couleur(15); Sleep(2000); afficher_annuaire_client(nomfichier); break;
            case 5: Couleur(2); printf("Vous avez choisi : Afficher la liste des clients trier par nom\n"); printf("\n"); Couleur(15); Sleep(2000); trier_clients_par_nom(nomfichier); afficher_annuaire_client("annuaire_triee.csv"); break;
            case 6: Couleur(2); printf("Vous avez choisi : Afficher les clients avec des donnees manquantes\n"); printf("\n"); Couleur(15); Sleep(2000); filtrer_client_donnees_manquantes(nomfichier); break;
            case 7: Couleur(2); printf("Vous avez choisi : Ecrire dans l'annuaire des clients\n"); printf("\n"); Couleur(15); Sleep(2000); ecriture_annuaire_client(nomfichier); break;
            case 8: Couleur(2); printf("Vous avez choisi : Verifier la validite de l'annuaire\n"); printf("\n"); Couleur(15); Sleep(2000); verifier_validite_annuaire_client(nomfichier); break;
            case 9: Couleur(2); printf("Vous avez choisi : Modifier client autre que mail"); printf("\n"); Couleur(15); modifier_client_autre_que_mel(nomfichier); break;
            default : Couleur(4);printf("Saisie invalide\n"); Couleur(4); break;
        }

        return 0;

}

int verif(const char *nom_fichier){
        FILE *annuaire = fopen(nom_fichier, "r");
        if (annuaire == NULL) {
            perror("\nErreur");
        return;
    }
}
