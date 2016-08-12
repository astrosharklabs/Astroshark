#include <stdio.h>
#include "SDL.h"
#include "textures.h"
#include "sprite.h"

int mainmenu(SDL_Renderer *renderer) {
	sprite astroshark_title;
	createSprite(renderer, &astroshark_title.dstrect.w, &astroshark_title.dstrect.h, &astroshark_titleTexture, "resources/gfx/astroshark_title_740x95.png");
	astroshark_title.dstrect.x = 640 - astroshark_title.dstrect.w / 2;
	astroshark_title.dstrect.y = 150;
	astroshark_title.alpha = 0;
	while (astroshark_title.alpha < 255) {
		SDL_SetTextureAlphaMod(astroshark_titleTexture, astroshark_title.alpha);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, astroshark_titleTexture, NULL, &astroshark_title.dstrect);
		SDL_RenderPresent(renderer);
		astroshark_title.alpha += 15;
	}
	SDL_SetTextureAlphaMod(astroshark_titleTexture, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, astroshark_titleTexture, NULL, &astroshark_title.dstrect);
	SDL_RenderPresent(renderer);
	return 0;
}