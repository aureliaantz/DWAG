#include "noeud.h"
#include "laby.h" //pour debug position dans laby


noeud noeud_nouv(int id){
	noeud new = malloc(sizeof(struct s_noeud));

	for(Dir d=NORD; d<NDIR; d++){
		new->voisins[d]=NULL;
	}
		
	new->id = id;
	return new;
}

void destroy_noeud(noeud n){
	/*pour tous ses voisins de toutes les directions,
	on leur dit que leur voisins de la direction opposée est NULL*/
	for(Dir d= NORD; d<NDIR; d++){
		if(n->voisins[d] != NULL)
			n->voisins[d]->voisins[(d+NAXE)%NDIR] = NULL;
	}
	free(n);
	return;
}

void passage(noeud n1, noeud n2, Dir d, int dist, float* tr){
	if(!n1){RALER(0, "n1 NULL")}
	if(!n2){RALER(0, "n2 NULL")}
	if(d>NDIR){RALER(0, "d > NDIR")}
	if(dist<=0){RALER(0, "dist <= 0")}
	//arc orienté
	n1->voisins[d]= n2;
	n1->distances[d]= dist;

	//arc orienté reciproque
	n2->voisins[(d+NAXE)%NDIR]= n1;
	n2->distances[(d+NAXE)%NDIR]= dist;

	if(!tr) return; // clause de sortie

	//si j'ai tresors
	//arc orienté
	n1->tresors[d] = tr;

	//arc orienté reciproque
	n2->tresors[(d+NAXE)%NDIR]= tr_nouv(dist, 0, 0.0);//trésors nulls
	for (int i = dist-1; i >= 0; i--){
		if (n1->tresors[d][i] != 0){
			tr_add(n2->tresors[(d+NAXE)%NDIR], dist, i, n1->tresors[d][i]);//ajouter le trésor
		}
	}


	#ifdef DEBUG
	#if DEBUG > 50 && DEBUG < 60
	printf("\n %s#tresors(%d)%s-%s(%d)%s\n", YELLOW,n1->id, NC, YELLOW,n2->id, NC);
	tr_printf(n1->tresors[d], dist);
	printf("\n %s#tresors(%d)%s-%s(%d)%s\n", YELLOW,n2->id, NC, YELLOW,n1->id, NC);
	tr_printf(n2->tresors[(d+NAXE)%NDIR], dist);
	#endif
	#endif
	
	return;
}


int noeud_cmp(noeud n1, noeud n2){
	if(!n1){return false;}
	if(!n2){return false;}
	/* 
	j'allais utiliser "calloc(1, sizeof(struct s_noeud));"" à la création et
	et "return memcmp(n1, n2, sizeof(struct s_noeud));" pour comparaison, puis j'ai pensé à utiliser un id unique par noeud.
	*/
	return (n1->id == n2->id)? true: false;
}

void noeud_printf_id(noeud n){
	if(!n){
		printf("NULL");}
	else{
		printf("n%d", n->id);}
	return;
}

void noeud_printf_voisins(noeud n){
	if(!n){RALER(0, "n NULL")}

	printf("voisins ");
	noeud_printf_id(n);
	printf(":\n");
	for(Dir d =0; d< NDIR; d++){
		printf("\t");
		noeud_printf_id(n->voisins[d]);
		printf("\n");
	}
	printf("\n");

	return;
}

void noeud_printf_position(noeud n){
	if(!n){RALER(0, "n NULL")}

	coord pos = coord_nouv();
	laby_position(n, pos);
	printf("%s(%d,%d)%s", lBLUE, pos->axe[X], pos->axe[Y], NC);
	coord_destroy(pos);

	return;
}