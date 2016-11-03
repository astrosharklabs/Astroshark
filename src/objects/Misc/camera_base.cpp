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

	deltaX = rect.x - oldXY.x;
	deltaY = rect.y - oldXY.y;

	updateSprites(-1 * deltaX, -1 * deltaY);
	deltaX = 0;
	deltaY = 0;
}

void camera_base::move(int delta_X, int delta_Y) {
	last_deltaX = delta_X;
	last_deltaY = delta_Y;
	rect.x += delta_X;
	rect.y += delta_Y;

	updateSprites(-delta_X, -delta_Y);
}

void camera_base::update() {
	move(deltaX, deltaY);
	deltaX = 0;
	deltaY = 0;
}