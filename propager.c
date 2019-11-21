#include "propager.h"

/* Ordre de traitement G*/
void propager(image g, int tab[], int i, int num_tache, pixel color){
	if(tab[i]!=0){
		affiche_tab(g,tab);
	}
	if(comparer_pixel(color,g.tab[i])){
			tab[i]=num_tache;
			if((i+1)<=g.w){
			    propager(g,tab,i+1,num_tache,color);
			    printf("%d\n",i);
			}
			if((i+g.w)<=g.h){
			    propager(g, tab, i+g.w, num_tache, color);
			    printf("2\n");
			}
			if((i-1)>=0){
			    propager(g,tab,i-1,num_tache,color);
			    printf("3\n");
			}
			if((i-g.w)>=0){
			    propager(g,tab,i-g.w,num_tache,color);
			    printf("4\n");
			}
	}
}


void affiche_tab(image g,int tab[]){
	int x,y;
	for(y=0;y< g.h ;++y){
		for(x=0;x< g.w;++x){
			printf("|%d|",tab[x]);
		}
		printf("\n");
	}
}
