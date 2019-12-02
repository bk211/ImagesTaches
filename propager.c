#include "propager.h"
void affiche(image g,int tab[]){
	int x,y;
	for(y=0;y< g.h ;y++){
		for(x=0;x< g.w;x++){
			printf("|%d",tab[x]);
		}
		printf("\n");
	}
}

/* Ordre de traitement G*/
int propager(image g, int tab[], int i, int num_tache, pixel p){
	printf("In propager for tab[%d] = %d\n",i,tab[i]);
	affiche(g,tab);
	printf(">>>\n");
	if(tab[i]!=0){
		printf("reject i=%d\n",i );
		return 0;
	}else if(compare_pixel(p, g.tab, i)){
			printf("match %d \n",i );
			//tab[i]=num_tache;

			/*if((i%g.w -1) >= 0){//gauche
				printf("%d %d %d\n",i, i%g.w, i%g.w -1 );
				propager(g,tab,i-1,num_tache,p);
			}
			*//*
			if((i-g.w)>=0){//haut
				propager(g,tab,i-g.w,num_tache,p);
			}

			if((i%g.w +1)< g.w ){//droite
			    propager(g,tab,i+1,num_tache,p);
			}
			if((i+g.w)< g.h* g.w){//bas
			    propager(g, tab, i+g.w, num_tache, p);
			}*/
			affiche(g,tab);
			printf(">>\n" );
	}
	return 0;
}
