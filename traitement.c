#include<stdlib.h>
#include<stdio.h>
#include "image.c"
#include "propager.c"
void affiche(image g,int tab[]);
void reset(image g,int tab[]);

/*dans le traitement je retranscrit l'image dans le tableau d'int avec une meme valeur pour tout les points d'une meme tache*/
void traitement(image g){
	int i=0;
	int num_tache=0;
	int tab [g.w * g.h];
	reset(g,tab);
	for(i=0; i< (g.w * g.h); i++){
		if(tab[i]==0){
			pixel color = g.tab[i];	
			propager(g,tab,i,num_tache,color);/*a faire*/ 
			//printf("propager traitement end\n");
		}
		
	}
	affiche(g,tab);
}

void affiche(image g,int tab[]){
	int x,y;
	for(y=0;y< g.h ;++y){
		for(x=0;x< g.w;++x){
			printf("|%d|",tab[x]);
		}
		printf("\n");
	}
}

void reset(image g,int tab[]){
	int i;
	for(i=0;i<(g.h * g.w);++i){
		tab[i]=0;
	}
	printf("reset end\n");
}

int main(){
	image bar = create_test_image();
	printf("image bar succes\n");
	traitement(bar);
}
