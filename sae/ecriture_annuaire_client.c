#include <stdio.h>
#include <string.h>

// Fonction pour ecrire une ligne de texte a la fin d'un fichier
void ecrire_ligne(FILE *annuaire, const char *ligne) {
    // Verifier que le pointeur de fichier est valide
    if (annuaire == NULL) {
        perror("L'ecriture n'a pas pu etre effectue, verifiez si le fichier n'est pas ouvert dans une autre application et reessayez.");
        return ;
    }

    // Deplacer le curseur de lecture/ecriture a la fin du fichier
    fseek(annuaire, 0, SEEK_END);

    // Ecrire la ligne de texte dans le fichier
    fputs(ligne, annuaire);
    printf("Ce que vous avez ecrit a bien ete ajoute au fichier. \n");
}

int ecriture_annuaire_client(const char *nom_fichier){
    FILE *annuaire = fopen(nom_fichier, "a");

    char nouvelle_ligne[2048];
    // On prend ce que l'utilisateur veut ecrire
    printf("Ecrivez ce que vous voulez ecrire dans le fichier : ");
    scanf("%s", nouvelle_ligne);

    ecrire_ligne(annuaire, nouvelle_ligne);


    fclose(annuaire);
    return 0;
}
