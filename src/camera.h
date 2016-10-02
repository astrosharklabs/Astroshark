#pragma once
#ifndef camera_h
#define camera_h
#include "SDL.h"
#include "timer.h"
class camera {
public:
	SDL_Rect rect;
	timer timer;
	void setup(int, int, int, int);
	int last_deltaX;
	int last_deltaY;
	void setXY(int, int);
	void move(int, int);
};
#endif // !camera_h