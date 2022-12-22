#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include <SDL_ttf.h>
#include <math.h>

/* Beolvas egy szoveget a billentyuzetrol.
 * Ehhez rajzol egy zold keretet x, y, sz, m helyen, 'hatter' szinnel
 * es 'szin' szinu betukkel.
 * A rajzolashoz hasznalt font es a kepernyo surface-e az utolso parameterek.
 * Az elso a tomb, ahova a beolvasott szoveg kerul. */
void input_text(Uint16 *dest, int x, int y, int sz, int m,
        SDL_Color hatter, SDL_Color szin, TTF_Font *font, SDL_Surface *screen) {
    SDL_Rect forras = { 0, 0, sz, m}, cel = { x, y, sz, m };
    SDL_Surface *felirat;
    SDL_Event event;
    int hossz, kilep;

    hossz = 0;
    dest[hossz] = 0x0000;   /* lezaro 0 */
    kilep = 0;
    do {
        /* szoveg kirajzolasa */
        boxRGBA(screen, x, y, x+sz-1, y+m-1, hatter.r, hatter.g, hatter.b, 255);
        felirat = TTF_RenderUNICODE_Blended(font, dest, szin);
        SDL_BlitSurface(felirat, &forras, screen, &cel);
        SDL_FreeSurface(felirat);
        rectangleRGBA(screen, x, y, x+sz-1, y+m-1, 0, 255, 0, 255);
        /* updaterect: mint az sdl_flip, de csak a kepernyo egy darabjat */
        SDL_UpdateRect(screen, x, y, sz, m);

        switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.unicode) {
                    case 0x0000:
                        /* nincs neki megfelelo karakter (pl. shift gomb) */
                        break;
                    case '\r':
                        /* enter: bevitel vege */
                        kilep = 1;
                        break;
                    case '\b':
                        /* backspace: torles visszafele, ha van karakter */
                        if (hossz>0)
                            dest[--hossz] = 0x0000;
                        break;
                    default:
                        /* karakter: tombbe vele, plusz lezaro nulla */
                        dest[hossz++] = event.key.keysym.unicode;
                        dest[hossz] = 0x0000;
                        break;
                }
        }
    } while (SDL_WaitEvent(&event) && !kilep);
}


int main(int argc, char *argv[]) {
    SDL_Color feher = {255, 255, 255}, fekete = { 0, 0, 0 };
    SDL_Rect hely;
    Uint16 szoveg[100];
    SDL_Event event;
    SDL_Surface *screen, *felirat;
    TTF_Font *font;
    int i;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("SDL szoveg bevitele", "SDL szoveg bevitele");
    screen=SDL_SetVideoMode(480, 200, 0, SDL_ANYFORMAT);
    if (!screen) {
        fprintf(stderr, "Nem sikerult megnyitni az ablakot!\n");
        exit(1);
    }
    TTF_Init();
    font = TTF_OpenFont("LiberationSerif-Regular.ttf", 32);
    if (!font) {
        fprintf(stderr, "Nem sikerult megnyitni a fontot! %s\n", TTF_GetError());
        exit(2);
    }
    SDL_EnableUNICODE(1);
    SDL_EnableKeyRepeat(500, 30);

    /* szoveg beolvasasa */
    for (i=0; i<500; ++i)
        lineRGBA(screen, rand()%screen->w, rand()%screen->h, rand()%screen->w, rand()%screen->h,
                rand()%256, rand()%256, rand()%256, 64);
    SDL_Flip(screen);
    input_text(szoveg, 40, 80, 400, 40, fekete, feher, font, screen);

    /* szoveg kirajzolasa */
    if (szoveg[0]!=0x0000) {
        boxRGBA(screen, 0, 0, screen->w, screen->h, 0, 0, 0, 255);
        for (i=0; i<100; ++i)
            filledCircleRGBA(screen, rand()%screen->w, rand()%screen->h,
                    20+rand()%5, rand()%256, rand()%256, rand()%256, 64);
        felirat = TTF_RenderUNICODE_Blended(font, szoveg, feher);
        hely.x = (screen->w - felirat->w)/2 + 2;
        hely.y = (screen->h - felirat->h)/2 + 2;
        SDL_BlitSurface(felirat, NULL, screen, &hely);
        SDL_FreeSurface(felirat);

        SDL_Flip(screen);
        while (SDL_WaitEvent(&event) && event.type!=SDL_QUIT)
            ;
    }

    TTF_CloseFont(font);
    SDL_Quit();

    return 0;
}
