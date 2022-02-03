#ifndef __IMG_H__
#define __IMG_H__
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "liste_noeuds.h"
#include "liste_passages.h"
#include "debug.h"

#define BLKX 2 //taille du block "X "
#define BLKY 1
#define VALMAX 9

//couleurs
#define CLR_BACKGROUND 0
#define CLR_PASSAGE 5
#define CLR_POINT 9


#define M 4 //taille passages
#define N 10 //taille points
 //largeur pixels

/**
 * \fn void img_creuserParcours(FILE* fd, noeud nd, coord position, coord taille, int m, int n)
 * \brief crée l'entête, remplis le fichier de noir, puis creuse le parcours du
 * graph en couleur.
 * \param fd file descriptor
 * \param nd le noeud de début pour creuser le laby
 * \param position position x y du noeud de nd
 * \param taille taille X Y du laby
 * \param m largeur d'un chemin
 * \param n	taille d'un pixel
 * \return void
 **/
void img_creuserParcours(FILE* fd, noeud nd, coord position, coord taille, int m, int n);

#endif