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


void propager2(my_image g, int tab[], int i, int * num_tache, pixel p){
//	printf("In propager2 for tab[%d] = %d\n",i,tab[i]);
	int diff_max = 30, diff_mono = 10; 

	if(tab[i] == 0){//si la case est nouvelle
//		printf("new tache at pos = %d\n", i);
		(*num_tache)++;
		tab[i] = *num_tache;
	}

	if((i%g.w +1) < g.w ){//droite
		if(compare(p, g.tab, i+1, diff_max, diff_mono)){
			tab[i+1] = tab[i];
		}
		
	}
	
	if((i+g.w) < g.h* g.w){//bas
		if(compare(p, g.tab, i+g.w, diff_max, diff_mono)){
			tab[i+g.w] = tab[i];
		}
	}

}

int compare(pixel pi, color * tab, int pos, int diff_max, int diff_mono){
	//printf("Comparing (%d %d %d) with (%d %d %d)\n", pi.R, pi.G, pi.B, tab[pos*3], tab[pos*3 +1], tab[pos*3+2]);
	color dr, dg, db; // delta_r/g/b difference entre la pixel de couleur et la pixel pos
	dr = abs(pi.R - tab[pos*3]);
	dg = abs(pi.G - tab[pos*3+1]);
	db = abs(pi.B - tab[pos*3+2]);
	color dt = dr + dg + db; //difference totale;
//	printf("delta >> %d %d %d\n", dr, dg, db);
//	printf("delta_tot >> %d\n", dt);
	int result = (dt < diff_max) && (dr < diff_mono) && (dg < diff_mono) && (db < diff_mono);
	//printf("result = %d\n",result);
	return result;
}