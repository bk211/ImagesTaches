#include "image.h"

/*
construit une structure pixel a partir de la position pos du tableau de couleur
*/
pixel build_pixel(color *tab, int pos){
	pixel result;
	result.R = tab[pos*3];
	result.G = tab[pos*3 +1];
	result.B = tab[pos*3 +2];

	return result;
}

/*
Modifie le pixel situe au postion pos du tableau tab par les attributs RGB
*/
void modify_pixel(color* tab,int pos, color R, color G, color B){
	tab[pos * 3] = R;
	tab[pos * 3 +1] = G;
	tab[pos * 3 +2] = B;
}

/*
affiche une pixel donne
*/
void affiche_pixel(color * tab,int pos){
    printf("(%3d,%3d,%3d)", tab[pos*3], tab[pos*3+1], tab[pos*3+2]);
}

/*
Alloue la memoire pour un tableau, mais n'initialise pas les pixels
*/
image create_image(int w, int h){
    image result;
    result.w = w;
    result.h = h;
    result.tab = malloc( w * h * 3 *sizeof(color));
    assert(result.tab);
    return result;
}

/*
	cree une copie de l'image src et l'a renvoie 
*/
image cpy_image(image src){
	image dst = create_image(src.w, src.h);
	for (int i = 0; i < src.w*src.h*3 ; ++i)
	{
		dst.tab[i] = src.tab[i];
	}
	return dst;

}


/*
Retourne une image pour les besoins de test
*/
image create_test_image(int i){
	if(i == 1){
    	image result = create_image(10,10);
    	int image_h = result.h;
    	int image_w = result.w;
    	for (int i = 0; i < image_h; i++) {
    	    for (int j = 0; j < image_w; j++) {
    	        if(j < 5){
		            modify_pixel(result.tab, i * image_w + j , 0, 255, 255);
    	        }else{
    	            modify_pixel(result.tab, i * image_w + j, 255, 1, 255);
    	        }
    	    }
    	}
    	return result;
	}else if(i == 2){

    	image result = create_image(400,400);
    	int image_h = result.h;
    	int image_w = result.w;
    	for (int i = 0; i < image_h; i++) {
    	    for (int j = 0; j < image_w; j++) {
    	        if(j < image_w/2 ){
		            modify_pixel(result.tab, i * image_w + j , 255, 255, 255);
					if(i < image_h/2 ){
						modify_pixel(result.tab, i * image_w + j , 128, 128, 128);
					}
    	        }else{
    	            modify_pixel(result.tab, i * image_w + j, 1, 1, 1);
    	        }
    	    }
    	}
		
		modify_pixel(result.tab, 0, 120, 120, 120);
    	
    	return result;

	}else if(i == 3){

    	image result = create_image(400,400);
    	int image_h = result.h;
    	int image_w = result.w;
    	for (int i = 0; i < image_h; i++) {
    	    for (int j = 0; j < image_w; j++) {
    	        if(j < image_w/2 ){
					if(i < image_h/2 ){
						modify_pixel(result.tab, i * image_w + j , 128, 128, 128);
					}else{
			            modify_pixel(result.tab, i * image_w + j , 255, 0, 0);
					}
    	        }else{
					if(i < image_h/2 ){
						modify_pixel(result.tab, i * image_w + j , 0, 255, 0);
					}else{
    	            	modify_pixel(result.tab, i * image_w + j, 0, 0, 255);
					}
    	        }
    	    }
    	}
		
		modify_pixel(result.tab, 0, 120, 120, 120);
    	
    	return result;
	}
	else{
		return create_test_image(1);
	}
}

/*comparer si 2 couleurs sont strictement egaux en terme de couleur;*/
int compare_pixel(pixel pi, color * tab, int pos, int option){
	if(!option){// Si option == 0 cad, comparaison strict
		//printf("compare pixel result %d pos :%d \n", (pi.R == tab[pos*3]) && (pi.G == tab[pos*3+1]) && (pi.B == tab[pos*3+2] ) , pos );
		return (pi.R == tab[pos*3]) && (pi.G == tab[pos*3+1]) && (pi.B == tab[pos*3+2] );
	}else{
		color dr, dg, db; // delta_r/g/b difference entre la pixel de couleur et la pixel pos
		dr = abs(pi.R - tab[pos*3]);
		dg = abs(pi.G - tab[pos*3]);
		db = abs(pi.B - tab[pos*3]);
		color dt = dr + dg + db; //difference totale;
		return (dt < DIFF_TOT) && (dr < DIFF_MONO) && (dg < DIFF_MONO) && (db < DIFF_MONO);
	}
}

/*comparer si 2 couleurs sont strictement egaux en terme de couleur;*/
int compare_color(color * tab, int pos_a, int pos_b){
    return (tab[pos_a *3] == tab[pos_b *3]
    	&& tab[pos_a *3+1 ] == tab[pos_b *3 +1]
    	&& tab[pos_a *3+2 ] == tab[pos_b *3 +2]);
}

/*
Affiche l'image
*/
void affiche_image(image img){
    printf("\nw: %d \th: %d\n",img.w, img.h );
    for (int i = 0; i < img.h; i++) {
        for (int j = 0; j < img.w; j++) {
            affiche_pixel(img.tab, i*img.w+j);
            printf(" ");
        }
        printf("\n");
    }
}
