#include "propager.h"

/* Ordre de traitement G*/
int propager(image g, int tab[], int i, int num_tache, pixel p){
	if(tab[i]!=0){
		printf("reject i=%d\n",i );
		return 0;
	}else if(compare_pixel(p, g.tab, i)){
			tab[i]=num_tache;
			printf("find 0 for %d\n",i );

			if((i%g.w -1) >= 0){//gauche
				propager(g,tab,i-1,num_tache,p);
			}
			if((i-g.w)>=0){//haut
				propager(g,tab,i-g.w,num_tache,p);
			}

			if((i%g.w +1)< g.w ){//droite
			    propager(g,tab,i+1,num_tache,p);
			}
			if((i+g.w)< g.h* g.w){//bas
			    propager(g, tab, i+g.w, num_tache, p);
			}
	}
	return 0;
}
