#include "traitement.h"

/*dans le traitement je retranscrit l'image dans le tableau d'int avec une meme valeur pour tout les points d'une meme tache*/
image traitement(image g){
	//printf("in traitement"); 
	int i;
	int num_tache=1;
	int tab [g.w * g.h];
	init_tab(g,tab);
	for(i=0; i< (g.w * g.h); i++){
		//printf("Outside ::tab[%d]==%d  tache==%d\n", i,tab[i],num_tache);
		if(tab[i]==0){
			pixel pi = build_pixel(g.tab, i);
			//printf("%d %d %d\n", pi.R, pi.G, pi.B);
		//	printf("Inside ::tab[%d]==%d  tache==%d\n", i,tab[i],num_tache);
			propager(g,tab,i,num_tache,pi);
			num_tache++;
		//	printf("Inside ::tab[%d]==%d  tache==%d\n", i,tab[i],num_tache);

		}
	} 

//	affiche_tab(g,tab);
	int * borders = mark_border(g, tab, num_tache);
//	affiche_tab(g,borders);

	image result = cpy_image(g);
	
	pixel couleur_bordure  = create_pixel(0, 0, 0);
	apply_borders(&result, borders, couleur_bordure);
	return result;
}

void affiche_tab(image g,int tab[]){
	int x,y;
	for(y=0;y< g.h ;y++){ 
		for(x=0;x< g.w;x++){
			printf("|%2d",tab[y*g.w +x]);
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
//			printf("find -1 at %d\n",i );
		}
	}

	return borders;
}

int is_border(int tab[], int w, int h, int i){
	int result = 0;
	//printf("testing %d\n",i );
	if((i%w -1)>=0){//gauche
	//	printf("g\n");
		result |= (tab[i] != tab[i-1]);
	}
	if((i-w)>=0){//haut
	//	printf("h\n");
		result |= (tab[i] != tab[i-w]);
	}
	if((i%w +1)< w){//droite
//		printf("d\n");
		result |= (tab[i] != tab[i+1]);
	}
	if((i+w)< h* w){ //bas
//		printf("b\n");
		result |= (tab[i] != tab[i+w]);
	}
	return result;
}

/*
	applique la pixel de couleur pi a toutes les bordures sur l'image dst
*/
void apply_borders(image * dst, int* borders, pixel pi){
	for (int i = 0; i < dst->w * dst->h ; i++)
	{
		if (borders[i] == -1)
		{	
			//printf("border find at %i\n", i);
			dst->tab[i*3]   = pi.R;
			dst->tab[i*3+1] = pi.G;
			dst->tab[i*3+2] = pi.B;
		}
	}
	
}