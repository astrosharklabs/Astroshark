#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "textures.h"
#include "sprite.h"

#ifndef title_h
#define title_h

class title {
public:
	title();
	void display(SDL_Renderer *renderer); //Displays the image at the given location
	void fadeIn(SDL_Renderer *renderer, int rate); //Fades the image out
	void alphaInc(int);
	void alphaDec(int);
private:
	defaultProp prop;
};
#endif