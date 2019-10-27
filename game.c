
#include "game.h"
#include "loaders.h"
#include "consts.h"
#include <stdbool.h>
#include <math.h>

SDL_Surface* screen = NULL;
SDL_Texture* tHello = NULL;

void init()
{
    tHello = loadBMP("resources/hello_world.bmp");
}

int events(SDL_Event* event)
{
    if ( event->window.type == SDL_QUIT ) {
        return CODE_QUIT;
    } else {
        return CODE_NONE;
    }
}

void loop(SDL_Renderer* renderer, double dt, int frame)
{
    // screen = SDL_GetWindowSurface( window );

    SDL_Rect dstrect;
	dstrect.x = sin((double)frame / 6000) * 100;
	dstrect.y = 0;
    dstrect.w = SCREEN_WIDTH;
    dstrect.h = SCREEN_HEIGHT;

    // SDL_BlitSurface(bmpHello, NULL, screen, &dstrect);
    SDL_RenderCopy(renderer, tHello, NULL, &dstrect);

    if ( frame % 1000 == 0 ) {
        printf("%f\n", 1 / dt);
    }
}
