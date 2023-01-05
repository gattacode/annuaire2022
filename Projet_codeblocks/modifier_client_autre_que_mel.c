#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"

#define LONGUEUR_MAX_LIGNE 2048


int modifier_client_autre_que_mel(const char *nomfichier){
    FILE *annuaire = fopen(nomfichier, "a");
    char nom[40];
    char prenom[20];
    char code_postale[6];
    char ville[58];
    char tel[14];
    char mel[400];
    char prof[500];
    char buffer[LONGUEUR_MAX_LIGNE];
    char emel[500];

    printf("Quel est le nom de la personne que vous voulez modifier ? : ");
    scanf("%s",nom);
    printf("Quel est le prenom de la personne que vous voulez modifier ? : ");
    scanf("%s",prenom);
    printf("Quel est le mail de la personne que vous voulez modifier ? : ");
    scanf("%s",emel);

    while (fgets(buffer, LONGUEUR_MAX_LIGNE, annuaire) != NULL) {
        if ((strstr(buffer, nom)!= NULL )&&(strstr(buffer, prenom)!= NULL )&&(strstr(buffer, emel)!= NULL )) {
            printf("Cette personne va etre modifier :\n %s", buffer);
        }
    }

    // On prend ce que l'utilisateur veut ecrire
    printf("\nEcrivez les nouvelles donnees du client : ");

    printf("\nNom : ");
    scanf("%s", nom);

    printf("Prenom : ");
    scanf("%s", prenom);

    printf("Code Postal : ");
    scanf("%s", code_postale);

    printf("Ville : ");
    scanf("%s", ville);

    printf("Numero de tel : ");
    scanf("%s", tel);

    printf("Mail : ");
    scanf("%s",mel);

    printf("Profession : ");
    scanf("%s",prof);

    echamge(annuaire, nom, prenom, code_postale, ville, tel, mel, prof, buffer);

    fclose(annuaire);
    return 0;
}

int echamge(FILE *annuaire, const char *nom, const char *prenom, const char *code_postale, const char *ville, const char *tel, const char *mel, const char *prof, const char *buffer){

    int a=strlen(nom);
    int b=strlen(prenom);


    return 0;
}
