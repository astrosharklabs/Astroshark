#include "GameObjects.h"
#include "SDL.h"
#include "GameObjects\ship_classes.h"

amadeusShip amadeus;

void GameObjectsLoad_ArcadeMode() {
	amadeus.initialize();
}

void GameObjectsRender_ArcadeMode(SDL_Renderer *renderer) {
	amadeus.render(renderer);
}