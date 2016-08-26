#include "SDL.h"
#include "SDL_image.h"
#include "textures.h"
#include "sprite.h"
#include "splashscreen.h"

splashScreen::splashScreen() {
	prop.dstrect.x = 0;
	prop.dstrect.y = 0;
	prop.alpha = 255;
}
void splashScreen::create(SDL_Renderer *renderer) {
	loadPNGImageToTexture(renderer, &prop.dstrect.w, &prop.dstrect.h, &splash_screenTexture, "resources/gfx/splash_screen.png");
	}
void splashScreen::display(SDL_Renderer *renderer) {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, splash_screenTexture, NULL, &prop.dstrect);
	SDL_RenderPresent(renderer);
	}
void splashScreen::fadeOut(SDL_Renderer *renderer) {
	while (prop.alpha > 0) {
		SDL_RenderClear(renderer);
		SDL_SetTextureAlphaMod(splash_screenTexture, prop.alpha);
		SDL_RenderCopy(renderer, splash_screenTexture, NULL, &prop.dstrect);
		SDL_RenderPresent(renderer);
		prop.alpha -= 5;
	}
}