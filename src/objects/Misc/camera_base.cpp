#include "camera_base.h"
#include "background_base.h"

void updateSprites(int deltaX, int deltaY) {
	bckgrdMove(deltaX, deltaY);
}

void camera_base::setup(int x, int y, int w, int h) {
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	timer.setup();
}

void camera_base::setXY(int x, int y) {
	rect.x = x;
	rect.y = y;
}

void camera_base::move(int deltaX, int deltaY) {
	last_deltaX = deltaX;
	last_deltaY = deltaY;
	rect.x += deltaX;
	rect.y += deltaY;

	updateSprites(-deltaX, -deltaY);
}