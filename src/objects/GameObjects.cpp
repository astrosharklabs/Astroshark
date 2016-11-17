#include "GameObjects.h"
#include "SDL.h"
#include "GameObjects\ship_classes.h"
#include "GameObjects\asteroid_classes.h"
#include "../engine/constants.h"

amadeusShip amadeus;

standardAsteroid smallAsteroid[24];
standardAsteroid mediumAsteroid[8];
standardAsteroid largeAsteroid[2];

int i;

void GameObjectsLoad_ArcadeMode() {
	amadeus.initialize();

	asteroid_classes_::arcadeMode_domain.setup(amadeus.ship.arcadeMode_domain.dstrect.x - 400, amadeus.ship.arcadeMode_domain.dstrect.y - 400, amadeus.ship.arcadeMode_domain.dstrect.w + 800, amadeus.ship.arcadeMode_domain.dstrect.h + 800, 0);

	for (i = 0; i < 24; i++)
		smallAsteroid[i].initialize(asteroid_classes_::SMALL);
	for (i = 0; i < 8; i++)
		mediumAsteroid[i].initialize(asteroid_classes_::MEDIUM);
	for (i = 0; i < 2; i++)
		largeAsteroid[i].initialize(asteroid_classes_::LARGE);
}

void GameObjectsUpdate_ArcadeMode() {
	amadeus.update();

	amadeus.ship.arcadeMode_domain.restrictIn(mainCamera.rect, &mainCamera.deltaX, &mainCamera.deltaY);
	mainCamera.update();

	for (i = 0; i < 24; i++)
		smallAsteroid[i].update();
	for (i = 0; i < 8; i++)
		mediumAsteroid[i].update();
	for (i = 0; i < 2; i++)
		largeAsteroid[i].update();
}

void GameObjectsRender_ArcadeMode(SDL_Renderer *renderer) {
	amadeus.render(renderer);

	for (i = 0; i < 24; i++)
		smallAsteroid[i].render(renderer);
	for (i = 0; i < 8; i++)
		mediumAsteroid[i].render(renderer);
	for (i = 0; i < 2; i++)
		largeAsteroid[i].render(renderer);
}