#pragma once
#include <SDL.h>
#include "../../engine/sprite.h"
#include "../../engine/textures.h"

#ifndef ship_base_h
#define ship_base_h

class ship_base {
public:
	void setup(int, int, int, int, SDL_Texture *);
	void render(SDL_Renderer *, SDL_Rect *);
	void setXY(int, int);
	void alphaInc(int);
	void alphaDec(int);
	void setAlpha(int);
	void defFrame(int, int, int, int, SDL_Rect *);
	void setFrame(int);
	void setCollision(int, int, int, int);

	void setSpeed(int);
	void move();

	bool isCollide();
	int livesRemaining();
private:
	defaultProp prop;
	basicMovement movement;
	collision collision;
	int lives;
	bool collide;
	bool invincible;
};
#endif
