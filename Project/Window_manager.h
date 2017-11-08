#ifndef WINDOW_MANAGER
#define WINDOW_MANAGER

#include "Main_menu.h"

class Window_manager {
	int init_main_menu();
	void init_help();
	int init_difficulty();
	void init_initials();
	void init_game(int difficulty);
public:
	Window_manager();
	void start_game_sequence();
};

#endif
