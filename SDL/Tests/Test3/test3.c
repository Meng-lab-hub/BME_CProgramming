#include <SDL.h>
#include <SDL_gfxPrimitives.h>

/* ez a fuggveny hivodik meg az idozito altal.
 *  * betesz a feldolgozando esemenyek koze (push)
 *   * egy felhasznaloi esemenyt */
Uint32 idozit(Uint32 ms, void* param) {
    SDL_Event ev;
    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
    return ms;   /* ujabb varakozas */
}

int main(int argc, char *argv[]) {
    enum { ABLAK=360, GOLYO_R=10 };
    struct Golyo {
        int x, y;
        int vx, vy;
    };
    SDL_Event event;
    SDL_Surface *screen;
    int quit;
    SDL_TimerID id;
    struct Golyo g;

    /* SDL inicializálása és ablak megnyitása */
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    screen=SDL_SetVideoMode(ABLAK, ABLAK, 0, SDL_ANYFORMAT);
    if (!screen) {
        fprintf(stderr, "Nem sikerult megnyitni az ablakot!\n");
        exit(1);
    }
    SDL_WM_SetCaption("SDL idozites", "SDL idozites");

    quit = 0;
    g.x=ABLAK/2;
    g.y=ABLAK/3;
    g.vx=3;
    g.vy=2;
    /* idozito hozzaadasa: 0 ms mulva hivodik meg eloszor */
    id = SDL_AddTimer(20, idozit, NULL);
    /* szokasos esemenyhurok */
    while (!quit) {
        SDL_WaitEvent(&event);

        switch (event.type) {
            /* felhasznaloi esemeny: ilyeneket general az idozito fuggveny */
            case SDL_USEREVENT:
                /* kitoroljuk az elozo poziciojabol */
                filledCircleRGBA(screen, g.x, g.y, GOLYO_R, 0, 0, 0, 255);
                /* kiszamitjuk az uj helyet */
                g.x+=g.vx;
                g.y+=g.vy;
                if (g.x<GOLYO_R || g.x>ABLAK-GOLYO_R) g.vx *= -1;
                if (g.y<GOLYO_R || g.y>ABLAK-GOLYO_R) g.vy *= -1;
                /* ujra kirajzolas, es mehet a kepernyore */
                filledCircleRGBA(screen, g.x, g.y, GOLYO_R, 128, 128, 255, 255);
                SDL_Flip(screen);
                break;

            case SDL_QUIT:
                quit=1;
                break;
        }
    }
    /* idozito torlese */
    SDL_RemoveTimer(id);

    SDL_Quit();

    return 0;
}

