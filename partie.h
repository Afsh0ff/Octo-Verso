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
 * @brief Fonction pour lire les cha�nes de caract�res depuis un fichier et les stocker dans un tableau dynamique.
 * Cette fonction ouvre un fichier fixe ("ods4.txt"), lit chaque ligne, alloue dynamiquement de la m�moire pour chaque
 * cha�ne lue, et stocke ces cha�nes dans un tableau pass� en param�tre.
 * @param[out] tableau Un tableau de pointeurs vers des cha�nes de caract�res o� les lignes lues du fichier seront stock�es. Le tableau doit avoir �t� pr�alablement allou�.
 * @return 1 Si la lecture du fichier et l'allocation m�moire se sont bien d�roul�es, sinon 0 en cas d'erreur.
 */
int dico(char** tableau);

/**
 * @brief Fonction qui v�rifie si une cha�ne de caract�res est pr�sente dans le dictionnaire.
 * @param[in] dico Tableau de cha�nes de caract�res contenant le dictionnaire.
 * @param[in] Taille Le nombre d'�l�ments dans le tableau.
 * @param[in] mot La cha�ne de caract�res � rechercher dans le dictionnaire.
 * @return 1 Si la cha�ne est pr�sente dans le dictionnaire, 0 sinon.
 */
int verifDico(char** dico, int Taille, const char* mot);

int verifelen(const char* input, int nbc);

