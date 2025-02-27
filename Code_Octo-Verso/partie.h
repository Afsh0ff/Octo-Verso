#pragma once

#include "Liste.h"

#define CHAINE 256
#define MAX_ALPHABET 26
#define MAX_INPUT 100
#define MAX_SENS 2
#define MAX_EP_RESTE 50



enum {
	MAX_A = 9,
	MAX_C = 2,
	MAX_D = 3,
	MAX_E = 14,
	MAX_I = 7,
	MAX_L = 5,
	MAX_M = 3,
	MAX_N = 6,
	MAX_O = 5,
	MAX_P = 2,
	MAX_R = 6,
	MAX_S = 7,
	MAX_T = 6,
	MAX_U = 5,
	MAX_V = 2,
	chevaletsJoueurs = 12
};


/**
* @brief Cette fonction permet de remplir la pioche en ajoutant les lettres selon leur quantité définie.
*	     Elle est appelée une seule fois au début de la partie pour initialiser la pioche.
* @param[in] p Pointeur vers La liste qui représente la pioche.
*/
void pioche(Liste* p);

/**
 * @brief Cette fonction trie les éléments du chevalet par ordre croissant (ordre alphabétique des lettres).
 * @param[in] chevalet Pointeur vers la liste représentant le chevalet du joueur.
*/
void trierChevalet(Liste* chevalet);

/**
* @brief Cette fonction permet de convertir tous les caractères d'une chaîne entrée par l'utilisateur en majuscules.
* @param[in] chaine La chaîne de caractère à transformer.
* @pre Le pointeur chaine doit être non nul et pointer vers une chaîne valide.
*/
void convmaj(char* chaine);

/**
 * @brief Cette fonction transfère les caractères d'une chaîne de caractères depuis une liste source (le chevalet du joueur)
 *        vers une liste destination (le plateau), en vérifiant que chaque caractère est présent dans la source.
 * @param[in,out] j1 Pointeur vers la liste source (chevalet du joueur).
 * @param[out] plateau Pointeur vers la liste destination (plateau de jeu).
 * @param[in] mot La chaîne de caractères à transférer depuis le chevalet vers le plateau.
 * @return 1 si tous les caractères ont été transférés avec succès, 0 si un caractère est manquant dans le chevalet.
*/
int transferChaineDeCarac(Liste* j1, Liste* plateau, const char* mot);

/**
 * @brief Cette fonction crée une nouvelle liste qui est la version inversée de la liste passée en paramètre.
 *        Les éléments sont ajoutés dans l'ordre inverse par rapport à la liste d'origine.
 * @param[in] li Pointeur vers la liste d'origine à inverser.
 * @return Une nouvelle liste contenant les mêmes éléments mais dans l'ordre inverse.
*/
Liste inverser(Liste* li);

/**
 * @brief Cette fonction lit les chaînes de caractères depuis un fichier texte ("ods4.txt") et les stocke dans un tableau dynamique.
 *        Chaque ligne du fichier devient une chaîne de caractères allouée dynamiquement dans le tableau.
 * @param[out] tableau Un pointeur vers un tableau de pointeurs de chaînes de caractères. Le tableau est alloué dynamiquement par la fonction.
 * @return Le nombre de lignes lues (la taille du dictionnaire) si la lecture et l'allocation se sont bien déroulées,
 *         ou 0 en cas d'erreur (fichier introuvable ou erreur d'allocation mémoire).
 * @pre Le fichier 'ods4.txt' doit exister dans le répertoire courant.
 */
int dico(char*** tableau);

/**
 * @brief Cette fonction vérifie la présence d'une chaîne de caractères dans un dictionnaire.
 * @param[in] dico Un tableau de chaînes de caractères représentant le dictionnaire. Le tableau doit être trié par ordre alphabétique.
 * @param[in] Taille Le nombre d'éléments dans le tableau.
 * @param[in] mot La chaîne de caractères à rechercher dans le dictionnaire.
 * @return 1 Si la chaîne est présente dans le dictionnaire, 0 sinon.
 * @pre Le tableau dico doit être non nul et trié par ordre alphabétique, La taille Taille doit être positive et
 *      la chaîne mot doit être non nulle.
 */
int verifDico(char** dico, int Taille, const char* mot);

