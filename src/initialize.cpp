#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"
#include "SDL_image.h"
#include "textures.h"
#include "mainmenu.h"
#include "splashscreen.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
const char *windowTitle = "Astroshark Labs Testbox v0.2.2";

void close();

SDL_Window *gameWindow;
SDL_Renderer *renderer;

void initialize(int *debug) {

	SDL_Init(SDL_INIT_VIDEO);
	gameWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	IMG_Init(IMG_INIT_PNG);
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	renderer = SDL_CreateRenderer(gameWindow, -1, render_flags);
	
	splashScreen splashScreen;
	splashScreen.create(renderer);
	splashScreen.display(renderer);

	SDL_Delay(3000);
	SDL_SetRenderDrawColor(renderer, 100, 222, 255, 255);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //temp

	splashScreen.fadeOut(renderer);

	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	mainmenu(renderer);

	SDL_Delay(2000);
	close();

	debug = 0;
}

void close() {
	SDL_DestroyTexture(splash_screenTexture);
	SDL_DestroyTexture(astroshark_titleTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(gameWindow);
	IMG_Quit();
	SDL_Quit();
}