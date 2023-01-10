#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"
#define LONGUEUR_MAX_LIGNE 2048


void ecrire_nv_client(FILE *annuaire, FILE *output, const char *nom, const char *prenom, const char *code_postale, const char *ville, const char *tel, const char *mail, const char *prof);

int ajouter_client(const char *nomfichier){
    FILE *annuaire = fopen(nomfichier, "r");
    FILE *output=fopen("fichier.txt","w");

//-------------------------------------------------------------------------------------------------------------//
//on defini tout les variables //

    char nom[40];
    char prenom[20];
    char code_postale[6];
    char ville[58];
    char tel[14];
    char mail[400];
    char prof[500];
//-------------------------------------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------------------------------//
// On prend ce que l'utilisateur veut ecrire //
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
    scanf("%s",mail);
    printf("Profession : ");
    scanf("%s",prof);
//-------------------------------------------------------------------------------------------------------------//

    ecrire_nv_client(annuaire,output, nom, prenom, code_postale, ville, tel, mail, prof);

    fclose(annuaire);
    fclose(output);
    return 0;
}

void ecrire_nv_client(FILE *annuaire, FILE *output, const char *nom, const char *prenom, const char *code_postale, const char *ville, const char *tel, const char *mail, const char *prof){

    char buffer[600];

//-------------------------------------------------------------------------------------------------------------//
//on ecrit toutes les lignes de l'annuaire dans le fichier et on ajout la ligne en plus a la fin du fichier    //
    while (fgets(buffer, LONGUEUR_MAX_LIGNE, annuaire) != NULL) {
        fseek(output, 0, SEEK_END);
        fputs(buffer,output);
    }

    fprintf(output, "\n%s,%s,%s,%s,%s,%s,%s", nom, prenom, code_postale, ville, tel, mail, prof);
//--------------------------------------------------------------------------------------------------------------//

    printf("\nCe que vous avez ecrit a bien ete ajoute au fichier. \n");
}
