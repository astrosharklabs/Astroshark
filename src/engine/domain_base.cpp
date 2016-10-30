#include "domain_base.h"

void domain_base::setup(int x, int y, int w, int h, int mode) {
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	restrictMode = mode;
}

void domain_base::setXY(int x, int y) {
}

void domain_base::move(int x, int y) {
}

void domain_base::restrictIn(SDL_Rect *rect) {
}

void domain_base::restrictOut(SDL_Rect *rect) {
}

void domain_base::restrictTeleportIn(SDL_Rect *rect) {
}

void domain_base::restrictTeleportOut(SDL_Rect *rect) {
}