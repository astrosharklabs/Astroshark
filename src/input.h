#pragma once
#ifndef input_h
#define input_h
namespace input {
	extern bool a_key;
	extern bool b_key;
	extern bool c_key;
	extern bool d_key;
	extern bool e_key;
	extern bool f_key;
	extern bool g_key;
	extern bool h_key;
	extern bool i_key;
	extern bool j_key;
	extern bool k_key;
	extern bool l_key;
	extern bool m_key;
	extern bool n_key;
	extern bool o_key;
	extern bool p_key;
	extern bool q_key;
	extern bool r_key;
	extern bool s_key;
	extern bool t_key;
	extern bool u_key;
	extern bool v_key;
	extern bool w_key;
	extern bool x_key;
	extern bool y_key;
	extern bool z_key;

	extern bool enter_key;
	extern bool escape_key;
	extern bool space_key;

	extern bool up_key;
	extern bool down_key;
	extern bool left_key;
	extern bool right_key;

	extern bool mouseMotion;
	extern bool left_mouse;

	extern int mouseX;
	extern int mouseY;
}

extern bool close_requested;

void checkInput();
#endif