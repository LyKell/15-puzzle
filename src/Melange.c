#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "Melange.h"


void shuffle_puzzle(Plateau *p, int x, int y, int* new_x, int* new_y, char name[]) {
	int current_direction, i, possible_movement, first_shuffling_result;
	int last_direction = 0;

	for (i = 0; i < NB_MOVEMENT; i++) {
		do {
			// Si c'est le premier mouvement, on ne peut pas déplacer la case noire en bas ou à droite.
			if (i == 0) {
				first_shuffling_result = MLV_get_random_integer(1,3);
				if (first_shuffling_result % 2 == 0) {
					current_direction = 1;	// Premier mouvement, case noire vers le haut.
				} else {
					current_direction = 4;	// Premier mouvement, case noire vers la gauche.
				}
			// Sinon, on est en plein milieu du mélange.
			} else {
				do {
					current_direction = MLV_get_random_integer(1, 5);
					// On évite de retourner en arrière dans le mélange. Si on fait droite, on ne peut pas faire gauche.
				} while ((last_direction + current_direction) % 2 == 0);
			}

			possible_movement = check_side_shuffle(p, current_direction, x, y, new_x, new_y, name);
		} while (possible_movement == 1);
		last_direction = current_direction;

		// Sauvegarde de la nouvelle position de la case [3, 3].
		x = *new_x;
		y = *new_y;
	}
}


int check_side_shuffle(Plateau *p, int direction, int x, int y, int* new_x, int* new_y, char name[]) {
	int x_dir, y_dir;
	switch (direction) {
		case 1:	// Haut
			if (x > 0) { // Déplacement haut possible.
				x_dir = -1;
				y_dir = 0;
			} else {	// Déplacement haut impossible.
				return 1;
			}
			break;

		case 2:	// Droite
			if (y < NB_COL-1) {	// Déplacement droite possible.
				x_dir = 0;
				y_dir = 1;
			} else {	// Déplacement droite impossible.
				return 1;
			}
			break;

		case 3:	// Bas
			if (x < NB_LIG-1) {	// Déplacement bas possible.
				x_dir = 1;
				y_dir = 0;
			} else {	// Déplacement bas impossible.
				return 1;
			}
			break;

		case 4:	// Gauche
			if (y > 0) { // Déplacement gauche possible.
				x_dir = 0;
				y_dir = -1;
			} else {	// Déplacement gauche impossible.
				return 1;
			}
			break;
	}
	move_direction(p, x, y, x_dir, y_dir, new_x, new_y, name);
	return 0;
}


void move_direction(Plateau *p, int x, int y, int x_dir, int y_dir, int *new_x, int *new_y, char name[]) {
	// Echange de valeur.
	Carre tmp = p->bloc[x][y];
	p->bloc[x][y] = p->bloc[x + x_dir][y + y_dir];
	p->bloc[x + x_dir][y + y_dir] = tmp;

	draw_taquin(*p, name);
	// MLV_wait_milliseconds(50);

	*new_x = (x + x_dir);
	*new_y = (y + y_dir);
}