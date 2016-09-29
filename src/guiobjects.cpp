#include "SDL.h"
#include "title.h"
#include "camera.h"
#include "buttons.h"
#include "constants.h"

title title;
button options_button(290, 375, 700, 50);
button credits_button(290, 425, 700, 50);
button quit_button(290, 475, 700, 50);

void GUILoad() {
  
  startgame_button.defFrame(0, 0, 700, 50, 0);
  startgame_button.defFrame(700, 0, 700, 50, 1);
  startgame_button.dsetFrame(0);
  startgame_button.setCollision(0, 325, 1280, 50);
  
  options_button.defFrame(0, 50, 700, 50, 0);
	options_button.defFrame(700, 50, 700, 50, 1);
	options_button.setFrame(0);
	options_button.setCollision(0, 375, 1280, 50);
  
  credits_button.defFrame(0, 100, 700, 50, 0);
	credits_button.defFrame(700, 100, 700, 50, 1);
	credits_button.setFrame(0);
	credits_button.setCollision(0, 425, 1280, 50);
  
  quit_button.defFrame(0, 150, 700, 50, 0);
	quit_button.defFrame(700, 150, 700, 50, 1);
	quit_button.setFrame(0);
	quit_button.setCollision(0, 475, 1280, 50);
}
