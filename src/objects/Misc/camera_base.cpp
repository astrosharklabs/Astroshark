#include "camera_base.h"
#include "background_base.h"
#include "../GameObjects.h"

void updateSprites(int deltaX, int deltaY) {
	bckgrdMove(deltaX, deltaY);
	//amadeus.ship.move(deltaX, deltaY);
}

void camera_base::setup(int x, int y, int w, int h) {
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	timer.setup();
}

void camera_base::setXY(int x, int y) {
	SDL_Point oldXY;
	oldXY.x = rect.x;
	oldXY.y = rect.y;
	rect.x = x;
	rect.y = y;

	int deltaX = rect.x - oldXY.x;
	int deltaY = rect.y - oldXY.y;

	updateSprites(-1 * deltaX, -1 * deltaY);
}

void camera_base::move(int deltaX, int deltaY) {
	last_deltaX = deltaX;
	last_deltaY = deltaY;
	rect.x += deltaX;
	rect.y += deltaY;

	updateSprites(-deltaX, -deltaY);
}