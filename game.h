#ifndef INIT_H
#define INIT_H

#include <SDL.h>

void init();

int event(SDL_Event* event);

void loop(SDL_Window* window, double dt, int frame);

#endif
