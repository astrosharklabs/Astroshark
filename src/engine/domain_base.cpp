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
		*deltaX = dstrect.x - rect.x;
	}
	if (rect.x + rect.w + *deltaX > dstrect.x + dstrect.w) {
		*deltaX = (dstrect.x + dstrect.w) - (rect.x + rect.w);
	}
	if (rect.y + *deltaY < dstrect.y) {
		*deltaY = dstrect.y - rect.y;
	}
	if (rect.y + rect.h + *deltaY > dstrect.y + dstrect.h) {
		*deltaY = (dstrect.y + dstrect.h) - (rect.y + rect.h);
	}
}

void domain_base::restrictOut(SDL_Rect *rect) {
}

void domain_base::restrictTeleportIn(SDL_Rect *rect) {
	if (rect->x + rect->w < dstrect.x) {
		rect->x = dstrect.x + dstrect.w;
	}
	if (rect->x > dstrect.x + dstrect.w) {
		rect->x = dstrect.x;
	}
	if (rect->y + rect->h < dstrect.y) {
		rect->y = dstrect.y + dstrect.h;
	}
	if (rect->y > dstrect.y + dstrect.h) {
		rect->y = dstrect.y;
	}
}

void domain_base::restrictTeleportOut(SDL_Rect *rect) {
}

void domain_base::restrictBounceIn(SDL_Rect rect) {

}

void domain_base::restrictBounceOut(SDL_Rect rect) {

}