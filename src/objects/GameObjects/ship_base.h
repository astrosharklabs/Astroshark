#pragma once
#include <SDL.h>
#include "../../engine/sprite.h"
#include "../../engine/textures.h"
#include "../../engine/domain_base.h"

#ifndef ship_base_h
#define ship_base_h

class ship_base {
public:
	void setup(int, int, int, int, SDL_Texture *);
	void render(SDL_Renderer *, SDL_Rect *);
	void setXY(int, int);
	void center();
	void alphaInc(int);
	void alphaDec(int);
	void setAlpha(int);
	void defFrame(int, int, int, int, SDL_Rect *);
	void setFrame(int);
	void setCollision(int, int, int, int);

	void setSpeed(int speed);
	void move(int *deltaX, int *deltaY);
	void rotate(int angle);

	void queueMoveForward();
	void queueMoveBackward();
	void queueStrafeLeft();
	void queueStrafeRight();
	void queueRotateLeft();
	void queueRotateRight();

	void getXY();
	bool isCollide();
	int lives;
	basicMovement movement;
private:
	defaultProp prop;
	collision collision;
	domain_base arcadeMode_domain;
	bool collide;
	bool invincible;
};
#endif
