#include "SDL.h"
#include "SDL_image.h"
#include "../../engine/textures.h"
#include "../../engine/sprite.h"
#include "buttons.h"
#include "../../engine/input.h"

void button::setup(int dstX, int dstY, int dstW, int dstH) {
	prop.texture = buttons_texture;

	prop.dstrect.x = dstX;
	prop.dstrect.y = dstY;
	prop.dstrect.w = dstW;
	prop.dstrect.h = dstH;

	collision.hitbox.x = dstX;
	collision.hitbox.y = dstY;
	collision.hitbox.w = dstW;
	collision.hitbox.h = dstH;

	prop.frame = 0;

	prop.alpha = 0;
	SDL_SetTextureAlphaMod(prop.texture, prop.alpha);
}

void button::render(SDL_Renderer *renderer) {
	SDL_RenderCopy(renderer, prop.texture, &frame[prop.frame].srcrect, &prop.dstrect);
}

void button::fadeIn(SDL_Renderer *renderer, int rate) {
	while (prop.alpha < 255) {
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, prop.texture, &frame[prop.frame].srcrect, &prop.dstrect);
		SDL_RenderPresent(renderer);
		alphaIncrease(prop.texture, &prop.alpha, 15);
	}
	prop.alpha = 255;
	SDL_SetTextureAlphaMod(prop.texture, prop.alpha);
}

void button::setXY(int dstX, int dstY) {
	setRect(dstX, dstY, NULL, NULL, &prop.dstrect);
}

void button::alphaInc(int rate) {
	alphaIncrease(prop.texture, &prop.alpha, rate);
}

void button::alphaDec(int rate) {
	alphaDecrease(prop.texture, &prop.alpha, rate);
}

void button::defFrame(int srcX, int srcY, int srcW, int srcH, int frameN) {
	setRect(srcX, srcY, srcW, srcH, &frame[frameN].srcrect);
}

void button::setFrame(int frameN) {
	prop.frame = frameN;
}

void button::setCollision(int x, int y, int w, int h) {
	setRect(x, y, w, h, &collision.hitbox);
}

bool button::mouseOver() {
	SDL_GetMouseState(&input::mouseX, &input::mouseY);

	if (input::mouseX < collision.hitbox.x)
		return false;
	if (input::mouseX > collision.hitbox.x + collision.hitbox.w)
		return false;
	if (input::mouseY < collision.hitbox.y)
		return false;
	if (input::mouseY > collision.hitbox.y + collision.hitbox.h)
		return false;

	return true;
}