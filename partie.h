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
* @brief Cette fonction permet de remplir la pioche en ajoutant les lettres selon leur quantit� d�finie.
*	     Elle est appel�e une seule fois au d�but de la partie pour initialiser la pioche.
* @param[in] p Pointeur vers La liste qui repr�sente la pioche.
*/
void pioche(Liste* p);

/**
 * @brief Cette fonction trie les �l�ments du chevalet par ordre croissant (ordre alphab�tique des lettres).
 * @param[in] chevalet Pointeur vers la liste repr�sentant le chevalet du joueur.
*/
void trierChevalet(Liste* chevalet);

/**
* @brief Cette fonction permet de convertir tous les caract�res d'une cha�ne entr�e par l'utilisateur en majuscules.
* @param[in] chaine La cha�ne de caract�re � transformer.
* @pre Le pointeur chaine doit �tre non nul et pointer vers une cha�ne valide.
*/
void convmaj(char* chaine);

/**
 * @brief Cette fonction transf�re les caract�res d'une cha�ne de caract�res depuis une liste source (le chevalet du joueur)
 *        vers une liste destination (le plateau), en v�rifiant que chaque caract�re est pr�sent dans la source.
 * @param[in,out] j1 Pointeur vers la liste source (chevalet du joueur).
 * @param[out] plateau Pointeur vers la liste destination (plateau de jeu).
 * @param[in] mot La cha�ne de caract�res � transf�rer depuis le chevalet vers le plateau.
 * @return 1 si tous les caract�res ont �t� transf�r�s avec succ�s, 0 si un caract�re est manquant dans le chevalet.
*/
int transferChaineDeCarac(Liste* j1, Liste* plateau, const char* mot);

/**
 * @brief Cette fonction cr�e une nouvelle liste qui est la version invers�e de la liste pass�e en param�tre.
 *        Les �l�ments sont ajout�s dans l'ordre inverse par rapport � la liste d'origine.
 * @param[in] li Pointeur vers la liste d'origine � inverser.
 * @return Une nouvelle liste contenant les m�mes �l�ments mais dans l'ordre inverse.
*/
Liste inverser(Liste* li);

/**
 * @brief Cette fonction lit les cha�nes de caract�res depuis un fichier texte ("ods4.txt") et les stocke dans un tableau dynamique.
 *        Chaque ligne du fichier devient une cha�ne de caract�res allou�e dynamiquement dans le tableau.
 * @param[out] tableau Un pointeur vers un tableau de pointeurs de cha�nes de caract�res. Le tableau est allou� dynamiquement par la fonction.
 * @return Le nombre de lignes lues (la taille du dictionnaire) si la lecture et l'allocation se sont bien d�roul�es,
 *         ou 0 en cas d'erreur (fichier introuvable ou erreur d'allocation m�moire).
 * @pre Le fichier 'ods4.txt' doit exister dans le r�pertoire courant.
 */
int dico(char*** tableau);

/**
 * @brief Cette fonction v�rifie la pr�sence d'une cha�ne de caract�res dans un dictionnaire.
 * @param[in] dico Un tableau de cha�nes de caract�res repr�sentant le dictionnaire. Le tableau doit �tre tri� par ordre alphab�tique.
 * @param[in] Taille Le nombre d'�l�ments dans le tableau.
 * @param[in] mot La cha�ne de caract�res � rechercher dans le dictionnaire.
 * @return 1 Si la cha�ne est pr�sente dans le dictionnaire, 0 sinon.
 * @pre Le tableau dico doit �tre non nul et tri� par ordre alphab�tique, La taille Taille doit �tre positive et
 *      la cha�ne mot doit �tre non nulle.
 */
int verifDico(char** dico, int Taille, const char* mot);

/**
 * @brief Cette fonction v�rifie si la longueur d'une cha�ne de caract�res correspond � une longueur donn�e.
 * @param[in] input La cha�ne de caract�res � v�rifier.
 * @param[in] nbc Le nombre de caract�res attendu.
 * @return 1 si la longueur de la cha�ne est �gale � nbc, 0 sinon.
 * @pre La cha�ne input doit �tre non nulle et le nombre nbc doit �tre positif.
*/
int verifelen(const char* input, int nbc);

