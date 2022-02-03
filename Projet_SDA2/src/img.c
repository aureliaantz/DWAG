#include "img.h"

long int entete(FILE* fd, coord taille){
	fprintf(fd, "P2\n%d %d\n%d\n", taille->axe[X], taille->axe[Y], VALMAX);
	long int start;
	FCHECK(start = ftell(fd)); //ou suis-je?
	return start;
}

void remplirBody(FILE* fd, coord taille){ 
	for(int y=0; y< taille->axe[Y]; y++){ //+1 pour ligne et colonne 0
		for(int x=0; x< taille->axe[X]; x++){
			#ifdef DEBUG
			fprintf(fd,". ");//+x
			#else
			fprintf(fd,"%d ", CLR_BACKGROUND);
			#endif
		}
		fprintf(fd, "\n");
	}
}

void creuser_passage_AxeX(FILE* fd, int distance, coord unit, int m, int n){
	/*j'aurais dû gérer le creusage de passage case par case,
	et faire vérif à chaque création de case pour avoir un structure "trésor friendly".
	là, je vais devoir gérer les trésors par jump.*/

	//je me situe en bas à droite d'un point
	int move;

	//je monte de n/2 + m/2
	move = 0;
	move -= ((n+m)/2) * unit->axe[Y];//-(n+m)/2 y
	if((n+m)%2==0){ move += unit->axe[Y];} //+y si même parité
	FCHECK(fseek(fd, move, SEEK_CUR));

	//je suis en haut à gauche du passage
	// je creuse M lignes de long n*distance
	for(int y=1; y<m; y++){
		for(int x=0; x<n*distance; x++){ //+distance*nx
			#ifdef DEBUG
			fprintf(fd,"= ");
			#else
			fprintf(fd,"%d ",CLR_PASSAGE);
			#endif
		}

		move = 0;
		move -= n*distance*unit->axe[X]; //-nx
		move += unit->axe[Y];   //+y
		FCHECK(fseek(fd, move, SEEK_CUR));
	}

	//dernière ligne
	for(int x=0; x<n*distance; x++){ //+nx
			#ifdef DEBUG
			fprintf(fd,"= ");
			#else
			fprintf(fd,"%d ",CLR_PASSAGE);
			#endif
	}
	//fprintf(fd,"X ");

	//je monte de m/2+n/2 pour me mettre en haut a gauche du prochain point
	move = 0;
	move -= ((n+m)/2-1) * unit->axe[Y]; //-(n+m)/2
	FCHECK(fseek(fd, move, SEEK_CUR));
	return;
}

void creuser_passage_AxeY(FILE* fd,int distance, coord unit, int m, int n){
	/*j'aurais dû gérer le creusage de passage case par case,
	et faire vérif à chaque création de case pour avoir un structure "trésor friendly".
	là, je vais devoir gérer les trésors par jump.*/

	//je me situe en bas à droite d'un point
	int move;

	//je vais de n/2 + m/2 unit à gauche
	//je descend de 1
	move = 0;
	move -= ((n+m)/2) * unit->axe[X]; //-((n+m)/2) x
	move += unit->axe[Y]; // +y
	FCHECK(fseek(fd, move, SEEK_CUR));  

	//je suis en haut à gauche du passage
	// je creuse m colonnes de long n*distance
	for(int y=1; y<n*distance; y++){
		for(int x=0; x<m; x++){ //+nx
			#ifdef DEBUG
			fprintf(fd,"# ");
			#else
			fprintf(fd,"%d ",CLR_PASSAGE);
			#endif
		}

		move = 0;
		move -= m*unit->axe[X]; //-nx
		move += unit->axe[Y];   //+y
		FCHECK(fseek(fd, move, SEEK_CUR));
	}

	//dernière ligne
	for(int x=0; x<m; x++){ //+nx
			#ifdef DEBUG
			fprintf(fd,"# ");
			#else
			fprintf(fd,"%d ",CLR_PASSAGE);
			#endif
	}

	#ifdef DEBUG
	FCHECK(fseek(fd, -unit->axe[X], SEEK_CUR));
	fprintf(fd,"N ");
	#endif

	//je monde de m/2+n/2 pour me mettre en haut a gauche du prochain point
	move = 0;
	move -= ((n+m)/2) * unit->axe[X]; //-(n+m)/2 à gauche
	if((n+m)%2==0){ move += unit->axe[X];} //+x si même parité
	FCHECK(fseek(fd, move, SEEK_CUR));

	return;

}

