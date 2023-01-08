#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define LONGUEUR_MAX_LIGNE 2048

int supprimer_client(const char *nomfichier) {

//-------------------------------------------------------------------------------------------------------------//
//on defini tout les variables //
	FILE *input = fopen(nomfichier, "r");
	FILE *output = fopen("fichier.txt", "w");

	char line[LONGUEUR_MAX_LIGNE];
	char nom[163];
	char mail[500];
//-------------------------------------------------------------------------------------------------------------//

    printf("\nQuel est le nom de la personne que vous voulez suprimer ? : ");
    scanf("%s",nom);
    printf("Quel est le mail de la personne que vous voulez suprimez ? : ");
    scanf("%s",mail);

//-------------------------------------------------------------------------------------------------------------//
// On trouve la personne qui doit tre suprimer //
	while (fgets(line, LONGUEUR_MAX_LIGNE, input) != NULL) {
        if ((strstr(line, nom)!= NULL )&&(strstr(line, mail)!= NULL )) {

            printf("\nCette ligne a ete sup : \n%s",line);
		}
		if (strstr(line, nom) == NULL || strstr(line, mail) == NULL) {
			fputs(line, output);
		}
	}
//-------------------------------------------------------------------------------------------------------------//


    printf("\nLa personne a bien ete suprimer\n\n");


	fclose(input);
	fclose(output);
	return 0;
}

