#ifndef LOOP_H
#define LOOP_H

#include <SDL.h>

int event(SDL_Event* event);

void loop(SDL_Window* window, double dt, int frame);

#endif
