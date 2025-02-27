#pragma once

typedef char ItemL;

struct Maillion;

typedef struct {
	ItemL element;
	struct Maillion* suivant;
} Maillion;


typedef struct {
	Maillion* premier;
}Liste;

typedef const Maillion* ConstIt;

/**
* @brief Cette fonction initialise une liste.
* @param[in] la liste � initialiser
*/
void initListe(Liste* li);

/**
* @brief Cette fonction permet d'ajouter des �l�ments en t�te d'une liste.
* @param[in] la liste o� l'on veut rajouter un �l�ment.
* @param[in] l'�l�ment que nous voulons ajouter.
*/
void inclure(Liste* li, ItemL it);

/**
* @brief Cette fonction permet d'afficher une liste donn�e
* @param[in] la liste � afficher
*/
void afficheListe(const Liste* li);

/**
* @brief Cette fonction permet de prendre un �l�ment d'une liste � une position donn� (index) pour la transf�rer � la premiere position d'une autre liste.
* @param[in] li1 La liste o� il faut retirer les �l�ments
* @param[in] li2 La liste o� les �l�ments sont transferer � la premiere position
* @param[in] index L'indice o� l'�l�ment va �tre r�cuperer
*/
void transfererIn(Liste* li1, Liste* li2, int index);

/**
 * @brief Cette fonction calcule le nombre d'�l�ments pr�sents dans une liste cha�n�e.
 * @param[in] li Pointeur constant vers la liste dont on veut compter les �l�ments.
 * @return Le nombre d'�l�ments dans la liste.
*/
int somme(const Liste* li);

/**
 * @brief Cette fonction passe � l'�l�ment suivant dans le parcours.
 * @param[in,out] iter Adresse de l'it�rateur de la liste.
 * @pre Le parcours ne doit pas �tre fini (@ref fini).
 */
void suivant(ConstIt* iter);

/**
 * @brief Cette fonction retourne l'�l�ment courant du parcours.
 * @param[in] iter Adresse de l'it�rateur de liste.
 * @return L'�l�ment de la liste actuellement d�signer par l'it�rateur.
 * @pre Le parcours ne doit pas �tre fini (@ref fini).
 */
ItemL courant(const ConstIt* iter);

/**
 * @brief Cette fonction indique si tous les �l�ments ont �t� parcourus.
 * @param[in] iter Adresse de l'it�rateur de liste.
 * @return 1 si tout a �t� parcouru et 0 dans le cas contraire.
 */
int fini(const ConstIt* iter);

/**
 * @brief Cette fonction retourne un it�rateur de liste au d�but du parcours.
 * @param[in] li Adresse de la liste � parcourir.
 * @return Un it�rateur initialiser au d�but de cette liste.
 */
ConstIt iterer(const Liste* li);

/**
 * @brief It�rateur sur une liste permettant d'obtenir un � un les
 * �l�ments qui la composent mais aussi de modifier cette liste
 * (modification de la valeur de l'�l�ment courant, insertion avant
 * l'�l�ment courant, suppression de l'�l�ment courant).
 */
typedef struct {
	Liste* liste; ///< La liste �tant parcourue.
	Maillion* pred; ///< D�signe le maillon pr�cedent le maillon courant (ou NULL).
	Maillion* courant; ///< D�signe le maillon courant (ou NULL).
} Iterateur;

/**
 * @brief Cette fonction initialise un it�rateur de la liste au d�but du parcours.
 * @param[in] li Adresse de la liste dont les �l�ments doivent �tre parcourus.
 * @param[out] iter Adresse de l'it�rateur � initialiser.
*/
void initIterateur(Liste* li, Iterateur* iter);

/**
 * @brief Cette fonction indique si tous les �l�ments ont �t� parcourus.
 * @param[in] iter Adresse de l'it�rateur de la liste.
 * @return 1 si tout a �t� parcouru et 0 dans le cas contraire.
*/
int finiIt(const Iterateur* iter);

/**
* @brief Cette fonction retourne l'�l�ment courant du parcours.
* @param[in] iter Adresse de l'it�rateur de la liste.
* @return L'�l�ment de la liste actuellement d�signer par l'it�rateur.
* @pre Le parcours ne doit pas �tre fini (@ref finiIt).
*/
ItemL courantIt(const Iterateur* iter);

