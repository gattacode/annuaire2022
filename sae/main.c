#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int entrer=0;

    printf("\t--------------Accueil--------------\n");
    printf("\n");
    printf("\t 1.Ajouter un nouveau client\n");
    printf("\t 2.Modification client\n");
    printf("\t 3.Suppression client\n");
    printf("\t 4.Afficher la liste des clients\n");
    printf("\t 5.Filtrer les clients\n");
    printf("\t 6.Liste des clients avec des donnees manquantes\n");
    printf("\t 7.sauvegarde des donnees\n");

    printf("Saisissez une valeur : ");
    scanf("%d", &entrer);

    switch (entrer)
    {
        case 1: printf("Vous avez choisi : Ajouter un nouveau client\n"); ajout(); break;
        case 2: printf("Vous avez choisi : Modification client\n"); modif(); break;
        case 3: printf("Vous avez choisi : Suppression client\n"); supp(); break;
        case 4: printf("Vous avez choisi : Afficher la liste des clients\n"); affiche(); break;
        case 5: printf("Vous avez choisi : Filtrer les clients\n"); filtre(); break;
        case 6: printf("Vous avez choisi : Liste des clients avec des donnees manquantes\n"); manquant(); break;
        case 7: printf("Vous avez choisi : sauvegarde des donnees\n"); save(); break;
        default : printf("Saisie invalide\n"); break;
    }

    return 0;
}
