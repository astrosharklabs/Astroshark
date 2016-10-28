#pragma once
#include "SDL.h"
#include "../engine/constants.h"
#include "../engine/timer.h"
#include "GUI/mainmenu_class.h"

#ifndef GUI_h
#define GUI_h

extern timer GUIkeydown_timer;

extern mainMenu_class mainMenu;

void GUILoad();
void GUIRender_MainMenu(SDL_Renderer *);

#endif
