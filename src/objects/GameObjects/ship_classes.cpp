#include <stdio.h>
#include "ship_classes.h"
#include "ship_base.h"
#include <SDL.h>
#include "../../engine/constants.h"
#include "../../engine/sprite.h"
#include <stdio.h>
#include <iostream>

enum status {STOPPED, ACCEL, ROTATE_L, ROTATE_R, MOVING};

void amadeusShip::initialize() {
	ship.setup(0, 0, 32, 48, amadeusShip_texture);
	ship.defFrame(0, 0, 320, 480, &defaultCycle.srcrect);
	ship.defFrame(320, 0, 320, 480, &rotateCycle[0].srcrect);
	ship.defFrame(640, 0, 320, 480, &rotateCycle[1].srcrect);
	ship.defFrame(960, 0, 320, 480, &rotateCycle[2].srcrect);
	ship.defFrame(1280, 0, 320, 480, &rotateCycle[3].srcrect);
	ship.defFrame(0, 480, 320, 480, &accelCycle.srcrect);
	ship.defFrame(320, 480, 320, 480, &moveCycle[0].srcrect);
	ship.defFrame(640, 480, 320, 480, &moveCycle[1].srcrect);
	ship.defFrame(960, 480, 320, 480, &moveCycle[2].srcrect);
	ship.defFrame(1280, 480, 320, 480, &moveCycle[3].srcrect);

	ship.lives = 3;

	ship.center();

	ship.rotate(90);
	copyRect(defaultCycle.srcrect, &currentSRCRECT.srcrect);

	state = STOPPED;

	setRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, &ship.movement.domain);
	ship.movement.origin.y = ship.getH() / 2 + 10;
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
}

void amadeusShip::updateState() {
	switch (state) {
	case STOPPED:
		copyRect(defaultCycle.srcrect, &currentSRCRECT.srcrect);
		break;
	case ACCEL:
		copyRect(accelCycle.srcrect, &currentSRCRECT.srcrect);
		break;
	case ROTATE_L:
		copyRect(rotateCycle[(std::rand() % 2) + 2].srcrect, &currentSRCRECT.srcrect);
		break;
	case ROTATE_R:
		copyRect(rotateCycle[std::rand() % 2].srcrect, &currentSRCRECT.srcrect);
		break;
	case MOVING:
		copyRect(moveCycle[std::rand() % 4].srcrect, &currentSRCRECT.srcrect);
		break;
	default:
		break;
	}
}

void amadeusShip::update() {
	ship.rotate(ship.movement.deltaAngle);
	ship.move(&ship.movement.deltaX, &ship.movement.deltaY);

	ship.movement.deltaX = 0;
	ship.movement.deltaY = 0;
	ship.movement.deltaAngle = 0;

	if (ship.keyDownRotate_timer.isStarted() == true) {
		switch (ship.rotateDirection) {
		case ship_base_::LEFT:
			state = ROTATE_L;
			break;
		case ship_base_::RIGHT:
			state = ROTATE_R;
			break;
		}
	}
	if (ship.keyDownRotate_timer.getCurrentSeconds() >= 1.0 / 60.0) {
		ship.keyDownRotate_timer.stop();
		state = STOPPED;
		ship.rotateDirection = ship_base_::NONE;
		//printf("rotate stopped\n");
	}
	if (ship.keyDown_timer.isStarted() == true) {
		state = MOVING;
	}
	if (ship.keyDown_timer.getCurrentSeconds() >= 1.0 / 60.0) {
		ship.keyDown_timer.stop();
		state = STOPPED;
		//printf("stopped\n");
	}

	updateState();
}