#include <stdio.h>
#include <SDL.h>
#include "ship_base.h"
#include "../../engine/textures.h"
#include "../../engine/sprite.h"
#include "../../engine/input.h"
#include "../../engine/constants.h"

enum cycle { DEFAULT_01, TRANSIT_01, ENGINE_01, ENGINE_02, ENGINE_03, ENGINE_04 };
enum cycleNum { DEFAULT, TRANSIT, ENGINE };

void ship_base::setup(int dstX, int dstY, int dstW, int dstH, SDL_Texture *texture) {
	prop.texture = texture;

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

	prop.origin.x = prop.dstrect.w / 2;
	prop.origin.y = prop.dstrect.h / 2;
	movement.movementSpeed = 5;
	movement.rotateSpeed = 5;
}

void ship_base::render(SDL_Renderer *renderer, SDL_Rect *srcrect) {
	if (testCollision(prop.dstrect, mainCamera.rect) == true)
		SDL_RenderCopyEx(renderer, prop.texture, srcrect, &prop.dstrect, -1 * prop.angle + 90, &prop.origin, SDL_FLIP_NONE);
	//printf("x: %d y: %d w: %d h: %d\n", srcrect->x, srcrect->y, srcrect->w, srcrect->h);
	//printf("x: %d y: %d w: %d h: %d\n", prop.dstrect.x, prop.dstrect.y, prop.dstrect.w, prop.dstrect.h);
}

void ship_base::setXY(int dstX, int dstY) {
	setRectXY(dstX, dstY, &prop.dstrect);
}

void ship_base::center() {
	setRectXY((WINDOW_WIDTH / 2) - (prop.dstrect.w / 2), (WINDOW_HEIGHT / 2) - (prop.dstrect.h / 2), &prop.dstrect);
}

void ship_base::alphaInc(int rate) {
	alphaIncrease(prop.texture, &prop.alpha, rate);
}

void ship_base::alphaDec(int rate) {
	alphaDecrease(prop.texture, &prop.alpha, rate);
}

void ship_base::setAlpha(int a) {
	SDL_SetTextureAlphaMod(prop.texture, a);
	prop.alpha = a;
}

void ship_base::defFrame(int srcX, int srcY, int srcW, int srcH, SDL_Rect *srcrect) {
	setRect(srcX, srcY, srcW, srcH, srcrect);
}

void ship_base::setFrame(int frameN) {
	prop.frame = frameN;
}

void ship_base::setCollision(int x, int y, int w, int h) {
	setRect(x, y, w, h, &collision.hitbox);
}

void ship_base::move(int deltaX, int deltaY) {
	prop.dstrect.x += deltaX;
	prop.dstrect.y += deltaY;
}

void ship_base::rotate(int deltaAngle) {
	prop.angle += deltaAngle;

	if (prop.angle < 0)
		prop.angle += 360;
	if (prop.angle >= 360)
		prop.angle -= 360;
}

void ship_base::queueMoveForward() {
	astroshark::calculateMovement(&movement.deltaX, &movement.deltaY, prop.angle, movement.movementSpeed);
}

void ship_base::queueMoveBackward() {
	astroshark::calculateMovement(&movement.deltaX, &movement.deltaY, prop.angle - 180, movement.movementSpeed);
}

void ship_base::queueStrafeLeft() {
	astroshark::calculateMovement(&movement.deltaX, &movement.deltaY, prop.angle + 90, movement.movementSpeed);
}

void ship_base::queueStrafeRight() {
	astroshark::calculateMovement(&movement.deltaX, &movement.deltaY, prop.angle - 90, movement.movementSpeed);
}

void ship_base::queueRotateLeft() {
	movement.deltaAngle += movement.rotateSpeed;
}

void ship_base::queueRotateRight() {
	movement.deltaAngle -= movement.rotateSpeed;
}