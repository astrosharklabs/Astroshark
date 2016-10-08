#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "../../engine/textures.h"
#include "../../engine/sprite.h"

#ifndef title_base_h
#define title_base_h

class title_base {
public:
	void setup();
	void render(SDL_Renderer *renderer); //renders the image at the given location
	void fadeIn(SDL_Renderer *renderer, int rate); //Fades the image out
	void alphaInc(int);
	void alphaDec(int);
private:
	defaultProp prop;
};
#endif