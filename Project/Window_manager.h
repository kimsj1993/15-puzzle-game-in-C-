//
//  Window_manager.h
//  Team 4 - 'Please Compile'
//
//  Created by Luke Grammer
//  Copyright © 2017 Luke Grammer. All rights reserved.

#ifndef WINDOW_MANAGER
#define WINDOW_MANAGER

#include "Main_window.h"
#include "Difficulty_window.h"
#include "Help_window.h"
#include "Initials_window.h"
#include "Game_window.h"
#include "Game_over_window.h"

class Window_manager {
	int init_main_window();
	void init_help();
	int init_difficulty();
	void init_initials();
	int init_game(int difficulty);
	bool init_game_over(int score, int difficulty);
	string user_initial;
public:
	Window_manager();
	void start_game_sequence();
};

#endif