#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include "sprite.h"
#include <math.h>

#define PI 3.14159265

enum output {TOP, RIGHT, CORNER};

enum direction { NORTH = 1, EAST, SOUTH, WEST };

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

void copyRect(const SDL_Rect constRect, SDL_Rect *newRect) {
	newRect->x = constRect.x;
	newRect->y = constRect.y;
	newRect->w = constRect.w;
	newRect->h = constRect.h;
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

	if (leftA >= rightB)
		return false;
	if (leftB >= rightA)
		return false;
	if (topA >= bottomB)
		return false;
	if (topB >= bottomA)
		return false;

	return true;
}

void rotationalMovement(int *deltaX, int *deltaY, int angle, int speed) {
	int facing = 0;
	float sinT;
	float cosT;

	/*Checks to see if rotation is greater or less than 360*/
	if (angle >= 360)
		angle -= 360;
	if (angle < 0)
		angle += 360;
	
	if (angle == 0)
		facing = EAST;
	if (angle == 90)
		facing = NORTH;
	if (angle == 180)
		facing = WEST;
	if (angle == 270)
		facing = SOUTH;

	sinT = -1 * (sin(angle * PI / 180) * speed);
	cosT = cos(angle * PI / 180) * speed;

	*deltaX = cosT;
	*deltaY = sinT;

	switch (facing) {
	case NORTH:
		*deltaX = cosT;
		*deltaY = sinT + 1;
		break;
	case EAST:
		*deltaX = cosT - 1;
		*deltaY = sinT;
		break;
	case SOUTH:
		*deltaX = cosT;
		*deltaY = sinT - 1;
		break;
	case WEST:
		*deltaX = cosT + 1;
		*deltaY = sinT;
		break;
	}
}