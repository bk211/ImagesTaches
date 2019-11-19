#include<stdio.h>
#include<stdlib.h>

/* Ordre de traitement G*/
int propager(image g, int tab[], int x, int y, int num_tache, pixel color){
	int i;
	if(tab[y*g.w+x]!=0){
		return 0;
	}
	if(tab[y*g.w+x]==0 && comparer_pixel(color,g.tab[y*g.w+x])){
			tab[x+g.w*y]=num_tache;
			if((y-1)>=0){
			    propager(g,tab,x,y-1,num_tache,color);
			}
			if((x+1)<=g.w){
			    propager(g,tab,x+1,y,num_tache,color);
			}
			if((y+1)<=g.h){
			    propager(g,tab,x,y+1,num_tache,color);
			}
			if((x-1)>=0){
			    propager(g,tab,x-1,y,num_tache,color);
			}
	}
}