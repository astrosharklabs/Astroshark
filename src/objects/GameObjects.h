#pragma once
#include "GameObjects\ship_classes.h"
#include "GameObjects\laser_classes.h"

#ifndef GameObjects_h
#define GameObjects_h

extern amadeusShip amadeus;
extern standardLaser laser_01;

void GameObjectsLoad_ArcadeMode();
void GameObjectsRender_ArcadeMode(SDL_Renderer *);

#endif