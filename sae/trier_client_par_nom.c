#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

#define MAX_ligne_LENGTH 1024

// Structure pour avoir une ligne et sa longueur
typedef struct {
    char *text;
    int longueur;
} ligne;

// Fonction de comparaison pour le tri
int compare_lignes(const void *a, const void *b) {
    const ligne *ligne_a = (const ligne*) a;
    const ligne *ligne_b = (const ligne*) b;
    return strcmp(ligne_a->text, ligne_b->text);
}

// Fonction de tri par ordre alphabetique
void trier_clients_par_nom(const char *filename) {
    // On ouvre le fichier en mode ecriture
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Fichier introuvable");
        return;
    }

    // On alloue de la memoire pour garder les lignes dans un fichier
    ligne *lignes = malloc(sizeof(ligne));
    int num_lignes = 0;

    // On lit chaque ligne du fichier et on la garde dans l'array de lignes
    char buffer[MAX_ligne_LENGTH];
    while (fgets(buffer, MAX_ligne_LENGTH, fp) != NULL) {
        // On alloue de la memoire pour garder le texte de la ligne et le copier
        lignes[num_lignes].text = malloc(strlen(buffer) + 1);
        strcpy(lignes[num_lignes].text, buffer);
        // On garde la longueur de la ligne
        lignes[num_lignes].longueur = strlen(buffer);
        // On incremente le compteur et on realloue la memoire pour l'array
        num_lignes++;
        lignes = realloc(lignes, (num_lignes + 1) * sizeof(ligne));
    }

    // Fermeture du fichier
    fclose(fp);

    // On trie les lignes en utilisant la fonction de comparaison
    qsort(lignes, num_lignes, sizeof(ligne), compare_lignes);

    // On ouvre le fichier "trier_alpha.csv" en mode écriture
    fp = fopen("trier_alpha.csv", "w");
    if (fp == NULL) {
        perror("Fichier introuvable");
        return;
    }

    // On ecrit les lignes dans l'ordre alphabetique dans le fichier
    for (int i = 0; i < num_lignes; i++) {
        fwrite(lignes[i].text, sizeof(char), lignes[i].longueur, fp);
        free(lignes[i].text);
    }

    // Fermeture du fichier
    fclose(fp);

    // On libère la mémoire alloué aux lignes
    free(lignes);
}
