# pragma warning(disable:4996)
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>

# include "Liste.h"

//iterateur debut
ConstIt iterer(const Liste* li) {
	return li->premier;
}

int fini(const ConstIt* iter) {
	return *iter == NULL;
}

ItemL courant(const ConstIt* iter) {
	assert(!fini(iter));
	return (*iter)->element;

}

void suivant(ConstIt* iter) {
	assert(!fini(iter));
	*iter = (*iter)->suivant;
}

int somme(const Liste* li) {
	int s = 0;
	for (ConstIt i = iterer(li); !fini(&i); suivant(&i))
		s++;
	return s;
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
//iterateur fin

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

void afficheListe(Liste* li) {
	if (li == NULL || li->premier == NULL) {
		printf("liste vide\n");
		return;
	}
	Maillion* m = li->premier;
	printf("[");
	while (m != NULL) {
		printf("%c%s", m->element, m->suivant ? " " : "");
		m = m->suivant;
	}
	printf("]\n");
}

void transferer(Liste* li1, Liste* li2, int index) {
	if (index < 0 || li1->premier == NULL) {
		printf("Index invalide ou liste source vide.\n");
		return;
	}
	Iterateur iter1, iter2;
	initIterateur(li1, &iter1);
	for (int i = 0; i < index; i++) {
		if (finiIt(&iter1)) {
			printf("Index hors limites.\n");
			return;
		}
		suivantIt(&iter1);
	}
	initIterateur(li2, &iter2);
	inserer(&iter2, courantIt(&iter1));
	effacer(&iter1);
}