void creuser_point(FILE* fd, coord unit, int n){
	//je suis en haut à gauche.
	int move;

	for(int y=1; y<n; y++){
		for(int x=0; x<n; x++){ //+nx
			#ifdef DEBUG
			fprintf(fd,"0 ");
			#else
			fprintf(fd,"%d ",CLR_POINT);
			#endif
		}

		move = 0;
		move -= n*unit->axe[X]; //-nx
		move += unit->axe[Y];   //+y
		FCHECK(fseek(fd, move, SEEK_CUR));
	}

	//dernière ligne
	for(int x=0; x<n; x++){ //+nx
		#ifdef DEBUG
		fprintf(fd,"0 ");
		#else
		fprintf(fd,"%d ",CLR_POINT);
		#endif
		}

	#ifdef DEBUG
	FCHECK(fseek(fd, -unit->axe[X], SEEK_CUR));
	fprintf(fd,"X ");
	#endif

	//je suis en bas à droite //+nx +ny
	return;
}

void creuser_N(FILE* fd, int distance, coord unit, int m, int n){
	int move = 0;
	//jump 
	move -= n*unit->axe[Y]*(distance-1); //-n*(distance-1)*y
	move -= n*unit->axe[Y]; // bouger d'un pixel en haut
	FCHECK(fseek(fd, move, SEEK_CUR));
	
	//ecrire
	creuser_passage_AxeY(fd, distance-1, unit, m, n); //passage de taille distance-1

	//jump
	move = 0;
	move -= n*unit->axe[Y]*(distance-1);
	move -= (n-1)*unit->axe[Y];
	move -=  unit->axe[X];
	FCHECK(fseek(fd, move,SEEK_CUR));
	return;
}

void creuser_S(FILE* fd, int distance, coord unit, int m, int n){
	int move;

	creuser_passage_AxeY(fd, distance-1, unit, m, n); //passage de taille distance-1
	#ifdef DEBUG
	FCHECK(fseek(fd, -unit->axe[X], SEEK_CUR));
	fprintf(fd,"Xv");
	#endif

	move = 0;
	move += unit->axe[Y]; //+y
	move -= unit->axe[X]; //-x
	FCHECK(fseek(fd, move, SEEK_CUR));
	return;
}

void creuser_E(FILE* fd, int distance, coord unit, int m, int n){
	//+(distance-1)*x
	creuser_passage_AxeX(fd, distance-1, unit, m, n); //passage de taille distance-1

	#ifdef DEBUG
	FCHECK(fseek(fd, -unit->axe[X], SEEK_CUR));
	fprintf(fd,"X>");
	#endif

	return;
}

void creuser_W(FILE* fd, int distance, coord unit, int m, int n){
	int move = 0;
	//jump 
	move -= n*unit->axe[X]*(distance-1); //-n*distance*x
	move -= n*unit->axe[X]; // bouger d'un pixel à gauche
	FCHECK(fseek(fd, move, SEEK_CUR));

	//ecrire
	creuser_passage_AxeX(fd, distance-1, unit, m, n); //passage de taille distance-1

	//jump
	move = 0;
	move -= n*unit->axe[X]*(distance-1);
	move -= n*unit->axe[X];
	FCHECK(fseek(fd, move,SEEK_CUR));

	return;
}

