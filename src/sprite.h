/*Sprite properties and functions that can be used for sprites*/
#pragma once
#ifndef sprite_h
#define sprite_h

#include "SDL.h"
enum orientation {NORTH, EAST, SOUTH, WEST};
/*TEMPORARY*/
typedef struct sprite {
	int deltaX;
	int deltaY;
	int speed;
	int rotate;
	int defaultOrientation;
	int totalFrames;
	int alpha;
	SDL_Rect dstrect;
	SDL_Rect frame[10];
} sprite;

typedef struct defaultProp {
	int alpha;
	int defaultOrientation;
	int frame;
	SDL_Rect dstrect;
	SDL_Rect srcrect;
	SDL_Texture *texture;
} defaultProp;

typedef struct basicMove {
	int deltaX;
	int deltaY;
	int speed;
	int rotate;
} basicMove;

typedef struct animation {
	SDL_Rect srcrect;
} animation;

typedef struct collision {
	SDL_Rect hitbox; //Basic area which an object can come in contact OR The area that will hit the enemy
	SDL_Rect hurtbox; //Area that will damage yourself if you get hit in
} collision;

/*Takes a texture and queries it onto a rectangle, thereby creating a sprite*/
void loadPNGImageToTexture(SDL_Renderer *, int *, int *, SDL_Texture **, const char *);

void setAlpha(SDL_Texture *, Uint8);

void alphaIncrease(SDL_Texture *, int *, int);

void alphaDecrease(SDL_Texture *, int *, int);

void setRect(int, int, int, int, SDL_Rect *);

bool testCollision(SDL_Rect, SDL_Rect);
#endif