#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"


/* Fonction non utilisée, car on utilise un affichage graphique */
int enter_choice() {
	int choice;

	while (1) {
		printf("Choose your puzzle :\n1. HK416\n2. Prinz Eugen\n3. Cherry blossom\n4. (K)NoW_NAME\n5. Touhou EoSD\n6. eYe's\n7. Silent Hill 2\n8. Hydra\n9 TIT FOR TAT\n10. Meteor/New Generation\n11. Kizuna AI\n12. Flowey\n13. Sayaka Miki\n14. Cherry blossom tree\n");
		scanf("%d", &choice);

		if (0 < choice && choice < 15) {
			break;
		} else {
			printf("This is not a puzzle !\n");
		}
	}
	return choice;
}


Image allocate_image(int image_number, char* image_name) {
	Image tmp = (Puzzle*) malloc(sizeof(Puzzle));

	if (tmp == NULL) {
		printf("Can't allocate image %s.\n", image_name);
		exit(EXIT_FAILURE);
	}

	tmp->image_name = (char *) malloc(sizeof(char) * strlen(image_name));
	if (tmp->image_name == NULL) {
		printf("Can't allocate %s name.\n", image_name);
		exit(EXIT_FAILURE);
	}

	tmp->image_number = image_number;
	strcpy(tmp->image_name, image_name);
	tmp->selected = 0;
	tmp->next = NULL;
	tmp->previous = NULL;

	return tmp;
}



Image add_image(Image* image, int image_number, char* image_name) {
	Image tmp = allocate_image(image_number, image_name);

	if (tmp != NULL) {
		tmp->next = *image;
		*image = tmp;
	}
	return tmp;
}



void show_images(Image image) {
	if (image == NULL) {
		printf("No Images\n");
	} else {
		while (image != NULL) {
			printf("%d %s %d -> ", image->image_number, image->image_name, image->selected);
			image = image->next;
		}
	}
	printf("\n");
}


/* Fonction non utilisée car la fonctionnalité associée requière trop de ressources. */
void change_selected(Image image, char* image_name) {
	if (image == NULL) {
		printf("No Images");
	} else {
		while (image != NULL) {
			if (strcmp(image->image_name, image_name) == 0) {
				image->selected = 1;
			} else {
				image->selected = 0;
			}
			image = image->next;
		}
	}
}


void initialize_images(Image* image, int len, char** list_puzzle) {
	int i;

	for (i = 0; i < len; i++) {
		*image = add_image(image, i, list_puzzle[i]);
	}
}


int select_image(Image image, char* title) {
	while (image != NULL) {
		if (strcmp(image->image_name, title) == 0) {
			return image->image_number;
		}
		image = image->next;
	}
	return -1;
}


char* select_puzzle(Image image, int choice) {
	while (image != NULL) {
		if (image->image_number == choice) {
			break;
		}
		image = image->next;
	}
	return image->image_name;
}