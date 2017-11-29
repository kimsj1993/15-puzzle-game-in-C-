//
//  Game.cpp
//  Team 4 - 'Please Compile'
//
//  Created by SeungJin Kim on 11/10/17.
//  Copyright © 2017 SeungJin Kim. All rights reserved.

#include "Game.h"

Game::Game(int difficulty, string initials)
	: difficulty{ difficulty }, initials{ initials }, move_count{ 0 }
{
	load_top_scores(); // Load scores from 'Scores.txt'
        tiles_incorrect_position = 0;
	switch (difficulty) { // Determines number of moves given to user
	case 1:
		moves_left = 10; break;
	case 2:
		moves_left = 20; break;
	case 3:
		moves_left = 40; break;
	case 4:
		moves_left = 80; break;
	}
}

// Getters and Setters
void Game::set_moves_left(int num) {
	moves_left = num;
}

int Game::get_moves_left() {
	return moves_left;
}

void Game::set_num_tiles_incorrect_position(int n) {
	tiles_incorrect_position = n;
}

int Game::get_num_tiles_incorrect_position() {
	return tiles_incorrect_position;
}

int Game::get_difficulty() {
	return difficulty;
}

Vector<User_score>& Game::get_top_scores() {
	return top_scores;
}

Vector<User_score>& Game::get_different_difficulties() {
	return different_difficulties;
}

void Game::set_move_count(int num) {
	move_count = num;
}

int Game::get_move_count() {
	return move_count;
}

// Loads scores from file
void Game::load_top_scores() {
	string line;
	User_score user(initials, 0, difficulty);
	fstream file("Scores.txt", ios::in|ios::out);
	// Open file or create it if DNE
	if (file) { // If file is open
		User_score temp("", 0, 0);
		while (file >> temp) {
			if (temp.get_difficulty() == difficulty)
				top_scores.push_back(temp);
			else
				different_difficulties.push_back(temp);
		}
		file << flush;
		file.close();
	}
	top_scores.push_back(user);
}
