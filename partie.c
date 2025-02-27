# pragma warning(disable:4996)
# include <stdio.h>
# include <assert.h>
# include <string.h>
# include <stdlib.h>

# include "partie.h"
# include "Liste.h"


void pioche(Liste* p) {
	for (int i = 0; i < MAX_A; ++i) {
		inclure(p, 'A');
	}

	inclure(p, 'B');

	for (int i = 0; i < MAX_C; ++i) {
		inclure(p, 'C');
	}

	for (int i = 0; i < MAX_D; ++i) {
		inclure(p, 'D');
	}

	for (int i = 0; i < MAX_E; ++i) {
		inclure(p, 'E');
	}

	inclure(p, 'F');

	inclure(p, 'G');

	inclure(p, 'H');

	for (int i = 0; i < MAX_I; ++i) {
		inclure(p, 'I');
	}

	inclure(p, 'J');

	for (int i = 0; i < MAX_L; ++i) {
		inclure(p, 'L');
	}

	for (int i = 0; i < MAX_M; ++i) {
		inclure(p, 'M');
	}

	for (int i = 0; i < MAX_N; ++i) {
		inclure(p, 'N');
	}

	for (int i = 0; i < MAX_O; ++i) {
		inclure(p, 'O');
	}

	for (int i = 0; i < MAX_P; ++i) {
		inclure(p, 'P');
	}

	inclure(p, 'Q');

	for (int i = 0; i < MAX_R; ++i) {
		inclure(p, 'R');
	}

	for (int i = 0; i < MAX_S; ++i) {
		inclure(p, 'S');
	}

	for (int i = 0; i < MAX_T; ++i) {
		inclure(p, 'T');
	}

	for (int i = 0; i < MAX_U; ++i) {
		inclure(p, 'U');
	}

	for (int i = 0; i < MAX_V; ++i) {
		inclure(p, 'V');
	}

}

void trierChevalet(Liste* chevalet) {
	if (chevalet == NULL || chevalet->premier == NULL) return;

	// Tri par insertion dans la liste chaînée
	Maillion* courant = chevalet->premier;
	while (courant != NULL) {
		Maillion* next = courant->suivant;
		while (next != NULL) {
			if (courant->element > next->element) {
				// Échange des valeurs
				char temp = courant->element;
				courant->element = next->element;
				next->element = temp;
			}
			next = next->suivant;
		}
		courant = courant->suivant;
	}
}

void convmaj(char* chaine) {
	for (int i = 0; chaine[i] != '\0'; ++i) {
		chaine[i] = toupper((unsigned char)chaine[i]);
	}
}

