#include "SDL.h"
#include "SDL_image.h"

void loadTexturefromIMG(SDL_Renderer *renderer, SDL_Texture **texture, char *file) {
	SDL_Surface *tempSurface;
	tempSurface = IMG_Load(file);
	*texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
}

SDL_Texture *splash_screenTexture = NULL;
SDL_Texture *astroshark_titleTexture = NULL;
SDL_Texture *buttons_texture = NULL;
SDL_Texture *background_texture = NULL;
SDL_Texture *amadeusShip_texture = NULL;
SDL_Texture *laserSpritesheet_texture = NULL;