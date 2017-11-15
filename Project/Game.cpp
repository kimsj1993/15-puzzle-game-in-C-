//
//  Game.cpp
//  TeamProject
//
//  Created by 김승진 on 11/10/17.
//  Copyright © 2017 SeugnJin Kim. All rights reserved.
//

#include "Game.h"


Game::Game(int difficulty, string initials)
	: difficulty{ difficulty }, initials{ initials }
{
	load_top_scores();

	switch (difficulty) {
	case 1:
		moves_left = 10;
		tiles_in_position = 10;
		break;
	case 2:
		moves_left = 20;
		tiles_in_position = 7;
		break;
	case 3:
		moves_left = 30;
		break;
	case 4:
		moves_left = 40;
		break;

	}
}

void Game::set_moves_left(int num) {
	moves_left = num;
}

int Game::get_moves_left() {
	return moves_left;
}
void Game::set_num_tiles_in_position(int n) {
	tiles_in_position = n;
}
int Game::get_num_tiles_in_position() {
	return tiles_in_position;
}

int Game::get_difficulty() {
	return difficulty;
}

Vector<User_score>& Game::get_top_scores() {
	return top_scores;
}

void Game::load_top_scores() {
	string line;
	User_score user(initials, 0, difficulty);

	//get scores from the file
	ifstream file("Scores.txt");
	if (file.is_open()) {
		User_score temp("", 0, 0);
		file >> temp;
		top_scores.push_back(temp);
		while (getline(file, line)) {
			file >> temp;
			if (temp.get_difficulty() == difficulty) {
				top_scores.push_back(temp);
			}
		}
		file.close();
	}
	top_scores.push_back(user);
}



