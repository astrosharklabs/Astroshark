#pragma once
#include "GameObjects\ship_classes.h"

#ifndef GameObjects_h
#define GameObjects_h

extern amadeusShip amadeus;

void GameObjectsLoad_ArcadeMode();
void GameObjectsRender_ArcadeMode(SDL_Renderer *);

#endif