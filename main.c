#include "traitement.h"

int main(int argc, char const *argv[])
{
    image before_image = create_test_image(1);
 	image after_image = traitement(before_image);
    //affiche_image(after_image);

    return 0; 
}
