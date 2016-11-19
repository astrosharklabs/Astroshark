#pragma once
#include <SDL.h>
#include "laser_base.h"
#include "../../engine/sprite.h"

#ifndef laser_classes_h
#define laser_classes_h

class standardLaser {
public:
	laser_base laser;
	void initialize();
	void render(SDL_Renderer *renderer);

	void updateStates();

	void update();

	void activate();
	void deactivate();

	bool isActive;
	bool isAvailable;
private:
	animation moveCycle[3];
	animation collisionCycle[3];
	animation currentSRCRECT;
	int state;
};

#endif