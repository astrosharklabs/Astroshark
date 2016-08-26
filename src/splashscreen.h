#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "textures.h"
#include "sprite.h"

#ifndef spriteclasses_h
#define spriteclasses_h

class splashScreen {
public:
	splashScreen();
	void create(SDL_Renderer *renderer); //Does all backend to create the splashScreen
	void display(SDL_Renderer *renderer); //Displays the image at the given location
private:
	defaultProp prop;
};
#endif