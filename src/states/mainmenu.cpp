#include <stdio.h>
#include "SDL.h"
#include "../engine/input.h"
#include "../engine/constants.h"
#include "../objects/GUI.h"
#include "../objects/Misc/background_base.h"

void mainmenu(SDL_Renderer *renderer) {
	mainCamera.timer.start();
	mainCamera.setXY(0, 0);
	int i;
	float keydown_rate = 1;
	int buttonCycle_max = 12;

	int alphaCounter = 0;
	while (alphaCounter < 255) {
		SDL_RenderClear(renderer);
		GUIRender_MainMenu(renderer);
		SDL_RenderPresent(renderer);
		mainMenu.title_image.alphaInc(15);
		mainMenu.startgame_button.alphaInc(15);
		mainMenu.quit_button.alphaInc(15);
		bckgrd[0].alphaInc(15);

		alphaCounter += 15;
	}

	int current_selection = -1;

	/*Debug*/
	/*SDL_Rect debug;
	setRect(0, 0, 10, 10, &debug);
	SDL_Rect debug2;
	setRect(0, 325, 1280, 50, &debug2);
	int mouseX;
	int mouseY;*/
	/*End Debug*/

	while (STATE == MAIN_MENU) {
		checkInput();
		if (mainCamera.timer.getCurrentSeconds() >= (1.0 / 35.0)) { //Regulates camera movement to 1/35th of a second
			mainCamera.move(3, -1);
			mainCamera.timer.start();
		}


		/*Debug*/
		/*SDL_GetMouseState(&mouseX, &mouseY);
		debug.x = mouseX;
		debug.y = mouseY;
		printf("%d, %d\n", debug.x, debug.y);

		if (testCollision(debug, debug2) == true) {
			current_selection = START_GAME;
			if (input::left_mouse == true)
				STATE = START_GAME;
		}*/
		/*End Debug*/
		if (mainMenu.startgame_button.mouseOver() == true) {
			current_selection = START_GAME;
			if (input::left_mouse == true)
				STATE = START_GAME;
		}
		if (mainMenu.options_button.mouseOver() == true) {
			current_selection = OPTIONS;
			if (input::left_mouse == true)
				STATE = OPTIONS;
		}
		if (mainMenu.credits_button.mouseOver() == true) {
			current_selection = CREDITS;
			if (input::left_mouse == true)
				STATE = CREDITS;
		}
		if (mainMenu.quit_button.mouseOver() == true) {
			current_selection = QUIT;
			if (input::left_mouse == true)
				STATE = QUIT;
		}

		if (input::down_key == true) {
			if (GUIkeydown_timer.isStarted() == false) {
				if (current_selection == -1) {
					current_selection = START_GAME;
					GUIkeydown_timer.start();
				}
				else {
					current_selection++;
					GUIkeydown_timer.start();
				}
			}

			if (GUIkeydown_timer.getCurrentSeconds() >= (1.0 / keydown_rate)) {
				current_selection++;
				GUIkeydown_timer.start();
				if (keydown_rate <= buttonCycle_max)
					keydown_rate += 1;
			}
		}

		if (input::up_key == true) {
			if (GUIkeydown_timer.isStarted() == false) {
				if (current_selection == -1){
					current_selection = QUIT;
					GUIkeydown_timer.start();
				}
				else {
					current_selection--;
					GUIkeydown_timer.start();
				}
			}

			if (GUIkeydown_timer.getCurrentSeconds() >= (1.0 / keydown_rate)) {
				current_selection--;
				GUIkeydown_timer.start();
				if (keydown_rate <= buttonCycle_max)
					keydown_rate += 1;
			}
		}
		if (input::up_key == false && input::down_key == false) {
			GUIkeydown_timer.stop();
			keydown_rate = 1;
		}

		if (current_selection != -1) {
			if (current_selection < START_GAME)
				current_selection = QUIT;
			if (current_selection > QUIT)
				current_selection = START_GAME;
		}

		switch(current_selection) {
		case START_GAME:
			mainMenu.startgame_button.highlighted();
			if (input::enter_key == true)
				STATE = START_GAME;
			break;
		case OPTIONS:
			mainMenu.options_button.highlighted();
			if (input::enter_key == true)
				STATE = OPTIONS;
			break;
		case CREDITS:
			mainMenu.credits_button.highlighted();
			if (input::enter_key == true)
				STATE = CREDITS;
			break;
		case QUIT:
			mainMenu.quit_button.highlighted();
			if (input::enter_key == true)
				STATE = QUIT;
			break;
		default:
			break;
		}

		SDL_RenderClear(renderer);
		//Render things here
		GUIRender_MainMenu(renderer); //parallax scrolling for stars/nebulas/galaxies
		SDL_RenderPresent(renderer);
		//SDL_Delay(1000 / 10); //fix timer, set clock on which the sprites are update (spriteRefreshTimer) for testing events every 1000 / 10 with 1000 / 60 fps or 1000 / 30 fps 
	}

	GUIkeydown_timer.stop();

	/*Fade Out*/
	while (alphaCounter > 0) {
		SDL_RenderClear(renderer);
		GUIRender_MainMenu(renderer);
		SDL_RenderPresent(renderer);
		mainMenu.title_image.alphaDec(15);
		mainMenu.startgame_button.alphaDec(15);
		mainMenu.quit_button.alphaDec(15);
		bckgrd[0].alphaDec(15);

		alphaCounter -= 15;
	}
}