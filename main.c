#include "traitement.h"

int main(){
	image bar = create_test_image(2);
    affiche_image(bar);
	printf("create image bar succes\n");
	traitement(bar);
}
