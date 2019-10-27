#include "game.h"
#include "event_codes.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <sys/time.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool initialize();
void stop();

SDL_Window* gWindow = NULL;

bool initialize()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    } else {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL ) {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
    }

	init();

    return success;
}

void stop()
{
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !initialize() ) {
        printf( "Failed to initialize!\n" );
        return 1;
    }

    bool quit = false;

    SDL_Event e;

    int frame = 0;
    double prevTime = 0;

    while ( !quit ) {
        int result;
        do {
            result = SDL_PollEvent(&e);
            int code = events(&e);
            switch (code) {
                case CODE_QUIT:
                    quit = true;
            }
        } while ( result != 0 );

        struct timeval tv;
        gettimeofday(&tv, NULL);

        double time = (double)tv.tv_usec / 1e6;
        double dt = time - prevTime;

        if ( dt < 0 ) {
            dt = (time + 1) - prevTime;
        }

        loop(gWindow, dt, frame);

        prevTime = time;

        //Update the surface
        SDL_UpdateWindowSurface( gWindow );

        frame ++;
    }

    //Free resources and close SDL
    close();

    return 0;
}
