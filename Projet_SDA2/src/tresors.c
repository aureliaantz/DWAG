#include "tresors.h"

float* tr_nouv(int dist, int where, float value){
	if (dist <0){ RALER(0," dist <0");}
	if (where <0){ RALER(0," where <0");}
	if (where >dist){ RALER(0," where >dist");}

	float* newtr = malloc(sizeof(float) * dist);

	//initialiser
	for(int i = 0; i < dist; i++){
		newtr[i] = 0;
	}

	if(where!=0)
    	tr_add(newtr, dist, where-1, value);

	return newtr;
}

float* tr_add(float* tr,int dist, int where, float value){
	if (!tr){ RALER(0," tr NULL");}
	if (where <0){ RALER(0," where <0");}
	if (where >dist){ RALER(0," where >dist");}

	tr[where]= value;
	return tr;
}

void tr_destroy(float* tr){
	free(tr);
	return;
}

void tr_printf(float* tr, int dist){
	if (!tr){ RALER(0," tr NULL");}
	if (dist <0){ RALER(0," dist <0");}

	printf("\n (dist (n1)<->(tr) =i+1)\ntresors:");

	int found = 0;
	int i=0;
	for(	; i<dist; i++){
		if (tr[i]!=0){
			printf(" [%d]:%s%.0f%s,\t\t(dist %d)\n",i,lBLUE, tr[i], NC, i+1);
			found++;
		}
	}
	if(found==0){
		printf(" [%d]:%s%.0f%s,\n",i,lBLUE, 0.0, NC);
	}

	printf("\n");
}