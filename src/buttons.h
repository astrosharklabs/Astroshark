#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "textures.h"
#include "sprite.h"

#ifndef buttons_h
#define buttons_h

class button {
public:
	button();
	void create(SDL_Renderer *renderer); //Does all backend to create the splashScreen
	void display(SDL_Renderer *renderer); //Displays the image at the given location
	void fadeIn(SDL_Renderer *renderer, int rate); //Fades the image out
private:
	defaultProp prop;
};
#endif