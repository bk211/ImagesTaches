#include <stdio.h>


typedef struct pixel pixel;
struct pixel{
    int R;
    int G;
    int B;
};

typedef struct image image;
struct image{
    int * pixel;
    int w;
    int h;
};
