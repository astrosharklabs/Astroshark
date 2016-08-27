#include "SDL.h"
#include "SDL_image.h"
#include "textures.h"
#include "sprite.h"
#include "buttons.h"

button::button(int srcX, int srcY, int srcW, int srcH) {
	prop.texture = buttons_texture;

	prop.dstrect.w = srcW;
	prop.dstrect.h = srcH;
	prop.dstrect.x = 640 - prop.dstrect.w / 2;
	prop.dstrect.y = 250;

	prop.srcrect.x = srcX;
	prop.srcrect.y = srcY;
	prop.srcrect.w = srcW;
	prop.srcrect.h = srcH;
	prop.alpha = 0;
	SDL_SetTextureAlphaMod(prop.texture, prop.alpha);
}

void button::display(SDL_Renderer *renderer) {
	SDL_RenderCopy(renderer, prop.texture, &prop.srcrect, &prop.dstrect);
}

void button::fadeIn(SDL_Renderer *renderer, int rate) {
	while (prop.alpha < 255) {
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, prop.texture, &prop.srcrect, &prop.dstrect);
		SDL_RenderPresent(renderer);
		alphaIncrease(prop.texture, &prop.alpha, 15);
	}
	prop.alpha = 255;
	SDL_SetTextureAlphaMod(prop.texture, prop.alpha);
}

void button::setXY(int dstX, int dstY) {
	if (dstX != NULL)
		prop.dstrect.x = dstX;
	if (dstY != NULL)
		prop.dstrect.y = dstY;
}

void button::alphaInc(int rate) {
	alphaIncrease(prop.texture, &prop.alpha, rate);
}

void button::alphaDec(int rate) {
	alphaDecrease(prop.texture, &prop.alpha, rate);
}