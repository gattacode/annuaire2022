#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"

#define LONGUEUR_MAX_LIGNE 2048

int modifier_mel_client(const char *nomfichier){
    FILE *annuaire = fopen(nomfichier, "r");
//-------------------------------------------------------------------------------------------------------------//
// on defini les variables //
    char mel[500];
    char emel[500];
    char nom[40];
    char prenom[30];
    int m=0;
//-------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------//
// On prend la personne que l'utilisateur veut modifier //
    printf("Quel est le nom de la personne que vous voulez modifier ? : ");
    scanf("%s",nom);
    printf("Quel est le prenom de la personne que vous voulez modifier ? : ");
    scanf("%s",prenom);
    printf("Quel est le l'ancienne adresse mail ? : ");
    scanf("%s",emel);
    printf("Entrer le nouveau mel : ");
    scanf("%s",mel);
//-------------------------------------------------------------------------------------------------------------//
    m=strlen(mel);
    changement(annuaire, emel, nom, prenom, mel, m);

    fclose(annuaire);
    return 0;
}

void changement(FILE *annuaire, const char *emel, const char *nom, const char *prenom, const char *mel, int m){
    FILE *output = fopen("fichier.txt", "w");
//-------------------------------------------------------------------------------------------------------------//
// on defini les variables //
    char buffer[LONGUEUR_MAX_LIGNE];    //ligne que l'on a selectionner
    char string[500];                   //chaine de caractere de la ligne selectionner
    char nv[500];                       //chaine de caractere de la personne avec la modif

    int y=0;                            //compteur qui permet de connaitre le caractere apres le 5eme caractere separateur
    int i=0;                            //compteur qui permet de connaitre le caractere de la chaine string
    int n=0;                            //compteur qui permet de connaitre le nombre de caractere séparateur
    int t=0;                            //compteur qui permet de connaitre le caractere de la chaine string (+1)
    int p=0;                            //compteur qui permet de connaitre le caractere de la chaine nv
    int z=0;                            //compteur qui permet de connaitre le caractere de la chaine string apres le 6eme caractere separateur
    int o=0;                            //compteur qui permet de connaitre le caractere apres le 5eme caractere separateur dans le cas ou le nv_mail est plus long que mail

//-------------------------------------------------------------------------------------------------------------//
// on ecrit toutes les lignes autre que celle qu'on a choisi de l'annuaire dans le fichier //
    while (fgets(buffer, LONGUEUR_MAX_LIGNE, annuaire) != NULL) {

        if ((strstr(buffer, nom)== NULL )&&(strstr(buffer, prenom)== NULL )&&(strstr(buffer, emel)== NULL )){
            fseek(output, 0, SEEK_END);
            fputs(buffer,output);
        }
//-------------------------------------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------------------------------//
// on trouve l'endroit ou est marquer le mail (au 5 caracteres séparateur) puis on réecrit une chaine avec le nouveau mail et on fini par récrire la fin de chaine a partire du 6 séparateur //
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

//-------------------------------------------------------------------------------------------------------------//

        }

    }
    fprintf(output,"\n%s", nv);
    fclose(output);

}
