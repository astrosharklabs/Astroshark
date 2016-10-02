#include "camera.h"
#include "background.h"

void updateSprites(int deltaX, int deltaY) {
	bckgrdMove(deltaX, deltaY);
}

void camera::setup(int x, int y, int w, int h) {
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	timer.setup();
}

void camera::setXY(int x, int y) {
	rect.x = x;
	rect.y = y;
}

void camera::move(int deltaX, int deltaY) {
	last_deltaX = deltaX;
	last_deltaY = deltaY;
	rect.x += deltaX;
	rect.y += deltaY;

	updateSprites(-deltaX, -deltaY);
}