#pragma once
#ifndef camera_base_h
#define camera_base_h
#include "SDL.h"
#include "../../engine/timer.h"
class camera_base {
public:
	SDL_Rect rect;
	timer timer;
	void setup(int, int, int, int);
	int last_deltaX;
	int last_deltaY;
	void setXY(int, int);
	void move(int, int);
	void update();
	int deltaX;
	int deltaY;
};
#endif // !camera_h