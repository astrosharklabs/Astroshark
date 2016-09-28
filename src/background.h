#pragma once
#include "SDL.h"
#include "sprite.h"
#include "textures.h"

#ifndef background_h
#define background_h

extern SDL_Point bckgrdOrigin;
extern int bckgrdOrder[4];

class background {
public:
	void setup(int, int, int, int);
	void render(SDL_Renderer *);
	void setXY(int, int);
	void orientate(int);
	int designation;
	defaultProp prop;
	basicMove move;
};

void bckgrdLoad();
void bckgrdRender(SDL_Renderer *);
void bckgrdUpdate();
void bckgrdMove(int, int);
#endif