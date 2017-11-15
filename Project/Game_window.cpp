//
//  GameWindow.cpp
//  TeamProject
//
//  Created by 김승진 on 11/10/17.
//  Copyright © 2017 SeugnJin Kim. All rights reserved.

#include "Game_window.h"

Game_window::Game_window(Point xy, int w, int h, const string& title, Game game)
	:Window{ xy,w,h,title }, board{ 0 }, numbers{ 0 }, scores{ 0 },
	background{ Point{ 0, 0 }, Point{ x_max(), y_max() } },
	hint_button{ Point{ 900, 70 }, 70, 20, "Hint", [](Address, Address pw) {reference_to<Game_window>(pw).change_state(); } },
	hint_button_text(Point(920, 85), "Hint"),
	quit_button{ Point{ 900, 650 }, 70, 20, "Quit", [](Address, Address pw) {reference_to<Game_window>(pw).change_state(); } },
	quit_button_text(Point(920, 665), "Quit"),
	moves_left(Point(500, 50), to_string(game.get_moves_left())),
	tiles_in_position(Point(500, 150), to_string(game.get_num_tiles_in_position())),
	top_scores{ game.get_top_scores() },
	button_pushed{ false }
{
	load_game(game.get_difficulty());
	load_scores();
	stylize_objects();
	attach_objects();
}

void Game_window::quit() {
	hide();
}

void Game_window::change_state() {
	button_pushed = true;
}

void Game_window::wait_for_button() {
	show();
	while (!button_pushed) {
		Fl::wait();
	}
}

void Game_window::load_game(int difficulty) {
	switch (difficulty) {
	case 1: matrix = { { 1,2,3,4 },{ 5,6,12,7 },{ 9,10,16,15 },{ 13,14,8,11 } }; break;
	case 2: matrix = { { 1,6,3,4 },{ 5,16,2,11 },{ 9,10,14,7 },{ 13,15,12,8 } }; break;
	case 3: matrix = { { 6,5,11,4 },{ 10,13,2,1 },{ 9,15,7,3 },{ 14,12,8,16 } }; break;
	case 4: matrix = { { 16,12,11,13 },{ 15,14,10,9 },{ 3,7,6,2 },{ 4,8,5,1 } }; break;
	}

	for (unsigned i = 0; i < 4; ++i) {
		for (unsigned j = 0; j < 4; ++j) {
			board.push_back(new Tile(Point(j * 100, i * 100), 100, to_string(matrix[i][j]), matrix[i][j], false,
				[](Address, Address pw) {reference_to<Game_window>(pw).change_state(); }));
			board_cover.push_back(new Rectangle{ Point(j * 100, i * 100), Point(j * 100 + 100, i * 100 + 100) });
			numbers.push_back(new Text(Point(j * 100 + 45, i * 100 + 50), board[board.size() - 1].get_title()));
		}
	}
	board_cover.push_back(new Rectangle{ Point{ 900, 70 }, Point{ 970, 90 } });
	board_cover.push_back(new Rectangle{ Point{ 900, 650 }, Point{ 970, 670 } });
}

void Game_window::load_scores() {
	for (unsigned i = 0; i < top_scores.size(); ++i) {
		if (i == top_scores.size() - 1) {
			scores.push_back(new Text(Point(600, i * 20 + 50), top_scores[i].get_initials()));
		}
		else {
			scores.push_back(new Text(Point(600, i * 20 + 50), top_scores[i].get_initials() + ": " + to_string(top_scores[i].get_score())));
		}
	}
}

void Game_window::stylize_objects() {
	background.set_fill_color(Color::white);
	for (unsigned i = 0; i < board.size(); ++i) {
		board_cover[i].set_fill_color(Color::white);
	}
	board_cover[board.size()].set_fill_color(Color::white);
	board_cover[board.size() + 1].set_fill_color(Color::white);
}

void Game_window::attach_objects() {
	attach(background);
	for (unsigned i = 0; i < board.size(); ++i) {
		attach(board[i]);
		attach(board_cover[i]);
		attach(numbers[i]);
	}
	for (unsigned i = 0; i < scores.size(); ++i) {
		attach(scores[i]);
	}
	attach(hint_button);
	attach(board_cover[board.size()]);
	attach(hint_button_text);
	attach(quit_button);
	attach(board_cover[board.size() + 1]);
	attach(quit_button_text);
}

/*Game_window::~Game_window() {
	delete[] & board;
	delete[] & scores;
	delete[] & board_cover;
	delete[] & numbers;
}*/