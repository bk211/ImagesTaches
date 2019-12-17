#include "image.h"

void propager(my_image g, int tab[], int i, int num_tache, pixel p);
void propager2(my_image g, int tab[], int i, int * num_tache, pixel p);
int compare(pixel pi, color * tab, int pos, int diff_max, int diff_mono);