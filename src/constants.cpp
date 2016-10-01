#include "constants.h"
#include "SDL.h"
#include "camera.h"
#include "background.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int STATE = MAIN_MENU;

const char *windowTitle = "Astroshark Labs Testbox v0.5.0";

camera mainCamera;

background bckgrd[4];