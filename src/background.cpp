#include "background.h"
#include "SDL.h"
#include "textures.h"
#include "constants.h"
#include "sprite.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
enum designationLocation { TL, TR, BL, BR }; //Top Left, Top Right, Bottom Left, Bottom Right

SDL_Point bckgrdOrigin;

int bckgrdOrder[4] = { 0, 1, 2, 3 };

void background::setup(int x, int y, int w, int h) {
	prop.dstrect.x = x;
	prop.dstrect.y = y;
	prop.dstrect.w = w;
	prop.dstrect.h = h;

	std::srand(std::time(0));

	prop.defaultOrientation = std::rand() % 4;
	prop.defaultOrientation *= 90;
}

void background::setXY(int x, int y) {
	prop.dstrect.x = x;
	prop.dstrect.y = y;
}

void background::render(SDL_Renderer *renderer) {
	if (testCollision(prop.dstrect, mainCamera.rect) == true)
		SDL_RenderCopyEx(renderer, background_texture, NULL, &prop.dstrect, prop.defaultOrientation, NULL, SDL_FLIP_NONE);
}

void background::orientate(int angle) {
	prop.defaultOrientation = angle;
}

void delta() {

}

void bckgrdLoad() {
	int i;
	i = 0;

	int x, y;
	int w, h;
	w = 1920;
	h = 1920;

	bckgrdOrigin.x = WINDOW_WIDTH - mainCamera.rect.x;
	bckgrdOrigin.y = WINDOW_HEIGHT - mainCamera.rect.y;

	x = bckgrdOrigin.x - 1920;
	y = bckgrdOrigin.y - 1920;

	bckgrd[0].setup(x, y, w, h);
	bckgrd[0].designation = TL;
	x += 1920;
	bckgrd[1].setup(x, y, w, h);
	bckgrd[1].designation = TR;
	x -= 1920;
	y += 1920;
	bckgrd[2].setup(x, y, w, h);
	bckgrd[2].designation = BL;
	x += 1920;
	bckgrd[3].setup(x, y, w, h);
	bckgrd[3].designation = BR;

	bckgrd[0].orientate(180);
}

void bckgrdRender(SDL_Renderer *renderer) {
	int i;
	for (i = 0; i < 4; i++) {
		bckgrd[i].render(renderer);
	}
}

void swapOrder(int a, int b) {
	int temp;
	temp = bckgrdOrder[a];
	bckgrdOrder[a] = bckgrdOrder[b];
	bckgrdOrder[b] = temp;
}