/**
 * @brief Cette fonction v�rifie si le joueur dispose de suffisamment de lettres dans son chevalet pour former le mot donn�.
 * @param[in] chevalet La liste contenant les lettres disponibles dans le chevalet du joueur.
 * @param[in] mot La cha�ne de caract�res repr�sentant le mot � v�rifier.
 * @return 1 si le joueur a suffisamment de lettres pour former le mot, 0 sinon.
 */
int lettresSuffisantes(const Liste* chevalet, const char* mot);

/**
 * @brief Cette fonction v�rifie si un mot est valide selon plusieurs crit�res.
 * @param[in] mot Le mot � v�rifier (cha�ne de caract�res).
 * @param[in] tableauDico Tableau contenant les mots du dictionnaire.
 * @param[in] tailleDico Taille du tableau de dictionnaire.
 * @param[in] chevalet Pointeur vers une liste repr�sentant les lettres disponibles du joueur.
 * @return 1 si le mot est valide, 0 sinon.
 * @pre Le mot ne doit pas �tre nul. Le dictionnaire et le chevalet doivent �tre correctement initialis�s.
*/
int motValide(const char* mot, char** tableauDico, int tailleDico, const Liste* chevalet);

/**
 * @brief Cette fonction permet � un joueur de piocher un �l�ment depuis la pioche.
 * @param[in,out] pioche Pointeur vers la liste repr�sentant la pioche.
 * @param[in,out] joueur Pointeur vers la liste repr�sentant le chevalet du joueur.
 * @param[in] la chaine de caractere contenant la lettre que le joueur veut echanger.
*/
int piochez(Liste* joueur, Liste* pioche, const char chaine);

/**
 * @brief Cette fonction v�rifie si un mot peut �tre form� � partir des lettres pr�sentes sur le plateau.
 * @param[in] p Pointeur vers la liste repr�sentant le plateau de jeu.
 * @param[in] input Tableau de caract�res contenant le mot � v�rifier.
 * @return 1 si le mot est form� � partir des lettres au d�but du plateau,
 *         2 si le mot est form� � partir des lettres � la fin du plateau,
 *         sinon, 0 si le mot ne peut pas �tre form� sur le plateau.
 * @pre La liste p doit �tre initialis�e et contenir les lettres du plateau et
 *      le tableau input doit �tre une cha�ne de caract�res valide.
*/
int verifPlateau(const Liste* plateau, const char* lettres);

/**
 * @brief Cette fonction supprime toutes les occurrences d'un caract�re sp�cifique dans une cha�ne.
 * @param[in,out] chaine Pointeur vers la cha�ne de caract�res � modifier.
 * @param[in] caractere Le caract�re � supprimer de la cha�ne.
 * @pre La cha�ne chaine doit �tre une cha�ne valide termin�e par un caract�re nul (`'\0'`), et
 *      la cha�ne doit �tre suffisamment allou�e pour contenir la modification.
*/
void supprimerCaractere(char* chaine, char caractere);

/**
 * @brief Cette fonction inverse une cha�ne de caract�res donn�e en place.
 * @param[in,out] chaine Pointeur vers la cha�ne de caract�res � inverser.
 * @pre La cha�ne chaine doit �tre une cha�ne valide termin�e par un caract�re nul (`'\0'`) et
 *      la cha�ne ne doit pas �tre nulle.
*/
void inversechaine(char* chaine);

/**
@brief G�re un tour de jeu pour un joueur sp�cifique, v�rifiant les mots saisis et appliquant les modifications n�cessaires.
@param[in, out] joueur Liste contenant les �l�ments du joueur en cours.
@param[in, out] plateau Liste repr�sentant l'�tat actuel du plateau.
@param[in] tableau Tableau 2D des lettres disponibles.
@param[in] Taille Taille du tableau(nombre de lignes et de colonnes, si carr�).
@param[in] joueurNum Num�ro du joueur jouant ce tour.
@param[in, out] p Liste suppl�mentaire pour des manipulations �ventuelles(fonctionnalit� non d�taill�e ici).
*/
void jouerTour1(Liste* joueur, Liste* plateau, char** tableau, int Taille, int joueurNum, Liste* p);

/**
@brief Compte le nombre de caract�res dans une cha�ne de caract�res.
@param[in] chaine Pointeur vers la cha�ne dont les caract�res doivent �tre compt�s.
@return Le nombre de caract�res dans la cha�ne (hors caract�re nul '\0').
*/
int compterCaracteres(const char* chaine);
