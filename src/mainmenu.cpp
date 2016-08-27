#include <stdio.h>
#include "SDL.h"
#include "title.h"
#include "buttons.h"
#include "input.h"
int mainmenu(SDL_Renderer *renderer) {
	title title;
	button startgame_button(290, 300, 700, 50);
	startgame_button.setFrame(0, 0, 700, 50, 0);
	startgame_button.setFrame(700, 0, 700, 50, 1);
	button quit_button(290, 350, 700, 50);
	quit_button.setFrame(0, 50, 700, 50, 0);
	quit_button.setFrame(700, 50, 700, 50, 1);

	int alphaCounter = 0;
	while (alphaCounter < 255) {
		SDL_RenderClear(renderer);
		title.display(renderer);
		startgame_button.display(renderer, 0);
		quit_button.display(renderer, 1);
		SDL_RenderPresent(renderer);
		title.alphaInc(15);
		startgame_button.alphaInc(15);
		quit_button.alphaInc(15);
		alphaCounter += 15;
	}

	SDL_RenderClear(renderer);
	title.display(renderer);
	startgame_button.display(renderer, 0);
	quit_button.display(renderer, 1);
	SDL_RenderPresent(renderer);
	return 0;
}