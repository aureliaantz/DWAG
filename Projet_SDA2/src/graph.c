#include "graph.h"

void graph_ini_noeuds(noeud* noeuds, const int x, const bool new){
	if (!noeuds){ RALER(0," tabNoeuds == NULL");} //safeguards
	if(x<=0){ RALER(0," x<=0");}

	static int id = 0; //pour comparaison de noeuds
	if(new){id =0;}

	for(int i=0; i<x; i++){
		noeuds[i]= noeud_nouv(id);
		id++;
	}
		
	return;
}

void graph_destroy(noeud* noeuds, const int x){
	if (!noeuds){ RALER(0," tabNoeuds == NULL");} //safeguards
	if(x<=0){ RALER(0," x<=0");}

	for(int i=0; i<x; i++){
		for(Dir d=0; d<NDIR; d++){
			tr_destroy(noeuds[i]->tresors[d]);
		}
		destroy_noeud(noeuds[i]);
	}
		

	return;
}


void graph_ini_passages_figure3(noeud* noeuds){
	if (!noeuds){ RALER(0," tabNoeuds == NULL");} //safeguard

	/* balayage de gauche à droite,de haut en bas, des lignes */
	/* les lignes sont définies par les noeuds sur une même valeur Y */
	/* on s'interessera d'abord aux voisins horizontaux puis vertivaux des
	noeuds sur chaque ligne.*/
	//ligne 1 - h
	passage(noeuds[0], noeuds[1], EST, 60, NULL);
	passage(noeuds[1], noeuds[2], EST, 50+30, NULL);
	//ligne 1 - v
	float* tr01_06 = tr_nouv(30, 30, 1000.0);

	
	passage(noeuds[1], noeuds[6], SUD, 30, tr01_06);
	passage(noeuds[2], noeuds[8], SUD, 30, NULL);
	float* tr03_09 = tr_nouv(30, 10, 1000.0);
	passage(noeuds[3], noeuds[9], SUD, 30, tr03_09);

	//ligne 2 - v
	passage(noeuds[4], noeuds[5], SUD, 20, NULL);

	//ligne 3 - h
	float* tr05_06 = tr_nouv(70, 70, 1000.0);
	passage(noeuds[5], noeuds[6], EST, 70, tr05_06);

	float* tr06_07 = tr_nouv(50, 00, 1000.0);
	passage(noeuds[6], noeuds[7], EST, 50, tr06_07);
	passage(noeuds[7], noeuds[8], EST, 30, NULL);
	passage(noeuds[8], noeuds[9], EST, 30, NULL);
	//ligne 3 - v
	passage(noeuds[5], noeuds[10], SUD, 20, NULL);
	passage(noeuds[7], noeuds[11], SUD, 20, NULL);

	//ligne 4 - h
	float* tr10_11 = tr_nouv(70+50, 10, 1000.0);
	passage(noeuds[10], noeuds[11], EST, 70+50, tr10_11);

	return;
}

void free_figure_3(noeud* graph){
	(void) graph;
	return;
}