
#include "loaders.h"
#include <stdbool.h>

void loadBMP(char* name, SDL_Surface* surface) {
	bool success = true;

	//Load splash image
	surface = SDL_LoadBMP( name );
	if( surface == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", name, SDL_GetError() );
		success = false;
	}

	return success;
}
