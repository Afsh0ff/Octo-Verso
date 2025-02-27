# pragma warning(disable:4996)
# include <stdio.h>
# include <assert.h>
# include <string.h>
#include <stdlib.h>

# include "partie.h"
# include "Liste.h"

void pioche(Liste* p) {
	for (int i = 0; i <= 9; ++i) {
		inclure(p, 'A');
	}
	inclure(p, 'B');

	inclure(p, 'C');
	inclure(p, 'C');

	inclure(p, 'D');
	inclure(p, 'D');
	inclure(p, 'D');

	for (int i = 0; i < 14; ++i) {
		inclure(p, 'E');
	}

	inclure(p, 'F');

	inclure(p, 'G');

	inclure(p, 'H');

	for (int i = 0; i < 7; ++i) {
		inclure(p, 'I');
	}

	inclure(p, 'J');

	for (int i = 0; i < 5; ++i) {
		inclure(p, 'L');
	}

	inclure(p, 'M');
	inclure(p, 'M');
	inclure(p, 'M');

	for (int i = 0; i < 6; ++i) {
		inclure(p, 'N');
	}

	for (int i = 0; i < 5; ++i) {
		inclure(p, 'O');
	}

	for (int i = 0; i < 2; ++i) {
		inclure(p, 'P');
	}

	inclure(p, 'Q');

	for (int i = 0; i < 6; ++i) {
		inclure(p, 'R');
	}

	for (int i = 0; i < 7; ++i) {
		inclure(p, 'S');
	}

	for (int i = 0; i < 6; ++i) {
		inclure(p, 'T');
	}

	for (int i = 0; i < 5; ++i) {
		inclure(p, 'U');
	}

	for (int i = 0; i < 2; ++i) {
		inclure(p, 'V');
	}

}

void convmaj(char* chaine) {
	for (int i = 0; chaine[i] != '\0'; i++) {
		chaine[i] = toupper((unsigned char)chaine[i]);
	}
}

int transferChaineDeCarac(Liste* j1, Liste* plateau, const char* mot) {
	for (int i = 0; mot[i] != '\0'; ++i) {
		int trouve = 0;
		int index = 0;

		for (ConstIt iter = iterer(j1); !fini(&iter); suivant(&iter), ++index) {
			if (courant(&iter) == mot[i]) {

				transferer(j1, plateau, index);
				trouve = 1;
				break;
			}
		}

		if (!trouve) {
			printf("Erreur : le caractère '%c' n'est pas dans la liste j1.\n", mot[i]);
			return 0;
		}
	}
	return 1;
}

Liste inverser(const Liste* li) {
	Liste nouvelleListe;
	initListe(&nouvelleListe);

	Maillion* courant = li->premier;
	while (courant != NULL) {

		inclure(&nouvelleListe, courant->element);
		courant = courant->suivant;
	}

	return nouvelleListe;
}



int dico(char*** tableau) {
	const char* NOM_FICHIER = "ods4.txt";  // Nom du fichier constant
	int Taille = 0;  // Déclaration locale de Taille
	FILE* fichier = fopen(NOM_FICHIER, "r");
	if (fichier != NULL) {  // Vérification si le fichier est ouvert avec succès
		char buffer[CHAINE];
		while (fgets(buffer, CHAINE, fichier)) {
			Taille++;
		}

		*tableau = (char**)malloc(Taille * sizeof(char*));
		if (*tableau == NULL) {
			printf("Erreur d'allocation mémoire\n");
			fclose(fichier);
			return 0;  // Retourner 0 pour indiquer l'échec
		}

		rewind(fichier);  // Revenir au début du fichier

		int index = 0;
		while (fgets(buffer, CHAINE, fichier)) {
			buffer[strcspn(buffer, "\n")] = '\0';  // Enlever le saut de ligne

			(*tableau)[index] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
			if ((*tableau)[index] == NULL) {
				printf("Erreur d'allocation mémoire\n");
				fclose(fichier);
				return 0;  // Retourner 0 pour indiquer l'échec
			}
			strcpy((*tableau)[index], buffer);
			index++;
		}

		fclose(fichier);
		return Taille;  // Retourner la taille du dictionnaire
	}
	else {
		printf("Erreur lors de l'ouverture du fichier\n");
		return 0;  // Retourner 0 pour indiquer l'échec
	}
}

int verifDico(char** dico, int Taille, const char* mot) {
	for (int i = 0; i < Taille; ++i) {
		if (strcmp(dico[i], mot) == 0) {
			return 1;
		}

	}
	printf("Le mot '%s' n'est pas présent dans le dictionnaire.\n", mot);
	return 0;
}
int verifelen(const char* input, int nbc) {
	// Vérifie si la longueur du mot est exactement de 4 caractères
	if (strlen(input) == nbc) {
		return 1;  // Le mot a 4 caractères
	}
	return 0;  // Le mot n'a pas 4 caractères
}



