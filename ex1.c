#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "tab.h"

int* myTab2 = NULL;

int initTab(int * tab, int size)
{
	int i = 0;
	for (i = 0; i < size; i++) {
		tab[i] = 0;
	}
	if (size < 0 || tab == NULL) {
		return -1;
	}
	else {
		return size;
	}
}

int afficheTab(int* tab, int size, int nbElts) {
	int i = 0;
	for (i = 0; i < nbElts; i++) {
		printf(tab[i]);
	}
	if (size < 0 || tab == NULL || size<nbElts) {
		return -1;
	}
	else {
		return 0;
	}
}

int ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	int i = 0;
  if (size < 0 || tab == NULL) {
		return -1;
	}
	else {
		if (*nbElts >= *size) {
			int* test_tab = tab;
			tab = (int*)realloc(tab, (*size + plus) * sizeof(int));
			if (test_tab == NULL) {
				tab = test_tab;
				return -1;
			}
			for (int i = 0; i < plus; i++) {
				*(tab + *size + i) = 0;
			}
			*size += plus;
		}
		*(tab + *nbElts) = element;
		*nbElts += 1;
		return *nbElts;
	}
}
int main() {
  int i = 0;
	int myTab1[10]={ 0 };
	int nbElmts = 20;
	int size = TAB2SIZE;
	myTab2 = (int*)malloc(100 * sizeof(int));
	initTab(myTab2, TAB2SIZE);
	if (myTab2 != NULL) {
		for (int i = 0; i < 20; i++) {
			myTab2[i] = i + 1;
		}
	}
	afficheTab(myTab2, size, 90);
	nbElmts = 105;
	ajoutElementDansTableau(myTab2, &size, &nbElmts, 15);
	printf("%d",afficheTab(myTab2, size, 106));
	free(myTab2);
}
