#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct pixel pixel;
struct pixel{
    int R;
    int G;
    int B;
};

typedef struct image image;
struct image{
    pixel * tab;
    int w;
    int h;
};

pixel create_pixel(int r, int g, int b);
void affiche_pixel(pixel pi);
image create_image(int w, int h);
image create_test_image();
int comparer_pixel(pixel a, pixel b);
void affiche_image(image img);
