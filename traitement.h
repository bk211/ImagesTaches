#include "propager.h"

void init_tab(image g,int tab[]);
image traitement(image g);
void affiche_tab(image g,int tab[]);
int* mark_border(image g, int tab[], int nb_tache);
int is_border(int tab[], int w, int h, int i);