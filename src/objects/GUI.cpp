#include <stdio.h>
#include "SDL.h"
#include "../engine/constants.h"
#include "../engine/timer.h"
#include "GUI/mainmenu_class.h"

timer GUIkeydown_timer;

mainMenu_class mainMenu;

void GUILoad() {

	GUIkeydown_timer.setup();
	
	mainMenu.initialize();
}

void GUIRender_MainMenu(SDL_Renderer *renderer) {
	mainMenu.render(renderer);
}
