#ifndef __LABY_H__
#define __LABY_H__

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "liste_noeuds.h"
#include "liste_passages.h"
#include "debug.h"
#include "img.h"

#define MAX_TAILLE_PATH 1024

/**
 * \fn void laby_taille(noeud n, coord longueur)
 * \brief parcours en profondeur les noeuds du laby pour en determiner les
 * extremums. en déduis et met la taille X Y du laby dans longueur
 * \param n un noeud du laby
 * \param longueur pour recevoir la taille X Y du laby
 * \return void
 **/
void laby_taille(noeud n, coord longueur);

/**
 * \fn void laby_position(noeud n, coord position)
 * \brief parcours en profondeur les noeuds du laby our en determiner les
 * extremums. en déduis et met la position x y du point dans le laby dans position
 * \param n un noeud du laby
 * \param longueur pour recevoir la position x y du noeud
 * \return void
 **/
void laby_position(noeud n, coord position);

/**
 * \fn int laby_longueur(noeud n)
 * \brief parcours en profondeur les passages du laby renvois la longueur du parcours de tous les chemins du laby
 * \param n un noeud du laby
 * \return la longueur du parcours de tous les chemins du laby
 **/
int laby_longueur(noeud n);

/**
 * \fn void laby_save_img(char* name, noeud nd, coord taille, coord position, int m, int n);
 * \brief enregistre la laby sous la forme une image name.pgm dans le dossier.
 parcours en profondeur les passages du laby pour le faire.
 * \param name le nom de l'image
 * \param fd file descriptor
 * \param nd le noeud de début pour creuser le laby
 * \param position position x y du noeud de nd
 * \param taille taille X Y du laby
 * \param m largeur d'un chemin
 * \param n	taille d'un pixel
 * \return void
 **/
void laby_save_img(char* name, noeud nd, coord taille, coord position, int m, int n);


/**
 * \fn float valeurTotalTresors(noeud n);
 * \brief parcours en profondeur le laby et donne la valeur du total des trésors
 * \param n un noeud du laby (depart du parcours)
 * \return valeur du total des trésors
 **/
float valeurTotalTresors(noeud n);

/**
 * \fn float valeurPlusProcheTresors(noeud n)
 * \brief parcours en largeur le laby, retourne la valeur du trésor le plus proche
 * \param n un noeud du laby
 * \return val plus proche trésor
 **/
float valeurPlusProcheTresors(noeud n);


#endif