#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "IGraph.h"
#include "Plateau.h"
#include "Melange.h"
#include "Score.h"
#include "Solve.h"
#include "Menu.h"


int main(int argc, char const *argv[]) {
	Plateau *p;
	int *new_x = malloc(sizeof(int)), *new_y = malloc(sizeof(int));
	int choice, len;
	char* list_puzzle[] = {"puzzle_14.jpg", "puzzle_13.jpg", "puzzle_12.jpg", "puzzle_11.jpg", "puzzle_10.jpg", "puzzle_9.jpg", "puzzle_8.jpg",
						"puzzle_7.jpg", "puzzle_6.jpg", "puzzle_5.jpg", "puzzle_4.jpg", "puzzle_3.jpg", "puzzle_2.jpg", "puzzle_1.jpg"};
	char puzzle_name[30];
	Image image = NULL;

	p = allocate_plateau();
	plateau_init(p);

	create_window();

	len = sizeof(list_puzzle) / sizeof(list_puzzle[0]);
	strcpy(puzzle_name, "../resources/");

	// Initialisation de la liste chaînée contenant les informations des images
	initialize_images(&image, len, list_puzzle);
	draw_all_images(image, len, list_puzzle);


	// Partie choix du puzzle
	do {
		choice = hover_and_select_image(image);
	} while (choice < 0 || choice > len);

	strcat(puzzle_name, select_puzzle(image, choice));

	// show_plateau(*p);


	// Partie mélange
	shuffle_puzzle(p, 3, 3, new_x, new_y, puzzle_name);

	draw_taquin(*p, puzzle_name);


	// Partie résolution
	while (verify_puzzle(*p) == 1) {
		mouse_click(p, puzzle_name);
	}

	MLV_wait_seconds(5);
	MLV_free_window();

	return 0;
}
