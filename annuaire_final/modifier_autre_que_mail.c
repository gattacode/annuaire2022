#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"

#define LONGUEUR_MAX_LIGNE 2048

int choix_modif(FILE *annuaire, FILE *output, const char *string);
void modif(FILE *annuaire, FILE *output, const char *var, int m, int q, const char *string);

int modifier_client_autre_que_mel(const char *nomfichier){
    FILE *annuaire = fopen(nomfichier, "r");
    FILE *output = fopen("fichier.txt", "w");

    char nom[40];
    char prenom[20];
    char buffer[LONGUEUR_MAX_LIGNE];
    char mail[500];
    char string[500];

    printf("\nQuel est le nom de la personne que vous voulez modifier ? : ");
    scanf("%s",nom);
    printf("Quel est le prenom de la personne que vous voulez modifier ? : ");
    scanf("%s",prenom);
    printf("Quel est le mail de la personne que vous voulez modifier ? : ");
    scanf("%s",mail);

    while (fgets(buffer, LONGUEUR_MAX_LIGNE, annuaire) != NULL) {
        if ((strstr(buffer, nom)== NULL )&&(strstr(buffer, prenom)== NULL )&&(strstr(buffer, mail)== NULL )){
            fseek(output, 0, SEEK_END);
            fputs(buffer,output);
        }

        if ((strstr(buffer, nom)!= NULL )&&(strstr(buffer, prenom)!= NULL )&&(strstr(buffer, mail)!= NULL )) {
            strcpy(string, buffer);
            printf("\nCette personne va etre modifier :\n%s", string);
        }
    }

    choix_modif(annuaire, output,string);

    fclose(annuaire);

    return 0;
}

int choix_modif(FILE *annuaire, FILE *output, const char *string){
    int m;
    int choix;
    int q;
    char var[500];
    printf("\nChoisisez ce que vous voulez modifier (1=nom, 2=prenom, 3=ville, 4=cp, 5=tel, 6=mail, 7=profession : ");
    scanf("%d",&choix);

    switch(choix){
        case 1:
            printf("\nDonner le nom : ");
            scanf("%s",var);
            m=strlen(var);
            q=0;
            modif(annuaire, output,var, m, q, string);
            break;

        case 2:
            printf("\nDonner le prenom : ");
            scanf("%s",var);
            m=strlen(var);
            q=1;
            modif(annuaire, output,var, m, q, string);
            break;

        case 3:
            printf("\nDonner la ville : ");
            scanf("%s",var);
            m=strlen(var);
            q=2;
            modif(annuaire, output,var, m, q, string);
            break;

        case 4:
            printf("\nDonner le code postale : ");
            scanf("%s",var);
            m=strlen(var);
            q=3;
            modif(annuaire, output,var, m, q, string);
            break;

        case 5:
            printf("\nDonner le numero de tel : ");
            scanf("%s",var);
            m=strlen(var);
            q=4;
            modif(annuaire, output,var, m, q, string);
            break;

        case 6:
            printf("\nDonner l'adresse mail : ");
            scanf("%s",var);
            m=strlen(var);
            q=5;
            modif(annuaire, output,var, m, q, string);
            break;

        case 7:
            printf("\nDonner la profession : ");
            scanf("%s",var);
            m=strlen(var);
            q=6;
            modif(annuaire, output,var, m, q, string);
            break;

        default : Couleur(4);printf("Saisie invalide\n"); Couleur(4); break;
    }
    return 0;
}

void modif(FILE *annuaire, FILE *output, const char *var, int m, int q, const char *string){

//-------------------------------------------------------------------------------------------------------------//
// on defini les variables //
    char buffer[LONGUEUR_MAX_LIGNE];    //ligne que l'on a selectionner
    char nv[500];                       //chaine de caractere de la personne avec la modif

    int y=0;                            //compteur qui permet de connaitre le caractere apres le 5eme caractere separateur
    int i=0;                            //compteur qui permet de connaitre le caractere de la chaine string
    int n=0;                            //compteur qui permet de connaitre le nombre de caractere sparateur
    int t=0;                            //compteur qui permet de connaitre le caractere de la chaine string (+1)
    int p=0;                            //compteur qui permet de connaitre le caractere de la chaine nv
    int z=0;                            //compteur qui permet de connaitre le caractere de la chaine string apres le 6eme caractere separateur
    int o=0;                            //compteur qui permet de connaitre le caractere apres le 5eme caractere separateur dans le cas ou le nv_mail est plus long que mail

            while (string[i]!='\0'){
                nv[p]=string[i];
                p=p+1;
                if (string[i]==','){
                    n=n+1;

                    if (n==q){
                        t=i+1;
                        while (string[t]!=','){
                            if (y<m){
                                nv[p]=var[y];
                                y=y+1;
                                p=p+1;
                                o=o+1;
                            }
                            t=t+1;
                        }

                        if (o<m){
                            while (y<m){
                                nv[p]=var[y];
                                y=y+1;
                                p=p+1;
                            }
                        }
                        i=t-1;
                    }

                    if (n==q+1){
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

    fprintf(output,"\n%s", nv);
    fclose(output);
}

