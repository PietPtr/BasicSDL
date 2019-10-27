
#include "loaders.h"
#include <stdbool.h>

SDL_Surface* loadBMP(char* name)
{
    SDL_Surface* surface = SDL_LoadBMP( name );
    if( surface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", name, SDL_GetError() );
        return NULL;
    }
    printf("loading %c", name);

    return surface;
}
