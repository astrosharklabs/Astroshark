/*Sprite properties and functions that can be used for sprites*/
#pragma once
#ifndef sprite_h
#define sprite_h

#include "SDL.h"

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
	SDL_Rect dstrect;
	SDL_Texture *texture;
} defaultProp;

typedef struct basicMove {
	int deltaX;
	int deltaY;
	int speed;
	int rotate;
} basicMove;

typedef struct animation {
	int totalFrames; //frame number?
	SDL_Rect frame[10];
} animation;

typedef struct collision {
	SDL_Rect hitbox; //Basic area which an object can come in contact OR The area that will hit the enemy
	SDL_Rect hurtbox; //Area that will damage yourself if you get hit in
} collision;

/*Takes a texture and queries it onto a rectangle, thereby creating a sprite*/
void loadPNGImageToTexture(SDL_Renderer *, int *, int *, SDL_Texture **, const char *);

void alphaIncrease(SDL_Texture *, int *, int);

void alphaDecrease(SDL_Texture *, int *, int);
#endif