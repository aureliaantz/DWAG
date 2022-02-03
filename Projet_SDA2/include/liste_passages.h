#ifndef __LISTE_PASSAGES_H__
#define __LISTE_PASSAGES_H__

#include <stdio.h>
#include "noeud.h"
#include "debug.h"

//maillon pour liste de passage.
//un passage est un arc non orienté entre deux noeuds.
typedef struct s_liste_p 
{
    noeud n1;// the data
    noeud n2;
	struct s_liste_p* succ;  // next link
} lp,*liste_p;

liste_p nouv_lp();
void destroy_lp(liste_p l);
liste_p adjtete_lp(liste_p l, noeud x1, noeud x2);
liste_p adjqueue_lp(liste_p l, noeud x1, noeud x2);
liste_p rech_lp(liste_p l, noeud n1, noeud n2);

void lp_printf(liste_p l);
void lp_printf_pos(liste_p l);

#endif