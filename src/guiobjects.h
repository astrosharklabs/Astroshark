#include "SDL.h"
#include "title.h"
#include "camera.h"
#include "buttons.h"
#include "constants.h"

#ifndef guiobjects_h

extern title title;
extern button startgame_button;
extern button option_button;
extern button credits_button;
extern button quit_button;

void GUILoad();
void GUIRender(SDL_Renderer *);

#endif
