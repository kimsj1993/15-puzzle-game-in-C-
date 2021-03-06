//
//  Difficulty_window.h
//  Team 4 - 'Please Compile'
//
//  Created by Daniel Hain-Trevino.
//  Copyright � 2017 Daniel Hain-Trevino. All rights reserved.

#ifndef DIFFICULTY_WINDOW
#define DIFFICULTY_WINDOW

#include "Simple_window.h"

class Difficulty_window : Graph_lib::Window {
	Rectangle background;
	Text difficulty_text;
	Button easy_button;
	Button normal_button;
	Button hard_button;
	Button expert_button;
	Rectangle easy_button_cover;
	Rectangle normal_button_cover;
	Rectangle hard_button_cover;
	Rectangle expert_button_cover;
	Text easy_button_text;
	Text normal_button_text;
	Text hard_button_text;
	Text expert_button_text;

	bool button_pushed;
	int selection;
	void stylize_objects();
	void attach_objects();
public:
	Difficulty_window(Point xy, int w, int h, const string& title);
	void wait_for_button();
	int change_state(int choice);
	int get_choice() { return selection; }
	void quit();
};

#endif
