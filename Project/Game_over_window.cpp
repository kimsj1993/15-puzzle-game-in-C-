//
//  Game_over_window.cpp
//  Team 4 - 'Please Compile'
//
//  Created by Daniel Hain-Trevino.
//  Copyright © 2017 Daniel Hain-Trevino. All rights reserved.

#include "Game_over_window.h"
#include "Graph.h"

Game_over_window::Game_over_window(Point xy, int w, int h, const string& title, int final_score)
	:Window{ xy,w,h,title },
	background{ Point{0, 0}, Point{x_max(), y_max()} },
	score{ Point{ x_max() / 2 - 75, y_max() / 4 + 95 }, "Final Score: " + to_string(final_score)},
	game_over_text{ Point{ x_max() / 4 + 10, y_max() / 4 + 50 }, "GAME OVER" },
	play_button{ Point{ x_max() / 2 - 70, y_max() / 2 }, 140, 40, "Play Again", 
		[](Address, Address pw) {reference_to<Game_over_window>(pw).change_state(true); } },
	quit_button{ Point{ x_max() / 2 - 35, y_max() / 2 + 75 }, 70, 20, "Quit", 
		[](Address, Address pw) {reference_to<Game_over_window>(pw).change_state(false); } }, // C++11 feature (lambda expressions)
	play_button_cover{ Point{ x_max() / 2 - 70, y_max() / 2 }, Point{ x_max() / 2 - 70 + 140, y_max() / 2 + 40} },
	quit_button_cover{ Point{ x_max() / 2 - 35, y_max() / 2 + 75 }, Point{ x_max() / 2 - 35 + 70, y_max() / 2 + 75 + 20 } },
	play_button_text{ Point{ x_max() / 2 - 70 + 35, y_max() / 2 + 25}, "Play Again" },
	quit_button_text{ Point{ x_max() / 2 - 35 + 20, y_max() / 2 + 75 + 15}, "Quit" },
	button_pushed{ false },
	selection{ false }
{
	stylize_objects();
	attach_objects();
}

void Game_over_window::stylize_objects() { 
	// Changes appearance of screen objects
	background.set_fill_color(Color::white);
	game_over_text.set_font_size(50);
	score.set_font_size(20);
}

void Game_over_window::attach_objects() { // Attaches objects to screen
	attach(background);
	attach(game_over_text);
	attach(score);
	attach(play_button);
	attach(quit_button);
	attach(play_button_cover);
	attach(quit_button_cover);
	attach(play_button_text);
	attach(quit_button_text);
}

void Game_over_window::quit() { // Closes window
	hide();
}

bool Game_over_window::change_state(bool choice) { 
	// Registers button push and returns selection
	button_pushed = true;
	selection = choice;
	return choice;
}

void Game_over_window::wait_for_button() { // Waits for button push
	show();
	while (!button_pushed) {
		Fl::wait();
	}
}
