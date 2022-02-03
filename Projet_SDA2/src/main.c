
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "laby.h"
#include "test.h"

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;
	#ifdef DEBUG
	printf("\n\t%s##============[   %sTEST %sLabyrinthe %sDEBUG=%d   %s%s]=============##%s\n",BOLD ,lGREEN, lBLUE, YELLOW, DEBUG, NC, BOLD, NC);
	//test_debug();
	#endif

	/*--------[  Question 1  ]--------*/
	noeud noeuds[12];
	/*le plus porpre est de definir un graph comme un talbeau de noeuds.
	 un graph est un ensemble de struct noeud, et donc implicitement aussi un ensemble
	 de passages*/ /*ici version quick and dirty.*/

	noeud* graph = noeuds;
	graph_ini_noeuds(graph, 12, true);
	graph_ini_passages_figure3(graph);

	/*--------[  Question 2,3,4  ]--------*/
	srand(time(NULL));
	int min_n = 0;// noeud quelconque entre 0 et 11
	int max_n = 11;
	int n = min_n + rand() %(max_n+1 -min_n);
	(void) n;

	coord taille = coord_nouv(); //nouvelles coord (0,0)
	coord position = coord_nouv();
	int longueur;
	n = 9;
	laby_taille(graph[n], taille);
	laby_position(graph[n], position);
	longueur = laby_longueur(graph[n]);
	laby_save_img("figure3", graph[n], taille, position, M, N);

	/*--------[  Question 5 ]--------*/

	float valeurTotal =0;
	valeurTotal = valeurTotalTresors(graph[n]);
	printf("%.0f", valeurTotal);

	(void) longueur;
	(void) valeurTotal;

	graph_destroy(graph, 12);
	coord_destroy(taille);
	coord_destroy(position);
	return EXIT_SUCCESS;
}