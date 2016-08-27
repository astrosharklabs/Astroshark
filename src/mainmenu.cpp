#include <stdio.h>
#include "SDL.h"
#include "title.h"

int mainmenu(SDL_Renderer *renderer) {
	title title;
	title.fadeIn(renderer, 15);
	title.display(renderer);
	return 0;
}