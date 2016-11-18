#include "constants.h"
#include "SDL.h"
#include "../objects/Misc/camera_base.h"
#include "../objects/Misc/background_base.h"
#include "timer.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int STATE = MAIN_MENU;

const char *windowTitle = "Astroshark Labs Testbox v0.13.3";

camera_base mainCamera;

background_base bckgrd[4];

timer FPS_timer;