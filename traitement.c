#include "traitement.h"

/*dans le traitement je retranscrit l'image dans le tableau d'int avec une meme valeur pour tout les points d'une meme tache*/
void traitement(image g){
	int i=0;
	int num_tache=1;
	int tab [g.w * g.h];
	init_tab(g,tab);
	for(i=0; i< (g.w * g.h); i++){
//	for(i=0; i< (20); i++){
		pixel color = g.tab[i];
		printf("Outside ::tab[%d]==%d  tache==%d\n", i,tab[i],num_tache);
		if(tab[i]==0){
			printf("Inside ::tab[%d]==%d  tache==%d\n", i,tab[i],num_tache);
			propager(g,tab,i,num_tache,color);/*a faire*/
			num_tache++;
			printf("Inside ::tab[%d]==%d  tache==%d\n", i,tab[i],num_tache);

		}

	}
	affiche_tab(g,tab);
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
	printf("reset end\n");
}
