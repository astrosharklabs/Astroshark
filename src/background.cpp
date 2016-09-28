#include "background.h"
#include "SDL.h"
#include "textures.h"
#include "constants.h"
#include "sprite.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

void background::setup(int x, int y, int w, int h) {
	prop.dstrect.x = x;
	prop.dstrect.y = y;
	prop.dstrect.w = w;
	prop.dstrect.h = h;

	std::srand(std::time(0));

	prop.defaultOrientation = std::rand() % 4;
	prop.defaultOrientation *= 90;
}

void background::setXY(int x, int y) {
	prop.dstrect.x = x - mainCamera.rect.x;
	prop.dstrect.y = y - mainCamera.rect.y;
}

void background::render(SDL_Renderer *renderer) {
	SDL_RenderCopyEx(renderer, background_texture, NULL, &prop.dstrect, prop.defaultOrientation, NULL, SDL_FLIP_NONE);
}

void loadBackgrounds() {
	int i;
	i = 0;
	int x, y;
	x = -1920;
	y = -1920;
	while (i <= 2) {
		bkgrd[i].setup(x, y, 1920, 1920);
		x += 1920;
		i++;
	}
	x = -1920;
	y = 0;
	while (i > 2 && i <= 5) {
		bkgrd[i].setup(x, y, 1920, 1920);
		x += 1920;
		i++;
	}
	x = -1920;
	y = 1920;
	while (i > 5 && i <= 8) {
		bkgrd[i].setup(x, y, 1920, 1920);
		x += 1920;
		i++;
	}
}

void renderBackgrounds(SDL_Renderer *renderer) {
	int i;
	for (i = 0; i < 8; i++) {
		bkgrd[i].render(renderer);
	}
}