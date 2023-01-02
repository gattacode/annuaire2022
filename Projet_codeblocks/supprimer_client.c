#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"

#define LONGUEUR_MAX_LIGNE 2048

int supprimer_client(const char *nomfichier){
    FILE *annuaire = fopen(nomfichier, "r+");

    char buffer[LONGUEUR_MAX_LIGNE];
    char mel[500];
    char nom[40];
    char prenom[30];
    int m=0;

    printf("Quel est le nom de la personne que vous voulez suprimer ? : ");
    scanf("%s",nom);
    printf("Quel est le prenom de la personne que vous voulez suprimer ? : ");
    scanf("%s",prenom);
    printf("Quel est le mail de la personne que vous voulez suprimez ? : ");
    scanf("%s",mel);

    while (fgets(buffer, LONGUEUR_MAX_LIGNE, annuaire) != NULL) {
        if ((strstr(buffer, nom)!= NULL )&&(strstr(buffer, prenom)!= NULL )&&(strstr(buffer, mel)!= NULL )) {
            printf("Cette personne a ete suprimer : \n%s\n", buffer);
        }
    }

    int i=strlen(buffer);
    while (i<m){
        if (buffer[i]!='\0'){
            buffer[i]=' ';
        }
        i=i+1;
    }

    fclose(annuaire);
    return 0;
}
