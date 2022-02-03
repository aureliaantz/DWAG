#include "laby.h"

//parcours profondeur noeuds pour trouver extremums
void ppn_Extrems(noeud n, coord current, extremums extrems, liste_n* colorized){
	int Xtmp=current->axe[X], Ytmp=current->axe[Y]; /*stoque temporairement la position courrant pour cette itération de la fonction*/
	int newX, newY=0;

	if(rech_ln(*colorized, n)==NULL){ // si pas encore dans la liste
		*colorized = adjtete_ln(*colorized, n);//on ajoute n dans la liste "coloriée"
	}

	#ifdef DEBUG
	#if (DEBUG > 12 && DEBUG <20)
		ln_printf(*colorized);
	#endif
	#endif

	//on traite les voisins
	for(Dir d=0; d< NDIR; d++){
		/*si je ne pointe pas d'ou je viens && si voisin non NULL && pas encore dans la liste*/
		if((n->voisins[d] != NULL)&&(rech_ln(*colorized, n->voisins[d])==NULL) ){ 
			//on ajoute n dans la liste "coloriée"
			*colorized = adjtete_ln(*colorized, n->voisins[d]);
			

			//traitement
			switch (d){
				case NORD:
					newY = Ytmp + n->distances[d];
					current->axe[X]= Xtmp;
					current->axe[Y]= newY;

					if(newY > extrems->max.axe[Y])
						extrems->max.axe[Y] = newY;

					break;

				case SUD:

					newY = Ytmp - n->distances[d];
					current->axe[X]= Xtmp;
					current->axe[Y]= newY;

					if(newY < extrems->min.axe[Y])
						extrems->min.axe[Y] = newY;

					break;

				case EST:
					newX = Xtmp + n->distances[d];
					current->axe[X]= newX;
					current->axe[Y]= Ytmp;

					if(newX > extrems->max.axe[X])
						extrems->max.axe[X] = newX;
					
					break;

				case OUEST:
					newX = Xtmp - n->distances[d];
					current->axe[X]= newX;
					current->axe[Y]= Ytmp;

					if(newX < extrems->min.axe[X])
						extrems->min.axe[X] = newX;

					break;

				default:
					RALER(0," CASE ne couvre pas tous les SENS donnés");
					break;
			}


			#ifdef DEBUG
			#if (DEBUG > 10) && (DEBUG < 30) && (DEBUG != 20)
				int car = (d==NORD)? 'N' :(d==SUD)? 'S' :(d==EST)? 'E' : 'W';
				printf("\n%s%c%s (%d,%d) ",YELLOW, car, NC, Xtmp, Ytmp);
				printf(" \t->%s(%d,%d)%s", YELLOW, current->axe[X], current->axe[Y], NC);
				printf("\t\tmX: %d, MX: %d   \tmY: %d, MY: %d", extrems->min.axe[X],extrems->max.axe[X],extrems->min.axe[Y],extrems->max.axe[Y]);
			#endif
			#endif

			ppn_Extrems(n->voisins[d], current, extrems, colorized);
			current->axe[X] = Xtmp; //retour au noeud courant pour prochaine boucle
        	current->axe[Y] = Ytmp; //
		}
	}
	return;
}

void laby_taille(noeud n, coord taille){
	if(!n){RALER(0, "n NULL")}
	if(!taille){RALER(0, "taille NULL")}

	extremums extrems = malloc(sizeof(struct s_extremums)); /* quick and dirty */

	for(Axe i=0; i<NAXE; i++){ // pour tous les axes
		extrems->max.axe[i]= 0;
		extrems->min.axe[i]= 0;

		taille->axe[i]= 0; //mesure de sécurité
	}
	

	liste_n colorized = nouv_ln(); //les points ajoutés à la liste sont "coloriés"
	ppn_Extrems(n, taille, extrems, &colorized); // parcours profondeur taille, recursif

	taille->axe[X] = extrems->max.axe[X] - extrems->min.axe[X]; //taille sur axe X
	taille->axe[Y] = extrems->max.axe[Y] - extrems->min.axe[Y]; //taille sur axe Y
	free(extrems);

	#ifdef DEBUG
	#if (DEBUG > 11) && (DEBUG < 20)
	printf("\n\n\t\t\t\t <--- (adjtete)");
	ln_printf(colorized);
	#endif
	#endif

	destroy_ln(colorized);
	return;
}

void laby_position(noeud n, coord position){
	if(!n){RALER(0, "n NULL")}
	if(!position){RALER(0, "position NULL")}

    extremums extrems = malloc(sizeof(struct s_extremums)); /* quick and dirty */
	for(Axe i=0; i<NAXE; i++){ // pour tous les axes
		extrems->max.axe[i]= 0;
		extrems->min.axe[i]= 0;

		position->axe[i]= 0; //mesure de sécurité
	}
	
	liste_n colorized = nouv_ln(); //les points ajoutés à la liste sont "coloriés"
	ppn_Extrems(n, position, extrems, &colorized); // parcours profondeur des noeuds,

	position->axe[X] = -extrems->min.axe[X]; 
	position->axe[Y] =  extrems->max.axe[Y];

	#ifdef DEBUG
	#if (DEBUG > 21) && (DEBUG < 30)
	printf("\n\n\t\t\t\t <--- (adjtete)");
	ln_printf(colorized);
	#endif
	#endif

	destroy_ln(colorized);
	free(extrems);
	return;
}

