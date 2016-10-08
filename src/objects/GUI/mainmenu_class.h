#pragma once
#include "button_base.h"
#include "title_base.h"
#include "../Misc/background_base.h"
#include <SDL.h>

#ifndef mainmenuObjects_h
#define mainmenuObjects_h

class mainMenu_class {
public:
	title_base title_image;
	button_base startgame_button;
	button_base options_button;
	button_base credits_button;
	button_base quit_button;
	void initialize();
	void render(SDL_Renderer *);
};
#endif