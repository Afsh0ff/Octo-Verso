# pragma warning(disable:4996)
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>

# include "Liste.h"

void initListe(Liste* li) {
	li->premier = NULL;
}

void inclure(Liste* li, ItemL it) {
	Maillion* q;
	q = (Maillion*)malloc(sizeof(Maillion));
	q->element = it;
	q->suivant = li->premier;
	li->premier = q;
}

void afficheListe(const Liste* li) {
	if (li == NULL || li->premier == NULL) {
		printf("liste vide\n");
		return;
	}
	Maillion* m = li->premier;
	while (m != NULL) {
		printf("%c", m->element);
		m = m->suivant;
	}
	printf("\n");
}

void transfererIn(Liste* li1, Liste* li2, int index) {
	if (index < 0 || li1->premier == NULL) {

		return;
	}
	Iterateur iter1, iter2;
	initIterateur(li1, &iter1);
	for (int i = 0; i < index; i++) {
		if (finiIt(&iter1)) {

			return;
		}
		suivantIt(&iter1);
	}
	initIterateur(li2, &iter2);
	inserer(&iter2, courantIt(&iter1));
	effacer(&iter1);
}

int somme(const Liste* li) {
	int s = 0;
	for (ConstIt i = iterer(li); !fini(&i); suivant(&i))
		s++;
	return s;
}

void suivant(ConstIt* iter) {
	assert(!fini(iter));
	*iter = (*iter)->suivant;
}

ItemL courant(const ConstIt* iter) {
	assert(!fini(iter));
	return (*iter)->element;
}

int fini(const ConstIt* iter) {
	return *iter == NULL;
}

ConstIt iterer(const Liste* li) {
	return li->premier;
}

void initIterateur(Liste* li, Iterateur* iter) {
	iter->liste = li;
	iter->pred = NULL;
	iter->courant = li->premier;
}

int finiIt(const Iterateur* iter) {
	return iter->courant == NULL;
}

ItemL courantIt(const Iterateur* iter) {
	assert(!finiIt(iter));
	return iter->courant->element;
}

void suivantIt(Iterateur* iter) {
	assert(!finiIt(iter));
	iter->pred = iter->courant;
	iter->courant = iter->courant->suivant;
}

void changer(const Iterateur* iter, ItemL it) {
	assert(!finiIt(iter));
	iter->courant->element = it;
}

int inserer(Iterateur* iter, ItemL it) {
	Maillion* m = (Maillion*)malloc(sizeof(Maillion));
	if (m == NULL)
		return 0;
	m->element = it;
	m->suivant = iter->courant;
	if (iter->pred == NULL)
		iter->liste->premier = m;
	else
		iter->pred->suivant = m;
	iter->courant = m;
	return 1;
}

ItemL effacer(Iterateur* iter) {
	assert(!finiIt(iter));
	Maillion* m = iter->courant;
	if (iter->pred == NULL)
		iter->liste->premier = m->suivant;
	else
		iter->pred->suivant = m->suivant;
	iter->courant = m->suivant;
	ItemL it = m->element;
	free(m);
	return it;
}

void inclureFin(Liste* li, ItemL element) {
	Maillion* nouveau = (Maillion*)malloc(sizeof(Maillion));
	nouveau->element = element;
	nouveau->suivant = NULL;

	if (li->premier == NULL) {
		// Si la liste est vide, le nouvel élément devient le premier élément
		li->premier = nouveau;
	}
	else {
		// Parcourir la liste jusqu'au dernier élément
		Maillion* temp = li->premier;
		while (temp->suivant != NULL) {
			temp = temp->suivant;
		}
		// Ajouter le nouvel élément à la fin
		temp->suivant = nouveau;
	}
}

