#include <SDL.h>
#include "playerShip.h"
#include "../../engine/textures.h"
#include "../../engine/sprite.h"
#include "../../engine/input.h"

void playerShip::setup(int dstX, int dstY, int dstW, int dstH) {
	//prop.texture = playerShips_texture;

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

void playerShip::render(SDL_Renderer *renderer) {
	SDL_RenderCopy(renderer, prop.texture, &frame[prop.frame].srcrect, &prop.dstrect);
}

void playerShip::setXY(int dstX, int dstY) {
	setRect(dstX, dstY, NULL, NULL, &prop.dstrect);
}

void playerShip::alphaInc(int rate) {
	alphaIncrease(prop.texture, &prop.alpha, rate);
}

void playerShip::alphaDec(int rate) {
	alphaDecrease(prop.texture, &prop.alpha, rate);
}

void playerShip::defFrame(int srcX, int srcY, int srcW, int srcH, int frameN) {
	setRect(srcX, srcY, srcW, srcH, &frame[frameN].srcrect);
}

void playerShip::setFrame(int frameN) {
	prop.frame = frameN;
}

void playerShip::setCollision(int x, int y, int w, int h) {
	setRect(x, y, w, h, &collision.hitbox);
}
