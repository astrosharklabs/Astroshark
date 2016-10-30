#pragma once
#ifndef constants_h
#define constants_h

#include "SDL.h"
#include "../objects/Misc/camera_base.h"
#include "../objects/Misc/background_base.h"
#include "timer.h"

enum screen_state { MAIN_MENU = 1, START_GAME, OPTIONS, CREDITS, QUIT, PAUSE_MENU };

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

extern const char *windowTitle;

extern int STATE;

extern camera_base mainCamera;
extern background_base bckgrd[4];

extern timer FPS_timer;
#endif