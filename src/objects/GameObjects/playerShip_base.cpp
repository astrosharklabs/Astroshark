#include <SDL.h>
#include "playerShip_base.h"
#include "../../engine/textures.h"
#include "../../engine/sprite.h"
#include "../../engine/input.h"
#include "../../engine/constants.h"

enum cycle { DEFAULT_01, TRANSIT_01, ENGINE_01, ENGINE_02, ENGINE_03, ENGINE_04 };
enum cycleNum { DEFAULT, TRANSIT, ENGINE };

void playerShip_base::setup(int dstX, int dstY, int dstW, int dstH) {
	prop.texture = playerShip_texture;

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

//void playerShip_base::render(SDL_Renderer *renderer, SDL_Rect srcrect) {
	//SDL_RenderCopy(renderer, prop.texture, &frame[prop.frame].srcrect, &prop.dstrect);
//}

void playerShip_base::setXY(int dstX, int dstY) {
	setRect(dstX, dstY, NULL, NULL, &prop.dstrect);
}

void playerShip_base::alphaInc(int rate) {
	alphaIncrease(prop.texture, &prop.alpha, rate);
}

void playerShip_base::alphaDec(int rate) {
	alphaDecrease(prop.texture, &prop.alpha, rate);
}

//void playerShip_base::defFrame(int srcX, int srcY, int srcW, int srcH, int frameN, SDL_Rect *srcrect) {
	//setRect(srcX, srcY, srcW, srcH, &frame[frameN].srcrect);
//}

void playerShip_base::setFrame(int frameN) {
	prop.frame = frameN;
}

void playerShip_base::setCollision(int x, int y, int w, int h) {
	setRect(x, y, w, h, &collision.hitbox);
}
