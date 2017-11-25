//
//  Initials_window.cpp
//  Team 4 - 'Please Compile'
//
//  Created by Daniel Hain-Trevino
//  Copyright © 2017 Daniel Hain-Trevino. All rights reserved.

#include "Initials_window.h"
#include "Graph.h"

Initials_window::Initials_window(Point xy, int w, int h, const string& title)
	:Window{ xy,w,h,title },
	background_top{ Point{0, 0}, Point{640, y_max() / 2} },
	background_left{ Point{0, 0}, Point{x_max() / 2 - 70, 480} },
	background_bottom{ Point{0, y_max() / 2 + 40}, Point{640, 480} },
	background_right{ Point{x_max() / 2 + 70, 0}, Point{640, 480} },
	initials_text{ Point{ 25, 40 }, "Input your initials:" },
	initials_input{ Point{ x_max() / 2 - 70, y_max() / 2 }, 140, 40, "" },
	initials_button{ Point { x_max() / 2 - 35, y_max() / 2 + 50 }, 70, 20, "Enter", [](Address, Address pw) {reference_to<Initials_window>(pw).store_init(); } },
	initials_button_cover{ Point { x_max() / 2 - 35, y_max() / 2 + 50 }, Point{ x_max() / 2 + 35, y_max() / 2 + 70} },
	initials_input_cover{ Point { x_max() / 2 - 70, y_max() / 2 }, Point{ x_max() / 2 + 70, y_max() / 2 + 40} },
	initials_button_text{ Point{ x_max() / 2 - 35 + 15, y_max() / 2 + 65 }, "Enter" },
	initials_string{ "" },
	button_pushed{ false }
{
	stylize_objects();
	attach_objects();
}

void Initials_window::stylize_objects() { // Changes appearance of objects
	background_top.set_fill_color(Color::white);
	background_left.set_fill_color(Color::white);
	background_bottom.set_fill_color(Color::white);
	background_right.set_fill_color(Color::white);
	background_top.set_color(Color::white);
	background_left.set_color(Color::white);
	background_bottom.set_color(Color::white);
	background_right.set_color(Color::white);
	initials_text.set_font_size(35);
}

void Initials_window::attach_objects() { // Attaches objects
	attach(background_top);
	attach(background_left);
	attach(background_bottom);
	attach(background_right);
	attach(initials_text);
	attach(initials_input);
	attach(initials_button);
	attach(initials_button_cover);
	attach(initials_input_cover);
	attach(initials_button_text);
}

void Initials_window::store_init() { 
	// Stores initials & registers button push
	button_pushed = true;
	initials_string = initials_input.get_string();
}

void Initials_window::quit() { // Close window
	hide();
}

void Initials_window::wait_for_button() { // Wait for button push
	show();
	while (!button_pushed) {
		Fl::wait();
	}
}
