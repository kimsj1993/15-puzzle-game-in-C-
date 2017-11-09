
#include "Window_manager.h"

const int WINDOW_X = 640;
const int WINDOW_Y = 480;
const int ORIG_X = 440;
const int ORIG_Y = 180;

Window_manager::Window_manager() {}

void Window_manager::start_game_sequence() {
	int choice;
	bool game = true;
	while(game) {
		choice = init_main_menu();
		if (choice == 1) {
			init_initials();
			choice = init_difficulty();
			init_game(choice);
			game = false;
		}
		else if (choice == 2) {
			init_help();
		}
		else {
			game = false;
		}
	}
}

int Window_manager::init_main_menu() {
	Main_menu menu{ Point{ ORIG_X,ORIG_Y }, WINDOW_X, WINDOW_Y, "Main Menu" };
	menu.wait_for_button();
	menu.quit();
	return menu.get_choice();
}

void Window_manager::init_help() {
	Simple_window help{ Point{ ORIG_X,ORIG_Y }, WINDOW_X, WINDOW_Y, "Help" };
	help.wait_for_button();
	//help.quit();
}

int Window_manager::init_difficulty() {
	Difficulty_menu difficulty{ Point{ ORIG_X,ORIG_Y }, WINDOW_X, WINDOW_Y, "Difficulty" };
        difficulty.wait_for_button();
        difficulty.quit();
        return difficulty.get_choice();
}

void Window_manager::init_initials() {
	Simple_window initials{ Point{ ORIG_X,ORIG_Y }, WINDOW_X, WINDOW_Y, "Initials" };
	initials.wait_for_button();
	//initials.quit();
}

void Window_manager::init_game(int difficulty) {
	int temp = difficulty;
        if(temp == 1) { Simple_window game{ Point{ 120, 58 }, 1280, 720, "Game (Easy)" }; game.wait_for_button(); }
        if(temp == 2) { Simple_window game{ Point{ 120, 58 }, 1280, 720, "Game (Normal)" }; game.wait_for_button(); }
        if(temp == 3) { Simple_window game{ Point{ 120, 58 }, 1280, 720, "Game (Hard)" }; game.wait_for_button(); }
        if(temp == 4) { Simple_window game{ Point{ 120, 58 }, 1280, 720, "Game (Expert)" }; game.wait_for_button(); }

	//game.quit();
}
