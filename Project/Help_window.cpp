//
//  Help_window.cpp
//  Team 4 - 'Please Compile'
//
//  Created by Luke Grammer
//  Copyright © 2017 Luke Grammer. All rights reserved.

#include "Help_window.h"

Help_window::Help_window(Point xy, int w, int h, const string& title)
	:Window{ xy,w,h,title },
	background{ Point{ 0, 0 }, Point{ x_max(), y_max() } },
	help_text_main{ Point{ 25, 40 }, "INSTRUCTIONS" },
	back_button{ Point{ x_max() / 2 - 35, y_max() / 2 + 80 }, 70, 20, "Back", [](Address, Address pw) {reference_to<Help_window>(pw).change_state(); } },
	back_button_cover{ Point{ x_max() / 2 - 35, y_max() / 2 + 80 }, Point{ x_max() / 2 - 35 + 70, y_max() / 2 + 80 + 20 } },
	back_button_text{ Point{ x_max() / 2 - 35 + 20, y_max() / 2 + 80 + 15 }, "Back" },
	button_pushed{ false }
{
	help_text.push_back(new Text(Point{ 25, 65 }, "After selecting 'play' from the main menu, enter your initials")),
	help_text.push_back(new Text(Point{ 25, 90 }, "and select 'next', then choose a difficulty. After a difficulty")),
	help_text.push_back(new Text(Point{ 25, 115 }, "is chosen, the game will be displayed. To play the game, click on")),
	help_text.push_back(new Text(Point{ 25, 140 }, "any tile adjacent to the blank tile to swap them. The game will")),
	help_text.push_back(new Text(Point{ 25, 165 }, "be over once all tiles are in the correct order or there are no")),
	help_text.push_back(new Text(Point{ 25, 190 }, "more moves remaining. score is calculated by the following equation:")),
	help_text.push_back(new Text(Point{ 25, 220 }, "     score = 'number of moves made' * 'tiles in correct position'.")),
	help_text.push_back(new Text(Point{ 25, 250 }, "You can get a hint at any time during the game by selecting the 'hint' button.")),
	stylize_objects();
	attach_objects();
}

void Help_window::stylize_objects() { // Change appearance of screen objects
	background.set_fill_color(Color::white);
	help_text_main.set_font_size(35);
	for (unsigned i = 0; i < help_text.size(); ++i)
		help_text[i].set_font_size(15);
}

void Help_window::attach_objects() { // Attach objects to window
	attach(background);
	attach(help_text_main);
	attach(back_button);
	attach(back_button_cover);
	attach(back_button_text);
	for (unsigned i = 0; i < help_text.size(); ++i)
		attach(help_text[i]);
}

void Help_window::quit() { // Close window
	hide();
}

void Help_window::change_state() { // Detects button push
	button_pushed = true;
}

void Help_window::wait_for_button() { // Wait for button push
	show();
	while (!button_pushed) {
		Fl::wait();
	}
}