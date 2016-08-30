#include "camera.h"

void camera::updateXY(int x, int y) {
	deltaX = x;
	deltaY = y;
	rect.x += x;
	rect.y += y;
}