#include "propager.h"

/* Ordre de traitement G*/
int propager(image g, int tab[], int i, int num_tache, pixel color){
	if(tab[i]!=0){
		return 0;
	}else if(comparer_pixel(color,g.tab[i])){
			tab[i]=num_tache;
			if((i+1)<=g.w){
			    propager(g,tab,i+1,num_tache,color);
			}
			if((i+g.w)<=g.h){
			    propager(g, tab, i+g.w, num_tache, color);
			}
			if((i-1)>=0){
			    propager(g,tab,i-1,num_tache,color);
			}
			if((i-g.w)>=0){
			    propager(g,tab,i-g.w,num_tache,color);
			}
	}
	return 0;
}
