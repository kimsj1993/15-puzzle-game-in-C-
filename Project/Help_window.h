//
//  Help_window.h
//  Team 4 - 'Please Compile'
//
//  Created by Luke Grammer
//  Copyright © 2017 Luke Grammer. All rights reserved.

#ifndef HELP_WINDOW
#define HELP_WINDOW

#include "Simple_window.h"

class Help_window : Graph_lib::Window {
	Rectangle background;
	Text help_text_main;
	Vector_ref<Text> help_text;
	Button back_button;
	Rectangle back_button_cover;
	Text back_button_text;
	bool button_pushed;

public:
	Help_window(Point xy, int w, int h, const string& title);
	void stylize_objects();
	void attach_objects();
	void change_state();
	void quit();
	void wait_for_button();

};
#endif
