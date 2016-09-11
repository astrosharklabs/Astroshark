#pragma once
#include "SDL.h"
#include "sprite.h"
#include "textures.h"

#ifndef background_h
#define background_h

class background {
public:
	background(int, int, int, int);
	void render(SDL_Renderer *);
	void setXY(int, int);
private:
	defaultProp prop;
	int tile;
};

extern int tileNumber;
#endif