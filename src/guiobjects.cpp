#include <stdio.h>
#include "SDL.h"
#include "title.h"
#include "camera.h"
#include "buttons.h"
#include "constants.h"

title title_image;
button startgame_button;
button options_button;
button credits_button;
button quit_button;

void GUILoad() {

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

void GUIRender_MainMenu(SDL_Renderer *renderer) {
	bckgrdRender(renderer);
	title_image.render(renderer);
	startgame_button.render(renderer);
	options_button.render(renderer);
	credits_button.render(renderer);
	quit_button.render(renderer);
}
