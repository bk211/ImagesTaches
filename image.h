#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STRICT 1
#define DIFF_MONO 15
#define DIFF_TOT 45

typedef unsigned char color;

typedef struct pixel pixel;
struct pixel{
    color R;
    color G;
    color B;
};


typedef struct image image;
struct image{
    color * tab;
    int w;
    int h;
};

typedef struct tache tache;
struct tache{
	int nb;
	tache * tab;
};

pixel build_pixel(color *tab, int pos);
void modify_pixel(color * tab,int pos, color R, color G, color B);
void affiche_pixel(color * tab,int pos);
image create_image(int w, int h);
image create_test_image(int i);
int compare_pixel(pixel pi, color * tab, int pos, int option);
int compare_color(color * tab, int pos_a, int pos_b);
void affiche_image(image img);
image cpy_image(image src);