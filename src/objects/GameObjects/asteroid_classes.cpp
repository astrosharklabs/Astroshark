#include "asteroid_classes.h"
#include <SDL.h>
#include "../../engine/constants.h"
#include "../../engine/textures.h"
#include <iostream>

enum status{ STOPPED, MOVING, COLLISION };

void standardAsteroid::initialize(int asteroidSize) {
	int dim;
	size = asteroidSize;
	if (size == asteroid_classes_::LARGE)
		dim = (rand() % 50) + 200;
	if (size == asteroid_classes_::MEDIUM)
		dim = (rand() % 50) + 100;
	if (size == asteroid_classes_::SMALL)
		dim = rand() % 50;
	asteroid.setup(0, 0, dim, dim, asteroidSpritesheet_texture);

	dim = rand() % 3 * 640;
	asteroid.defFrame(dim, 0, 640, 640, &currentSRCRECT.srcrect);

	asteroid.rotate(rand() % 360);

	state = STOPPED;
}

void standardAsteroid::render(SDL_Renderer *renderer) {
	//if (state != STOPPED)
		asteroid.render(renderer, &currentSRCRECT.srcrect);
}

void standardAsteroid::update() {

}