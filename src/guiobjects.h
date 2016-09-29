#pragma once
#include "SDL.h"
#include "title.h"
#include "camera.h"
#include "buttons.h"
#include "constants.h"

#ifndef guiobjects_h

extern title title_image;
extern button startgame_button;
extern button options_button;
extern button credits_button;
extern button quit_button;

void GUILoad();
void GUIRender_MainMenu(SDL_Renderer *);

#endif
