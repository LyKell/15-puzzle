#ifndef __MENU__
#define __MENU__


typedef struct puzzle {
	int image_number;
	char* image_name;
	int selected;
	struct puzzle* previous;
	struct puzzle* next;
} Puzzle, *Image;


/**
 * Fonction permettant de choisir le puzzle que l'on veut faire (Dans le terminal).
 * @return Le numéro du puzzle choisi.
 */
int enter_choice();


/**
 * Fonction permettant d'allouer l'espace mémoire nécessaire pour une Image.
 * @param  image_number Le numéro de l'image.
 * @param  image_name   Le nom de l'image (puzzle_1.jpg).
 * @return              Un pointeur vers l'espace mémoire allouée.
 */
Image allocate_image(int image_number, char* image_name);


/**
 * Fonction permettant d'ajouter une Image à la liste chaînée contenant toutes les Images.
 * @param  image        La liste chaînée d'Images.
 * @param  image_number Le numéro de l'image.
 * @param  image_name   Le nom de l'image (puzzle_1.jpg).
 * @return              Un pointeur vers l'espace mémoire de la liste chaînée mise à jour.
 */
Image add_image(Image* image, int image_number, char* image_name);


/**
 * Fonction permettant d'afficher la liste chaînée d'images dans le terminal.
 * @param image La Liste chaînée d'Images.
 */
void show_images(Image image);


/**
 * Fonction permettant de changer le statut selected des images. Non utilisée, car la fonctionnalité associée est trop lourde.
 * @param image      La liste chaînée d'images.
 * @param image_name Le nom de l'image survolée.
 */
void change_selected(Image image, char* image_name);


/**
 * Fonction permettant d'initialiser la liste chaînée d'images, avec toutes les images disponibles.
 * @param image       La liste chaînée d'images.
 * @param len         Le nombre d'images disponibles.
 * @param list_puzzle La liste contenant le nom des images.
 */
void initialize_images(Image* image, int len, char** list_puzzle);


/**
 * Fonction permettant de sélectionner l'image que l'on veut par son nom. Remplace la fonction enter_choice() vue plus haut.
 * @param  image La liste chaînée d'images.
 * @param  title Le nom de l'image choisie.
 * @return       Le numéro de l'image si elle existe. -1 sinon.
 */
int select_image(Image image, char* title);


/**
 * Fonction permettant de sélectionner l'image que l'on veut par son numéro.
 * @param  image  La liste chaînée d'images.
 * @param  choice Le numéro de l'image.
 * @return        Le nom de l'image.
 */
char* select_puzzle(Image image, int choice);


#endif