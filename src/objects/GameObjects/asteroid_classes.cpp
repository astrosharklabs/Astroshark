#include "asteroid_classes.h"
#include <SDL.h>
#include "../../engine/constants.h"
#include "../../engine/textures.h"
#include "../../engine/sprite.h"
#include "../../engine/domain_base.h"
#include <iostream>

enum status{ STOPPED, MOVING, COLLISION };

domain_base asteroid_classes_::arcadeMode_domain;

void standardAsteroid::initialize(int asteroidSize) {
	int dim;
	size = asteroidSize;
	if (size == asteroid_classes_::LARGE)
		dim = (rand() % 50) + 400;
	if (size == asteroid_classes_::MEDIUM)
		dim = (rand() % 50) + 200;
	if (size == asteroid_classes_::SMALL)
		dim = (rand() % 50) + 50;
	base.setup(0, 0, dim, dim, asteroidSpritesheet_texture);

	dim = rand() % 3 * 640;
	base.defFrame(dim, 0, 640, 640, &currentSRCRECT.srcrect);

	base.rotate(rand() % 360);

	while (testCollision(base.movement.Gdstrect, asteroid_classes_::arcadeMode_domain.dstrect) == false || testCollision(base.movement.Gdstrect, mainCamera.rect) == true) {
		base.setXY((rand() % asteroid_classes_::arcadeMode_domain.dstrect.w) - 200, (rand() % asteroid_classes_::arcadeMode_domain.dstrect.h) - 200);
	}

	//std::cout << base.movement.Gdstrect.x << " " << base.movement.Gdstrect.y << std::endl;

	while (base.movement.deltaX == 0) {
		base.movement.deltaX = (rand() % 20) - 10;
	}
	while (base.movement.deltaY == 0) {
		base.movement.deltaY = (rand() % 20) - 10;
	}

	while (base.movement.deltaAngle == 0) {
		base.movement.deltaAngle = rand() % 3 - 1;
	}

	base.rotateRate = (rand() % 59) + 1;
	
	/*If the asteroid size is large, it gets a slower rotation speed*/
	if (size == asteroid_classes_::LARGE)
		base.rotateRate = (rand() % 29) + 1;

	state = STOPPED;

	base.rotateTimer.start();
}

void standardAsteroid::render(SDL_Renderer *renderer) {
	//if (state != STOPPED)
		base.render(renderer, &currentSRCRECT.srcrect);
}

void standardAsteroid::update() {
	base.move(&base.movement.deltaX, &base.movement.deltaY);

	/*Rotates on a timer*/
	if (base.rotateTimer.getCurrentSeconds() >= (1.0 / (float)base.rotateRate)) {
		base.rotate(base.movement.deltaAngle);
		base.rotateTimer.start();
	}
}