//
//  Game.h
//  Team 4 - 'Please Compile'
//
//  Created by SeungJin Kim on 11/10/17.
//  Copyright © 2017 SeungJin Kim. All rights reserved.

#ifndef GAME
#define GAME

#include "User_score.h"

class Game {
	int difficulty;
	int moves_left;
	string initials;
	int move_count;
	int tiles_incorrect_position;
	Vector<User_score> top_scores;
	Vector<User_score> different_difficulties;
	void load_top_scores();

public:
	Game(int difficulty, string initials);

	void set_moves_left(int n);
	int get_moves_left();
	void set_move_count(int n);
	int get_move_count();
	void set_num_tiles_incorrect_position(int n);
	int get_num_tiles_incorrect_position();
	int get_difficulty();
	Vector<User_score>& get_top_scores();
	Vector<User_score>& get_different_difficulties();
};

#endif