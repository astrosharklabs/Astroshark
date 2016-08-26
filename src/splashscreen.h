#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "textures.h"
#include "sprite.h"

#ifndef splashscreen_h
#define splashscreen_h

class splashScreen {
public:
	splashScreen();
	void create(SDL_Renderer *renderer); //Does all backend to create the splashScreen
	void display(SDL_Renderer *renderer); //Displays the image at the given location
	void fadeOut(SDL_Renderer *renderer); //Fades the image out
private:
	defaultProp prop;
};
#endif