#include "constants.h"
#include "SDL.h"
#include "camera.h"
#include "background.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int STATE = MAIN_MENU;

const char *windowTitle = "Astroshark Labs Testbox v0.3.11";

camera mainCamera;

background bkgrd[9];