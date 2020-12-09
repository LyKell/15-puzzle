#ifndef __SOLVE__
#define __SOLVE__

#include "Melange.h"


/**
 * Fonction permettant de vérifier si le puzzle est complété.
 * @param  p Le puzzle à vérifier.
 * @return   Renvoie 1 si le puzzle n'est pas fini. 0 sinon.
 */
int verify_puzzle(Plateau p);


/**
 * Fonction permettant de récupérer le clic de souris.
 * @param p    Le puzzle que l'on veut résoudre.
 * @param name Le nom de l'image du puzzle.
 */
void mouse_click(Plateau* p, char name[]);


/**
 * Fonction permettant de vérifier si la position du clic de souris sur le puzzle permet un potentiel déplacement
 * et convertie la position du clic en coordonnée du plateau.
 * @param  p       Le puzzle que l'on veut résoudre.
 * @param  mouse_x La position verticale (ligne) du clic de souris.
 * @param  mouse_y La position horizontale (colonne) du clic de souris.
 * @param  name    Le nom de l'image du puzzle.
 * @return         Renvoie 1 si le clic ne mène pas à un déplacement légal. 0 sinon.
 */
int get_piece_position(Plateau* p, int mouse_x, int mouse_y, char name[]);


/**
 * Fonction permettant de convertir la position du clic de souris en coordonnée de l'image SANS les bandes noires.
 * @param mouse_x La position verticale (ligne) du clic de souris.
 * @param mouse_y La position horizontale (colonne) du clic de souris.
 */
void get_mouse_position_on_image(int* mouse_x, int* mouse_y);


/**
 * Fonction permettant de vérifier si un déplacement est légal.
 * @param  p         Le puzzle que l'on veut résoudre.
 * @param  direction La direction du déplacement.
 * @param  x         La coordonnée verticale (ligne) de la pièce à déplacer.
 * @param  y         La coordonnée horizontale (colonne) de la pièce à déplacer.
 * @param  name      Le nom de l'image du puzzle.
 * @return           Renvoie 1 si le déplacement est illégal. 0 sinon.
 */
int check_side_solver(Plateau* p, int direction, int x, int y, char name[]);

#endif