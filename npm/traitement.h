#include "propager.h"
#include "ima.h"

void init_tab(my_image g,int tab[]);
my_image traitement(my_image g);
void affiche_tab(my_image g,int tab[]);
int* mark_border(my_image g, int tab[], int nb_tache);
int is_border(int tab[], int w, int h, int i);
void apply_borders(my_image * dst, int* borders, pixel pi);

my_image conv_Image_to_my_image(Image src);

Image conv_my_image_to_Image(my_image src);
void import_modifications(Image *src, Image *dst);