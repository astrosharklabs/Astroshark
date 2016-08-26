#include "SDL.h"
#include "SDL_image.h"
#include "textures.h"
#include "sprite.h"
#include "title.h"

title::title() {
	prop.dstrect.x = 0;
	prop.dstrect.y = 0;
	prop.alpha = 0;
}
void title::create(SDL_Renderer *renderer) {
	loadPNGImageToTexture(renderer, &prop.dstrect.w, &prop.dstrect.h, &astroshark_titleTexture, "resources/gfx/astroshark_title_740x95.png");
	prop.dstrect.x = 640 - prop.dstrect.w / 2;
	prop.dstrect.y = 150;
}
void title::display(SDL_Renderer *renderer) {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, astroshark_titleTexture, NULL, &prop.dstrect);
	SDL_RenderPresent(renderer);
}
void title::fadeIn(SDL_Renderer *renderer, int rate) {
	while (prop.alpha < 255) {
		SDL_RenderClear(renderer);
		SDL_SetTextureAlphaMod(astroshark_titleTexture, prop.alpha);
		SDL_RenderCopy(renderer, astroshark_titleTexture, NULL, &prop.dstrect);
		SDL_RenderPresent(renderer);
		prop.alpha += rate;
	}
	SDL_SetTextureAlphaMod(astroshark_titleTexture, 255);
}