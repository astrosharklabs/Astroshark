#include "constants.h"
#include "SDL.h"
#include "../objects/camera.h"
#include "../objects/background.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int STATE = MAIN_MENU;

const char *windowTitle = "Astroshark Labs Testbox v0.7.2";

camera mainCamera;

background bckgrd[4];