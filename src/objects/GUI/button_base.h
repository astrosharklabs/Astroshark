#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "../../engine/sprite.h"

#ifndef buttons_base_h
#define button_base_h

class button_base {
public:
	void setup(int, int, int, int);
	void render(SDL_Renderer *); //renders the image at the given location
	void fadeIn(SDL_Renderer *, int); //Fades the image out
	void setXY(int, int);
	void alphaInc(int);
	void alphaDec(int);
	void defFrame(int, int, int, int, int);
	void setFrame(int);
	void setCollision(int, int, int, int);
	bool mouseOver();
private:
	defaultProp prop;
	animation frame[2];
	collision collision;
};
#endif