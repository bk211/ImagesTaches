#include <stdio.h>
#include <stdlib.h>

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
image create_image(int w, int h);
int comparer_pixel(pixel a, pixel b);
