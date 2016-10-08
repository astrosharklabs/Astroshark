#pragma once
#include "SDL.h"
#include "../../engine/sprite.h"

#ifndef background_base_h
#define background_base_h

extern SDL_Point bckgrdOrigin;
extern int bckgrdOrder[4];

class background_base {
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