//
//  Window_manager.cpp
//  Team 4 - 'Please Compile'
//
//  Created by Luke Grammer
//  Copyright © 2017 Luke Grammer. All rights reserved.

#include "Window_manager.h"

const int WINDOW_X = 640; // Window size
const int WINDOW_Y = 480;
const int ORIG_X = 640; // Window origin
const int ORIG_Y = 300;

Window_manager::Window_manager() {}

void Window_manager::start_game_sequence() { // Runs the game
	int choice, score;
	bool game = true, replay = true;
	while (game) {
		choice = init_main_window(); // Display main menu
		if (choice == 1) {
			init_initials(); // Display initials screen
			while (replay) {
				choice = init_difficulty(); // Display difficulty screen
				score = init_game(choice); // Display game
				replay = init_game_over(score, choice); // Display game over
			}
			game = false; // Do not go back to main menu
		}
		else if (choice == 2) {
			init_help(); // Help screen
		}
		else {
			game = false; // Do not go back to main menu
		}
	}
}

int Window_manager::init_main_window() { // Display main menu
	Main_window menu{ Point{ ORIG_X,ORIG_Y }, WINDOW_X, WINDOW_Y, "Main Menu" };
	menu.wait_for_button();
	menu.quit();
	return menu.get_choice();
}

void Window_manager::init_help() { // Display help menu
	Help_window help{ Point{ ORIG_X,ORIG_Y }, WINDOW_X, WINDOW_Y, "Help" };
	help.wait_for_button();
	help.quit();
}

int Window_manager::init_difficulty() { // Display difficulty menu
	Difficulty_window difficulty{ Point{ ORIG_X,ORIG_Y }, WINDOW_X, WINDOW_Y, "Difficulty" };
	difficulty.wait_for_button();
	difficulty.quit();
	return difficulty.get_choice();
}

void Window_manager::init_initials() { // Display initials window
	Initials_window initials{ Point{ ORIG_X,ORIG_Y }, WINDOW_X, WINDOW_Y, "Initials" };
	initials.wait_for_button();
	user_initial = initials.get_initials();
	initials.quit();
}

int Window_manager::init_game(int difficulty) { // Display game
	Game game{ difficulty, user_initial };
	Game_window game_window(Point{ 320, 180 }, 1280, 720, "Game", game);
	game_window.wait_for_button();
	game_window.quit();
	return game_window.get_final_score();
}

bool Window_manager::init_game_over(int score, int difficulty) { // Display game over
	Game_over_window game_over{ Point{ ORIG_X,ORIG_Y }, WINDOW_X, WINDOW_Y, "Game Over", score, difficulty, user_initial};
	game_over.wait_for_button();
	game_over.quit();
	return game_over.get_choice();
}
