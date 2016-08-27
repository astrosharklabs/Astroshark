#include <stdio.h>
#include "SDL.h"
#include "title.h"
#include "buttons.h"
int mainmenu(SDL_Renderer *renderer) {
	title title;
	button startgame_button(0, 0, 700, 50);
	startgame_button.setXY(290, 300);
	button quit_button(0, 50, 700, 50);
	quit_button.setXY(290, 350);

	int alphaCounter = 0;
	while (alphaCounter < 255) {
		SDL_RenderClear(renderer);
		title.display(renderer);
		startgame_button.display(renderer);
		quit_button.display(renderer);
		SDL_RenderPresent(renderer);
		title.alphaInc(15);
		startgame_button.alphaInc(15);
		quit_button.alphaInc(15);
		alphaCounter += 15;
	}

	SDL_RenderClear(renderer);
	title.display(renderer);
	startgame_button.display(renderer);
	quit_button.display(renderer);
	SDL_RenderPresent(renderer);
	return 0;
}