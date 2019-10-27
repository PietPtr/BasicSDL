
#include "game.h"
#include "loaders.h"
#include "event_codes.h"
#include <stdbool.h>


SDL_Surface* gScreenSurface = NULL;

void init() {

}

int events(SDL_Event* event) {
    if (event->window.type == SDL_QUIT) {
        return CODE_QUIT;
    } else {
        return CODE_NONE;
    }
}

void loop(SDL_Window* window, double dt, int frame) {
    gScreenSurface = SDL_GetWindowSurface( window );

    if (frame % 60 == 0) {
        printf("%f\n", 1 / dt);
    }
}
