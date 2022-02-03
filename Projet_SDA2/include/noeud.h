#ifndef __NOEUD_H__
#define __NOEUD_H__

#include "coord.h"
#include "tresors.h"
#include "debug.h"
#include <stdbool.h>

typedef struct s_noeud {
	struct s_noeud* voisins[NDIR];
	int distances[NDIR];
	float* tresors[NDIR];
	int id; //pour comparaisons
} *noeud;

/**
 * \fn noeud noeud_nouv(int id);
 * \brief crée un nouveau noeud "vide" cad sans voisins
 * \return l'adresse noeud crée
 **/
noeud noeud_nouv(int id);

/**
 * \fn void destroy_noeud(noeud n);
 * \brief détruire un noeud
 * \return void
 **/
void destroy_noeud(noeud n);

/**
 * \fn void passage(noeud n1, noeud n2, Dir d, int dist); 
 * \brief //creation de deux arcs reciproques de n1 à n2, valués dist, sur l'axe de direction dir
 * \param n1 noeud 1
 * \param n2 noeud 1
 * \param d la direction du passage pour n1
 * \param dist la distance du passage
 * \return void
 **/
void passage(noeud n1, noeud n2, Dir d, int dist, float* tr); 

/**
 * \fn int noeud_cmp(noeud n1, noeud n2);
 * \brief comparer l'id de deux noeuds
 * \param n1 noeud 1
 * \param n2 noeud 1
 * \return void
 **/
int noeud_cmp(noeud n1, noeud n2);

/**
 * \fn void noeud_printf_id(noeud n);
 * \brief affiche l'id d'un noeud
 * \param n le noeud
 * \return void
 **/
void noeud_printf_id(noeud n);

#ifdef DEBUG
/**
 * \fn void noeud_printf_position(noeud n);
 * \brief affiche la position d'un noeud (a utiliser uniquement pour debug. trom
couteux. )
 * \param n le noeud
 * \return void
 **/
void noeud_printf_position(noeud n);
#endif
#endif