#pragma once
#include <SDL.h>
#include "../../engine/sprite.h"
#include "../../engine/domain_base.h"

#ifndef laser_base_h
#define laser_base_h

class laser_base {
public:
	void setup(int dstX, int dstY, int dstW, int dstH, SDL_Texture *texture);
	void render(SDL_Renderer *renderer, SDL_Rect *srcrect);
	void setXY(int dstX, int dstY);
	void setOrigin(int dstX, int dstY);
	void alphaInc(int rate);
	void alphaDec(int rate);
	void setAlpha(int a);
	void defFrame(int srcX, int srcY, int srcW, int srcH, SDL_Rect *srcrect);
	void setFrame(int frameN);

	void setSpeed(int speed);
	void move(int *deltaX, int *deltaY);
	void rotate(int deltaAngle);

	void fire(int angle, SDL_Rect dstrect);

	int getW();
	basicMovement movement;
	collision collision;
private:
	defaultProp prop;
	domain_base arcadeMode_domain;
};

#endif