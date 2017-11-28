//
//  Game_over_window.h
//  Team 4 - 'Please Compile'
//
//  Created by Daniel Hain-Trevino.
//  Copyright © 2017 Daniel Hain-Trevino. All rights reserved.

#ifndef GAME_OVER_WINDOW
#define GAME_OVER_WINDOW

#include "Simple_window.h"

class Game_over_window : Graph_lib::Window {
	Rectangle background;
	Text score;
	Text game_over_text;
	Button play_button;
	Button quit_button;
	Rectangle play_button_cover;
	Rectangle quit_button_cover;
	Text play_button_text;
	Text quit_button_text;
	bool button_pushed;
	int selection;
	int final_score;
	int difficulty;

	void check_win();
	void stylize_objects();
	void attach_objects();
public:
	Game_over_window(Point xy, int w, int h, const string& title, int final_score, int difficulty);
	void wait_for_button();
	bool change_state(bool choice);
	bool get_choice() { return selection; }
	void quit();
};

#endif
