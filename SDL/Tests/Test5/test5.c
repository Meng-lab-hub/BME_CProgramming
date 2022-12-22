#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include <SDL_ttf.h>

int main(int argc, char *argv[]) {
    SDL_Color feher = {255, 255, 255}, piros = {255, 0, 0};
    SDL_Rect hova = { 0, 0, 0, 0 };
    SDL_Event event;
    SDL_Surface *screen;
    TTF_Font *font;
    SDL_Surface *felirat;
    int i;

    SDL_Init(SDL_INIT_VIDEO);
    screen=SDL_SetVideoMode(480, 200, 0, SDL_ANYFORMAT);
    if (!screen) {
        fprintf(stderr, "Nem sikerult megnyitni az ablakot!\n");
        exit(1);
    }
    SDL_WM_SetCaption("SDL betutipusok", "SDL betutipusok");

    /* hatter */
    for (i=0; i<500; ++i)
        filledCircleRGBA(screen, rand()%screen->w, rand()%screen->h,
                10+rand()%5, rand()%256, rand()%256, rand()%256, 64);

    /* betutipus betoltese, 32 pont magassaggal */
    TTF_Init();
    font = TTF_OpenFont("LiberationSerif-Regular.ttf", 32);
    if (!font) {
        fprintf(stderr, "Nem sikerult megnyitni a fontot! %s\n", TTF_GetError());
        exit(2);
    }

    /* felirat megrajzolasa */
    felirat = TTF_RenderUTF8_Solid(font, "TTF_RenderUTF8_Solid()", feher);
    /* felirat kep masolasa a kepernyore */
    hova.x = (screen->w-felirat->w)/2;
    hova.y = 20;
    SDL_BlitSurface(felirat, NULL, screen, &hova);
    /* a feliratot tartalmazo kepre nincs mar szukseg */
    SDL_FreeSurface(felirat);

    felirat = TTF_RenderUTF8_Shaded(font, "TTF_RenderUTF8_Shaded()", feher, piros);
    hova.x = (screen->w-felirat->w)/2;
    hova.y += 40;
    SDL_BlitSurface(felirat, NULL, screen, &hova);
    SDL_FreeSurface(felirat);

    felirat = TTF_RenderUTF8_Blended(font, "TTF_RenderUTF8_Blended()", feher);
    hova.x = (screen->w-felirat->w)/2;
    hova.y += 40;
    SDL_BlitSurface(felirat, NULL, screen, &hova);
    SDL_FreeSurface(felirat);

    felirat = TTF_RenderUTF8_Blended(font,
            /* ez az utf8 szoveg azert nez ki ilyen rosszul,
             *          * mert szinte csak ekezetes betu van benne */
            "\xC3\xA1rv\xC3\xADzt\xC5\xB1r\xC5\x91 "
            "t\xC3\xBCk\xC3\xB6rf\xC3\xBAr\xC3\xB3g\xC3\xA9p "
            "\xE2\x98\xBA \xE2\x82\xAC", feher);
    hova.x = (screen->w-felirat->w)/2;  /* kozepre vele */
    hova.y += 40;
    SDL_BlitSurface(felirat, NULL, screen, &hova);
    SDL_FreeSurface(felirat);

    /* nem kell tobbe */
    TTF_CloseFont(font);

    SDL_Flip(screen);
    while (SDL_WaitEvent(&event) && event.type!=SDL_QUIT) {
    }

    SDL_Quit();

    return 0;
}

