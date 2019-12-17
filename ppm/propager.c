#include "propager.h"

void propager(my_image g, int tab[], int i, int num_tache, pixel p){
	printf("In propager for tab[%d] = %d\n",i,tab[i]);
	if(tab[i]!=0){
		//printf("reject i=%d\n",i );
		return ;
	}else if(compare_pixel(p, g.tab, i, STRICT)){
			tab[i]=num_tache;

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
	return ;
}


void propager2(my_image g, int tab[], int i, int num_tache, pixel p){
	printf("In propager2 for tab[%d] = %d\n",i,tab[i]);
	int test;
	if((i%g.w -1) >= 0){//gauche
		if(compare_pixel(p, g.tab, i-1, STRICT)){
			tab[i-1] = tab[i];
		}
	}
				
	if((i-g.w) >= 0){//haut 
		if(compare_pixel(p, g.tab, i-g.w, STRICT)){
			tab[i-g.w] = tab[i];
		}
	}
	if((i%g.w +1) < g.w ){//droite
		//test = compare_pixel(p, g.tab, i+1, STRICT);
		if(compare_pixel(p, g.tab, i+1, STRICT)){
			tab[i+1] = tab[i];
		}
		//printf("test = %d \n", test);
	}
	
	if((i+g.w) < g.h* g.w){//bas
		if(compare_pixel(p, g.tab, i+g.w, STRICT)){
			tab[i+g.w] = tab[i];
		}
	}

}