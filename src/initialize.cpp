#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"
#include "SDL_image.h"
#include "backend.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
const char *windowTitle = "Astroshark Labs Testbox v0.1.0";

void initialize(int *debug) {

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *gameWindow;
	gameWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	IMG_Init(IMG_INIT_PNG);
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer *renderer = SDL_CreateRenderer(gameWindow, -1, render_flags);

	SDL_Texture *splash_screenTexture;
	SDL_Rect splash_screenRect;
	createSprite(&renderer, &splash_screenRect.w, &splash_screenRect.h, &splash_screenTexture, "resources/gfx/splash_screen.png");
	splash_screenRect.w *= 1;
	splash_screenRect.h *= 1;
	splash_screenRect.x = (WINDOW_WIDTH / 2) - (splash_screenRect.w / 2);
	splash_screenRect.y = (WINDOW_HEIGHT / 2) - (splash_screenRect.h / 2) - 25;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, splash_screenTexture, NULL, &splash_screenRect);
	SDL_RenderPresent(renderer);

	SDL_Delay(3000);

	int backgroundColor = 255;
	while (backgroundColor > 0) {
		SDL_SetRenderDrawColor(renderer, backgroundColor, backgroundColor, backgroundColor, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, splash_screenTexture, NULL, &splash_screenRect);
		SDL_SetTextureAlphaMod(splash_screenTexture, backgroundColor);
		SDL_RenderPresent(renderer);
		backgroundColor -= 5;
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_Delay(2000);

	SDL_DestroyTexture(splash_screenTexture);
	SDL_DestroyWindow(gameWindow);
	IMG_Quit();
	SDL_Quit();
	
}
