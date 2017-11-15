//
//  Game.hpp
//  TeamProject
//
//  Created by 김승진 on 11/10/17.
//  Copyright © 2017 SeugnJin Kim. All rights reserved.

#ifndef GAME
#define GAME

#include "User_score.h"

class Game {

	int difficulty;
	int moves_left;
	int tiles_in_position;
	string initials;
	Vector<User_score> top_scores;
	void load_top_scores();

public:
	Game(int difficulty, string initials);

	void set_moves_left(int n);
	int get_moves_left();
	void set_num_tiles_in_position(int n);
	int get_num_tiles_in_position();
	int get_difficulty();
	Vector<User_score>& get_top_scores();
};

#endif

