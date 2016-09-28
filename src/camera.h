#pragma once
#ifndef camera_h
#define camera_h
#include "SDL.h"
class camera {
public:
	SDL_Rect rect;
	int last_deltaX;
	int last_deltaY;
	void setXY(int, int);
	void move(int, int);
};
#endif // !camera_h