/*!\file window.c
 *
 * \brief Mobiles simulation with 100% GPU rendering.
 * \author Farès BELHADJ, amsi@ai.univ-paris8.fr 
 * \date February 15 2017
 */
#include <assert.h>
#include <GL4D/gl4dg.h>
#include <GL4D/gl4dp.h>
#include <GL4D/gl4duw_SDL2.h>
#include "traitement.h"

static void init(void);
static void resize(int w, int h);
static void keydown(int keycode);
static void draw(void);
static void quit(void);

/*!\brief window's width and height by default, but actually never used because of overwriting in main*/
static int _windowWidth = 800, _windowHeight = 600;
static image before_image, after_image;
static GLuint _screen = 0;

/*!\brief main function, creates the window, initialise OpenGL
 *  parameters and objects, sets GL4Dummies callback function and
 *  starts the main loop.
 */
int main(int argc, char ** argv) {
  before_image = create_test_image(1);
 	after_image = traitement(before_image);
  _windowWidth = before_image.w;
  _windowHeight = before_image.h;

  if(!gl4duwCreateWindow(argc, argv, "ImagesTaches", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
			 _windowWidth, _windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN))
    return 1;
  init();
  atexit(quit);
  gl4duwResizeFunc(resize);
  gl4duwKeyDownFunc(keydown);
  gl4duwDisplayFunc(draw);
  gl4duwMainLoop();
  return 0;
}

/*!\brief initialise OpenGL parameters and data. */
static void init(void) {
  /* setting OpenGL clear color (for next glClear) */
  _screen = gl4dpInitScreen();
  gl4dpSetScreen(_screen);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  resize(_windowWidth, _windowHeight);
  
}

/*!\brief sets the OpenGL viewport according to the window width and height.
 */
static void resize(int w, int h) {
  _windowWidth  = w;
  _windowHeight = h;
  glViewport(0, 0, _windowWidth, _windowHeight);
}

/*!\brief manages keyboard-down event */
static void keydown(int keycode) {
  switch(keycode) {
  case SDLK_ESCAPE:
  case 'q':
    exit(0);
  case 'v':
      printf("v key pressed");
      before_image = create_test_image(3);
 	    after_image = traitement(before_image);
    break;
  case 'r':
      printf("r key pressed");
    break;
  }
}

static void print_image(image img){

  for (int i = 0; i < img.h; i++)
  {
    for (int j = 0; j < img.w; j++)
    {
      GLubyte r, g, b; 
      r = img.tab[(i*img.w+j)*3 ];
      g = img.tab[(i*img.w+j)*3 +1];
      b = img.tab[(i*img.w+j)*3 +2];
      gl4dpSetColor(RGB(r, g, b));
      gl4dpPutPixel(j, i);
    }
    
  }
  gl4dpUpdateScreen(NULL);

}

/*!\brief 
 */
static void draw(void) {
  print_image(after_image);

}

/*!\brief called at exit and delete and clean used data. */
static void quit(void) {
  gl4duClean(GL4DU_ALL);
}
