# pragma warning(disable:4996)
# include <stdio.h>
#include <stdlib.h>
# include <assert.h>
# include <string.h>
#include <ctype.h>

# include "partie.h"
# include "Liste.h"

int main() {
    srand(time(NULL));

    Liste p, j1, j2, plateau, plateauInv;
    char** tableau = NULL;
    int Taille = dico(&tableau);

    // Initialisation des listes
    initListe(&p);
    initListe(&j1);
    initListe(&j2);
    initListe(&plateau);

    // Pioche des lettres
    pioche(&p);

    // Distribution des lettre aux joueurs
    for (int i = 0; i <= 12; ++i) {
        int aleatoire = rand() % somme(&p);
        transferer(&p, &j1, aleatoire);
    }

    for (int i = 0; i <= 12; ++i) {
        int aleatoire = rand() % somme(&p);
        transferer(&p, &j2, aleatoire);
    }

    // Demande du mot à l'utilisateur
    char input[5];
    printf("Bienvenu dans cette partie d'octo-verso !\n");
    printf("Ecrivez un mot de 4 lettres : ");
    afficheListe(&j1);


    scanf("%s", input);
    if (verifelen(&input, 4) == 1) {

    }
    else {
        printf("entrer un mots de 4 caractere ");
        return 0;
    }
    convmaj(input); // Convient à la chaîne

    // Vérification du mot dans le dictionnaire
    if (verifDico(tableau, Taille, input) == 1) {
        // Si le mot est valide, transfert des caractères
        transferChaineDeCarac(&j1, &plateau, input);

        // Affichage du plateau
        printf("Plateau-octo:\n");
        afficheListe(&plateau);

        // Inversion du plateau et affichage
        printf("Plateau-verso:\n");
        plateauInv = inverser(&plateau);
        afficheListe(&plateauInv);
    }
    else {
        printf("");
    }

    // Libération de la mémoire pour le dictionnaire
    for (int i = 0; i < Taille; ++i) {
        free(tableau[i]);
    }
    free(tableau);

    return 0;
}