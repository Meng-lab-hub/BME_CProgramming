#include <SDL.h>
#include <SDL_image.h>
#include <SDL_gfxPrimitives.h>
#include <math.h>

enum { MERET = 52, KERET = 26 };

/* mezon allo figura. ugyanolyan sorrendben vannak, mint a kepen,
 *  * igy a kapott egesz szamok megegyeznek a png-beli indexekkel */
typedef enum Babu {
    Ures = -1,
    VKiraly, VVezer, VBastya, VFuto, VHuszar, VGyalog,
    SKiraly, SVezer, SSastya, SFuto, SHuszar, SGyalog
} Babu;
typedef Babu Tabla[8][8];

/* uj allassal tolti ki a parameterkent kapott tablat */
void uj_allas(Tabla tabla) {
    int x, y;

    for (y=0; y<8; y++)
        for (x=0; x<8; x++)
            tabla[y][x]=Ures;
    tabla[0][0]=SSastya; tabla[0][1]=SHuszar; tabla[0][2]=SFuto; tabla[0][3]=SVezer;
    tabla[0][4]=SKiraly; tabla[0][5]=SFuto; tabla[0][6]=SHuszar; tabla[0][7]=SSastya;
    for (x=0; x<8; x++)
        tabla[1][x]=SGyalog;
    tabla[7][0]=VBastya; tabla[7][1]=VHuszar; tabla[7][2]=VFuto; tabla[7][3]=VVezer;
    tabla[7][4]=VKiraly; tabla[7][5]=VFuto; tabla[7][6]=VHuszar; tabla[7][7]=VBastya;
    for (x=0; x<8; x++)
        tabla[6][x]=VGyalog;
}

/* kiszamolja, hogy milyen koordinatan van a kepernyon az adott mezo */
int palyapos(int koord) {
    return MERET*koord + KERET;
}

/* kirajzol egy mezot; a forras a betoltott png, a cel nevu kepre rajzol.
 *  * melyik babut, milyen koordinatakra: melyik, x, y. */
void mezo_rajzol(SDL_Surface *forraskep, SDL_Surface *celkep, Babu melyik, int x, int y) {
    /* a forras kepbol ezekrol a koordinatakrol, ilyen meretu reszletet masolunk. */
    SDL_Rect src = { 12+(melyik%6)*62-2, 13+60*(melyik/6)-2, MERET, MERET };
    /* a cel kepre, ezekre a koordinatakra masoljuk. (0, 0 lenne a meret, de az nem szamit,
     *      * a masolando kepreszlet meretet az elozo struct adja meg. */
    SDL_Rect dest = { x*MERET + KERET, y*MERET + KERET, 0, 0 };

    /* mezo alapszine */
    if (x%2 != y%2)
        boxRGBA(celkep, palyapos(x), palyapos(y), palyapos(x+1)-1, palyapos(y+1)-1, 0xcc, 0xad, 0x99, 255);
    else
        boxRGBA(celkep, palyapos(x), palyapos(y), palyapos(x+1)-1, palyapos(y+1)-1, 0xe6, 0xd1, 0xc3, 255);

    if (melyik==Ures)
        return;
    /* kepreszlet masolasa */
    SDL_BlitSurface(forraskep, &src, celkep, &dest);
}

/* kirajzolja az egesz tablat. forraskep a betoltott png, celkep ahova rajzol. */
void tabla_rajzol(Tabla tabla, SDL_Surface *forraskep, SDL_Surface *celkep) {
    int x, y;

    /* az egeszet kitolti */
    boxRGBA(celkep, 0, 0, celkep->w-1, celkep->h-1, 0x90, 0xe0, 0x90, 255);
    rectangleRGBA(celkep, palyapos(0)-1, palyapos(0)-1, palyapos(8), palyapos(8), 0, 0, 0, 128);
    /* kirajzolja a mezoket */
    for (y=0; y<8; y++)
        for (x=0; x<8; x++)
            mezo_rajzol(forraskep, celkep, tabla[y][x], x, y);
}

int main(int argc, char *argv[]) {
    SDL_Event event;
    SDL_Surface *screen;
    SDL_Surface *babuk;
    Tabla tabla;

    SDL_Init(SDL_INIT_VIDEO);
    screen=SDL_SetVideoMode(MERET*8+KERET*2, MERET*8+KERET*2, 0, SDL_ANYFORMAT);
    if (!screen) {
        fprintf(stderr, "Nem sikerult megnyitni az ablakot!\n");
        exit(1);
    }
    SDL_WM_SetCaption("SDL kepek", "SDL kepek");

    /* kep betoltese */
    babuk = IMG_Load("pieces.png");
    if (!babuk) {
        fprintf(stderr, "Nem sikerult betolteni a kepfajlt!\n");
        exit(2);
    }

    /* uj allas letrehozasa es kirajzolasa */
    uj_allas(tabla);
    tabla_rajzol(tabla, babuk, screen);
    SDL_Flip(screen);

    while (SDL_WaitEvent(&event) && event.type!=SDL_QUIT) {
    }

    /* nincs mar ra szukseg: felszabaditjuk a memoriat */
    SDL_FreeSurface(babuk);

    SDL_Quit();

    return 0;
}
