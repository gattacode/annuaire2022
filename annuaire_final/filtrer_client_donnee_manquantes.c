#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonctions.h"

#include <stdio.h>
#include <string.h>

#define LONGUEUR_MAX_LIGNE 2048

// Fonction pour afficher les lignes avec des donnees manquantes
void filtrer_client_donnees_manquantes(const char *filename) {
    // On ouvre le fichier en mode lecture
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Lisez chaque ligne du fichier et affichez celles qui contiennent ",," ou ", " ou ",\n" soit les lignes avec des donnees manquantes
    char buffer[LONGUEUR_MAX_LIGNE];
    while (fgets(buffer, LONGUEUR_MAX_LIGNE, fp) != NULL) {
        if ((strstr(buffer, ",,") != NULL) || ((strstr(buffer, ", ")!= NULL )|| (strstr(buffer, ",\n")!= NULL ))) {
            printf("%s", buffer);
        }
    }

    // Fermer le fichier
    fclose(fp);
}

