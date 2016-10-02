#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "../engine/textures.h"
#include "../engine/sprite.h"

#ifndef splashscreen_h
#define splashscreen_h

class splashScreen {
public:
	splashScreen(SDL_Renderer *renderer);
	void render(SDL_Renderer *renderer); //renders the image at the given location
	void fadeOut(SDL_Renderer *renderer); //Fades the image out
private:
	defaultProp prop;
};
#endif