void transfererInFin(Liste* source, Liste* destination, int index) {
	if (index < 0 || source->premier == NULL) {

		return;
	}

	Iterateur iter;
	initIterateur(source, &iter);

	// Parcourir la liste source jusqu'à l'élément à transférer
	for (int i = 0; i < index; i++) {
		if (finiIt(&iter)) {

			return;
		}
		suivantIt(&iter);
	}

	// Récupérer l'élément à transférer
	ItemL element = effacer(&iter);

	// Ajouter l'élément à la fin de la liste destination
	inclureFin(destination, element);
}

int retrouverIndex(Liste* li, ItemL element) {
	Iterateur iter;
	initIterateur(li, &iter);

	int index = 0;
	while (!finiIt(&iter)) {
		if (courantIt(&iter) == element) {
			return index;  // Retourne l'index si l'élément est trouvé
		}
		suivantIt(&iter);
		index++;
	}
	return -1;  // Retourne -1 si l'élément n'est pas trouvé
}

void supprimerDebut(Liste* li) {
	if (li->premier == NULL) {
		return;
	}

	Maillion* temp = li->premier;
	li->premier = li->premier->suivant;
	free(temp);
}

void supprimerFin(Liste* li) {
	if (li->premier == NULL) {
		return;
	}

	if (li->premier->suivant == NULL) {
		// Si la liste a un seul élément
		free(li->premier);
		li->premier = NULL;
	}
	else {
		// Parcourir la liste jusqu'à l'avant-dernier élément
		Maillion* current = li->premier;
		Maillion* prev = NULL;

		// On parcourt jusqu'à ce que current pointe sur le dernier élément
		while (current->suivant != NULL) {
			prev = current;
			current = current->suivant;
		}

		// Le dernier élément est maintenant pointed par current, et l'avant-dernier par prev
		free(current);
		prev->suivant = NULL;
	}
}

void transfererDebut(Liste* li1, Liste* li2) {
	if (li1 == NULL || li1->premier == NULL) {
		return;
	}

	// Extraire le premier élément de la liste source
	Maillion* element_a_transferer = li1->premier;
	li1->premier = li1->premier->suivant;

	// Ajouter cet élément en tête de la liste cible
	element_a_transferer->suivant = li2->premier;
	li2->premier = element_a_transferer;
}

void transfererLast(Liste* li1, Liste* li2) {
	if (li1 == NULL || li1->premier == NULL) {
		return;
	}

	// Cas où la liste source a un seul élément
	if (li1->premier->suivant == NULL) {
		// Retirer l'élément de la liste source
		Maillion* element_a_transferer = li1->premier;
		li1->premier = NULL;

		// Ajouter cet élément en tête de la liste cible
		element_a_transferer->suivant = li2->premier;
		li2->premier = element_a_transferer;

		return;
	}

	// Parcourir jusqu'au dernier élément de la liste source
	Maillion* courant = li1->premier;
	while (courant->suivant != NULL) {
		courant = courant->suivant;
	}

	// `courant` est maintenant le dernier élément de la liste source
	Maillion* element_a_transferer = courant;
	Maillion* precedent = li1->premier;

	// Parcourir pour trouver l'élément précédent
	while (precedent->suivant != courant) {
		precedent = precedent->suivant;
	}

	// Retirer l'élément de la liste source
	precedent->suivant = NULL;

	// Ajouter cet élément en tête de la liste cible
	element_a_transferer->suivant = li2->premier;
	li2->premier = element_a_transferer;
}

int comparerListes(Liste* liste1, Liste* liste2) {
	Maillion* courant1 = liste1->premier;
	Maillion* courant2 = liste2->premier;

	while (courant1 != NULL && courant2 != NULL) {
		if (courant1->element != courant2->element) {
			return 0;  // Les valeurs ne correspondent pas
		}
		courant1 = courant1->suivant;
		courant2 = courant2->suivant;
	}

	// Si l'une des listes est plus longue que l'autre, elles ne sont pas égales
	if (courant1 != NULL || courant2 != NULL) {
		return 0;
	}

	return 1;  // Les listes sont égales
}
