#include <stdio.h>
#include <SDL2/SDL.h>

int main (int argc, char * argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) printf ("\nCouldn't initialize! SDL Error %s\n\n", SDL_GetError());
    return EXIT_SUCCESS;
}
