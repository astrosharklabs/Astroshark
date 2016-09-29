#include "SDL.h"
#include "SDL_image.h"
#include "textures.h"
#include "sprite.h"
#include "title.h"

void title::setup() {
	prop.texture = astroshark_titleTexture;
	prop.dstrect.w = 740;
	prop.dstrect.h = 95;
	prop.dstrect.x = 640 - prop.dstrect.w / 2;
	prop.dstrect.y = 150;
	prop.alpha = 0;
	SDL_SetTextureAlphaMod(prop.texture, prop.alpha);
}
void title::render(SDL_Renderer *renderer) {
	SDL_RenderCopy(renderer, prop.texture, NULL, &prop.dstrect);
}
void title::fadeIn(SDL_Renderer *renderer, int rate) {
	while (prop.alpha < 255) {
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, prop.texture, NULL, &prop.dstrect);
		SDL_RenderPresent(renderer);
		alphaIncrease(prop.texture, &prop.alpha, 15);
	}
	prop.alpha = 255;
	SDL_SetTextureAlphaMod(prop.texture, prop.alpha);
}

void title::alphaInc(int rate) {
	alphaIncrease(prop.texture, &prop.alpha, rate);
}

void title::alphaDec(int rate) {
	alphaDecrease(prop.texture, &prop.alpha, rate);
}