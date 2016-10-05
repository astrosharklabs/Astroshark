#pragma once
#include "SDL.h"
#include "title.h"
#include "buttons.h"
#include "../../engine/constants.h"
#include "../../engine/timer.h"

#ifndef guiobjects_h

extern timer GUIkeydown_timer;

extern title title_image;
extern button startgame_button;
extern button options_button;
extern button credits_button;
extern button quit_button;

void GUILoad();
void GUIRender_MainMenu(SDL_Renderer *);

#endif