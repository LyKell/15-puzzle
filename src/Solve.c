#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "Solve.h"


int verify_puzzle(Plateau p) {
	int i, j;
	for (i = 0; i < NB_LIG; i++) {
		for (j = 0; j < NB_COL; j++) {
			// Si le puzzle est complet, alors il est dans sa position d'initialisation. Donc i == lig et j == col.
			if ((p.bloc)[i][j].lig != i || (p.bloc)[i][j].col != j) {
				return 1;
			}
		}
	}
	// printf("Puzzle complete !\n");
	puzzle_complete();
	return 0;
}


void mouse_click(Plateau* p, char name[]) {
	int mouse_x, mouse_y;
	MLV_wait_mouse(&mouse_x, &mouse_y);
	get_piece_position(p, mouse_x, mouse_y, name);
}


int get_piece_position(Plateau* p, int mouse_x, int mouse_y, char name[]) {
	int i, coord_x, coord_y, res;

	for (i = 0; i < NB_LIG - 1; i++) {
		if ((PUZZLE_PIECE + 5) * i + PUZZLE_PIECE < mouse_x && mouse_x < (PUZZLE_PIECE + 5) * i + (PUZZLE_PIECE + 5)) {
			return 1;	// On appuye sur une bande noire.
		}
	}
	for (i = 0; i < NB_COL - 1; i++) {
		if ((PUZZLE_PIECE + 5) * i + PUZZLE_PIECE < mouse_y && mouse_y < (PUZZLE_PIECE + 5) * i + (PUZZLE_PIECE + 5)) {
			return 1;	// On appuye sur une bande noire.
		}
	}

	get_mouse_position_on_image(&mouse_y, &mouse_x);

	coord_x = mouse_x / PUZZLE_PIECE;
	coord_y = mouse_y / PUZZLE_PIECE;

	for (i = 1; i < 5; i++) {
		res = check_side_solver(p, i, coord_y, coord_x, name);
		if (res == 0) {
			return 0;
		}
	}
	return 1;
}


void get_mouse_position_on_image(int* mouse_x, int* mouse_y) {
	int i, j;

	// Comme les pièces de l'image affichée sont séparées par des bandes noires, le calcul de la position de la case dans plateau est légèrement modifiée.
	// En fonction de la pièce sur laquelle on appuye, il faut retirer le bon nombre de bandes noires pour pouvoir appliquer un calcul fonctionnel pour
	// récupérer les coordonnées de la case.

	for (j = 0; j < NB_LIG - 1; j++) {
		if (*mouse_y >= (PUZZLE_PIECE + 5) * j + (PUZZLE_PIECE + 5) && *mouse_y <= (PUZZLE_PIECE + 5) * (j + 1) + PUZZLE_PIECE) {
			*mouse_y -= (j + 1) * 5;
		}
	}
	for (i = 0; i < NB_LIG - 1; i++) {
		if (*mouse_x >= (PUZZLE_PIECE + 5) * i + (PUZZLE_PIECE + 5) && *mouse_x <= (PUZZLE_PIECE + 5) * (i + 1) + PUZZLE_PIECE) {
			*mouse_x -= (i + 1) * 5;
		}
	}
}


int check_side_solver(Plateau* p, int direction, int x, int y, char name[]) {
	int x_dir, y_dir, useless_x, useless_y;
	switch (direction) {
		case 1:	// Haut
			if (x > 0 && (p->bloc)[x-1][y].lig == 3 && (p->bloc)[x-1][y].col == 3) {	// Déplacement haut possible
				x_dir = -1;
				y_dir = 0;
			} else {	// Déplacement haut impossible
				return 1;
			}
			break;

		case 2:	// Droite
			if (y < NB_COL-1 && (p->bloc)[x][y+1].lig == 3 && (p->bloc)[x][y+1].col == 3) {	// Déplacement droite possible
				x_dir = 0;
				y_dir = 1;
			} else {	// Déplacement droite impossible
				return 1;
			}
			break;

		case 3:	// Bas
			if (x < NB_LIG-1 && (p->bloc)[x+1][y].lig == 3 && (p->bloc)[x+1][y].col == 3) {	// Déplacement bas possible
				x_dir = 1;
				y_dir = 0;
			} else {	// Déplacement bas impossible
				return 1;
			}
			break;

		case 4:	// Gauche
			if (y > 0 && (p->bloc)[x][y-1].lig == 3 && (p->bloc)[x][y-1].col == 3) {	// Déplacement gauche possible
				x_dir = 0;
				y_dir = -1;
			} else {	// Déplacement gauche impossible
				return 1;
			}
			break;
	}
	move_direction(p, x, y, x_dir, y_dir, &useless_x, &useless_y, name);
	return 0;
}