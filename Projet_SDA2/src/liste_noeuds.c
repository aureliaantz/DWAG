#include "liste_noeuds.h"

liste_n nouv_ln() { return NULL; }

liste_n adjtete_ln(liste_n l, noeud x){
	
	liste_n new = malloc(sizeof(struct s_liste_n));
	if (new == NULL)
	{
		printf("fatal error: no memory allocation possible.\n");
		abort();
	}
	new->succ = l;
	new->data = x;
	return new;
}

liste_n rech_ln(liste_n l, noeud x){
	if (l == NULL)
		return NULL;
	if (noeud_cmp(x, l->data))
		return l;
	return rech_ln(l->succ, x);
}

void destroy_ln(liste_n l){
	while (l != NULL)
	{
		liste_n n = l->succ;
		/*if(l->data!=NULL){
			destroy_noeud(l->data);
		}*/ //honest mistake : //les noeuds sont passés par pointeurs,
		//les libérer reviendrait à libérer les noeuds du graph.
		free(l);
		l = n;
	}
}

void ln_printf(liste_n l){
	printf("\n");
	while (l != NULL)
	{
		liste_n n = l->succ;
		printf("|->|%s(", lBLUE);
		noeud_printf_id(l->data);
		printf(")%s", NC);
		l = n;
	}
	printf("|->|NULL\n\n");
	return;
}

void ln_printf_pos(liste_n l){
	printf("\n");
	while (l != NULL)
	{
		liste_n n = l->succ;
		printf("|->|");
		if(l->data!=NULL){noeud_printf_position(l->data);}
		l = n;
	}
	printf("|->|NULL\n\n");
	return;
}