/*!\file window.c
 *
 * \brief Mobiles simulation with 100% GPU rendering.
 * \author Farès BELHADJ, amsi@ai.univ-paris8.fr 
 * \date February 15 2017
 */
#include <assert.h>
#include <GL4D/gl4dg.h>
#include <GL4D/gl4duw_SDL2.h>

static void init(void);
static void resize(int w, int h);
static void keydown(int keycode);
static void draw(void);
static void quit(void);

/*!\brief window's width and height */
static int _windowWidth = 600, _windowHeight = 600;

/*!\brief main function, creates the window, initialise OpenGL
 *  parameters and objects, sets GL4Dummies callback function and
 *  starts the main loop.
 */
int main(int argc, char ** argv) {
  if(!gl4duwCreateWindow(argc, argv, "GL4Dummies", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
			 _windowWidth, _windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN))
    return 1;
  init();
  gl4duwResizeFunc(resize);
  gl4duwKeyDownFunc(keydown);
  gl4duwDisplayFunc(draw);
  gl4duwMainLoop();
  return 0;
}

/*!\brief initialise OpenGL parameters and data. */
static void init(void) {
  /* setting OpenGL clear color (for next glClear) */
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
    break;
  case 'r':
      printf("r key pressed");
    break;
  }
}

/*!\brief mobile simulation and draw
 */
static void draw(void) {
}

/*!\brief called at exit and delete and clean used data. */
static void quit(void) {
  gl4duClean(GL4DU_ALL);
}
