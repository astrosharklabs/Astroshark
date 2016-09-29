#include <stdio.h>
#include "SDL.h"
#include "input.h"
#include "constants.h"
#include "guiobjects.h"

void mainmenu(SDL_Renderer *renderer) {

	int alphaCounter = 0;
	while (alphaCounter < 255) {
		SDL_RenderClear(renderer);
		GUIRender_MainMenu(renderer);
		SDL_RenderPresent(renderer);
		title_image.alphaInc(15);
		startgame_button.alphaInc(15);
		quit_button.alphaInc(15);
		alphaCounter += 15;
	}

	int current_selection = -1;

	while (STATE == MAIN_MENU) {
		checkInput();

		mainCamera.move(5, -1);

		if (startgame_button.mouseOver() == true)
			current_selection = START_GAME;
		if (options_button.mouseOver() == true)
			current_selection = OPTIONS;
		if (credits_button.mouseOver() == true)
			current_selection = CREDITS;
		if (quit_button.mouseOver() == true)
			current_selection = QUIT;

		if (input::down_key == true)
			current_selection++;
		if (input::up_key == true)
			current_selection--;

		if (current_selection < START_GAME)
			current_selection = QUIT;
		if (current_selection > QUIT)
			current_selection = START_GAME;
		
		switch(current_selection) {
		case START_GAME:
			startgame_button.setFrame(1);
			options_button.setFrame(0);
			credits_button.setFrame(0);
			quit_button.setFrame(0);
			if (input::enter_key == true || input::left_mouse == true)
				STATE = START_GAME;
			break;
		case OPTIONS:
			startgame_button.setFrame(0);
			options_button.setFrame(1);
			credits_button.setFrame(0);
			quit_button.setFrame(0);
			if (input::enter_key == true || input::left_mouse == true)
				STATE = OPTIONS;
			break;
		case CREDITS:
			startgame_button.setFrame(0);
			options_button.setFrame(0);
			credits_button.setFrame(1);
			quit_button.setFrame(0);
			if (input::enter_key == true || input::left_mouse == true)
				STATE = CREDITS;
			break;
		case QUIT:
			startgame_button.setFrame(0);
			options_button.setFrame(0);
			credits_button.setFrame(0);
			quit_button.setFrame(1);
			if (input::enter_key == true || input::left_mouse == true)
				STATE = QUIT;
			break;
		}

		SDL_RenderClear(renderer); //MAKE FUNCTION IN CAMERA.CPP to handle renders within the camera renderSprites() | renderALLSprites()
		GUIRender_MainMenu(renderer); //parallax scrolling for stars/nebulas/galaxies
		SDL_RenderPresent(renderer);
		SDL_Delay(1000 / 10); //fix timer, set clock on which the sprites are update (spriteRefreshTimer) for testing events every 1000 / 10 with 1000 / 60 fps or 1000 / 30 fps 
	}
}