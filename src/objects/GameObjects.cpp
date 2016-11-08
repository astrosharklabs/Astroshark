#include "GameObjects.h"
#include "SDL.h"
#include "GameObjects\ship_classes.h"
#include "GameObjects\asteroid_classes.h"

amadeusShip amadeus;

standardAsteroid smallAsteroid[24];
standardAsteroid mediumAsteroid[8];
standardAsteroid largeAsteroid[2];

int i;

void GameObjectsLoad_ArcadeMode() {
	amadeus.initialize();

	for (i = 0; i < 24; i++)
		smallAsteroid[i].initialize(asteroid_classes_::SMALL);
	for (i = 0; i < 8; i++)
		mediumAsteroid[i].initialize(asteroid_classes_::MEDIUM);
	for (i = 0; i < 2; i++)
		largeAsteroid[i].initialize(asteroid_classes_::LARGE);
}

void GameObjectsUpdate_ArcadeMode() {

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