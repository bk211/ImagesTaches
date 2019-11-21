#include "propager.h"

/* Ordre de traitement G*/
int propager(image g, int tab[], int i, int num_tache, pixel color){
	if(tab[i]!=0){
		return 0;
	}else if(comparer_pixel(color,g.tab[i])){
			tab[i]=num_tache;
			if((i+1)<=g.w){//propage a droite
			    propager(g,tab,i+1,num_tache,color);
			}
			if((i+g.w)<=g.h){//propage vers le bas
			    propager(g, tab, i+g.w, num_tache, color);
			}
			if((i-1)>=0){//propage vers la gauche
			    propager(g,tab,i-1,num_tache,color);
			}
			if((i-g.w)>=0){//propage vers le haut
			    propager(g,tab,i-g.w,num_tache,color);
			}
	}
	return 0;
}

/*
affiche le tableau de traitement
*/
void affiche_tab(image g,int tab[]){
	int x,y;
	for(y=0;y< g.h ;++y){
		for(x=0;x< g.w;++x){
			printf("|%d|",tab[x]);
		}
		printf("\n");
	}
}
