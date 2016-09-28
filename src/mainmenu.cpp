#include <stdio.h>
#include "SDL.h"
#include "title.h"
#include "buttons.h"
#include "input.h"
#include "constants.h"
#include "background.h"

void mainmenu(SDL_Renderer *renderer) {
	title title;
	button startgame_button(290, 325, 700, 50);
	startgame_button.defFrame(0, 0, 700, 50, 0);
	startgame_button.defFrame(700, 0, 700, 50, 1);
	startgame_button.setFrame(0);
	startgame_button.setCollision(0, 325, 1280, 50);
	
	button options_button(290, 375, 700, 50);
	options_button.defFrame(0, 50, 700, 50, 0);
	options_button.defFrame(700, 50, 700, 50, 1);
	options_button.setFrame(0);
	options_button.setCollision(0, 375, 1280, 50);
	
	button credits_button(290, 425, 700, 50);
	credits_button.defFrame(0, 100, 700, 50, 0);
	credits_button.defFrame(700, 100, 700, 50, 1);
	credits_button.setFrame(0);
	credits_button.setCollision(0, 425, 1280, 50);

	button quit_button(290, 475, 700, 50);
	quit_button.defFrame(0, 150, 700, 50, 0);
	quit_button.defFrame(700, 150, 700, 50, 1);
	quit_button.setFrame(0);
	quit_button.setCollision(0, 475, 1280, 50);

	//background background(0, 0, 1920, 1920);

	int alphaCounter = 0;
	while (alphaCounter < 255) {
		SDL_RenderClear(renderer);
		bkgrd[0].render(renderer);
		title.render(renderer);
		startgame_button.render(renderer);
		options_button.render(renderer);
		credits_button.render(renderer);
		quit_button.render(renderer);
		SDL_RenderPresent(renderer);
		title.alphaInc(15);
		startgame_button.alphaInc(15);
		quit_button.alphaInc(15);
		alphaCounter += 15;
	}

	int current_selection = -1;

	while (STATE == MAIN_MENU) {
		checkInput();

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

		SDL_RenderClear(renderer);
		bkgrd[0].render(renderer);
		title.render(renderer);
		startgame_button.render(renderer);
		options_button.render(renderer);
		credits_button.render(renderer);
		quit_button.render(renderer);
		SDL_RenderPresent(renderer);
		SDL_Delay(1000 / 10);
	}
}