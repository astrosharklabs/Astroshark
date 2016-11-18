#include "GameObjects.h"
#include "SDL.h"
#include "GameObjects\ship_classes.h"
#include "GameObjects\asteroid_classes.h"
#include "../engine/constants.h"

amadeusShip amadeus;

standardAsteroid asteroid_small[24];
standardAsteroid asteroid_medium[8];
standardAsteroid asteroid_large[2];

int asteroid_smallTotal;
int asteroid_mediumTotal;
int asteroid_largeTotal;

int i;

void GameObjectsLoad_ArcadeMode() {
	amadeus.initialize();

	asteroid_classes_::arcadeMode_domain.setup(amadeus.ship.arcadeMode_domain.dstrect.x - 400, amadeus.ship.arcadeMode_domain.dstrect.y - 400, amadeus.ship.arcadeMode_domain.dstrect.w + 800, amadeus.ship.arcadeMode_domain.dstrect.h + 800, 0);

	asteroid_smallTotal = sizeof(asteroid_small) / sizeof(asteroid_small[0]);
	asteroid_mediumTotal = sizeof(asteroid_medium) / sizeof(asteroid_medium[0]);
	asteroid_largeTotal = sizeof(asteroid_large) / sizeof(asteroid_large[0]);

	for (i = 0; i < asteroid_smallTotal; i++)
		asteroid_small[i].initialize(asteroid_classes_::SMALL);
	for (i = 0; i < asteroid_mediumTotal; i++)
		asteroid_medium[i].initialize(asteroid_classes_::MEDIUM);
	for (i = 0; i < asteroid_largeTotal; i++)
		asteroid_large[i].initialize(asteroid_classes_::LARGE);
}

void GameObjectsUpdate_ArcadeMode() {
	amadeus.update();

	amadeus.ship.arcadeMode_domain.restrictIn(mainCamera.rect, &mainCamera.deltaX, &mainCamera.deltaY);
	mainCamera.update();

	for (i = 0; i < asteroid_smallTotal; i++) {
		asteroid_small[i].update();
		asteroid_classes_::arcadeMode_domain.restrictTeleportIn(&asteroid_small[i].base.movement.Gdstrect);
	}
	for (i = 0; i < asteroid_mediumTotal; i++) {
		asteroid_medium[i].update();
		asteroid_classes_::arcadeMode_domain.restrictTeleportIn(&asteroid_medium[i].base.movement.Gdstrect);
	}
	for (i = 0; i < asteroid_largeTotal; i++) {
		asteroid_large[i].update();
		asteroid_classes_::arcadeMode_domain.restrictTeleportIn(&asteroid_large[i].base.movement.Gdstrect);
	}

	//Check for collisions
}

void GameObjectsRender_ArcadeMode(SDL_Renderer *renderer) {
	amadeus.render(renderer);

	for (i = 0; i < asteroid_smallTotal; i++)
		asteroid_small[i].render(renderer);
	for (i = 0; i < asteroid_mediumTotal; i++)
		asteroid_medium[i].render(renderer);
	for (i = 0; i < asteroid_largeTotal; i++)
		asteroid_large[i].render(renderer);
}