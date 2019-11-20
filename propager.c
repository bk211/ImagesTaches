#include<stdio.h>
#include<stdlib.h>

/* Ordre de traitement G*/
int propager(image g, int tab[], int i, int num_tache, pixel color){
	if(tab[i]!=0){
		printf("propager ==> return\n");
		return 0;
	}
	if(tab[i]==0 && comparer_pixel(color,g.tab[i])){
			tab[i]=num_tache;
			if((i+1)>=0){
			    propager(g,tab,i+1,num_tache,color);
			    printf("1\n");
			}
			if((i+w)<=g.w){
			    propager(g,tab,i+w,num_tache,color);
			    printf("2\n");
			}
			if((i-1)<=g.h){
			    propager(g,tab,i-1,num_tache,color);
			    printf("3\n");
			}
			if((i-w)>=0){
			    propager(g,tab,i-w,num_tache,color);
			    printf("4\n");
			}
	}
}