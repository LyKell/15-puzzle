#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <MLV/MLV_all.h>
#include "IGraph.h"


void create_window() {
	MLV_create_window("TP4 - Taquin", "TP4 - Taquin", WIDTH_WINDOW, HEIGHT_WINDOW);
} 


void draw_taquin(Plateau p, char name[]) {
	MLV_Image *background;

	/* Affichage de l'arrière plan de la fenêtre */
	background = MLV_load_image("../resources/background2.png");
	MLV_draw_image(background, 0, 0);
	
	draw_cut_image(p, name);

	MLV_actualise_window();
	MLV_free_image(background);
}


void draw_cut_image(Plateau p, char name[]) {
	int i = 0, j = 0;
	int plateau_i, plateau_j, position_i, position_j;
	MLV_Image *image;

	image = MLV_load_image(name);
	for (i = 0; i < NB_LIG; i++) {
		for (j = 0; j < NB_COL; j++) {
			plateau_i = ((p.bloc)[i][j]).lig;	// i coord for the plateau
			plateau_j = ((p.bloc)[i][j]).col;	// j coord for the plateau

			position_i = 128 * i;	// i coord of the image part
			position_j = 128 * j;	// j coord of the image part

			// On affiche les cases uniquement si ce n'est pas la case contenant l'image en position [3, 3].
			if (!(plateau_i == 3 && plateau_j == 3)) {
				MLV_draw_partial_image(image, plateau_j * 128, plateau_i * 128, 128, 128, j * 5 + position_j, i * 5 + position_i);
			}
		}
	}
	MLV_resize_image_with_proportions(image, SIZE_PUZZLE, SIZE_PUZZLE);
	MLV_draw_image(image, 572, 0);

	MLV_free_image(image);
}


void puzzle_complete() {
	const char* text_box = "Bravo !\nVous avez complété le puzzle !";
	int width_box = 0, height_box = 0, size_interligne = 9;
	int position_box_x, position_box_y;

	MLV_get_size_of_adapted_text_box(text_box, size_interligne, &width_box, &height_box);

	position_box_x = (WIDTH_WINDOW - width_box) / 2;
	position_box_y = (HEIGHT_WINDOW - height_box) / 2;

	MLV_draw_adapted_text_box(position_box_x, position_box_y, text_box, 9, MLV_COLOR_RED, MLV_COLOR_RED, MLV_rgba(0, 0, 0, 128), MLV_TEXT_CENTER);
	MLV_actualise_window();
}


void draw_small_image(char* image_name, int i, int j) {
	MLV_Image* image = MLV_load_image(image_name);
	MLV_resize_image_with_proportions(image, IMAGE_THUMBNAIL, IMAGE_THUMBNAIL);
	MLV_draw_image(image, IMAGE_W_ORIG * (i + 1) + IMAGE_THUMBNAIL * i, IMAGE_H_ORIG + (j * (100 + IMAGE_THUMBNAIL)));
	MLV_free_image(image);
}


void draw_all_images(Image image, int len, char** list_puzzle) {
	int i, j, line = 0;
	char file_directory[75];
	MLV_Image *background;

	strcpy(file_directory, "../resources/");
	background = MLV_load_image("../resources/background2.png");
	MLV_draw_image(background, 0, 0);

	for (i = 0, j = 0; i < len; i++, j++) {
		strcat(file_directory, image->image_name);
		draw_small_image(file_directory, j, line);

		// if (image->selected == 1) {
		// 	draw_selected(j, line);
		// }

		// 14 images réparties en 2 lignes.
		// Il faut savoir quand afficher les images sur la deuxième ligne.
		if (i == 6) {
			line = 1;	// Variable de contrôle de ligne
			j = -1;
		}

		strcpy(file_directory, "../resources/");
		image = image->next;
	}
	MLV_free_image(background);
	MLV_actualise_window();
}


int hover_and_select_image(Image image) {
	int x, y, i = 0, j = 0, line = 0;
	Image tmp = image;

	MLV_get_mouse_position(&x, &y);

	while (image != NULL) {
		if (IMAGE_W_ORIG * (j + 1) + IMAGE_THUMBNAIL * j < x && x < (IMAGE_W_ORIG + IMAGE_THUMBNAIL) * (j + 1) && 
			IMAGE_H_ORIG + (line * (100 + IMAGE_THUMBNAIL)) < y && y < IMAGE_H_ORIG + (line * (100 + IMAGE_THUMBNAIL)) + IMAGE_THUMBNAIL) {
			// change_selected(tmp, image->image_name);
			if (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED) {
				return select_image(image, image->image_name);
			}
		}
		// 14 images réparties en 2 lignes.
		// Il faut donc indiquer quand est-ce qu'il faut afficher les images sur la deuxième ligne.
		if (i == 6) {
			line++;	// Variable de contrôle de ligne
			j = -1;
		}

		i++;
		j++;
		image = image->next;
	}
	return -1;
}










/* Fonction non utilisée car la fonctionnalité associée requière trop de ressources. */
void draw_selected(int i, int j) {
	MLV_Image* image;
	image = MLV_load_image("../resources/selected.png");

	MLV_resize_image_with_proportions(image, IMAGE_SELECTION, IMAGE_SELECTION);
	MLV_draw_image(image, (IMAGE_W_ORIG - 6) + (13 + IMAGE_SELECTION) * i, (IMAGE_H_ORIG - 6) + (j * (100 + IMAGE_THUMBNAIL)));
	free(image);
}

