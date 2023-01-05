#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"


int ajouter_client(const char *nomfichier){
    FILE *annuaire = fopen(nomfichier, "a");
    char nom[40];
    char prenom[20];
    char code_postale[6];
    char ville[58];
    char tel[14];
    char mel[400];
    char prof[500];

    // On prend ce que l'utilisateur veut ecrire
    printf("Ecrivez les donnees du client : ");

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

    ecrire_nv_client(annuaire, nom, prenom, code_postale, ville, tel, mel, prof);

    fclose(annuaire);
    return 0;
}

void ecrire_nv_client(FILE *annuaire, const char *nom, const char *prenom, const char *code_postale, const char *ville, const char *tel, const char *mel, const char *prof){

    // Deplacer le curseur de lecture/ecriture a la fin du fichier
    fseek(annuaire, 0, SEEK_END);

    // Ecrire la ligne de texte dans le fichier
    fprintf(annuaire, "\n%s, %s, %s, %s, %s, %s, %s", nom, prenom, code_postale, ville, tel, mel, prof);

    printf("\nCe que vous avez ecrit a bien ete ajoute au fichier. \n");
}
