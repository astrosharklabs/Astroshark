#pragma once
#include "SDL.h"
#include "../engine/sprite.h"

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
	void alphaInc(int);
	void alphaDec(int);
	defaultProp prop;
};

void bckgrdLoad();
void bckgrdRender(SDL_Renderer *);
void bckgrdUpdate();
void bckgrdMove(int, int);
#endif