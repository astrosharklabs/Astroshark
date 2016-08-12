/*Sprite properties and functions that can be used for sprites*/
#pragma once
#ifndef sprite_h
#define sprite_h

#include "SDL.h"

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

typedef struct RGBA {
	int r;
	int g;
	int b;
	int a;
} RGBA;

/*Takes a texture and queries it onto a rectangle, thereby creating a sprite*/
void createSprite(struct SDL_Renderer *, int *, int *, struct SDL_Texture **, const char *);
#endif