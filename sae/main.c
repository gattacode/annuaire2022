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
    printf("\t 6.Liste des clients avec donnees manquantes\n");
    printf("\t 7.sauvegarde des donnees\n");

    printf("saisissez une valeur : ");
    scanf("%d", &entrer);

    switch (entrer)
    {
        case 1: printf("vous avez choisi : Ajouter un nouveau client\n"); ajout(); break;
        case 2: printf("vous avez choisi : Modification client\n"); modif(); break;
        case 3: printf("vous avez choisi : Suppression client\n"); supp(); break;
        case 4: printf("vous avez choisi : Afficher la liste des clients\n"); affiche(); break;
        case 5: printf("vous avez choisi : Filtrer les clients\n"); filtre(); break;
        case 6: printf("vous avez choisi : Liste des clients avec donnees manquantes\n"); manquant(); break;
        case 7: printf("vous avez choisi : sauvegarde des donnees\n"); save(); break;
        default : printf("saisie invalide\n"); break;
    }

    return 0;
}
