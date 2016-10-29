#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include "sprite.h"
#include <math.h>

#define PI 3.14159265

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

void setRectXY(int x, int y, SDL_Rect *rect) {
	rect->x = x;
	rect->y = y;
}

void copyRect(SDL_Rect *oldRect, SDL_Rect *newRect) {
	newRect->x = oldRect->x;
	newRect->y = oldRect->y;
	newRect->w = oldRect->w;
	newRect->h = oldRect->h;
}

bool testCollision(SDL_Rect a, SDL_Rect b) {
	int leftA, rightA, topA, bottomA;
	int leftB, rightB, topB, bottomB;

	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if (leftA <= rightB)
		return true;
	if (leftB <= rightA)
		return true;
	if (topA <= bottomB)
		return true;
	if (topB <= bottomA)
		return true;

	return false;
}

void astroshark::calculateMovement(int *deltaX, int *deltaY, int angle, int speed) {
	int quadrant = 0;
	float sinT;
	float cosT;

	/*Checks to see if rotation is greater or less than 360*/
	if (angle >= 360)
		angle -= 360;
	if (angle < 0)
		angle += 360;
	
	/*Sets proper Quadrant*/
	if (angle < 90 && angle > 0) {
		quadrant = 1;
	}
	if (angle < 180 && angle > 90) {
		quadrant = 2;
		angle -= 90;
	}
	if (angle < 270 && angle > 180) {
		quadrant = 3;
		angle -= 180;
	}
	if (angle <= 359 && angle > 270) {
		quadrant = 4;
		angle -= 270;
	}
	if (angle == 0)
		quadrant = astroshark::EAST;
	if (angle == 90)
		quadrant = astroshark::NORTH;
	if (angle == 180)
		quadrant = astroshark::WEST;
	if (angle == 270)
		quadrant = astroshark::SOUTH;

	sinT = sin(angle * PI / 180) * speed;
	cosT = cos(angle * PI / 180) * speed;

	if (deltaX != NULL && deltaY != NULL) {
		switch (quadrant) {
		case 1:
			*deltaX = cosT;
			*deltaY = -1 * sinT;
			break;
		case 2:
			*deltaX = -1 * sinT;
			*deltaY = -1 * cosT;
			break;
		case 3:
			*deltaX = -1 * cosT;
			*deltaY = sinT;
			break;
		case 4:
			*deltaX = sinT;
			*deltaY = cosT;
			break;
		case astroshark::NORTH:
			*deltaX = 0;
			*deltaY = -1 * sinT + 1;
			break;
		case astroshark::EAST:
			*deltaX = cosT - 1;
			*deltaY = 0;
			break;
		case astroshark::SOUTH:
			*deltaX = 0;
			*deltaY = -1 * sinT - 1;
			break;
		case astroshark::WEST:
			*deltaX = cosT + 1;
			*deltaY = 0;
			break;
		}
	}
}