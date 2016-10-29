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

		if (input::w_key == true) {
			amadeus.queueRequest(MOVE_FORWARD);
		}
		if (input::s_key == true) {
			//amadeus.queueRequest(MOVE_BACKWARD);
		}
		if (input::a_key == true && input::left_key == false) {
			amadeus.queueRequest(ROTATE_LEFT);
		}
		if (input::d_key == true && input::right_key ==false) {
			amadeus.queueRequest(ROTATE_RIGHT);
		}
		if (input::left_key == true) {
			amadeus.queueRequest(ROTATE_LEFT);
		}
		if (input::right_key == true) {
			amadeus.queueRequest(ROTATE_RIGHT);
		}

		mainCamera.move(amadeus.ship.movement.deltaX, amadeus.ship.movement.deltaY);

		amadeus.update();

		SDL_RenderClear(renderer);
		//Render things here
		bckgrdRender(renderer);
		GameObjectsRender_ArcadeMode(renderer);
		SDL_RenderPresent(renderer);
	}
}