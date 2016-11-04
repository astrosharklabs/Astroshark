#include "GameObjects.h"
#include "SDL.h"
#include "GameObjects\ship_classes.h"
#include "GameObjects\laser_classes.h"

amadeusShip amadeus;
standardLaser laser_01;

void GameObjectsLoad_ArcadeMode() {
	amadeus.initialize();
	laser_01.initialize();
}

void GameObjectsRender_ArcadeMode(SDL_Renderer *renderer) {
	amadeus.render(renderer);
	laser_01.render(renderer);
}