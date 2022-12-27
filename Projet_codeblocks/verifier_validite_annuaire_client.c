#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONGUEUR_MAX_MOT 1024

int verifier_validite_annuaire_client(const char *nom_fichier)
{
    char ligne[2000];
    char mot[LONGUEUR_MAX_MOT];
    // Tableau pour stocker les mots lus
    char mots[100][LONGUEUR_MAX_MOT];  
    int compteur = 0;
    int i;

    FILE *pf = NULL;

    if ( ( pf = fopen (nom_fichier, "r")) == NULL) {
        printf ( "Fichier introuvable");
        return 0;
    }

    while ( ( fgets ( ligne, sizeof ( ligne), pf))) {
        char *p = ligne;
        // Tant que le mot est inferieur a la taille max et qu'il n'y a pas de virgule
        while ( ( sscanf ( p, "%1023[^,]%*c%n", mot, &compteur)) == 1) {
            p += compteur;
            for (i = 0; i < compteur; i++) {
                // Comparaison avec les mots deja lus
                if (strcmp(mot, mots[i]) == 0) {
                    fclose(pf);
                    printf("L'annuaire n'est pas valide, il y a des elements qui se repetent (ex: le meme mail y est present 2 fois)\n");
                    return 0;
                }
            }
            // Enregistrement du mot lu
            strcpy(mots[compteur], mot);  
            compteur++;
        }
    }
    printf("L'annuaire est valide.\n");
    fclose ( pf);
    return 1;
}
