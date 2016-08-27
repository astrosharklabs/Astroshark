#include "SDL.h"
#include "SDL_image.h"
#include "textures.h"
#include "sprite.h"
#include "buttons.h"

button::button(int dstX, int dstY, int dstW, int dstH) {
	prop.texture = buttons_texture;

	prop.dstrect.x = dstX;
	prop.dstrect.y = dstY;
	prop.dstrect.w = dstW;
	prop.dstrect.h = dstH;

	prop.alpha = 0;
	SDL_SetTextureAlphaMod(prop.texture, prop.alpha);
}

void button::display(SDL_Renderer *renderer, int frameN) {
	SDL_RenderCopy(renderer, prop.texture, &frame[frameN].srcrect, &prop.dstrect);
}

void button::fadeIn(SDL_Renderer *renderer, int rate, int frameN) {
	while (prop.alpha < 255) {
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, prop.texture, &frame[frameN].srcrect, &prop.dstrect);
		SDL_RenderPresent(renderer);
		alphaIncrease(prop.texture, &prop.alpha, 15);
	}
	prop.alpha = 255;
	SDL_SetTextureAlphaMod(prop.texture, prop.alpha);
}

void button::setXY(int dstX, int dstY) {
	setRect(dstX, dstY, NULL, NULL, &prop.dstrect.x, &prop.dstrect.y, NULL, NULL);
}

void button::alphaInc(int rate) {
	alphaIncrease(prop.texture, &prop.alpha, rate);
}

void button::alphaDec(int rate) {
	alphaDecrease(prop.texture, &prop.alpha, rate);
}

void button::setFrame(int srcX, int srcY, int srcW, int srcH, int frameN) {
	setRect(srcX, srcY, srcW, srcH, &frame[frameN].srcrect.x, &frame[frameN].srcrect.y, &frame[frameN].srcrect.w, &frame[frameN].srcrect.h);
}