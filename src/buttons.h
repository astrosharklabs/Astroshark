#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "textures.h"
#include "sprite.h"

#ifndef buttons_h
#define buttons_h
enum selection {START_GAME, QUIT};

class button {
public:
	button(int, int, int, int);
	void display(SDL_Renderer *); //Displays the image at the given location
	void fadeIn(SDL_Renderer *, int); //Fades the image out
	void setXY(int, int);
	void alphaInc(int);
	void alphaDec(int);
	void defFrame(int, int, int, int, int);
	void setFrame(int);
private:
	defaultProp prop;
	animation frame[2];
};
#endif