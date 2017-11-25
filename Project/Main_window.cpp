//
//  Main_window.cpp
//  Team 4 - 'Please Compile'
//
//  Created by Luke Grammer
//  Copyright © 2017 Luke Grammer. All rights reserved.

#include "Main_window.h"
#include "Graph.h"

Main_window::Main_window(Point xy, int w, int h, const string& title)
	:Window{ xy,w,h,title },
	background{ Point{0, 0}, Point{x_max(), y_max()} },
	splash_text1{ Point{ 25, 40 }, "PLEASE COMPILE - THE 16 GAME" },
	splash_text2{ Point{ 25, 65 }, "By Team 4 - Luke Grammer, Daniel Hain-Trevino, and Seungjin Kim" },
	start_button{ Point{ x_max() / 2 - 70, y_max() / 2 }, 140, 40, "Play",
		[](Address, Address pw) {reference_to<Main_window>(pw).change_state(1); } },
	help_button{ Point{ x_max() / 2 - 35, y_max() / 2 + 80 }, 70, 20, "Help",
		[](Address, Address pw) {reference_to<Main_window>(pw).change_state(2); } },
	quit_button{ Point{ x_max() / 2 - 35, y_max() / 2 + 140 }, 70, 20, "Quit",
		[](Address, Address pw) {reference_to<Main_window>(pw).change_state(0); } }, // C++11 features (lambda expressions)
	start_button_cover{ Point{ x_max() / 2 - 70, y_max() / 2 }, Point{ x_max() / 2 - 70 + 140, y_max() / 2 + 40} },
	help_button_cover{ Point{ x_max() / 2 - 35, y_max() / 2 + 80 }, Point{ x_max() / 2 - 35 + 70, y_max() / 2 + 80 + 20 } },
	quit_button_cover{ Point{ x_max() / 2 - 35, y_max() / 2 + 140 }, Point{ x_max() / 2 - 35 + 70, y_max() / 2 + 140 + 20 } },
	start_button_text{ Point{ x_max() / 2 - 70 + 55, y_max() / 2 + 25}, "Play" },
	help_button_text{ Point{ x_max() / 2 - 35 + 20, y_max() / 2 + 80 + 15 }, "Help" },
	quit_button_text{ Point{ x_max() / 2 - 35 + 20, y_max() / 2 + 140 + 15}, "Quit" },
	button_pushed{ false },
	selection{ 0 }
{
	stylize_objects();
	attach_objects();
}

void Main_window::stylize_objects() {
	// Changes appearance of objects
	background.set_fill_color(Color::white);
	splash_text1.set_font_size(35);
	splash_text2.set_font_size(15);
}

void Main_window::attach_objects() {
	// Attaches all objects to window
	attach(background);
	attach(splash_text1);
	attach(splash_text2);
	attach(start_button);
	attach(help_button);
	attach(quit_button);
	attach(start_button_cover);
	attach(help_button_cover);
	attach(quit_button_cover);
	attach(start_button_text);
	attach(help_button_text);
	attach(quit_button_text);
}

void Main_window::quit() {
	hide(); // Closes window
}

int Main_window::change_state(int choice) {
	// Detects button push, and returns which button was pushed
	button_pushed = true;
	selection = choice;
	return choice;
}

void Main_window::wait_for_button() {
	// Waits for button push
	show();
	while (!button_pushed) {
		Fl::wait();
	}
}