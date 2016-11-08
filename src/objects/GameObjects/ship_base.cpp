#include <stdio.h>
#include <SDL.h>
#include "ship_base.h"
#include "../../engine/sprite.h"
#include "../../engine/input.h"
#include "../../engine/constants.h"
#include "../../engine/timer.h"

enum cycle { DEFAULT_01, TRANSIT_01, ENGINE_01, ENGINE_02, ENGINE_03, ENGINE_04 };
enum cycleNum { DEFAULT, TRANSIT, ENGINE };

void ship_base::setup(int dstX, int dstY, int dstW, int dstH, SDL_Texture *texture) {
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

	//printf("%d, %d\n", mainCamera.rect.w, mainCamera.rect.h);
	arcadeMode_domain.setup(-350, -200, mainCamera.rect.w + 700, mainCamera.rect.h + 400, 0);
	//printf("%d, %d\n", mainCamera.rect.w, mainCamera.rect.h);

	keyDown_timer.setup();
	keyDownRotate_timer.setup();

	prop.frame = 0;

	prop.alpha = 0;
	SDL_SetTextureAlphaMod(prop.texture, prop.alpha);

	movement.origin.x = prop.dstrect.w / 2;
	movement.origin.y = prop.dstrect.h / 2;
	movement.movementSpeed = 10;
	movement.rotateSpeed = 5;
	rotateDirection = ship_base_::NONE;

	movement.deltaAngle = 0;
	movement.deltaX = 0;
	movement.deltaY = 0;
	prop.angle = 0;
}

void ship_base::render(SDL_Renderer *renderer, SDL_Rect *srcrect) {
	if (testCollision(movement.Gdstrect, mainCamera.rect) == true)
		SDL_RenderCopyEx(renderer, prop.texture, srcrect, &prop.dstrect, -1 * prop.angle + 90, &movement.origin, SDL_FLIP_NONE);
	//printf("x: %d y: %d w: %d h: %d\n", srcrect->x, srcrect->y, srcrect->w, srcrect->h);
	//printf("x: %d y: %d w: %d h: %d\n", prop.dstrect.x, prop.dstrect.y, prop.dstrect.w, prop.dstrect.h);
}

void ship_base::setXY(int dstX, int dstY) {
	movement.Gdstrect.x = dstX;
	movement.Gdstrect.y = dstY;

	prop.dstrect.x = movement.Gdstrect.x - mainCamera.rect.x;
	prop.dstrect.y = movement.Gdstrect.y - mainCamera.rect.y;
}

void ship_base::center() {
	/*movement.Gdstrect.x = mainCamera.rect.x;
	movement.Gdstrect.y = mainCamera.rect.y;

	movement.deltaX = (WINDOW_WIDTH / 2) - (movement.Gdstrect.w / 2);
	movement.deltaY = (WINDOW_HEIGHT / 2) - (movement.Gdstrect.h / 2);
	move(movement.deltaX, movement.deltaY);*/

	setXY(mainCamera.rect.x + ((WINDOW_WIDTH / 2) - (movement.Gdstrect.w / 2)), mainCamera.rect.y + ((WINDOW_HEIGHT / 2) - (movement.Gdstrect.h / 2)));

	movement.deltaX = 0;
	movement.deltaY = 0;
	//setRectXY((WINDOW_WIDTH / 2) - (prop.dstrect.w / 2), (WINDOW_HEIGHT / 2) - (prop.dstrect.h / 2), &prop.dstrect);
	//printf("%d, %d, %d, %d\n", prop.dstrect.x, prop.dstrect.y, prop.dstrect.w, movement.Gdstrect.h);
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

void ship_base::move(int *deltaX, int *deltaY) {
	if (STATE == START_GAME) {

		mainCamera.deltaX = *deltaX / 2;
		mainCamera.deltaY = *deltaY / 2;

		arcadeMode_domain.dstrect.y -= 20;
		arcadeMode_domain.dstrect.h += 20;
		arcadeMode_domain.restrictIn(movement.Gdstrect, deltaX, deltaY);
		arcadeMode_domain.dstrect.y += 20;
		arcadeMode_domain.dstrect.h -= 20;

		movement.Gdstrect.x += *deltaX;
		movement.Gdstrect.y += *deltaY;

		prop.dstrect.x = movement.Gdstrect.x - mainCamera.rect.x - *deltaX;
		prop.dstrect.y = movement.Gdstrect.y - mainCamera.rect.y - *deltaY;
	}

	/*prop.dstrect.x += deltaX;
	prop.dstrect.y += deltaY;

	movement.Gdstrect.x = prop.dstrect.x + mainCamera.rect.x;
	movement.Gdstrect.y = prop.dstrect.y + mainCamera.rect.y;*/

	//printf("%d, %d, %d, %d\n", movement.Gdstrect.x, movement.Gdstrect.y, movement.Gdstrect.w, movement.Gdstrect.h);
	/*if (testCollision(movement.Gdstrect, mainCamera.rect) == false) {
		//domainRestrict(deltaX, deltaY, prop.angle, &prop.dstrect, mainCamera.rect);
		//printf("%d, %d, %d, %d\n", prop.dstrect.x, prop.dstrect.y, prop.dstrect.w, prop.dstrect.h);
		//printf("%d, %d, %d, %d\n", movement.Gdstrect.x, movement.Gdstrect.y, movement.Gdstrect.w, movement.Gdstrect.h);
	}*/
}

void ship_base::rotate(int deltaAngle) {
	prop.angle += deltaAngle;

	if (prop.angle < 0)
		prop.angle += 360;
	if (prop.angle >= 360)
		prop.angle -= 360;
}

void ship_base::queueMoveForward() {
	rotationalMovement(&movement.deltaX, &movement.deltaY, prop.angle, movement.movementSpeed);
	keyDown_timer.start();
}

void ship_base::queueMoveBackward() {
	rotationalMovement(&movement.deltaX, &movement.deltaY, prop.angle - 180, movement.movementSpeed);
}

void ship_base::queueStrafeLeft() {
	rotationalMovement(&movement.deltaX, &movement.deltaY, prop.angle + 90, movement.movementSpeed);
}

void ship_base::queueStrafeRight() {
	rotationalMovement(&movement.deltaX, &movement.deltaY, prop.angle - 90, movement.movementSpeed);
}

void ship_base::queueRotateLeft() {
	movement.deltaAngle += movement.rotateSpeed;
	keyDownRotate_timer.start();
	rotateDirection = ship_base_::LEFT;
}

void ship_base::queueRotateRight() {
	movement.deltaAngle -= movement.rotateSpeed;
	keyDownRotate_timer.start();
	rotateDirection = ship_base_::RIGHT;
}

int ship_base::getAngle() {
	return prop.angle;
}

int ship_base::getH() {
	return prop.dstrect.h;
}