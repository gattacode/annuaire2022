#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

#define LONGUEUR_MAX_LIGNE 2048

// Fonction de comptage de ligne dans un fichier
int nombre_ligne(const char *nom_fichier)
{
    // On initialise le compteur de ligne
    int nombre = 0;

    // Pour garder le caractere
    char c;

    // On ouvre le fichier
    FILE *annuaire = fopen(nom_fichier, "r");

    // Verification de l'existence du fichier
    if (annuaire == NULL)
    {
        printf("Fichier introuvable");
        return 0;
    }

    // Extract characters from file and store in character c
    for (c = getc(annuaire); c != EOF; c = getc(annuaire))
        if (c == '\n')
            // On incremente le compteur si le caratere est une nouvelle ligne
            nombre = nombre + 1;

    // Fermeture du fichier
    fclose(annuaire);

    return nombre;
}

// Fonction d'affichage d'une ligne specifique contenu dans un fichier

int afficher_ligne(int a,const char *nom_fichier)
{
    // Choix de la ligne a afficher
    int numero_ligne = a;

    // Ouverture du fichier en mode lecture
    FILE *annuaire = fopen(nom_fichier, "r");
    int i = 0;

    if ( annuaire != NULL )
    {
        char ligne[LONGUEUR_MAX_LIGNE];

        // Lecture de la ligne
        while (fgets(ligne, sizeof ligne, annuaire) != NULL)
        {
            if (i == numero_ligne)
            {
                printf("%s",ligne);

                // Fermeture du fichier
                fclose(annuaire);
                return 0;
            }
            else
            {
                // On passe a la prochaine ligne
                i++;
            }
        }
    }
    return -1;
}

// Fonction pour afficher chaque ligne d'un fichier
int afficher_annuaire_client(const char *nom_fichier)
{
    for(int i = 0; i < nombre_ligne(nom_fichier); i++){
        afficher_ligne(i,nom_fichier);
    }
    return 0;
}

