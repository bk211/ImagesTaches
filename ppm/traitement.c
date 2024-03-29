#include "traitement.h"
#include "ima.h"

/*dans le traitement je retranscrit l'image dans le tableau d'int avec une meme valeur pour tout les points d'une meme tache*/
my_image traitement(my_image g){
	//printf("in traitement\n"); 
	int i;
	int num_tache=0;
//	int tab [g.w * g.h];
	int * tab = malloc(g.w * g.h * sizeof (int*));
	assert(tab);
	init_tab(g,tab);
	for(i=0; i< (g.w * g.h); i++){
	//for(i=0; i< 20; i++){
	//printf("i =%d\n",i );
		pixel pi = build_pixel(g.tab, i); 
		propager2(g,tab,i,&num_tache,pi);
	} 
	

//	affiche_tab(g,tab); 
	int * borders = mark_border(g, tab, num_tache);
	//affiche_tab(g,borders);
	free(tab);
	my_image result = cpy_image(g);
		
	pixel couleur_bordure  = create_pixel(0, 0, 0);
	apply_borders(&result, borders, couleur_bordure);
	free(borders);
	//affiche_image(result);

	return result;
}

void affiche_tab(my_image g,int tab[]){
	int x,y;
	for(y=0;y< g.h ;y++){ 
		for(x=0;x< g.w;x++){
			printf("|%2d",tab[y*g.w +x]);
		}
		printf("\n");
	}
}

void init_tab(my_image g,int tab[]){
	int i;
	for(i=0;i<(g.h * g.w);i++){
		tab[i]=0;
	}
//	printf("init success\n");
}


int* mark_border(my_image g, int tab[], int nb_tache){
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
void apply_borders(my_image * dst, int* borders, pixel pi){
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

my_image conv_Image_to_my_image(Image src){
	my_image result;
	result.tab = src.data;
	result.w = src.sizeX;
	result.h = src.sizeY; 
	return result;
}

Image conv_my_image_to_Image(my_image src){
	Image result;
	result.data = src.tab;
	result.sizeX = src.w;
	result.sizeY = src.h; 
	return result;
}

void import_modifications(Image *src, Image *dst){
	int j, size;
    GLubyte * pt_src;
	GLubyte * pt_dst;
    size = 3 * src->sizeY * src->sizeX;
    pt_src = src->data;
	pt_dst = dst->data;
    for (j = 0; j < size; j ++) {
	    *pt_dst++ = *pt_src++;
    }
}
