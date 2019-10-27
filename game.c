
#include "game.h"
#include "loaders.h"
#include "event_codes.h"
#include <stdbool.h>
#include <math.h>

SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

void init()
{
    gHelloWorld = loadBMP("resources/hello_world.bmp");
}

int events(SDL_Event* event)
{
    if ( event->window.type == SDL_QUIT ) {
        return CODE_QUIT;
    } else {
        return CODE_NONE;
    }
}

void loop(SDL_Window* window, double dt, int frame)
{
    gScreenSurface = SDL_GetWindowSurface( window );

    SDL_Rect dstrect;
	dstrect.x = sin((double)frame / 100) * 100;
	dstrect.y = 0;

    SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, &dstrect);

    if ( frame % 60 == 0 ) {
        printf("%f\n", 1 / dt);
    }
}
