#include "propager.h"

int propager(my_image g, int tab[], int i, int num_tache, pixel p){
	//printf("In propager for tab[%d] = %d\n",i,tab[i]);
//	printf(">>>\n");
	if(tab[i]!=0){
		//printf("reject i=%d\n",i );
		return 0;
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
	return 0;
}
