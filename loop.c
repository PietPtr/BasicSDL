
#include "loop.h"
#include "event_codes.h"
#include <stdbool.h>

int events(SDL_Event* event) {
    if (event->window.type == SDL_QUIT) {
        return CODE_QUIT;
    } else {
        return CODE_NONE;
    }
}


SDL_Surface* gScreenSurface = NULL;


void loop(SDL_Window* window, double dt, int frame) {
    gScreenSurface = SDL_GetWindowSurface( window );

    int test = 1;
    test++;
}
