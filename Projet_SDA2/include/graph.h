#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include "noeud.h"
#include "debug.h"

/**
 * \fn void noeuds(const noeud* noeuds, const int x)
 * \brief remplis un tableau de noeuds vide par de nouveaux noeuds.
 * \pre x est la taille de tabnoeuds
 * \param noeuds l'adresse d'un tableau de neuds à remplir
 * \param x la taille du tableau
 * \return void
 **/
void graph_ini_noeuds(noeud* noeuds, const int x, const bool new);

/**
 * \fn void graph_destroy(noeud* tabNoeuds, const int x)
 * \brief detruit les noeuds d'un tableau de noeuds
 * \pre x est la taille de tabnoeuds
 * \param noeuds l'adresse d'un tableau de neuds à remplir
 * \param x la taille du tableau
 * \return void
 **/
void graph_destroy(noeud* noeuds, const int x);

/**
 * \fn void graph_ini_passages_figure3(noeud* noeuds);
 * \brief creuse les passages de l'exemple 1
 * \param tabNoeuds l'adresse du tableau de noeuds
 * \return void
 **/
void graph_ini_passages_figure3(noeud* noeuds);
#endif