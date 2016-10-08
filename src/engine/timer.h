#pragma once
#include "SDL.h"

#ifndef timer_h
#define timer_h

class timer {
public:
	void setup();
	void start();
	void stop();
	void pause();
	void unpause();

	Uint32 getTicks();
	Uint32 getStoppedTicks(); //Gets last stopped ticks
	float getCurrentSeconds();

	bool isStarted();
	bool isPaused();
private:
	Uint32 ticksPaused;
	Uint32 ticksStarted;
	Uint32 ticksStopped;

	bool STARTED;
	bool PAUSED;
};

#endif // !timer_h