/**
 * @brief Cette fonction vérifie si la longueur d'une chaîne de caractères correspond à une longueur donnée.
 * @param[in] input La chaîne de caractères à vérifier.
 * @param[in] nbc Le nombre de caractères attendu.
 * @return 1 si la longueur de la chaîne est égale à nbc, 0 sinon.
 * @pre La chaîne input doit être non nulle et le nombre nbc doit être positif.
*/
int verifelen(const char* input, int nbc);

/**
 * @brief Cette fonction vérifie si le joueur dispose de suffisamment de lettres dans son chevalet pour former le mot donné.
 * @param[in] chevalet La liste contenant les lettres disponibles dans le chevalet du joueur.
 * @param[in] mot La chaîne de caractères représentant le mot à vérifier.
 * @return 1 si le joueur a suffisamment de lettres pour former le mot, 0 sinon.
 */
int lettresSuffisantes(const Liste* chevalet, const char* mot);

/**
 * @brief Cette fonction vérifie si un mot est valide selon plusieurs critères.
 * @param[in] mot Le mot à vérifier (chaîne de caractères).
 * @param[in] tableauDico Tableau contenant les mots du dictionnaire.
 * @param[in] tailleDico Taille du tableau de dictionnaire.
 * @param[in] chevalet Pointeur vers une liste représentant les lettres disponibles du joueur.
 * @return 1 si le mot est valide, 0 sinon.
 * @pre Le mot ne doit pas être nul. Le dictionnaire et le chevalet doivent être correctement initialisés.
*/
int motValide(const char* mot, char** tableauDico, int tailleDico, const Liste* chevalet);

/**
 * @brief Cette fonction permet à un joueur de piocher un élément depuis la pioche.
 * @param[in,out] pioche Pointeur vers la liste représentant la pioche.
 * @param[in,out] joueur Pointeur vers la liste représentant le chevalet du joueur.
 * @param[in] la chaine de caractere contenant la lettre que le joueur veut echanger.
*/
int piochez(Liste* joueur, Liste* pioche, const char chaine);

/**
 * @brief Cette fonction vérifie si un mot peut être formé à partir des lettres présentes sur le plateau.
 * @param[in] p Pointeur vers la liste représentant le plateau de jeu.
 * @param[in] input Tableau de caractères contenant le mot à vérifier.
 * @return 1 si le mot est formé à partir des lettres au début du plateau,
 *         2 si le mot est formé à partir des lettres à la fin du plateau,
 *         sinon, 0 si le mot ne peut pas être formé sur le plateau.
 * @pre La liste p doit être initialisée et contenir les lettres du plateau et
 *      le tableau input doit être une chaîne de caractères valide.
*/
int verifPlateau(const Liste* plateau, const char* lettres);

/**
 * @brief Cette fonction supprime toutes les occurrences d'un caractère spécifique dans une chaîne.
 * @param[in,out] chaine Pointeur vers la chaîne de caractères à modifier.
 * @param[in] caractere Le caractère à supprimer de la chaîne.
 * @pre La chaîne chaine doit être une chaîne valide terminée par un caractère nul (`'\0'`), et
 *      la chaîne doit être suffisamment allouée pour contenir la modification.
*/
void supprimerCaractere(char* chaine, char caractere);

/**
 * @brief Cette fonction inverse une chaîne de caractères donnée en place.
 * @param[in,out] chaine Pointeur vers la chaîne de caractères à inverser.
 * @pre La chaîne chaine doit être une chaîne valide terminée par un caractère nul (`'\0'`) et
 *      la chaîne ne doit pas être nulle.
*/
void inversechaine(char* chaine);

/**
@brief Gère un tour de jeu pour un joueur spécifique, vérifiant les mots saisis et appliquant les modifications nécessaires.
@param[in, out] joueur Liste contenant les éléments du joueur en cours.
@param[in, out] plateau Liste représentant l'état actuel du plateau.
@param[in] tableau Tableau 2D des lettres disponibles.
@param[in] Taille Taille du tableau(nombre de lignes et de colonnes, si carré).
@param[in] joueurNum Numéro du joueur jouant ce tour.
@param[in, out] p Liste supplémentaire pour des manipulations éventuelles(fonctionnalité non détaillée ici).
*/
void jouerTour1(Liste* joueur, Liste* plateau, char** tableau, int Taille, int joueurNum, Liste* p);

/**
@brief Compte le nombre de caractères dans une chaîne de caractères.
@param[in] chaine Pointeur vers la chaîne dont les caractères doivent être comptés.
@return Le nombre de caractères dans la chaîne (hors caractère nul '\0').
*/
int compterCaracteres(const char* chaine);
