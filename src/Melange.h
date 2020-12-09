#ifndef __MELANGE__
#define __MELANGE__

#include "Plateau.h"
#include "IGraph.h"

#define NB_MOVEMENT 120


/**
 * Fonction mettant en place tout le mélange. Définit la direction dans laquelle déplacer la case noire.
 * @param p     Le plateau à mélanger.
 * @param x     La coordonnée verticale (ligne) de la case noire.
 * @param y     La coordonnée horizontale (colonne) de la case noire.
 * @param new_x La nouvelle coordonnée verticale (ligne) de la case noire (Là où la case noire se déplace).
 * @param new_y La nouvelle coordonnée horizontale (colonne) de la case noire (Là où la case noire se déplace).
 * @param name  Le nom de l'image du puzzle.
 */
void shuffle_puzzle(Plateau *p, int x, int y, int* new_x, int* new_y, char name[]);


/**
 * Fonction permettant de vérifier si un déplacement est possible ou non.
 * @param  p         Le plateau à mélanger
 * @param  direction La direction dans laquelle on veut déplacer la case noire.
 * @param  x         La coordonnée verticale (ligne) de la case noire.
 * @param  y         La coordonnée horizontale (colonne) de la case noire.
 * @param  new_x     La nouvelle coordonnée verticale (ligne) de la case noire (Là où la case noire se déplace).
 * @param  new_y     La nouvelle coordonnée horizontale (colonne) de la case noire (Là où la case noire se déplace).
 * @param  name      Le nom de l'image du puzzle.
 * @return           Renvoie 1 si le déplacement est illégal. 0 sinon.
 */
int check_side_shuffle(Plateau *p, int direction, int x, int y, int* new_x, int* new_y, char name[]);


/**
 * [move_direction description]
 * @param p     Le plateau à mélanger.
 * @param x     La coordonnée verticale (ligne) de la case noire.
 * @param y     La coordonnée horizontale (colonne) de la case noire.
 * @param x_dir Le nombre de cases que l'on déplace en x (1 ou -1).
 * @param y_dir Le nombre de cases que l'on déplace en y (1 ou -1).
 * @param new_x La nouvelle coordonnée verticale (ligne) de la case noire (Là où la case noire se déplace).
 * @param new_y La nouvelle coordonnée horizontale (colonne) de la case noire (Là où la case noire se déplace).
 * @param name  Le nom de l'image du puzzle.
 */
void move_direction(Plateau *p, int x, int y, int x_dir, int y_dir, int *new_x, int *new_y, char name[]);

#endif