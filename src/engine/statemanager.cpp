#include "statemanager.h"
#include "constants.h"
#include "SDL.h"
//Include States Here
#include "../states/mainmenu.h"
#include "../states/arcadeMode.h"

void initialize_StateManager(SDL_Renderer *renderer) {

	while (STATE != QUIT) {

		switch (STATE) {
		case MAIN_MENU:
			mainmenu(renderer);
			break;
		case START_GAME:
			arcadeMode(renderer);
			break;
		case OPTIONS:
			STATE = MAIN_MENU; //Temporary
			break;
		case CREDITS:
			STATE = MAIN_MENU; //Temporary
			break;
		case QUIT:
			break;
		}
	}
}