int transferChaineDeCarac(Liste* j, Liste* plateau, const char* mot) {
	for (int i = 0; mot[i] != '\0'; ++i) {
		int trouve = 0;
		int index = 0;

		for (ConstIt iter = iterer(j); !fini(&iter); suivant(&iter), ++index) {
			if (courant(&iter) == mot[i]) {

				transfererIn(j, plateau, index);
				trouve = 1;
				break;
			}
		}

		if (!trouve) {
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
	int Taille = 0;							 // Déclaration locale de Taille
	FILE* fichier = fopen(NOM_FICHIER, "r");
	if (fichier != NULL) {						// Vérification si le fichier est ouvert avec succès
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
	int gauche = 0, droite = Taille - 1;
	while (gauche <= droite) {
		int milieu = (gauche + droite) / 2;
		int cmp = strcmp(dico[milieu], mot);

		if (cmp == 0) {
			return 1;
		}
		else if (cmp < 0) {
			gauche = milieu + 1;
		}
		else {
			droite = milieu - 1;
		}
	}
	return 0;
}

int verifelen(const char* input, int nbc) {
	// Vérifie si la longueur du mot est exactement de 4 caractères
	if (strlen(input) == nbc) {
		return 1;  // Le mot a 4 caractères
	}
	return 0;  // Le mot n'a pas 4 caractères
}

int lettresSuffisantes(const Liste* chevalet, const char* mot) {
	int compteJoueur[MAX_ALPHABET] = { 0 };  // Tableau pour compter les lettres du joueur
	int compteMot[MAX_ALPHABET] = { 0 };     // Tableau pour compter les lettres du mot

	// Compter les lettres dans le chevalet
	ConstIt iter = iterer(chevalet);
	while (!fini(&iter)) {
		char lettre = courant(&iter);
		compteJoueur[lettre - 'A']++;
		suivant(&iter);
	}

	// Compter les lettres dans le mot
	for (int i = 0; mot[i] != '\0'; ++i) {
		compteMot[mot[i] - 'A']++;
	}

	// Vérifier que le joueur a assez de chaque lettre
	for (int i = 0; i < MAX_ALPHABET; ++i) {
		if (compteMot[i] > compteJoueur[i]) {
			return 0;  // Pas assez de lettres
		}
	}
	return 1;  // Lettres suffisantes
}

int motValide(const char* mot, char** tableauDico, int tailleDico, const Liste* chevalet) {
	// 1. Vérifier la longueur du mot
	if (strlen(mot) != 4) {

		return 0;
	}

	// 2. Vérifier si le mot est dans le dictionnaire
	int dansDico = 0;
	for (int i = 0; i < tailleDico; ++i) {
		if (strcmp(tableauDico[i], mot) == 0) {
			dansDico = 1;
			break;
		}
	}
	if (!dansDico) {

		return 0;
	}

	// 3. Vérifier si le joueur a les lettres suffisantes
	if (!lettresSuffisantes(chevalet, mot)) {

		return 0;
	}

	// Si toutes les conditions sont respectées
	return 1;
}

int piochez(Liste* joueur, Liste* pioche, const char chaine) {
	srand(time(NULL));
	int aleatoire = rand() % somme(pioche);
	int index = retrouverIndex(joueur, chaine);
	if (index != -1) {
		transfererIn(joueur, pioche, index);
		transfererIn(pioche, joueur, aleatoire);
		trierChevalet(joueur);
		return 1;
	}
	else {
		return 0;
	}
}

int verifPlateau(const Liste* plateau, const char* lettres) {
	int len = strlen(lettres);
	int taille = somme(plateau); // Utilise votre fonction pour obtenir la taille de la liste.

	// Si la liste est plus courte que la chaîne, impossible de vérifier.
	if (len > taille) {
		return 0; // Pas trouvé
	}

	// Vérification au début.
	ConstIt it = iterer(plateau); // Initialiser l'itérateur au début de la liste.
	int i = 0;
	while (!fini(&it) && i < len) {
		if (courant(&it) != lettres[i]) {
			break;
		}
		suivant(&it);
		i++;
	}
	if (i == len) {
		return 1; // Lettres trouvées au début.
	}

	// Vérification à la fin.
	// Positionner l'itérateur sur le (taille - len)-ième élément.
	it = iterer(plateau);
	for (int j = 0; j < taille - len; j++) {
		suivant(&it);
	}

	i = 0;
	while (!fini(&it) && i < len) {
		if (courant(&it) != lettres[i]) {
			return 0; // Pas trouvé.
		}
		suivant(&it);
		i++;
	}

	return 2; // Lettres trouvées à la fin.
}

void supprimerCaractere(char* chaine, char caractere) {
	int i, j = 0;
	int longueur = strlen(chaine);

	for (i = 0; i < longueur; i++) {
		if (chaine[i] != caractere) {
			chaine[j] = chaine[i];
			j++;
		}
	}
	chaine[j] = '\0';  // Terminer la chaîne
}

void inversechaine(char* chaine) {
	int longueur = strlen(chaine);
	for (int i = 0; i < longueur / 2; i++) {
		char temp = chaine[i];
		chaine[i] = chaine[longueur - i - 1];
		chaine[longueur - i - 1] = temp;
	}
}

void jouerTour1(Liste* joueur, Liste* plateau, char** tableau, int Taille, int joueurNum, Liste* p) {
	char input[MAX_INPUT];

	printf("%d> ", joueurNum);

	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';  // Supprimer le '\n'

	while (1) {


		convmaj(input);
		if (motValide(input, tableau, Taille, joueur)) {
			if (verifDico(tableau, Taille, input) == 1) {
				transferChaineDeCarac(joueur, plateau, input);
				break;
			}
			else {

			}
		}
		else {

			printf("%d> ", joueurNum);
			fgets(input, sizeof(input), stdin);
			input[strcspn(input, "\n")] = '\0';
		}
	}
}

int compterCaracteres(const char* chaine) {
	int compteur = 0;

	// Parcourir la chaîne jusqu'à la fin ('\0')
	while (chaine[compteur] != '\0') {
		compteur++;
	}

	return compteur;
}



