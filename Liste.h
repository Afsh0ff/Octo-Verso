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
* @param[in] la liste à initialiser
*/
void initListe(Liste* li);

/**
* @brief Cette fonction permet d'ajouter des éléments en tête d'une liste.
* @param[in] la liste oú l'on veut rajouter un élément.
* @param[in] l'élément que nous voulons ajouter.
*/
void inclure(Liste* li, ItemL it);

/**
* @brief Cette fonction permet d'afficher une liste donnée
* @param[in] la liste à afficher
*/
void afficheListe(const Liste* li);

/**
* @brief Cette fonction permet de prendre un élément d'une liste à une position donné (index) pour la transférer à la premiere position d'une autre liste.
* @param[in] li1 La liste oú il faut retirer les éléments
* @param[in] li2 La liste oú les éléments sont transferer à la premiere position
* @param[in] index L'indice oú l'élément va être récuperer
*/
void transfererIn(Liste* li1, Liste* li2, int index);

/**
 * @brief Cette fonction calcule le nombre d'éléments présents dans une liste chaînée.
 * @param[in] li Pointeur constant vers la liste dont on veut compter les éléments.
 * @return Le nombre d'éléments dans la liste.
*/
int somme(const Liste* li);

/**
 * @brief Cette fonction passe à l'élément suivant dans le parcours.
 * @param[in,out] iter Adresse de l'itérateur de la liste.
 * @pre Le parcours ne doit pas être fini (@ref fini).
 */
void suivant(ConstIt* iter);

/**
 * @brief Cette fonction retourne l'élément courant du parcours.
 * @param[in] iter Adresse de l'itérateur de liste.
 * @return L'élément de la liste actuellement désigner par l'itérateur.
 * @pre Le parcours ne doit pas être fini (@ref fini).
 */
ItemL courant(const ConstIt* iter);

/**
 * @brief Cette fonction indique si tous les éléments ont été parcourus.
 * @param[in] iter Adresse de l'itérateur de liste.
 * @return 1 si tout a été parcouru et 0 dans le cas contraire.
 */
int fini(const ConstIt* iter);

/**
 * @brief Cette fonction retourne un itérateur de liste au début du parcours.
 * @param[in] li Adresse de la liste à parcourir.
 * @return Un itérateur initialiser au début de cette liste.
 */
ConstIt iterer(const Liste* li);

/**
 * @brief Itérateur sur une liste permettant d'obtenir un à un les
 * éléments qui la composent mais aussi de modifier cette liste
 * (modification de la valeur de l'élément courant, insertion avant
 * l'élément courant, suppression de l'élément courant).
 */
typedef struct {
	Liste* liste; ///< La liste étant parcourue.
	Maillion* pred; ///< Désigne le maillon précedent le maillon courant (ou NULL).
	Maillion* courant; ///< Désigne le maillon courant (ou NULL).
} Iterateur;

/**
 * @brief Cette fonction initialise un itérateur de la liste au début du parcours.
 * @param[in] li Adresse de la liste dont les éléments doivent être parcourus.
 * @param[out] iter Adresse de l'itérateur à initialiser.
*/
void initIterateur(Liste* li, Iterateur* iter);

/**
 * @brief Cette fonction indique si tous les éléments ont été parcourus.
 * @param[in] iter Adresse de l'itérateur de la liste.
 * @return 1 si tout a été parcouru et 0 dans le cas contraire.
*/
int finiIt(const Iterateur* iter);

/**
* @brief Cette fonction retourne l'élément courant du parcours.
* @param[in] iter Adresse de l'itérateur de la liste.
* @return L'élément de la liste actuellement désigner par l'itérateur.
* @pre Le parcours ne doit pas être fini (@ref finiIt).
*/
ItemL courantIt(const Iterateur* iter);

