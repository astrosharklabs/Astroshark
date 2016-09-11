#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"

void loadPNGImageToTexture(SDL_Renderer *renderer, int *w, int *h, SDL_Texture **spriteTexture, const char *file) {
	SDL_Surface *tempSurface = IMG_Load(file);
	*spriteTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	SDL_QueryTexture(*spriteTexture, NULL, NULL, w, h);
}

void setAlpha(SDL_Texture *texture, Uint8 alpha) {
	SDL_SetTextureAlphaMod(texture, alpha);
}

void alphaIncrease(SDL_Texture *texture, int *alpha, int rate) {
	*alpha += rate;
	SDL_SetTextureAlphaMod(texture, *alpha);
}

void alphaDecrease(SDL_Texture *texture, int *alpha, int rate) {
	*alpha -= rate;
	SDL_SetTextureAlphaMod(texture, *alpha);
}

void setRect(int x, int y, int w, int h, SDL_Rect *rect) {
	rect->x = x;	
	rect->y = y;	
	rect->w = w;	
	rect->h = h;
}

bool testCollision(SDL_Rect x, SDL_Rect y) {
	int leftX, rightX, topX, bottomX;
	int leftY, rightY, topY, bottomY;

	leftX = x.x;
	rightX = x.x + x.w;
	topX = x.y;
	bottomX = x.y + x.h;

	leftY = y.x;
	rightY = y.x + y.w;
	topY = y.y;
	bottomY = y.y + y.h;

	if (leftX <= rightY)
		return false;
	if (leftY <= rightX)
		return false;
	if (topX <= bottomY)
		return false;
	if (topY <= bottomX)
		return false;

	return true;
}