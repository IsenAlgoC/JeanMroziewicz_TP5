#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define TAILLEINITIALE 100
typedef struct Tableau {
  int i;
	int* elt; 
	int size; 
	int eltsCount; 
} TABLEAU;
TABLEAU newArray() {
	TABLEAU tab;
	tab.size = TAILLEINITIALE;
	tab.eltsCount = 0;
	tab.elt = malloc(TAILLEINITIALE * sizeof(int));
	for (int i = 0; i < TAILLEINITIALE; i++) {
		tab.elt[i] = 0;
	}
	return tab;
}
int incrementArraySize(TABLEAU* tab, int incrementValue) {
	int i;
  int* save = tab->elt;
	tab->elt = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));
	if (tab->elt == NULL) {
		tab->elt = save;
		return -1;
	}
	for (int i = 0; i < incrementValue; i++) {
		tab->elt[tab->size + i] = 0;
	}
	tab->size += incrementValue;
	return tab->size;
}
int setElement(TABLEAU* tab, int pos, int element) {
	if (pos < 1) {
		return 0;
	}
	if (pos > tab->size) {
		incrementArraySize(tab, pos - tab->size);
	}
	if (tab->elt == NULL) {
		return 0;
	}
	if (pos > tab->eltsCount) { 
		tab->eltsCount = pos;
	}
	tab->elt[pos-1] = element;
	return pos;
}
int displayElements(TABLEAU* tab, int startPos, int endPos) { 
	int i;
  if (startPos >= endPos ) {
		int indice = endPos;
		endPos = startPos;
		startPos = indice;
	}

	if (tab->elt == NULL || startPos<1 || endPos > tab->eltsCount) {
		return -1;
	}
	for (int i = startPos; i <= endPos; i++) {
		printf("%d ", tab->elt[i - 1]);
	}
	return 0;
}
int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	int i;
  if (startPos >= endPos) {
		int indice = endPos;
		endPos = startPos;
		startPos = indice;
	}
	if (tab->elt == NULL || endPos > tab->eltsCount || startPos < 1) {
		return -1;
	}
	int* tab2 = tab->elt;
	int c = 0;
	for (int i = 0; i<tab->size;i++) {
		if (i<(startPos - 1) || i>(endPos - 1)) {
			tab->elt[c] = tab2[i];
			c++;
		}
	}
	tab->eltsCount -= endPos - startPos + 1;
	tab->size -= endPos - startPos + 1;
	return tab->size;
}
int main() {
	TABLEAU tab;
	tab = newArray();
	setElement(&tab,3,10);
	setElement(&tab, 2, 11);
	setElement(&tab, 1, 12);
	setElement(&tab, 4, 10);
	displayElements(&tab, 1, 5);
	deleteElements(&tab, 1, 3);
	displayElements(&tab, 1, 6);
	setElement(&tab, 11, 15);
	displayElements(&tab, 1, 15);
}
