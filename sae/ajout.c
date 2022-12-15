#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nomannuaire[]="annuaire.csv"; /* mettre le nom du fichier */
    FILE* entree;
    entree=fopen(nomannuaire, "w");

    if(!entree){
        perror("fichier non trouver");
        return 1;
    }

    char nom_p[40];
    char prenom_p[20];
    char code_postale_p[7];
    char ville_p[58];
    char tel_p[14];
    char mel_p[400];
    char profession_p[500];

    printf("Renseigner :\n");

    printf("Nom : ");
    fgets("%39s", nom_p);

    printf("Prenom : ");
    fgets("%19s", prenom_p);

    printf("Code Postal : ");
    fgets("%6s", code_postale_p);

    printf("Ville : ");
    fgets("%57s", ville_p);

    printf("Numero de tel : ");
    fgets("%13s", tel_p);

    printf("Mail : ");
    fgets("%399s",mel_p);

    printf("Profession : ");
    fgets("%499s", profession_p);

    printf("%s,%s,%s,%s,%s,%s,%s", nom_p,prenom_p,code_postale_p,ville_p,tel_p,mel_p,profession_p);

    return 0;
}
