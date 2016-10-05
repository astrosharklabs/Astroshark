#pragma once
#include <SDL.h>
#include "../../engine/sprite.h"
#include "../../engine/textures.h"

#ifndef playerShip_h

class playerShip {
public:
	void setup(int, int, int, int);
	void render(SDL_Renderer *);
	void setXY(int, int);
	void alphaInc(int);
	void alphaDec(int);
	void defFrame(int, int, int, int, int);
	void setFrame(int);
	void setCollision(int, int, int, int);

	void setSpeed(int);
	void move();

	bool isCollide();
	int livesRemaining();
private:
	defaultProp prop;
	basicMovement movement;
	animation frame[6];
	collision collision;
	int lives;
	bool collide;
	bool invincible;
};
#endif
