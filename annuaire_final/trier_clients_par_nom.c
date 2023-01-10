#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

#define LONGUEUR_MAX_LIGNE 2048

// Structure pour avoir une ligne et sa longueur
typedef struct {
    char *texte;
    int longueur;
} ligne;

// Fonction de comparaison pour le tri
int compare_lignes(const void *a, const void *b) {
    const ligne *ligne_a = (const ligne*) a;
    const ligne *ligne_b = (const ligne*) b;
    return strcmp(ligne_a->texte, ligne_b->texte);
}

// Fonction de tri par ordre alphabetique
int trier_clients_par_nom(const char *nom_fichier) {

    // On ouvre le fichier en mode ecriture
    FILE *annuaire = fopen(nom_fichier, "r");
    if (annuaire == NULL) {
        perror("Fichier introuvable");
        return 1;
    }

    // On alloue de la memoire pour garder les lignes dans un fichier
    ligne *lignes = malloc(sizeof(ligne));
    int num_lignes = 0;

    // On lit chaque ligne du fichier et on la garde dans l'array de lignes
    char buffer[LONGUEUR_MAX_LIGNE];
    while (fgets(buffer, LONGUEUR_MAX_LIGNE, annuaire) != NULL) {

        // On alloue de la memoire pour garder le texte de la ligne et le copier
        lignes[num_lignes].texte = malloc(strlen(buffer) + 1);
        strcpy(lignes[num_lignes].texte, buffer);

        // On garde la longueur de la ligne
        lignes[num_lignes].longueur = strlen(buffer);

        // On incremente le compteur et on realloue la memoire pour l'array
        num_lignes++;
        lignes = realloc(lignes, (num_lignes + 1) * sizeof(ligne));
    }

    // Fermeture du fichier
    fclose(annuaire);

    // On trie les lignes en utilisant la fonction de comparaison
    qsort(lignes, num_lignes, sizeof(ligne), compare_lignes);

    // On ouvre le fichier "trier_alpha.csv" en mode ecriture
    annuaire = fopen("trier_alpha.csv", "w");
    if (annuaire == NULL) {
        perror("Fichier introuvable");
        return 1;
    }

    // On ecrit les lignes dans l'ordre alphabetique dans le fichier
    for (int i = 0; i < num_lignes; i++) {
        fwrite(lignes[i].texte, sizeof(char), lignes[i].longueur, annuaire);
        free(lignes[i].texte);
    }

    // Fermeture du fichier
    fclose(annuaire);

    // On libere la memoire alloue aux lignes
    free(lignes);

    return 0;
}


