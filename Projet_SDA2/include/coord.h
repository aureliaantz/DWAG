#ifndef __COORD_H__
#define __COORD_H__

#include <stdio.h>
#include <stdlib.h>
#include "debug.h"

#define NDIR 4 /* on entends ici directions cardinales */
#define NAXE (NDIR/2) /* nombre d'axes */

/* 
NDIR nombre de directions cardinales imposé par le sujet.
remarque : pour généralisation à N dimensiosn,

NDIR = 2
NSENS = (2*NDIR)   signification vectorielle pour sens / direction 

aurait plus de sens
*/

/* on ne nous demande pas de généralisaer l'algorithme, je vais donc me
contenter de hardcoder X,Y,NORD, EST, SUD, OUEST, pour donner du sens dans le code */

typedef enum e_axes { X=0, Y } Axe;
typedef enum e_directions { NORD=0, EST, SUD, OUEST } Dir; /* on entends ici directions cardinales */

typedef struct s_coord{
	int axe[NAXE];
} *coord;

typedef struct s_extremums{
	struct s_coord min;
	struct s_coord max;
} *extremums;

/**
 * \fn coord coord_nouv()
 * \brief cree une nouvelle coord 0,0
 * \return void
 **/
coord coord_nouv();

/**
 * \fn void coord_destroy(coord xy)
 * \brief dretuit une coord
 * \param xy adresse de la coord a detruire
 * \return void
 **/
void coord_destroy(coord xy);

#endif