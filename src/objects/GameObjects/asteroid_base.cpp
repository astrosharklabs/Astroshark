#include "asteroid_base.h"
#include <SDL.h>
#include "../../engine/sprite.h"
#include "../../engine/constants.h"

void asteroid_base::setup(int dstX, int dstY, int dstW, int dstH, SDL_Texture *texture) {
	prop.texture = texture;

	prop.dstrect.x = dstX;
	prop.dstrect.y = dstY;
	prop.dstrect.w = dstW;
	prop.dstrect.h = dstH;

	movement.Gdstrect.x = dstX;
	movement.Gdstrect.y = dstY;
	movement.Gdstrect.w = dstW;
	movement.Gdstrect.h = dstH;

	collision.hitbox.x = dstX;
	collision.hitbox.y = dstY;
	collision.hitbox.w = dstW;
	collision.hitbox.h = dstH;

	prop.frame = 0;

	prop.alpha = 255;
	setAlpha(prop.alpha);

	movement.origin.x = prop.dstrect.w / 2;
	movement.origin.y = prop.dstrect.h / 2;
	movement.movementSpeed = 20;
	movement.rotateSpeed = 5;
}

void asteroid_base::render(SDL_Renderer *renderer, SDL_Rect *srcrect) {
	if (testCollision(movement.Gdstrect, mainCamera.rect) == true)
		SDL_RenderCopyEx(renderer, prop.texture, srcrect, &prop.dstrect, -1 * prop.angle + 90, &movement.origin, SDL_FLIP_NONE);
}

void asteroid_base::setXY(int dstX, int dstY) {
	movement.Gdstrect.x = dstX;
	movement.Gdstrect.y = dstY;

	prop.dstrect.x = movement.Gdstrect.x - mainCamera.rect.x;
	prop.dstrect.y = movement.Gdstrect.y - mainCamera.rect.y;
}

void asteroid_base::setOrigin(int dstX, int dstY) {
	movement.origin.x = dstX;
	movement.origin.y = dstY;
}

void asteroid_base::alphaInc(int rate) {
	alphaIncrease(prop.texture, &prop.alpha, rate);
}

void asteroid_base::alphaDec(int rate) {
	alphaDecrease(prop.texture, &prop.alpha, rate);
}

void asteroid_base::setAlpha(int a) {
	SDL_SetTextureAlphaMod(prop.texture, a);
	prop.alpha = a;
}

void asteroid_base::defFrame(int srcX, int srcY, int srcW, int srcH, SDL_Rect *srcrect) {
	setRect(srcX, srcY, srcW, srcH, srcrect);
}

void asteroid_base::setFrame(int frameN) {
	prop.frame = frameN;
}


void asteroid_base::setSpeed(int speed) {
	movement.movementSpeed = speed;
}

void asteroid_base::move(int *deltaX, int *deltaY) {
	if (STATE == START_GAME) {
		movement.Gdstrect.x += *deltaX;
		movement.Gdstrect.y += *deltaY;

		prop.dstrect.x = movement.Gdstrect.x - mainCamera.rect.x - *deltaX;
		prop.dstrect.y = movement.Gdstrect.y - mainCamera.rect.y - *deltaY;
	}
}

void asteroid_base::rotate(int deltaAngle) {
	prop.angle += deltaAngle;

	if (prop.angle < 0)
		prop.angle += 360;
	if (prop.angle >= 360)
		prop.angle -= 360;
}


void asteroid_base::fire(int angle, SDL_Rect dstrect) {
	setXY((dstrect.x + (dstrect.w / 2)) - (prop.dstrect.w / 2), dstrect.y);
	prop.angle = angle;

	rotationalMovement(&movement.deltaX, &movement.deltaY, prop.angle, movement.movementSpeed);
}

int asteroid_base::getW() {
	return prop.dstrect.w;
}
