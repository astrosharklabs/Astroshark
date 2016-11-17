#pragma once
#include <SDL.h>
#include "asteroid_base.h"
#include "../../engine/sprite.h"
#include "../../engine/domain_base.h"

#ifndef asteroid_classes_h
#define asteroid_classes_h

namespace asteroid_classes_ {
	enum size {LARGE, MEDIUM, SMALL};
	extern domain_base arcadeMode_domain;
}

class standardAsteroid {
public:
	asteroid_base base;
	void initialize(int asteroidSize);
	void render(SDL_Renderer *renderer);

	void update();

	int size;
private:
	animation currentSRCRECT;
	int state;
};
#endif