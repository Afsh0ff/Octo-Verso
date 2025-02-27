# pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "partie.h"
#include "Liste.h"


int main() {
    srand(time(NULL));

    Liste p, j1, j2, plateau;
    char** tableau = NULL;
    int Taille = dico(&tableau);

    initListe(&p);
    initListe(&j1);
    initListe(&j2);
    initListe(&plateau);

    pioche(&p);

    for (int i = 0; i < chevaletsJoueurs; ++i) {
        int aleatoire = rand() % somme(&p);
        transfererIn(&p, &j1, aleatoire);
    }
    trierChevalet(&j1);

    for (int i = 0; i < chevaletsJoueurs; ++i) {
        int aleatoire = rand() % somme(&p);
        transfererIn(&p, &j2, aleatoire);
    }
    trierChevalet(&j2);

    printf("1 : ");
    afficheListe(&j1);
    printf("2 : ");
    afficheListe(&j2);

    printf("Entrez un mot de 4 lettres :\n");
    jouerTour1(&j1, &plateau, tableau, Taille, 1, &p);
    jouerTour1(&j2, &plateau, tableau, Taille, 2, &p);

    printf("1 : ");
    afficheListe(&j1);
    printf("2 : ");
    afficheListe(&j2);

    printf("R : ");
    Liste plateauInv = inverser(&plateau);
    afficheListe(&plateauInv);

    printf("V : ");
    afficheListe(&plateau);
    int joueur = 0;
    while ((somme(&j1) > 0 || somme(&j2) > 0)) {
        int motValide = 0;
        while (!motValide) {
            int recto = 0;
            char input[MAX_INPUT];




            printf("%d> ", joueur + 1);

            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0'; // Supprime le caractère de nouvelle ligne
            convmaj(input);

            while (input[0] == '-') {
                // if (input[0] == '-') {
                char piochechaine = input[1];
                int tmp = piochez(joueur ? &j2 : &j1, &p, piochechaine);
                if (tmp != 0)
                    printf("%d : ", joueur + 1);
                afficheListe(joueur ? &j2 : &j1);
                printf("%d> ", joueur + 1);
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0'; // Supprime le caractère de nouvelle ligne
                convmaj(input);
            }


            char sens[MAX_SENS] = { 0 }, entreParentheses[MAX_EP_RESTE] = { 0 }, reste[MAX_EP_RESTE] = { 0 };

            // Trouver les parenthèses
            char* parentheseOuvrante = strchr(input, '(');
            char* parentheseFermante = strchr(input, ')');

            if (parentheseOuvrante && parentheseFermante) {
                // Extraire la partie entre parenthèses
                strncpy(entreParentheses, parentheseOuvrante + 1, parentheseFermante - parentheseOuvrante - 1);
                entreParentheses[parentheseFermante - parentheseOuvrante - 1] = '\0';

                // Extraire le sens (premier caractère de l'entrée)
                sens[0] = input[0];

                // Extraire les parties avant et après les parenthèses pour 'reste'
                if (parentheseOuvrante > input + 1) {
                    strncat(reste, input + 2, parentheseOuvrante - input - 2);
                }
                if (*(parentheseFermante + 1) != '\0') {
                    strcat(reste, parentheseFermante + 1);
                }
            }




            // Créer les mots en concatenant "reste" et "entreParanthese" dans les deux ordres possibles
            char motsJ[MAX_EP_RESTE] = "";
            char motsJin[MAX_EP_RESTE] = "";

            strcat(motsJ, entreParentheses);
            strcat(motsJ, reste);
            strcat(motsJin, reste);
            strcat(motsJin, entreParentheses);
            supprimerCaractere(motsJ, '(');
            supprimerCaractere(motsJ, ')');
            supprimerCaractere(motsJin, '(');
            supprimerCaractere(motsJin, ')');




            if (lettresSuffisantes(joueur ? &j2 : &j1, reste) != 1) {
                break;
            }
            else {
                if (strcmp(sens, "R") == 0) {
                    recto = 1;
                    if (verifPlateau(&plateauInv, entreParentheses) == 0) {
                        continue;
                    }
                    else {
                        if (verifPlateau(&plateauInv, entreParentheses) == 2) {
                            if (verifDico(tableau, Taille, motsJ) != 1) {
                                break;
                            }
                            else {
                                for (int i = 0; i < strlen(reste); i++) {
                                    int index = retrouverIndex(joueur ? &j2 : &j1, reste[i]);
                                    transfererInFin(joueur ? &j2 : &j1, &plateauInv, index);
                                    if (joueur == 0) {
                                        transfererDebut(&plateauInv, &j2);
                                    }
                                    else {
                                        transfererDebut(&plateauInv, &j1);
                                    }
                                }
                                motValide = 1; // Sortir de la boucle
                            }
                        }
                        else if (verifPlateau(&plateauInv, entreParentheses) == 1) {
                            if (verifDico(tableau, Taille, motsJin) != 1) {
                                break;
                            }
                            else {
                                inversechaine(reste);
                                for (int i = 0; i < strlen(reste); i++) {
                                    int index = retrouverIndex(joueur ? &j2 : &j1, reste[i]);
                                    transfererIn(joueur ? &j2 : &j1, &plateauInv, index);
                                    if (joueur == 0) {
                                        transfererLast(&plateauInv, &j2);
                                    }
                                    else {
                                        transfererLast(&plateauInv, &j1);
                                    }
                                }
                                motValide = 1; // Sortir de la boucle
                            }
                        }
                    }
                }
                else if (strcmp(sens, "V") == 0) { // Vertical
                    recto = 0;
                    if (verifPlateau(&plateauInv, entreParentheses) == 0) {
                        break;
                    }
                    else {
                        if (verifPlateau(&plateau, entreParentheses) == 2) {
                            if (verifDico(tableau, Taille, motsJ) != 1) {
                                break;
                            }
                            else {
                                for (int i = 0; i < strlen(reste); i++) {
                                    int index = retrouverIndex(joueur ? &j2 : &j1, reste[i]);
                                    transfererInFin(joueur ? &j2 : &j1, &plateau, index);
                                    if (joueur == 0) {
                                        transfererDebut(&plateau, &j2);
                                    }
                                    else {
                                        transfererDebut(&plateau, &j1);
                                    }
                                }
                                motValide = 1; // Sortir de la boucle
                            }
                        }
                        else if (verifPlateau(&plateau, entreParentheses) == 1) {
                            inversechaine(&reste);
                            if (verifDico(tableau, Taille, motsJin) != 1) {
                                break;
                            }
                            else {
                                for (int i = 0; i < strlen(reste); i++) {
                                    int index = retrouverIndex(joueur ? &j2 : &j1, reste[i]);
                                    transfererIn(joueur ? &j2 : &j1, &plateau, index);
                                    if (joueur == 0) {
                                        transfererLast(&plateau, &j2);
                                    }
                                    else {
                                        transfererLast(&plateau, &j1);
                                    }
                                }
                                motValide = 1; // Sortir de la boucle
                            }
                        }
                    }
                }
            }


            if (somme(&j1) == 0 || somme(&j2) == 0) {
                if (somme(&j1) > 0) {
                    printf("Joueur 1 a gagner !!");
                }
                else {
                    printf("Joueur 2 a gagner !!");
                }
            }
            else {
                if (!motValide) {
                    continue;
                }
                else if (motValide) {

                    if (recto) {
                        plateau = plateauInv;
                        plateau = inverser(&plateau);
                    }
                    else if (!recto) {
                        plateauInv = plateau;
                        plateauInv = inverser(&plateau);
                    }


                    trierChevalet(&j1);
                    trierChevalet(&j2);


                    if (compterCaracteres(motsJ) == 8) {
                        printf("-%d> ", joueur + 1);
                        fgets(input, sizeof(input), stdin);
                        input[strcspn(input, "\n")] = '\0'; // Supprime le caractère de nouvelle ligne
                        convmaj(input);
                        char piochechaine = input[0];
                        piochez(joueur ? &j2 : &j1, &p, piochechaine);

                    }


                    printf("1 : ");
                    afficheListe(&j1);
                    printf("2 : ");
                    afficheListe(&j2);

                    printf("R : ");
                    afficheListe(&plateauInv);

                    printf("V : ");
                    afficheListe(&plateau);

                    joueur = (joueur + 1) % 2;
                }
            }
        }
    }
}



