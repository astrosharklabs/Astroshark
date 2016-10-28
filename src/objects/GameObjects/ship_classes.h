#pragma once
#include "ship_base.h"
#include "../../engine/sprite.h"
#include "SDL.h"

#ifndef ship_classes_h
#define ship_classes_h

class amadeusShip {
public:
	ship_base ship;
	void initialize();
	void render(SDL_Renderer *);
private:
	animation defaultCycle;
	animation transitCycle;
	animation moveCycle[4];
	animation currentSRCRECT;
};

#endif