/*Sprite properties and functions that can be used for sprites*/
#pragma once
#ifndef sprite_h
#define sprite_h

#include "SDL.h"
//enum orientation {NORTH, EAST, SOUTH, WEST};
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
	int angle;
	SDL_Rect dstrect; //Relative to the screen
	SDL_Rect srcrect;
	SDL_Texture *texture;
} defaultProp;

typedef struct basicMovement {
	int deltaX;
	int deltaY;
	int deltaAngle;
	int movementSpeed;
	int rotateSpeed;
	SDL_Point origin;
	SDL_Rect domain;
	SDL_Rect Gdstrect;
} basicMovement;

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

void setRectXY(int x, int y, SDL_Rect *rect);

/*Copies constRect into newRect*/
void copyRect(const SDL_Rect constRect, SDL_Rect *newRect);

bool testCollision(SDL_Rect a, SDL_Rect b);

void rotationalMovement(int *deltaX, int *deltaY, int angle, int speed);
#endif