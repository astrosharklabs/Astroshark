#include "arcadeMode.h"
#include <SDL.h>
#include "../engine/input.h"
#include "../engine/constants.h"
#include "../objects/Misc/background_base.h"
#include "../objects/GameObjects.h"

void arcadeMode(SDL_Renderer *renderer) {
	mainCamera.timer.start();
	mainCamera.setXY(0, 0);
	int i;

	/*Fade In*/
	int alphaCounter = 0;
	while (alphaCounter < 255) {
		SDL_RenderClear(renderer);
		//Render
		bckgrdRender(renderer);
		GameObjectsRender_ArcadeMode(renderer);
		SDL_RenderPresent(renderer);
		//Change Alpha

		bckgrd[0].alphaInc(15);
		amadeus.ship.alphaInc(15);

		alphaCounter += 15;
	}

	amadeus.ship.setAlpha(255);

	while (STATE == START_GAME) {
		checkInput();
		SDL_RenderClear(renderer);
		//Render things here
		bckgrdRender(renderer);
		GameObjectsRender_ArcadeMode(renderer);
		SDL_RenderPresent(renderer);
	}
}