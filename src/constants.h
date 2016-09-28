#pragma once
#ifndef constants_h
#define constants_h

#include "SDL.h"
#include "camera.h"
#include "background.h"

enum screen_state { MAIN_MENU = 1, START_GAME, OPTIONS, CREDITS, QUIT, PAUSE_MENU };

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

extern const char *windowTitle;

extern int STATE;

extern camera mainCamera;
extern background bckgrd[4];
#endif