#include "SDL.h"
#include "timer.h"

void timer::setup() {
	ticksPaused = 0;
	ticksStarted = 0;

	STARTED = false;
	PAUSED = false;
}

void timer::start() {
	//Resets everything and starts the timer
	STARTED = true;
	PAUSED = false;

	ticksStarted = SDL_GetTicks();
	ticksPaused = 0;
}

void timer::stop() {
	STARTED = false;
	PAUSED = false;

	ticksStopped = SDL_GetTicks() - ticksStarted;
	ticksStarted = 0;
	ticksPaused = 0;
}

void timer::pause() {
	if (STARTED == true && PAUSED == false) {
		PAUSED = true;

		ticksPaused = SDL_GetTicks() - ticksStarted;
		ticksStarted = 0;
	}
}

void timer::unpause() {
	if (STARTED == true && PAUSED == true) {
		PAUSED = false;

		ticksStarted = SDL_GetTicks() - ticksPaused;
		ticksPaused = 0;
	}
}

float timer::getCurrentSeconds() {
	return (float)getTicks() / 1000;
}

Uint32 timer::getTicks() {
	Uint32 ticks = 0;

	if (STARTED == true) {
		if (PAUSED == true) {
			ticks = ticksPaused;
		}
		else {
			ticks = SDL_GetTicks() - ticksStarted;
		}
	}
	
	return ticks;
}

Uint32 timer::getStoppedTicks() {
	return ticksStopped;
}

bool timer::isStarted() {
	return STARTED;
}

bool timer::isPaused() {
	return PAUSED;
}