/**
* @brief Cette fonction passe a l'�l�ment suivant dans le parcours.
* @param[in,out] iter Adresse de l'it�rateur de liste.
* @pre Le parcours ne doit pas �tre fini (@ref finiIt).
*/
void suivantIt(Iterateur* iter);

/**
* @brief Cette fonction modifie l'�l�ment courant �tant parcouru.
* @param[in] iter Adresse de l'it�rateur de la liste.
* @param it Nouvelle valeur de l'�l�ment courant.
* @pre Le parcours ne doit pas �tre fini (@ref finiIt).
*/
void changer(const Iterateur* iter, ItemL it);

/**
* @brief Cette fonction ins�re un nouvel �l�ment avant l'�l�ment courant du parcours
* et, en fin de liste, si le parcours est fini (@ref finiIt). Le nouvel
* �l�ment courant est celui ayant �t� ins�r�.
* @param[in,out] iter Adresse de l'it�rateur de la liste.
* @param[in] it La valeur du nouvel �l�ment.
* @return 1 en cas de succ�s et 0 en cas de m�moire insuffisante. Dans ce dernier cas,
* la liste est inchang�e.
*/
int inserer(Iterateur* iter, ItemL it);

/**
 * @brief Cette fonction supprime l'�l�ment courant du parcours et positionne l'it�rateur
 * sur l'�l�ment suivant.
 * @param[in,out] iter Adresse de l'it�rateur de la liste.
 * @return L'�l�ment ayant �t� supprim� de la liste.
 * @pre Le parcours ne doit pas �tre fini (@ref finiIt).
*/
ItemL effacer(Iterateur* iter);

/**
 * @brief Cette fonction ajoute un �l�ment � la fin de la liste.
 * @param[in,out] li Pointeur vers la liste o� ajouter l'�l�ment.
 * @param[in] element �l�ment � ajouter � la fin de la liste.
*/
void inclureFin(Liste* li, ItemL element);

/**
 * @brief Cette fonction transf�re un �l�ment d'une position sp�cifique dans une liste source vers la fin d'une liste destination.
 * @param[in,out] source Pointeur vers la liste source contenant l'�l�ment � transf�rer.
 * @param[in,out] destination Pointeur vers la liste destination o� ajouter l'�l�ment.
 * @param[in] index Index de l'�l�ment � transf�rer dans la liste source.
*/
void transfererInFin(Liste* source, Liste* destination, int index);

/**
 * @brief Cette fonction retrouve l'index d'un �l�ment sp�cifique dans une liste.
 * @param[in] li Pointeur vers la liste o� chercher l'�l�ment.
 * @param[in] element �l�ment dont on cherche l'index.
 * @return L'index de l'�l�ment dans la liste, ou -1 si l'�l�ment n'est pas trouv�.
*/
int retrouverIndex(Liste* li, ItemL element);

/**
 * @brief Cette fonction supprime le premier �l�ment d'une liste.
 * @param[in,out] li Pointeur vers la liste dont on supprime le premier �l�ment.
*/
void supprimerDebut(Liste* li);

/**
 * @brief Cette fonction supprime le dernier �l�ment d'une liste.
 * @param[in,out] li Pointeur vers la liste dont on supprime le dernier �l�ment.
*/
void supprimerFin(Liste* li);

/**
 * @brief Cette fonction transf�re le premier �l�ment d'une liste source vers le d�but d'une liste destination.
 * @param[in,out] li1 Pointeur vers la liste source.
 * @param[in,out] li2 Pointeur vers la liste destination.
*/
void transfererDebut(Liste* li1, Liste* li2);

/**
 * @brief Cette fonction transf�re le dernier �l�ment d'une liste source vers le d�but d'une liste destination.
 * @param[in,out] li1 Pointeur vers la liste source.
 * @param[in,out] li2 Pointeur vers la liste destination.
*/
void transfererLast(Liste* li1, Liste* li2);

/**
 * @brief Cette fonction compare deux listes pour v�rifier leur �galit�.
 * @param[in] liste1 Pointeur vers la premi�re liste � comparer.
 * @param[in] liste2 Pointeur vers la seconde liste � comparer.
 * @return 1 si les listes sont �gales (m�me ordre, m�mes �l�ments), 0 sinon.
*/
int comparerListes(Liste* liste1, Liste* liste2);