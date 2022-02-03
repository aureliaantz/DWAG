#include "liste_passages.h"

liste_p nouv_lp() { return NULL; }

void destroy_lp(liste_p l)
{
	while (l != NULL)
	{
		liste_p n = l->succ;
		/*if(l->n1 != NULL){destroy_noeud(l->n1);}
		if(l->n1 != NULL){destroy_noeud(l->n2);}*/ //les noeuds sont passés pas pointeurs
		free(l);
		l = n;
	}
}

liste_p adjtete_lp(liste_p l, noeud x1, noeud x2)
{
    liste_p new = malloc(sizeof(struct s_liste_p));
	if (new == NULL)
	{
		printf("fatal error: no memory allocation possible.\n");
		abort();
	}
	new->succ = l;
	new->n1 = x1;
    new->n2 = x2;
	return new;
}

liste_p rech_lp(liste_p l, noeud n1, noeud n2)
{
    if (l == NULL)
		return NULL;
	if(noeud_cmp(n1, l->n1) && noeud_cmp(n2, l->n2))
		return l;
	if(noeud_cmp(n2, l->n1) && noeud_cmp(n1, l->n2))
		return l;
	return rech_lp(l->succ, n1, n2);
}

void lp_printf(liste_p l){
	printf("\n");
	while (l != NULL)
	{
		liste_p n = l->succ;
		printf("|->|%s(", lBLUE);
		noeud_printf_id(l->n1);
		printf("-");
		noeud_printf_id(l->n2);
		printf(")%s", NC);
		l = n;
	}
	printf("|->|NULL\n\n");
	return;
}

void lp_printf_pos(liste_p l){
	printf("\n");
	while (l != NULL)
	{
		liste_p n = l->succ;
		printf("|->|(");
		//if(l->data!=NULL){printf("%sn%s",lBLUE, NC);
		if(l->n1!=NULL){
			noeud_printf_position(l->n1);
			printf(",");
			noeud_printf_position(l->n2);
		}
		l = n;
	}
	printf(")->|NULL\n\n");
	return;
}