#pragma once
#ifndef camera_h
#define camera_h
#include "SDL.h"
class camera {
public:
	SDL_Rect rect;
	int deltaX;
	int deltaY;
	void updateXY(int, int);
};
#endif // !camera_h