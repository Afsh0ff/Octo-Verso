#pragma once

typedef char ItemL;

typedef struct {
	ItemL element;
	struct Maillion* suivant;
} Maillion;


typedef struct {
	Maillion* premier;
}Liste;

typedef const Maillion* ConstIt;
/**
* @brief initialise une liste
* @param[in] la liste a initialiser
*/
void initListe(Liste* li);

/**
* @brief Cette fonction permet d'ajouter des ellementse en tete d'une liste.
* @param[in] la liste ou l'on veut rajouter un element.
* @param[in] l'ellement que nous voulons ajouter.
*/
void inclure(Liste* li, ItemL it);

/**
* @brief permet d'afficher une liste donnée
* @param[in] la liste a afficher
*/
void afficheListe(Liste* li);

/**
* @brief permet de prendre un ellement d'une Liste a une position donné (index) pour La transferer a la premier position d'une autre liste
* @param[in] La liste ou il faut retirer les ellements
* @param[in] La liste ou les ellements son transferé a la premier position
* @param[in] l'index ou l'ellement va etre recuperer
*/
void transferer(Liste* li1, Liste* li2, int index);

int somme(const Liste* li);
void suivant(ConstIt* iter);
ItemL courant(const ConstIt* iter);
int fini(const ConstIt* iter);
ConstIt iterer(const Liste* li);

/**
 * @brief Retourne un it?rateur de liste au d?but du parcours.
 * @param[in] li Adresse de la liste ? parcourir.
 * @return Un it?rateur initialis? au d?but de cette liste.
 */
ConstIt iterer(const Liste* li);

/**
 * @brief Indique si tous les ?l?ments ont ?t? parcourus.
 * @param[in] iter Adresse de l'it?rateur de liste.
 * @return 1 si tout a ?t? parcouru et 0 dans le cas contraire.
 */
int fini(const ConstIt* iter);

/**
 * @brief Retourne l'?l?ment courant du parcours.
 * @param[in] iter Adresse de l'it?rateur de liste.
 * @return L'?l?ment de la liste actuellement d?sign? par l'it?rateur.
 * @pre Le parcours ne doit pas ?tre fini (@ref fini).
 */
ItemL courant(const ConstIt* iter);

/**
 * @brief Passe ? l'?l?ment suivant dans le parcours.
 * @param[in,out] iter Adresse de l'it?rateur de liste.
 * @pre Le parcours ne doit pas ?tre fini (@ref fini).
 */
void suivant(ConstIt* iter);

/**
 * @brief It?rateur sur une liste permettant d'obtenir un ? un les
 * ?l?ments qui la composent mais aussi de modifier cette liste
 * (modification de la valeur de l'?l?ment courant, insertion avant
 * l'?l?ment courant, suppression de l'?l?ment courant).
 */
typedef struct {
	Liste* liste; ///< La liste ?tant parcourue.
	Maillion* pred; ///< D?signe le maillon pr?c?dent le maillon courant (ou NULL).
	Maillion* courant; ///< D?signe le maillon courant (ou NULL).
} Iterateur;

/**
 * @brief Initialise un it?rateur de liste au d?but du parcours.
 * @param[in] li Adresse de la liste dont les ?l?ments doivent ?tre parcourus.
 * @param[out] iter Adresse de l'it?rateur ? initialiser.
 */
void initIterateur(Liste* li, Iterateur* iter);

/**
 * @brief Indique si tous les ?l?ments ont ?t? parcourus.
 * @param[in] iter Adresse de l'it?rateur de liste.
 * @return 1 si tout a ?t? parcouru et 0 dans le cas contraire.
 */
int finiIt(const Iterateur* iter);

/**
 * @brief Retourne l'?l?ment courant du parcours.
 * @param[in] iter Adresse de l'it?rateur de liste.
 * @return L'?l?ment de la liste actuellement d?sign? par l'it?rateur.
 * @pre Le parcours ne doit pas ?tre fini (@ref finiIt).
 */
ItemL courantIt(const Iterateur* iter);

/**
 * @brief Passe ? l'?l?ment suivant dans le parcours.
 * @param[in,out] iter Adresse de l'it?rateur de liste.
 * @pre Le parcours ne doit pas ?tre fini (@ref finiIt).
 */
void suivantIt(Iterateur* iter);

/**
 * @brief Modifie l'?l?ment courant ?tant parcouru.
 * @param[in] iter Adresse de l'it?rateur de liste.
 * @param it Nouvelle valeur de l'?l?ment courant.
 * @pre Le parcours ne doit pas ?tre fini (@ref finiIt).
 */
void changer(const Iterateur* iter, ItemL it);

/**
 * @brief Ins?re un nouvel ?l?ment avant l'?l?ment courant du parcours
 * et, en fin de liste, si le parcours est fini (@ref finiIt). Le nouvel
 * ?l?ment courant est celui ayant ?t? ins?r?.
 * @param[in,out] iter Adresse de l'it?rateur de liste.
 * @param[in] it La valeur du nouvel ?l?ment.
 * @return 1 en cas de succ?s et 0 en cas de m?moire insuffisante. Dans ce dernier cas,
 * la liste est inchang?e.
 */
int inserer(Iterateur* iter, ItemL it);

/**
 * @brief Supprime l'?l?ment courant du parcours et positionne l'it?rateur
 * sur l'?l?ment suivant.
 * @param[in,out] iter Adresse de l'it?rateur de liste.
 * @return L'?l?ment ayant ?t? supprim? de la liste.
 * @pre Le parcours ne doit pas ?tre fini (@ref finiIt).
 */
ItemL effacer(Iterateur* iter);
