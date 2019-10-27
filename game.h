#ifndef INIT_H
#define INIT_H

#include <SDL.h>

void init();
int event(SDL_Event* event);
void loop(SDL_Renderer* renderer, double dt, int frame);

#endif
