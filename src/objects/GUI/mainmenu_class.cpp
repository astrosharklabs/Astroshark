#include <SDL.h>
#include "mainmenu_class.h"
#include "button_base.h"
#include "title_base.h"
#include "../Misc/background_base.h"
#include "../../engine/constants.h"

void mainMenu_class::initialize() {
	title_image.setup();

	startgame_button.setup(290, 325, 700, 50);
	startgame_button.defFrame(0, 0, 700, 50, 0);
	startgame_button.defFrame(700, 0, 700, 50, 1);
	startgame_button.setFrame(0);
	startgame_button.setCollision(0, 325, 1280, 50);

	options_button.setup(290, 375, 700, 50);
	options_button.defFrame(0, 50, 700, 50, 0);
	options_button.defFrame(700, 50, 700, 50, 1);
	options_button.setFrame(0);
	options_button.setCollision(0, 375, 1280, 50);

	credits_button.setup(290, 425, 700, 50);
	credits_button.defFrame(0, 100, 700, 50, 0);
	credits_button.defFrame(700, 100, 700, 50, 1);
	credits_button.setFrame(0);
	credits_button.setCollision(0, 425, 1280, 50);

	quit_button.setup(290, 475, 700, 50);
	quit_button.defFrame(0, 150, 700, 50, 0);
	quit_button.defFrame(700, 150, 700, 50, 1);
	quit_button.setFrame(0);
	quit_button.setCollision(0, 475, 1280, 50);
}

void mainMenu_class::render(SDL_Renderer *renderer) {
	bckgrdRender(renderer);
	title_image.render(renderer);
	startgame_button.render(renderer);
	options_button.render(renderer);
	credits_button.render(renderer);
	quit_button.render(renderer);
}