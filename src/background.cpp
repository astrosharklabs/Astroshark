#include "background.h"
#include "SDL.h"
#include "textures.h"
#include "constants.h"
#include "sprite.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

int tileNumber = 0;

void background::setup(int x, int y, int w, int h) {
	prop.dstrect.x = x;
	prop.dstrect.y = y;
	prop.dstrect.w = w;
	prop.dstrect.h = h;

	tile = tileNumber;
	tileNumber++;
	std::srand(std::time(0));

	prop.defaultOrientation = std::rand() % 4;
	prop.defaultOrientation *= 90;
}

void background::render(SDL_Renderer *renderer) {
	SDL_RenderCopyEx(renderer, background_texture, NULL, &prop.dstrect, prop.defaultOrientation, NULL, SDL_FLIP_NONE);
}