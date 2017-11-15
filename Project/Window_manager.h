#ifndef WINDOW_MANAGER
#define WINDOW_MANAGER

#include "Main_window.h"
#include "Difficulty_window.h"
#include "Help_window.h"
#include "Initials_window.h"
#include "Game_window.h"

class Window_manager {
	int init_main_window();
	void init_help();
	int init_difficulty();
	void init_initials();
	bool init_game(int difficulty);
	string user_initial;
public:
	Window_manager();
	void start_game_sequence();
};

#endif
