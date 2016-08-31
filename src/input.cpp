#include "input.h"
#include "SDL.h"
#include "constants.h"

bool input::a_key = false;
bool input::b_key = false;
bool input::c_key = false;
bool input::d_key = false;
bool input::e_key = false;
bool input::f_key = false;
bool input::g_key = false;
bool input::h_key = false;
bool input::i_key = false;
bool input::j_key = false;
bool input::k_key = false;
bool input::l_key = false;
bool input::m_key = false;
bool input::n_key = false;
bool input::o_key = false;
bool input::p_key = false;
bool input::q_key = false;
bool input::r_key = false;
bool input::s_key = false;
bool input::t_key = false;
bool input::u_key = false;
bool input::v_key = false;
bool input::w_key = false;
bool input::x_key = false;
bool input::y_key = false;
bool input::z_key = false;

bool input::enter_key = false;
bool input::escape_key = false;
bool input::space_key = false;

bool input::up_key = false;
bool input::down_key = false;
bool input::left_key = false;
bool input::right_key = false;

bool input::mouseMotion = false;
bool input::left_mouse = false;
bool input::middle_mouse = false;
bool input::right_mouse = false;

int input::mouseX = 0;
int input::mouseY = 0;

void checkInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			SCREEN = QUIT;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.scancode) {
			case SDL_SCANCODE_W:
				input::w_key = true;
				break;
			case SDL_SCANCODE_A:
				input::a_key = true;
				break;
			case SDL_SCANCODE_S:
				input::s_key = true;
				break;
			case SDL_SCANCODE_D:
				input::d_key = true;
				break;
			case SDL_SCANCODE_SPACE:
				input::space_key = true;
				break;
			case SDL_SCANCODE_UP:
				input::up_key = true;
				break;
			case SDL_SCANCODE_DOWN:
				input::down_key = true;
				break;
			case SDL_SCANCODE_LEFT:
				input::left_key = true;
				break;
			case SDL_SCANCODE_RIGHT:
				input::right_key = true;
				break;
			case SDL_SCANCODE_RETURN:
				input::enter_key = true;
				break;
			}
			break;
		case SDL_KEYUP:
			switch(event.key.keysym.scancode) {
			case SDL_SCANCODE_W:
				input::w_key = false;
				break;
			case SDL_SCANCODE_A:
				input::a_key = false;
				break;
			case SDL_SCANCODE_S:
				input::s_key = false;
				break;
			case SDL_SCANCODE_D:
				input::d_key = false;
				break;
			case SDL_SCANCODE_SPACE:
				input::space_key = false;
				break;
			case SDL_SCANCODE_UP:
				input::up_key = false;
				break;
			case SDL_SCANCODE_DOWN:
				input::down_key = false;
				break;
			case SDL_SCANCODE_LEFT:
				input::left_key = false;
				break;
			case SDL_SCANCODE_RIGHT:
				input::right_key = false;
				break;
			case SDL_SCANCODE_RETURN:
				input::enter_key = false;
				break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button) {
			case SDL_BUTTON_LEFT:
				input::left_mouse = true;
				break;
			case SDL_BUTTON_MIDDLE:
				input::middle_mouse = true;
				break;
			case SDL_BUTTON_RIGHT:
				input::right_mouse = true;
				break;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button) {
			case SDL_BUTTON_LEFT:
				input::left_mouse = false;
				break;
			case SDL_BUTTON_MIDDLE:
				input::middle_mouse = false;
				break;
			case SDL_BUTTON_RIGHT:
				input::right_mouse = false;
				break;
			}
		}
	}
}