void bckgrdUpdate() {
	
	bckgrd[bckgrdOrder[TL]].prop.dstrect.x = bckgrdOrigin.x - bckgrd[bckgrdOrder[TL]].prop.dstrect.w;
	bckgrd[bckgrdOrder[BL]].prop.dstrect.x = bckgrdOrigin.x - bckgrd[bckgrdOrder[BL]].prop.dstrect.w;
	bckgrd[bckgrdOrder[TR]].prop.dstrect.x = bckgrdOrigin.x;
	bckgrd[bckgrdOrder[BR]].prop.dstrect.x = bckgrdOrigin.x;

	bckgrd[bckgrdOrder[TL]].prop.dstrect.y = bckgrdOrigin.y - bckgrd[bckgrdOrder[TL]].prop.dstrect.h;
	bckgrd[bckgrdOrder[TR]].prop.dstrect.y = bckgrdOrigin.y - bckgrd[bckgrdOrder[TR]].prop.dstrect.h;
	bckgrd[bckgrdOrder[BL]].prop.dstrect.y = bckgrdOrigin.y;
	bckgrd[bckgrdOrder[BR]].prop.dstrect.y = bckgrdOrigin.y;

	//Stitching
	if (bckgrd[bckgrdOrder[TL]].prop.dstrect.x + mainCamera.rect.x  > mainCamera.rect.x || bckgrd[bckgrdOrder[BL]].prop.dstrect.x + mainCamera.rect.x  > mainCamera.rect.x) {
		bckgrd[bckgrdOrder[TR]].prop.dstrect.x = bckgrd[bckgrdOrder[TL]].prop.dstrect.x - bckgrd[bckgrdOrder[TR]].prop.dstrect.w - mainCamera.rect.x;
		bckgrd[bckgrdOrder[BR]].prop.dstrect.x = bckgrd[bckgrdOrder[BL]].prop.dstrect.x - bckgrd[bckgrdOrder[BR]].prop.dstrect.w - mainCamera.rect.x;
		swapOrder(TL, TR);
		swapOrder(BL, BR);
		bckgrdOrigin.x -= bckgrd[bckgrdOrder[TR]].prop.dstrect.w;
	}

	if (bckgrd[bckgrdOrder[TR]].prop.dstrect.x + bckgrd[bckgrdOrder[TR]].prop.dstrect.w + mainCamera.rect.x < mainCamera.rect.x + mainCamera.rect.w || bckgrd[bckgrdOrder[BR]].prop.dstrect.x + bckgrd[bckgrdOrder[BR]].prop.dstrect.w + mainCamera.rect.x  < mainCamera.rect.x + mainCamera.rect.w) {
		bckgrd[bckgrdOrder[TL]].prop.dstrect.x = bckgrd[bckgrdOrder[TR]].prop.dstrect.x + bckgrd[bckgrdOrder[TR]].prop.dstrect.w - mainCamera.rect.x;
		bckgrd[bckgrdOrder[BL]].prop.dstrect.x = bckgrd[bckgrdOrder[BR]].prop.dstrect.x + bckgrd[bckgrdOrder[BR]].prop.dstrect.w - mainCamera.rect.x;
		swapOrder(TL, TR);
		swapOrder(BL, BR);
		bckgrdOrigin.x += bckgrd[bckgrdOrder[TL]].prop.dstrect.w;
	}

	if (bckgrd[bckgrdOrder[TL]].prop.dstrect.y + mainCamera.rect.y  > mainCamera.rect.y || bckgrd[bckgrdOrder[TR]].prop.dstrect.y + mainCamera.rect.y > mainCamera.rect.y) {
		bckgrd[bckgrdOrder[BL]].prop.dstrect.y = bckgrd[bckgrdOrder[TL]].prop.dstrect.y - bckgrd[bckgrdOrder[BL]].prop.dstrect.h - mainCamera.rect.y;
		bckgrd[bckgrdOrder[BR]].prop.dstrect.y = bckgrd[bckgrdOrder[TR]].prop.dstrect.y - bckgrd[bckgrdOrder[BR]].prop.dstrect.h - mainCamera.rect.y;
		swapOrder(TL, BL);
		swapOrder(TR, BR);
		bckgrdOrigin.y -= bckgrd[bckgrdOrder[BL]].prop.dstrect.h;
	}

	if (bckgrd[bckgrdOrder[BL]].prop.dstrect.y + bckgrd[bckgrdOrder[BL]].prop.dstrect.h + mainCamera.rect.y < mainCamera.rect.y + mainCamera.rect.h || bckgrd[bckgrdOrder[BR]].prop.dstrect.y + bckgrd[bckgrdOrder[BR]].prop.dstrect.h + mainCamera.rect.y < mainCamera.rect.y + mainCamera.rect.h) {
		bckgrd[bckgrdOrder[TL]].prop.dstrect.y = bckgrd[bckgrdOrder[BL]].prop.dstrect.y + bckgrd[bckgrdOrder[TL]].prop.dstrect.h - mainCamera.rect.y;
		bckgrd[bckgrdOrder[TR]].prop.dstrect.y = bckgrd[bckgrdOrder[BR]].prop.dstrect.y + bckgrd[bckgrdOrder[TR]].prop.dstrect.h - mainCamera.rect.y;
		swapOrder(TL, BL);
		swapOrder(TR, BR);
		bckgrdOrigin.y += bckgrd[bckgrdOrder[BR]].prop.dstrect.h;
	}
}

void bckgrdMove(int deltaX, int deltaY) {
	bckgrdOrigin.x += deltaX;
	bckgrdOrigin.y += deltaY;
	bckgrdUpdate();
}