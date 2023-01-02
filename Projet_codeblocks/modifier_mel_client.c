#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"

#define LONGUEUR_MAX_LIGNE 2048

int modifier_mel_client(const char *nomfichier){
    FILE *annuaire = fopen(nomfichier, "r+");

    char emel[500];
    char mel[500];
    char nom[40];
    char prenom[30];
    int choix = 0;
    int m=strlen(mel);

    printf("Quel est le nom de la personne que vous voulez modifier ? : ");
    scanf("%s",nom);
    printf("Quel est le prenom de la personne que vous voulez modifier ? : ");
    scanf("%s",prenom);
    printf("Quel est le l'ancienne adresse mail ? : ");
    scanf("%s",emel);
    printf("Entrer le nouveau mel : ");
    scanf("%s",mel);

    changement(annuaire, mel, nom, prenom, emel, m);


    fclose(annuaire);
    return 0;
}

int changement(FILE *annuaire, const char *mel, const char *nom, const char *prenom, const char *emel, int m){

    char buffer[LONGUEUR_MAX_LIGNE];
    int y=0;
    int i=0;
    int n=0;
    while (fgets(buffer, LONGUEUR_MAX_LIGNE, annuaire) != NULL) {
        if ((strstr(buffer, nom)!= NULL )&&(strstr(buffer, prenom)!= NULL )&&(strstr(buffer, emel)!= NULL )) {
            printf("%s", buffer);
        }
    }


    while (buffer[i]!='\0'){
        if (buffer[i]==','){
            n=n+1;
        }
        while (n==6){
            i=i+1;
            if (buffer[i]==','){
                n=n+1;
            }
            if (y<m){
                buffer[i]=mel[y];
                y=y+1;
            }
            else{
                buffer[i]=' ';
            }

        }
        i=i+1;
    }

    return 0;
}
