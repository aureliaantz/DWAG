#include "coord.h"

coord coord_nouv(){
	coord new = malloc(sizeof(struct s_coord));
	new->axe[X]=0;
	new->axe[Y]=0;

	return new;
}

void coord_destroy(coord xy){
	free(xy);

	return;
}

