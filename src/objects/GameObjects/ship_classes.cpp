#include <stdio.h>
#include "ship_classes.h"
#include "ship_base.h"
#include <SDL.h>
#include "../../engine/constants.h"
#include "../../engine/sprite.h"
void amadeusShip::initialize() {
	ship.setup(0, 0, 32, 48, amadeusShip_texture);
	ship.defFrame(0, 0, 320, 480, &defaultCycle.srcrect);
	ship.lives = 3;

	ship.center();
//	ship.move(0, 100);
	ship.rotate(90);
	copyRect(&defaultCycle.srcrect, &currentSRCRECT.srcrect);

	setRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, &ship.movement.domain);
}

void amadeusShip::queueRequest(int type) {
	switch (type) {
	case MOVE_FORWARD:
		ship.queueMoveForward();
		break;
	case MOVE_BACKWARD:
		ship.queueMoveBackward();
		break;
	case STRAFE_LEFT:
		ship.queueStrafeLeft();
		break;
	case STRAFE_RIGHT:
		ship.queueStrafeRight();
		break;
	case ROTATE_LEFT:
		ship.queueRotateLeft();
		break;
	case ROTATE_RIGHT:
		ship.queueRotateRight();
		break;
	case SHOOT:
		break;
	default:
		break;
	}
}

void amadeusShip::render(SDL_Renderer *renderer) {
	ship.render(renderer, &currentSRCRECT.srcrect);
	ship.movement.deltaX = 0;
	ship.movement.deltaY = 0;
	ship.movement.deltaAngle = 0;
}

void amadeusShip::update() {
	ship.rotate(ship.movement.deltaAngle);
	ship.move(&ship.movement.deltaX, &ship.movement.deltaY);
}