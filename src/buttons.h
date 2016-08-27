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
	void display(SDL_Renderer *, int); //Displays the image at the given location
	void fadeIn(SDL_Renderer *, int, int); //Fades the image out
	void setXY(int, int);
	void alphaInc(int);
	void alphaDec(int);
	void setFrame(int, int, int, int, int);
private:
	defaultProp prop;
	animation frame[2];
};
#endif