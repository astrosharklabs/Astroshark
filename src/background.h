#pragma once
#include "SDL.h"
#include "sprite.h"
#include "textures.h"

#ifndef background_h
#define background_h

class background {
public:
	void setup(int, int, int, int);
	void render(SDL_Renderer *);
	void setXY(int, int);
private:
	defaultProp prop;
	basicMove move;
	int tile;
};

void loadBackgrounds();
void renderBackgrounds(SDL_Renderer *);
#endif