/**
* @brief Cette fonction passe a l'élément suivant dans le parcours.
* @param[in,out] iter Adresse de l'itérateur de liste.
* @pre Le parcours ne doit pas être fini (@ref finiIt).
*/
void suivantIt(Iterateur* iter);

/**
* @brief Cette fonction modifie l'élément courant étant parcouru.
* @param[in] iter Adresse de l'itérateur de la liste.
* @param it Nouvelle valeur de l'élément courant.
* @pre Le parcours ne doit pas être fini (@ref finiIt).
*/
void changer(const Iterateur* iter, ItemL it);

/**
* @brief Cette fonction insère un nouvel élément avant l'élément courant du parcours
* et, en fin de liste, si le parcours est fini (@ref finiIt). Le nouvel
* élément courant est celui ayant été inséré.
* @param[in,out] iter Adresse de l'itérateur de la liste.
* @param[in] it La valeur du nouvel élément.
* @return 1 en cas de succès et 0 en cas de mémoire insuffisante. Dans ce dernier cas,
* la liste est inchangée.
*/
int inserer(Iterateur* iter, ItemL it);

/**
 * @brief Cette fonction supprime l'élément courant du parcours et positionne l'itérateur
 * sur l'élément suivant.
 * @param[in,out] iter Adresse de l'itérateur de la liste.
 * @return L'élément ayant été supprimé de la liste.
 * @pre Le parcours ne doit pas être fini (@ref finiIt).
*/
ItemL effacer(Iterateur* iter);

/**
 * @brief Cette fonction ajoute un élément à la fin de la liste.
 * @param[in,out] li Pointeur vers la liste où ajouter l'élément.
 * @param[in] element Élément à ajouter à la fin de la liste.
*/
void inclureFin(Liste* li, ItemL element);

/**
 * @brief Cette fonction transfère un élément d'une position spécifique dans une liste source vers la fin d'une liste destination.
 * @param[in,out] source Pointeur vers la liste source contenant l'élément à transférer.
 * @param[in,out] destination Pointeur vers la liste destination où ajouter l'élément.
 * @param[in] index Index de l'élément à transférer dans la liste source.
*/
void transfererInFin(Liste* source, Liste* destination, int index);

/**
 * @brief Cette fonction retrouve l'index d'un élément spécifique dans une liste.
 * @param[in] li Pointeur vers la liste où chercher l'élément.
 * @param[in] element Élément dont on cherche l'index.
 * @return L'index de l'élément dans la liste, ou -1 si l'élément n'est pas trouvé.
*/
int retrouverIndex(Liste* li, ItemL element);

/**
 * @brief Cette fonction supprime le premier élément d'une liste.
 * @param[in,out] li Pointeur vers la liste dont on supprime le premier élément.
*/
void supprimerDebut(Liste* li);

/**
 * @brief Cette fonction supprime le dernier élément d'une liste.
 * @param[in,out] li Pointeur vers la liste dont on supprime le dernier élément.
*/
void supprimerFin(Liste* li);

/**
 * @brief Cette fonction transfère le premier élément d'une liste source vers le début d'une liste destination.
 * @param[in,out] li1 Pointeur vers la liste source.
 * @param[in,out] li2 Pointeur vers la liste destination.
*/
void transfererDebut(Liste* li1, Liste* li2);

/**
 * @brief Cette fonction transfère le dernier élément d'une liste source vers le début d'une liste destination.
 * @param[in,out] li1 Pointeur vers la liste source.
 * @param[in,out] li2 Pointeur vers la liste destination.
*/
void transfererLast(Liste* li1, Liste* li2);

/**
 * @brief Cette fonction compare deux listes pour vérifier leur égalité.
 * @param[in] liste1 Pointeur vers la première liste à comparer.
 * @param[in] liste2 Pointeur vers la seconde liste à comparer.
 * @return 1 si les listes sont égales (même ordre, mêmes éléments), 0 sinon.
*/
int comparerListes(Liste* liste1, Liste* liste2);