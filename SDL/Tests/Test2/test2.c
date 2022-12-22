#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include <math.h>

int main(int argc, char *argv[]) {
    SDL_Event event;
    SDL_Surface *screen;
    int elozox, elozoy, click, quit, rajzoltam;

    /* SDL inicializálása és ablak megnyitása */
    SDL_Init(SDL_INIT_VIDEO);
    screen=SDL_SetVideoMode(360, 360, 0, SDL_ANYFORMAT);
    if (!screen) {
        fprintf(stderr, "Nem sikerult megnyitni az ablakot!\n");
        exit(1);
    }
    SDL_WM_SetCaption("SDL esemenyek", "SDL esemenyek");

    /* az esemenyvezerelt hurok */
    quit = 0;
    click = 0;
    elozox = 0;
    elozoy = 0;
    while (!quit) {
        SDL_WaitEvent(&event);

        rajzoltam = 0;

        switch (event.type) {
            /* eger kattintas */
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    click = 1;
                    elozox = event.button.x;
                    elozoy = event.button.y;
                }
                else if (event.button.button == SDL_BUTTON_RIGHT) {
                    boxRGBA(screen, 0, 0, 359, 359, 0, 0, 0, 255);
                    rajzoltam = 1;
                }
                break;
                /* egergomb elengedese */
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    click = 0;
                }
                break;
                /* eger mozdulat */
            case SDL_MOUSEMOTION:
                if (click) {
                    aalineRGBA(screen, elozox, elozoy, event.motion.x, event.motion.y,
                            255, 255, 255, 255);
                    rajzoltam = 1;
                }
                /* a kovetkezo mozdulat esemenyhez */
                elozox = event.motion.x;
                elozoy = event.motion.y;
                break;
                /* ablak bezarasa */
            case SDL_QUIT:
                quit=1;
                break;
        }

        if (rajzoltam)
            SDL_Flip(screen);
    }

    SDL_Quit();

    return 0;
}

