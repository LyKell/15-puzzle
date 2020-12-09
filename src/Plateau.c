#include <stdio.h>
#include <stdlib.h>
#include "Plateau.h"


Plateau* allocate_plateau() {
	Plateau* tmp = (Plateau*) malloc(sizeof(Plateau));
	if (tmp == NULL) {
		printf("Allocation error on Plateau.");
		exit(EXIT_FAILURE);
	}
	plateau_init(tmp);
	return tmp;
}


void plateau_init(Plateau *p) {
	int i, j;

	for (i = 0; i < NB_LIG; i++) {
		for (j = 0; j < NB_COL; j++) {
			((p->bloc)[i][j]).lig = i;
			((p->bloc)[i][j]).col = j;
		}
	}
}


void show_plateau(Plateau p) {
	int i, j;

	for (i = 0; i < NB_LIG; i++) {
		for (j = 0; j < NB_COL; j++) {
			printf("[%d, %d] ", ((p.bloc)[i][j]).lig, ((p.bloc)[i][j]).col);
		}
		printf("\n");
	}
}



