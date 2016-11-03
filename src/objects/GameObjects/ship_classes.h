#pragma once
#include "ship_base.h"
#include "../../engine/sprite.h"
#include "SDL.h"

#ifndef ship_classes_h
#define ship_classes_h

enum shipRequestType {MOVE_FORWARD, MOVE_BACKWARD, STRAFE_LEFT, STRAFE_RIGHT, ROTATE_LEFT, ROTATE_RIGHT, SHOOT};
class amadeusShip {
public:
	ship_base ship;
	void initialize();
	void queueRequest(int type);
	void render(SDL_Renderer *renderer);

	void updateState();

	void update();
private:
	animation defaultCycle;
	animation accelCycle;
	animation rotateCycle[4];
	animation moveCycle[4];
	animation currentSRCRECT;
	int state;
};

#endif