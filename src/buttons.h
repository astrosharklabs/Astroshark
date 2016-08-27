#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "textures.h"
#include "sprite.h"

#ifndef buttons_h
#define buttons_h

class button {
public:
	button(int, int, int, int);
	void display(SDL_Renderer *renderer); //Displays the image at the given location
	void fadeIn(SDL_Renderer *renderer, int rate); //Fades the image out
	void setXY(int, int);
	void alphaInc(int);
	void alphaDec(int);
private:
	defaultProp prop;
};
#endif