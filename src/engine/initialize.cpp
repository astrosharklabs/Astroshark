#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"
#include "SDL_image.h"
#include "textures.h"
#include "../states/splashscreen.h"
#include "../objects/GUI.h"
#include "../objects/GameObjects.h"
#include "constants.h"
#include "statemanager.h"

void loadTextures();
void close();

SDL_Window *gameWindow;
SDL_Renderer *renderer;

void initialize(int *debug) {

	SDL_Init(SDL_INIT_VIDEO);
	gameWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	IMG_Init(IMG_INIT_PNG);
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	renderer = SDL_CreateRenderer(gameWindow, -1, render_flags);
	
	splashScreen splashScreen(renderer);
	splashScreen.render(renderer);

	//LOAD STUFF HERE
	mainCamera.setup(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT); //MUST BE LOADED FIRST BECAUSE OTHERS DEPEND ON IT
	loadTextures();
	bckgrdLoad();
	GUILoad();

	GameObjectsLoad_ArcadeMode();
	//printf("%d, %d\n", mainCamera.rect.w, mainCamera.rect.h);
	//SDL_Delay(3000);
	//SDL_SetRenderDrawColor(renderer, 100, 222, 255, 255);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //temp

	splashScreen.fadeOut(renderer);

	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	initialize_StateManager(renderer);

	close();

	debug = 0;
}

void loadTextures() {
	loadTexturefromIMG(renderer, &astroshark_titleTexture, "resources/gfx/astroshark_title_740x95.png");
	loadTexturefromIMG(renderer, &buttons_texture, "resources/gfx/GUI/buttons.png");
	loadTexturefromIMG(renderer, &background_texture, "resources/gfx/background_1920x1920.png");
	loadTexturefromIMG(renderer, &amadeusShip_texture, "resources/gfx/sprites/playerShip_spritesheet_320x480.png");
	loadTexturefromIMG(renderer, &laserSpritesheet_texture, "resources/gfx/sprites/lasers_spritesheet_160x320.png");
	loadTexturefromIMG(renderer, &asteroidSpritesheet_texture, "resources/gfx/sprites/asteroid_spritesheet_640x640.png");
}

void close() {
	SDL_DestroyTexture(splash_screenTexture);
	SDL_DestroyTexture(astroshark_titleTexture);
	SDL_DestroyTexture(buttons_texture);
	SDL_DestroyTexture(background_texture);
	SDL_DestroyTexture(amadeusShip_texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(gameWindow);
	IMG_Quit();
	SDL_Quit();
}