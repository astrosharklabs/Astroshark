#include "statemanager.h"
#include "constants.h"
#include "SDL.h"
//Include States Here
#include "mainmenu.h"

void initialize_StateManager(SDL_Renderer *) {
 
  while (STATE != QUIT) {
   switch (STATE) {
     case MAIN_MENU:
       mainmenu(renderer);
       break;
     case START_GAME:
       break;
     case QUIT:
       break;
   }
  }
}
