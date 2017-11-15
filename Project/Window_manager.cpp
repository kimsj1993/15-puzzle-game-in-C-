
#include "Window_manager.h"

const int WINDOW_X = 640;
const int WINDOW_Y = 480;
const int ORIG_X = 640;
const int ORIG_Y = 300;

Window_manager::Window_manager() {}

void Window_manager::start_game_sequence() {
	int choice;
	bool game = true;
	bool replay = true;
	while(game) {
		choice = init_main_window();
		if (choice == 1) {
			init_initials();
			choice = init_difficulty();
			while(replay) 
				replay = init_game(choice);
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

int Window_manager::init_main_window() {
	Main_window menu{ Point{ ORIG_X,ORIG_Y }, WINDOW_X, WINDOW_Y, "Main Menu" };
	menu.wait_for_button();
	menu.quit();
	return menu.get_choice();
}

void Window_manager::init_help() {
	Help_window help{ Point{ ORIG_X,ORIG_Y }, WINDOW_X, WINDOW_Y, "Help" };
	help.wait_for_button();
	help.quit();
}

int Window_manager::init_difficulty() {
	Difficulty_window difficulty{ Point{ ORIG_X,ORIG_Y }, WINDOW_X, WINDOW_Y, "Difficulty" };
    difficulty.wait_for_button();
    difficulty.quit();
    return difficulty.get_choice();
}

void Window_manager::init_initials() {
	Initials_window initials{ Point{ ORIG_X,ORIG_Y }, WINDOW_X, WINDOW_Y, "Initials" };
    initials.wait_for_button();
	user_initial = initials.get_initials();
    initials.quit();
}

bool Window_manager::init_game(int difficulty) { 
	Game game{ difficulty, user_initial };
	Game_window game_window(Point{ 320, 180 }, 1280, 720, "Game", game);
	game_window.wait_for_button();
	game_window.quit();
	return false;
}
