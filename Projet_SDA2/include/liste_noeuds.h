#ifndef __LISTE_NOEUDS_H__
#define __LISTE_NOEUDS_H__

#include <stdio.h>
#include "noeud.h"
#include "debug.h"

//maillon pour liste de noeuds.
typedef struct s_liste_n 
{
    noeud data; // the data
	struct s_liste_n* succ;  // next link
} ln,*liste_n;

liste_n nouv_ln();
void destroy_ln(liste_n l);
liste_n adjtete_ln(liste_n l, noeud x);
liste_n adjqueue_ln(liste_n l, noeud x);
liste_n rech_ln(liste_n l, noeud x);

void ln_printf(liste_n l);
void ln_printf_pos(liste_n l);

#endif