#include "test.h"

#ifdef DEBUG
int test_debug(void){
    int success=0;

    noeud noeuds[12];
	/*le plus porpre est de definir un graph comme un talbeau de noeuds.
	 un graph est un ensemble de struct noeud, et donc implicitement aussi un ensemble
	 de passages*/ /*ici version quick and dirty.*/
	noeud* graph = noeuds;
	graph_ini_noeuds(graph, 12, true);
	graph_ini_passages_figure3(graph);

	coord taille = coord_nouv(); //nouvelles coord (0,0)
	coord position = coord_nouv();

    int nbNoeuds = 12;
    if (DEBUG >= 10){
        printf("\n%s#====== taille de labyrinthe (debute en ni):  ======#%s\n", YELLOW, NC);
        for(int i=0; i<nbNoeuds; i++){
            (DEBUG%10==0)? printf("n%d", i): printf("%s----n%d----%s",YELLOW, i,NC);
            laby_taille(graph[i], taille);
            printf("\t|taille:\t|X: %d\t|Y: %d\n", taille->axe[X], taille->axe[Y]);
            if(taille->axe[X] != 180){ success--;}
            if(taille->axe[Y] != 50){ success--;}
            if(success!=0){
                printf("\n\t%s##============[  %staille FAILURE   %s%s]=============##%s\n\n",BOLD , RED, NC, BOLD, NC);
            }
        }
    }


    if (DEBUG >= 20){
        printf("\n%s#====== position ni: ======#%s\n", YELLOW, NC);
        for(int i=0; i<nbNoeuds; i++){
            (DEBUG%10==0)? printf("n%d", i): printf("%s----n%d----%s",YELLOW, i,NC);
            laby_position(graph[i], position);
            printf("\t|(%d,%d)\n", position->axe[X], position->axe[Y]);
            //test pas encore implémenté, mais pas demandé dans le sujet.
        }
    }

    if (DEBUG >= 30){
        int longueur;
        printf("\n%s#====== longueur (debute en ni): ======#%s\n", YELLOW, NC);
        for(int i=0; i<nbNoeuds; i++){
            (DEBUG%10==0)? printf("n%d", i): printf("%s----n%d----%s",YELLOW, i,NC);
            longueur = laby_longueur(graph[i]);
            printf("\t|longueur: %d\n", longueur);
            if(longueur != 590){ success--;}
        }
    }

    /*if (DEBUG >= 40){
        noeud A = noeud_nouv(0);
        noeud B = noeud_nouv(1);
        noeud C = noeud_nouv(2);
        noeud D = noeud_nouv(3);
        noeud E = noeud_nouv(4);
        noeud F = noeud_nouv(5);
        

        passage(A, B, EST, 10);
        passage(B, C, SUD, 6);
        passage(C, D, OUEST, 10);
        passage(D, A, NORD, 6);
        passage(D, E, SUD, 6);
        passage(F, E, NORD, 10);

        laby_taille(A, taille);
        laby_position(A, position);
        laby_save_img("rectangleA", A, taille, position);
        laby_position(B, position);
        laby_save_img("rectangleB", B, taille, position);
        laby_position(C, position);
        laby_save_img("rectangleC", C, taille, position);
        laby_position(D, position);
        laby_save_img("rectangleD", D, taille, position);



        noeud noeuds2[12];
        noeud* graph2 = noeuds2;
        graph_ini_noeuds(graph2, 12, true);
        passage(noeuds2[0], noeuds2[1], EST, 6);
        passage(noeuds2[1], noeuds2[2], EST, 5+3);
        //ligne 1 - v
        passage(noeuds2[1], noeuds2[6], SUD, 3);
        passage(noeuds2[2], noeuds2[8], SUD, 3);
        passage(noeuds2[3], noeuds2[9], SUD, 3);

        //ligne 2 - v
        passage(noeuds2[4], noeuds2[5], SUD, 2);

        //ligne 3 - h
        passage(noeuds2[5], noeuds2[6], EST, 7);
        passage(noeuds2[6], noeuds2[7], EST, 5);
        passage(noeuds2[7], noeuds2[8], EST, 3);
        passage(noeuds2[8], noeuds2[9], EST, 3);
        //ligne 3 - v
        passage(noeuds2[5], noeuds2[10], SUD, 2);
        passage(noeuds2[7], noeuds2[11], SUD, 2);

        //ligne 4 - h
        passage(noeuds2[10], noeuds2[11], EST, 7+5);

        laby_taille(graph2[6], taille);
        laby_position(graph2[6], position);
        laby_save_img("smol6", graph2[6], taille, position);

    }*/

    coord_destroy(taille);
    coord_destroy(position);
    graph_destroy(graph, 12);

    if(success!=0){
        printf("\n\t%s##============[   %sLabyrinthe %sTEST FAILURE   %s%s]=============##%s\n\n",BOLD ,lBLUE, RED, NC, BOLD, NC);
        exit(EXIT_FAILURE);
    }
    printf("\n\t%s##============[   %sLabyrinthe %sTEST SUCCESS   %s%s]=============##%s\n\n",BOLD ,lBLUE, lGREEN, NC, BOLD, NC);
    return EXIT_SUCCESS;
}
#else
int test_debug(void){return;}
#endif