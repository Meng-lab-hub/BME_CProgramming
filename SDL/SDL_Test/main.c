#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include <math.h>

int main(int argc, char *argv[]) {
    SDL_Event ev;
    SDL_Surface *screen;
    int x, y, r;

    /* init SDL and open a window */
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    screen = SDL_SetVideoMode(440, 360, 0, SDL_ANYFORMAT);
    if (!screen) {
        fprintf(stderr, "The window could not be opened!\n");
        exit(1);
    }
    SDL_WM_SetCaption("SDL sample program", "SDL sample program");

    r = 50;

    /* circle */
    x = 100;
    y = 100;
    circleRGBA(screen, x, y, r, 255, 0, 0, 255);
    circleRGBA(screen, x + r, y, r, 0, 255, 0, 255);
    circleRGBA(screen, x + r * cos(3.1415 / 3), y - r * sin(3.1415 / 3), r, 0, 0, 255, 255);

    /* antialias circle */
    x = 280;
    y = 100;
    aacircleRGBA(screen, x, y, r, 255, 0, 0, 255);
    aacircleRGBA(screen, x + r, y, r, 0, 255, 0, 255);
    aacircleRGBA(screen, x + r * cos(3.1415 / 3), y - r * sin(3.1415 / 3), r, 0, 0, 255, 255);

    /* filled circle */
    x = 100;
    y = 280;
    filledCircleRGBA(screen, x, y, r, 255, 0, 0, 255);
    filledCircleRGBA(screen, x + r, y, r, 0, 255, 0, 255);
    filledCircleRGBA(screen, x + r * cos(3.1415 / 3), y - r * sin(3.1415 / 3), r, 0, 0, 255, 255);

    /* circle with transparency */
    x = 280;
    y = 280;
    filledCircleRGBA(screen, x, y, r, 255, 0, 0, 96);
    filledCircleRGBA(screen, x + r, y, r, 0, 255, 0, 96);
    filledCircleRGBA(screen, x + r * cos(3.1415 / 3), y - r * sin(3.1415 / 3), r, 0, 0, 255, 96);

    /* text */
    stringRGBA(screen, 110, 350, "Click the X to exit", 255, 255, 255, 255);

    /* actually display the drawing */
    SDL_Flip(screen);

    /* wait for exit */
    while (SDL_WaitEvent(&ev) && ev.type != SDL_QUIT) {
    }

    /* close the window */
    SDL_Quit();

    return 0;
}
