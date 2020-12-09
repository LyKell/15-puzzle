#ifndef __IGRAPH__
#define __IGRAPH__

#include "Plateau.h"
#include "Menu.h"


#define WIDTH_WINDOW 1094
#define HEIGHT_WINDOW 522
#define SIZE_PUZZLE 522
#define IMAGE_THUMBNAIL 128
#define IMAGE_SELECTION 140
#define IMAGE_W_ORIG 25
#define IMAGE_H_ORIG 50
#define PUZZLE_PIECE 128


/**
 * Fonction permettant de créer la fenêtre de jeu.
 */
void create_window();


/**
 * Fonction permettant d'afficher le puzzle.
 * @param p    Le puzzle à afficher.
 * @param name Le nom de l'image du puzzle.
 */
void draw_taquin(Plateau p, char name[]);


/**
 * Fonction permettant d'afficher le puzzle fractionné.
 * @param p    Le puzzle à afficher.
 * @param name Le nom de l'image du puzzle.
 */
void draw_cut_image(Plateau p, char name[]);


/**
 * Fonction permettant d'afficher un message lorsque le puzzle est complété.
 */
void puzzle_complete();


/**
 * Fonction permettant d'afficher un puzzle en miniature pour choisir l'image du puzzle.
 * @param image_name Le nom de l'image.
 * @param i          Un indice indiquant la position horizontale de l'image.
 * @param j          Un indice indiquant la position verticale de l'image.
 */
void draw_small_image(char* image_name, int i, int j);


/**
 * Fonction permettant de gérer l'affichage de tous les puzzles en miniature.
 * @param image       La liste chaînée contenant toutes les images.
 * @param len         Le nombre d'images disponibles.
 * @param list_puzzle La liste contenant le nom des images (puzzle_1.jpg, pas le chemin).
 */
void draw_all_images(Image image, int len, char** list_puzzle);


/**
 * Fonction permettant de savoir quel puzzle est survolé et sélectionné.
 * @param  image La liste chaînée contenant toutes les images.
 * @return       L'indice de l'image sélectionnée. -1 si aucune image n'est sélectionnée.
 */
int hover_and_select_image(Image image);


/**
 * Fonction permettant de mettre en évidence puzzle sélectionné ou hover. Non utilisée, car la fonctionnalité associée est trop lourde, donc à améliorer.
 * @param i Un indice indiquant la position horizontale de l'image.
 * @param j Un indice indiquant la position verticale de l'image.
 */
void draw_selected(int i, int j);


#endif