void ppp_longueur(noeud n, int* longueur, liste_p* colorized){
	#ifdef DEBUG
	#if (DEBUG > 30) && (DEBUG < 40) 
	lp_printf(*colorized);
	#endif
	#endif

	for(Dir d=0; d< NDIR; d++){
		if((n->voisins[d] != NULL)){
			if(rech_lp(*colorized,n, n->voisins[d])==NULL){ //si voisin non NULL && si pas encore dans la liste
				//on ajoute n dans la liste "coloriée"
				*colorized = adjtete_lp(*colorized, n, n->voisins[d]);
				
				//traitement
				*longueur += n->distances[d];
				
				#ifdef DEBUG
				#if (DEBUG > 30) && (DEBUG < 40) 
					int car = (d==NORD)? 'N' :(d==SUD)? 'S' :(d==EST)? 'E' : 'W';
					printf("\n%s%c%s %d  %d",YELLOW,car,NC, n->distances[d], *longueur);
					printf("\t\t("); noeud_printf_id(n);
					printf(") ->%s(", YELLOW); noeud_printf_id(n->voisins[d]);
					printf("%s)%s",YELLOW, NC );
				#endif
				#endif

				ppp_longueur(n->voisins[d], longueur, colorized);
			}
		}
	}
	return;
}

int laby_longueur(noeud n){
	if(!n){ RALER(0," n NULL");} //safeguards

	int longueur=0; //sécurité

	liste_p colorized = nouv_lp();
	ppp_longueur(n, &longueur, &colorized);
	destroy_lp(colorized);

	return longueur;
}

void laby_save_img(char* name, noeud nd, coord taille, coord position, int m, int n){
	if (!name){ RALER(0," name NULL");} //safeguards
	if(!nd){ RALER(0," nd NULL");} //safeguards
	if(!taille){ RALER(0," taille NULL");}
	if(!position){ RALER(0," position NULL");}
	if(m<=0){ RALER(0," m<=0");}
	if(m>n){ RALER(0," m>n");}
	if(n<=0){ RALER(0," n<=0");}

	laby_taille(nd, taille);

	char imgpath[MAX_TAILLE_PATH];
	sprintf(imgpath, "%s%s%s", "./img/", name, ".pgm"); //creer path

	FILE* fd = fopen(imgpath, "w+"); //ouvrir fichier creer/ecraser/ecriture
	if(!fd){ RALER(0,"fd NULL: imgpath mauvais");} 

	img_creuserParcours(fd, nd, position, taille, m, n); //on creuse le chemin

	return;
}

void ppp_ValeurTotalTresors(noeud n, float* valeur, liste_p* colorized){ // parcours profondeur des passages
	#ifdef DEBUG
	#if (DEBUG > 30) && (DEBUG < 40) 
	lp_printf(*colorized);
	#endif
	#endif

	for(Dir d=0; d< NDIR; d++){
		if((n->voisins[d] != NULL)){
			if(rech_lp(*colorized,n, n->voisins[d])==NULL){ //si voisin non NULL && si pas encore dans la liste
				//on ajoute n dans la liste "coloriée"
				*colorized = adjtete_lp(*colorized, n, n->voisins[d]);
				
				//traitement
				if(n->tresors[d]!=NULL){
					for(int i=0; i<n->distances[d]; i++){ 
						if (n->tresors[d][i]!=0){
							*valeur += n->tresors[d][i]; //problème dans traitement
						}
					}
				}
				
				
				#ifdef DEBUG
				#if (DEBUG > 61) && (DEBUG < 70) 
					int car = (d==NORD)? 'N' :(d==SUD)? 'S' :(d==EST)? 'E' : 'W';
					printf("\n%s%c%s %d  %d",YELLOW,car,NC, n->distances[d], *valeur);
					printf("\t\t("); noeud_printf_id(n);
					printf(") ->%s(", YELLOW); noeud_printf_id(n->voisins[d]);
					printf("%s)%s",YELLOW, NC );
				#endif
				#endif

				ppp_ValeurTotalTresors(n->voisins[d], valeur, colorized);
			}
		}
	}
	return;
}

float valeurTotalTresors(noeud n){ // même chose que pour la parcours longueur
	if(!n){ RALER(0," n NULL");} //safeguards
	float valeur=0; //sécurité

	liste_p colorized = nouv_lp();
	ppp_ValeurTotalTresors(n, &valeur, &colorized);
	destroy_lp(colorized);

	return valeur;

}

float valeurPlusProcheTresors(noeud n){
	if(!n){ RALER(0," n NULL");} //safeguards
	float valeur=0; //sécurité

	liste_p colorized = nouv_lp();
	//plp_longueur(n, &valeur, &colorized); // on veut faire un parcours en
	//large des passages sur un graph avec arc valués strictement positifs cad
	//une sorte de dijskra

	//premier reflexe :parcours en largeur pour une largeur L donnée, en s'arrêtant soit
	//après distance plus proche trésor trouvé soit premier trésor trouvé, soit
	//à la largeur L pour vérifier le plus proche dans les noedsz à une distance
	//L de moi. là, en fait, on veut un L non limitant. Mais je crois qu'en
	//relisant dijskra et en prenant temps de le dessiner je me rendrais compte
	//que j'ai cette idée parcequ'on la vu en cours et que c'est +- ce qu'il
	//fait, haha. mais il est 23:30 et je vais écrire rapport. Manque de temps.
	//Dommage ! Le sujet était sympatique à coder, bien qu'il aurait été
	//appréciable de voir plus de parcours en largeur & ses applications.
	destroy_lp(colorized);

	return valeur;
}