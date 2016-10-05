#include "arcadeMode.h"
#include <SDL.h>
#include "../engine/input.h"
#include "../engine/constants.h"
#include "../objects/background.h"

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
		SDL_RenderPresent(renderer);
		//Change Alpha

		for (i = 0; i < 4; i++)
			bckgrd[i].alphaInc(15);

		alphaCounter += 15;
	}

	while (STATE == START_GAME) {
		checkInput();

		SDL_RenderClear(renderer);
		//Render things here
		bckgrdRender(renderer);
		SDL_RenderPresent(renderer);
	}
}