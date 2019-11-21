#include "traitement.h"

/*dans le traitement je retranscrit l'image dans le tableau d'int avec une meme valeur pour tout les points d'une meme tache*/
void traitement(image g){
	int i=0;
	int num_tache=1;
	int tab [g.w * g.h];
	init_tab(g,tab);
	affiche_tab(g,tab);
	for(i=0; i< (g.w * g.h); i++){
		if(tab[i]==0){
			printf("tab[%d] == %d\n",i,tab[i]);
			printf("tache == %d\n",num_tache);
			pixel color = g.tab[i];
			propager(g,tab,i,num_tache,color);
			printf("propager traitement end\n");
			affiche_tab(g,tab);
			num_tache++;
		}


	}
	printf("FROM END OF traitement\n" );
	affiche_tab(g,tab);
}



/*
initialise le tableau tab a 0 selon les dimensions de l'image
*/
void init_tab(image g,int tab[]){
	int i;
	for(i=0;i<(g.h * g.w);++i){
		tab[i]=0;
	}
	printf("reset end\n");
}
