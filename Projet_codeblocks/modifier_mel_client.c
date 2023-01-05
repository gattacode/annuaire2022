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
    int m=0;

    printf("Quel est le nom de la personne que vous voulez modifier ? : ");
    scanf("%s",nom);
    printf("Quel est le prenom de la personne que vous voulez modifier ? : ");
    scanf("%s",prenom);
    printf("Quel est le l'ancienne adresse mail ? : ");
    scanf("%s",emel);
    printf("Entrer le nouveau mel : ");
    scanf("%s",mel);
    m=strlen(mel);
    changement(annuaire, mel, nom, prenom, emel, m);

    fclose(annuaire);
    return 0;
}

int changement(FILE *annuaire, const char *mel, const char *nom, const char *prenom, const char *emel, int m){

    FILE *output = fopen("fichier.txt", "w");
    char buffer[LONGUEUR_MAX_LIGNE];
    char string[500];
    int y=0;
    int i=0;
    int n=0;
    int t=0;
    int p=0;
    int z=0;
    int o=0;
    char nv[500];

    while (fgets(buffer, LONGUEUR_MAX_LIGNE, annuaire) != NULL) {
        if ((strstr(buffer, nom)!= NULL )&&(strstr(buffer, prenom)!= NULL )&&(strstr(buffer, emel)!= NULL )) {
            strcpy(string, buffer);
            printf("\n%s\n", string);



            while (string[i]!='\0'){
                nv[p]=string[i];
                p=p+1;
                if (string[i]==','){
                    n=n+1;

                    if (n==5){
                        t=i+1;
                        while (string[t]!=','){
                            if (y<m){
                                nv[p]=mel[y];
                                y=y+1;
                                p=p+1;
                                o=o+1;
                            }
                            t=t+1;
                        }

                        if (o<m){
                            while (y<m){
                                nv[p]=mel[y];
                                y=y+1;
                                p=p+1;
                            }
                        }
                        i=t-1;
                    }

                    if (n==6){
                        z=i+1;
                        while (string[z]!='\0'){
                            nv[p]=string[z];
                            z=z+1;
                            p=p+1;
                        }
                        i=z-1;
                    }
                }
                i=i+1;
        }

        printf("Fais %s", nv);
        fputs(nv, output);
}

}
return 0;
}
