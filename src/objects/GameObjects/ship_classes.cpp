#include <stdio.h>
#include "ship_classes.h"
#include "ship_base.h"
#include <SDL.h>
#include "../../engine/constants.h"
#include "../../engine/sprite.h"

void amadeusShip::initialize() {
	ship.setup(0, 0, 32, 48, amadeusShip_texture);
	ship.defFrame(0, 0, 320, 480, &defaultCycle.srcrect);
	
	copyRect(&defaultCycle.srcrect, &currentSRCRECT.srcrect);
}

void amadeusShip::render(SDL_Renderer *renderer) {
	ship.render(renderer, &currentSRCRECT.srcrect);
}