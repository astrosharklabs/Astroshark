#pragma once
#include "GameObjects\ship_classes.h"
#include "GameObjects\laser_classes.h"
#include "GameObjects\asteroid_classes.h"

#ifndef GameObjects_h
#define GameObjects_h

extern amadeusShip amadeus;
extern standardAsteroid smallAsteroid[24];
extern standardAsteroid mediumAsteroid[8];
extern standardAsteroid largeAsteroid[2];

void GameObjectsLoad_ArcadeMode();
void GameObjectsUpdate_ArcadeMode();
void GameObjectsRender_ArcadeMode(SDL_Renderer *);

#endif