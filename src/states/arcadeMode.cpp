#include "arcadeMode.h"
#include <stdio.h>
#include <SDL.h>
#include "../engine/input.h"
#include "../engine/constants.h"
#include "../objects/Misc/background_base.h"
#include "../objects/GameObjects.h"

void arcadeMode(SDL_Renderer *renderer) {
	mainCamera.timer.start();
	FPS_timer.start();
	mainCamera.setXY(0, 0);
	amadeus.ship.center();
	//mainCamera.setXY(0, 0);
	//printf("%d, %d\n", mainCamera.rect.w, mainCamera.rect.h);
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
		if (FPS_timer.getCurrentSeconds() >= (1.0 / 60.0)) { //Regulates FPS to 1/60th of a second
			if (input::w_key == true) {
				amadeus.queueRequest(MOVE_FORWARD);
			}
			if (input::s_key == true) {
				//amadeus.queueRequest(MOVE_BACKWARD);
			}
			if (input::a_key == true && input::left_key == false) {
				amadeus.queueRequest(ROTATE_LEFT);
			}
			if (input::d_key == true && input::right_key == false) {
				amadeus.queueRequest(ROTATE_RIGHT);
			}
			if (input::left_key == true) {
				amadeus.queueRequest(ROTATE_LEFT);
			}
			if (input::right_key == true) {
				amadeus.queueRequest(ROTATE_RIGHT);
			}
			if (input::space_key == true) {
				amadeus.queueRequest(SHOOT);
			}

			amadeus.update();

			amadeus.ship.arcadeMode_domain.restrictIn(mainCamera.rect, &mainCamera.deltaX, &mainCamera.deltaY);
			mainCamera.update();
			//printf("hhh%d, %d, %d, %d\n", mainCamera.rect.x, mainCamera.rect.y, mainCamera.rect.w, mainCamera.rect.h);

			SDL_RenderClear(renderer);
			//Render things here
			bckgrdRender(renderer);
			GameObjectsRender_ArcadeMode(renderer);
			SDL_RenderPresent(renderer);

			//printf("%f\n", FPS_timer.getCurrentSeconds());
			FPS_timer.start();
		}
	}

	FPS_timer.stop();
}