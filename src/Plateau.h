#ifndef __PLATEAU__
#define __PLATEAU__

#define NB_COL 4
#define NB_LIG 4


typedef struct carre {
	int lig;	// lig mutable
	int col;	// col mutable
} Carre;


typedef struct plateau {
	Carre bloc[NB_COL][NB_LIG];	// i et j immutable
} Plateau;


/**
 * Fonction permettant d'allouer la place nécessaire pour un Plateau.
 * @return Un pointeur vers l'espace mémoire allouée.
 */
Plateau* allocate_plateau();


/**
 * Fonction du sujet permettant d'initialiser le plateau.
 * @param p Le plateau à initialiser.
 */
void plateau_init(Plateau *p);


/**
 * Fonction permettant d'afficher le plateau.
 * @param p Le plateau à afficher.
 */
void show_plateau(Plateau p);

#endif