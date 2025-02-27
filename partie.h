#pragma once

#include "Liste.h"

#define CHAINE 256
/**
* @brief  cette fonction permet le remplisage de la pioche on ne l'utilise qu'une seule fois par partie afin de definire la pioche.
* @param[in] La liste contenant le pioche
*/
void pioche(Liste* p);
/**
* @brief cette fonction permet de convertire toute les caractere entres par l'utilisateur en majuscule
* @param[in] la chaine de caractere a transformer
*/
void convmaj(char* chaine);

int transferChaineDeCarac(Liste* j1, Liste* plateau, const char* mot);

Liste inverser(Liste* li);

/**
 * @brief Fonction pour lire les chaînes de caractères depuis un fichier et les stocker dans un tableau dynamique.
 * Cette fonction ouvre un fichier fixe ("ods4.txt"), lit chaque ligne, alloue dynamiquement de la mémoire pour chaque
 * chaîne lue, et stocke ces chaînes dans un tableau passé en paramètre.
 * @param[out] tableau Un tableau de pointeurs vers des chaînes de caractères où les lignes lues du fichier seront stockées. Le tableau doit avoir été préalablement alloué.
 * @return 1 Si la lecture du fichier et l'allocation mémoire se sont bien déroulées, sinon 0 en cas d'erreur.
 */
int dico(char** tableau);

/**
 * @brief Fonction qui vérifie si une chaîne de caractères est présente dans le dictionnaire.
 * @param[in] dico Tableau de chaînes de caractères contenant le dictionnaire.
 * @param[in] Taille Le nombre d'éléments dans le tableau.
 * @param[in] mot La chaîne de caractères à rechercher dans le dictionnaire.
 * @return 1 Si la chaîne est présente dans le dictionnaire, 0 sinon.
 */
int verifDico(char** dico, int Taille, const char* mot);

int verifelen(const char* input, int nbc);

