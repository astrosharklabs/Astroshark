#include "domain_base.h"
#include <stdio.h>

void domain_base::setup(int x, int y, int w, int h, int mode) {
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = w;
	dstrect.h = h;

	restrictMode = mode;
	//printf("%d, %d, %d, %d\n", x, y, w, h);
}

void domain_base::setXY(int x, int y) {
}

void domain_base::move(int x, int y) {
}

void domain_base::restrictIn(SDL_Rect rect, int *deltaX, int *deltaY) {
	//printf("%d, %d, %d, %d\n", dstrect.x, dstrect.y, dstrect.w, dstrect.h);
	if (rect.x + *deltaX < dstrect.x) {
		*deltaX = 0;
	}
	if (rect.x + rect.w + *deltaX > dstrect.x + dstrect.w) {
		*deltaX = 0;
	}
	if (rect.y + *deltaY < dstrect.y) {
		*deltaY = 0;
	}
	if (rect.y + rect.h + *deltaY > dstrect.y + dstrect.h) {
		*deltaY = 0;
	}
}

void domain_base::restrictOut(SDL_Rect *rect) {
}

void domain_base::restrictTeleportIn(SDL_Rect *rect) {
}

void domain_base::restrictTeleportOut(SDL_Rect *rect) {
}