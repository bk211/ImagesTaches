#include "traitement.h"

/*dans le traitement je retranscrit l'image dans le tableau d'int avec une meme valeur pour tout les points d'une meme tache*/
void traitement(image g){
	int i=0;
	int num_tache=1;
	int tab [g.w * g.h];
	init_tab(g,tab);
	for(i=0; i< (g.w * g.h); i++){
//	for(i=0; i< (20); i++){
		//printf("Outside ::tab[%d]==%d  tache==%d\n", i,tab[i],num_tache);
		if(tab[i]==0){
			pixel pi = build_pixel(g.tab, i);
		//	printf("Inside ::tab[%d]==%d  tache==%d\n", i,tab[i],num_tache);
			propager(g,tab,i,num_tache,pi);
			num_tache++;
		//	printf("Inside ::tab[%d]==%d  tache==%d\n", i,tab[i],num_tache);

		}

	}
	affiche_tab(g,tab);
	int * borders = mark_border(g, tab, num_tache);
	affiche_tab(g,borders);
		
}

void affiche_tab(image g,int tab[]){
	int x,y;
	for(y=0;y< g.h ;y++){
		for(x=0;x< g.w;x++){
			printf("|%d",tab[x]);
		}
		printf("\n");
	}
}

void init_tab(image g,int tab[]){
	int i;
	for(i=0;i<(g.h * g.w);i++){
		tab[i]=0;
	}
//	printf("init success\n");
}


int* mark_border(image g, int tab[], int nb_tache){
	int * borders = malloc(g.w * g.h * sizeof (int*));
	assert(borders);
	init_tab(g, borders);

	int size = g.w * g.h;
	for (int i = 0; i < size; ++i)
	{
		if(is_border(tab, g.w, g.h, i)){
			borders[i] = -1;
		}
	}

	return borders;
}

int is_border(int tab[], int w, int h, int i){
	int result = 0;
	if((i+1)< w){//droite
		result |= (tab[i] != tab[i+1]);
	}
	if((i+w)<= h* w){ //bas
		result |= (tab[i] != tab[i+w]);
	}
	if((i-1)>=0){//gauche
		result |= (tab[i] != tab[i-1]);
	}
	if((i-w)>=0){//haut
		result |= (tab[i] != tab[i-w]);
	}
	return result;
}