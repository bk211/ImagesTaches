#include "image.h"

/*
Cree une pixel d'attribut r g b
*/
pixel create_pixel(int r, int g, int b){
    pixel result;
    result.R = r;
    result.G = g;
    result.B = b;
    return result;
}

/*
affiche une pixel donne
*/
void affiche_pixel(pixel pi){
    printf("(%3d,%3d,%3d)", pi.R, pi.G, pi.B);
}

/*
Alloue la memoire pour un tableau, mais n'initialise pas les pixels
*/
image create_image(int w, int h){
    image result;
    result.w = w;
    result.h = h;
    result.tab = malloc( w * h * sizeof(pixel));
    return result;
}

/*
Retourne une image pour les besoins de test
*/
image create_test_image(){
    image result = create_image(10,10);
    for (int i = 0; i < result.h; i++) {
        for (int j = 0; j < result.w; j++) {
            if(j < 5){
                result.tab[i* result.w +j] = create_pixel(255,255,255);
            }else{
                result.tab[i* result.w +j] = create_pixel(1,1,1);
            }
        }
    }
    return result;
}

int comparer_pixel(pixel a, pixel b){
    return (a.R == b.R && a.G == b.G && a.B == b.B);
}

/*
Affiche l'image
*/
void affiche_image(image img){
    printf("\n%d %d\n",img.w, img.h );

    for (int i = 0; i < img.h; i++) {
        for (int j = 0; j < img.w; j++) {
            affiche_pixel(img.tab[i*img.w+j]);
            printf(" ");
        }
        printf("\n");
    }
}


int main(int argc, char const *argv[]) {
    pixel foo = create_pixel(0,255,255);
    pixel pi2 = create_pixel(0,255,255);
    pixel pi3 = create_pixel(25,255,255);
    printf("%d %d\n", comparer(foo,pi2), comparer(pi2,pi3) );
    affiche_pixel(foo);
    image bar = create_test_image();
//    affiche_image(bar);


    return 0;
}
