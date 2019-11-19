#include <stdio.h>


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