void ppp_creuser(FILE* fd, noeud nd, liste_p* colorized, coord unit, int m, int n){
	#ifdef DEBUG
	#if (DEBUG > 42) && (DEBUG < 50) 
	lp_printf(*colorized);

	noeud_printf_position(nd);
	#endif
	#endif


	int pos_nd;
	FCHECK(pos_nd = ftell(fd)); //ou suis-je?

	

	for(Dir d=0; d <NDIR; d++){
		if(nd->voisins[d] != NULL){
			if(rech_lp(*colorized, nd, nd->voisins[d])==NULL){ //si voisin non NULL && si pas encore dans la liste
				//on ajoute n dans la liste "coloriée"
				*colorized = adjtete_lp(*colorized, nd, nd->voisins[d]);

				//traitement
				FCHECK(fseek(fd, pos_nd, SEEK_SET)); // on va sur le noeud
				switch (d){
					case NORD:
						creuser_N(fd, nd->distances[d], unit, m, n); //+(distance)*y -x
						break;

					case SUD:
						creuser_S(fd, nd->distances[d], unit, m, n); //-(distance)*y -x
						break;

					case EST:
						creuser_E(fd, nd->distances[d], unit, m, n); //+(distance)*x -x
						break;

					case OUEST:
						creuser_W(fd, nd->distances[d], unit, m, n); //-(distance)*x -x
						break;
					
					default:
						RALER(0," CASE ne couvre pas tous les SENS donnés");
						break;
				}
				creuser_point(fd, unit, n);//+x
				

				#ifdef DEBUG
				#if (DEBUG > 41) && (DEBUG < 50) 
					int car = (d==NORD)? 'N' :(d==SUD)? 'S' :(d==EST)? 'E' : 'W';
						printf("\n%s%c%s %d ",YELLOW,car,NC, nd->distances[d]);
						printf("\t\t("); noeud_printf_id(nd);
						printf(") ->%s(", YELLOW); noeud_printf_id(nd->voisins[d]);
						printf("%s)%s",YELLOW, NC );
				#endif
				#endif

				ppp_creuser(fd, nd->voisins[d], colorized, unit, m, n);
			}
		}
	}
	return;
}

void img_creuserParcours(FILE* fd, noeud nd, coord position, coord taille, int m, int n){
	if (!fd){ RALER(0," fd NULL");}
	if (!nd){ RALER(0," nd NULL");}
	if (!position){ RALER(0," position NULL");}
	if (!taille){ RALER(0," taille NULL");}
	if (m > n){ RALER(0," m > n");}

	//changement de référentiel :
	//il n'est pas demandé de généraliser dans le sujet : on opère ici en 2D:
	taille->axe[X] += 1; // colonne de 0
	taille->axe[X] *= n;
	taille->axe[Y] += 1; // ligne de 0
	taille->axe[Y] *= n;

	//naviguer les blocs de char "XX"
	coord unit = coord_nouv();
	unit->axe[X] = (BLKX);
	unit->axe[Y] = ((taille->axe[X])*unit->axe[X] +1)*(BLKY); //+1 pour le \n

	//pour naviguer l'image (meilleur lisibilité/maintenabilité) 
	//naviguer les pixels de blocs de chars
	int go[NDIR]; 
	go[NORD]= -unit->axe[Y]*n; //UP
	go[SUD]= +unit->axe[Y]*n; //DOWN
	go[OUEST]= -unit->axe[X]*n; //LEFT
	go[EST]= +unit->axe[X]*n; //RIGHT


	long int pos_entete = entete(fd, taille); //on veut commener après l'entete.
	remplirBody(fd, taille); //on remplis de noir

	//on se place dans notre nouveau référentiel
	int pos_depart = pos_entete;
	pos_depart += position->axe[X] * go[EST];
	pos_depart += position->axe[Y] * go[SUD];

	liste_p colorized = nouv_lp();
	
	FCHECK(fseek(fd, pos_depart, SEEK_SET)); // on va sur le noeud

	
	creuser_point(fd, unit, n); //on fait le premier point
	ppp_creuser(fd, nd, &colorized, unit, m, n);


	#ifdef DEBUG
	#if (DEBUG > 41) && (DEBUG < 50)
	printf("\n\n\t\t\t\t <--- (adjtete)");
	lp_printf(colorized);
	#endif
	#endif

	destroy_lp(colorized);
	coord_destroy(unit);
	return;
}
