//
//  GameWindow.cpp
//  Team 4 - 'Please Compile'
//
//  Created by 김승진 on 11/10/17.
//  Copyright © 2017 SeugnJin Kim. All rights reserved.

#include "Game_window.h"

Game_window::Game_window(Point xy, int w, int h, const string& title, Game game)
	:Window{ xy,w,h,title }, board{ 0 }, numbers{ 0 }, scores{ 0 }, game{ game },
	background{ Point{ 0, 0 }, Point{ x_max(), y_max() } },
	hint_button{ Point{ 900, 70 }, 70, 20, "Hint",
		[](Address, Address pw) {reference_to<Game_window>(pw).create_hint_text(); } },
	hint_button_text(Point(920, 85), "Hint"),
	quit_button{ Point{ 900, 650 }, 70, 20, "Quit",
		[](Address, Address pw) {reference_to<Game_window>(pw).change_state(); } }, // C++11 Feature (lambda expressions)
	quit_button_text(Point(920, 665), "Quit"),
	hint_text{ Point{ 892, 135 }, "" },
	moves_left(Point(100, 500), "Moves Remaining: " + to_string(game.get_moves_left())),
	tiles_needed_move(Point(300, 500), "Incorrect Tiles:" + to_string(game.get_num_tiles_incorrect_position())),
	top_scores{ game.get_top_scores() },
	button_pushed{ false }
{
	load_game(game.get_difficulty());
	stylize_objects();
	attach_objects();
}

void Game_window::quit() { // Closes window
	hide();
}

void Game_window::wait_for_button() { // Waits for non-tile button push
	show();
	while (!button_pushed) {
		Fl::wait();
	}
}

void Game_window::change_state() { // Registers non-tile button push
	button_pushed = true;
}

void Game_window::stylize_objects() { // Changes appearance of screen objects
	background.set_fill_color(Color::white);
	for (unsigned i = 0; i < board.size(); ++i) {
		board_cover[i].set_fill_color(Color::white);
	}
	board_cover[board.size()].set_fill_color(Color::white);
	board_cover[board.size() + 1].set_fill_color(Color::white);
}

void Game_window::attach_objects() { // Attaches screen objects
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
	attach(board_cover[board.size()]); // Hint button cover
	attach(hint_button_text);
	attach(quit_button);
	attach(board_cover[board.size() + 1]); // Quit button cover
	attach(quit_button_text);
	attach(moves_left);
	attach(tiles_needed_move);
}

void Game_window::load_game(int difficulty) {
	// Calls load board & load scores, and locates special tile
	load_board(difficulty);
	load_scores();

	for (int i = 0; i < board.size(); ++i) {
		if (board[i].get_title() == "16") {
			empty_index = i;
			set_moveable(i, true);
		}
	}
	set_moveable(empty_index, true);
}

// Gives board starting positions and adds tiles and backgrounds
void Game_window::load_board(int difficulty) {
	switch (difficulty) {
	case 1: matrix = { {1,2,3,4},{5,6,12,7},{9,10,16,15},{13,14,8,11} }; break;
	case 2: matrix = { {1,6,3,4},{5,16,2,11},{9,10,14,7},{13,15,12,8} }; break;
	case 3: matrix = { {4,8,12,15},{3,16,7,11},{9,2,1,10},{13,14,5,6} }; break;
	case 4: matrix = { {16,12,11,13},{15,14,10,9},{3,7,6,2},{4,8,5,1} }; break;
	}
	for (auto i = 0; i < 4; ++i) { // C++11 feature (auto variables)
		for (auto j = 0; j < 4; ++j) {
			board.push_back(new Tile(Point(j * 100, i * 100), 100,
				to_string(matrix[i][j]), matrix[i][j], false, cb_tile));
			board_cover.push_back(new Rectangle{ Point(j * 100, i * 100),
				Point(j * 100 + 100, i * 100 + 100) });
			numbers.push_back(new Text(Point(j * 100 + 45, i * 100 + 50),
				(board[board.size() - 1].get_title() != "16") ? board[board.size() - 1].get_title() : ""));
		}
	}
	board_cover.push_back(new Rectangle{ Point{ 900, 70 }, Point{ 970, 90 } });
	board_cover.push_back(new Rectangle{ Point{ 900, 650 }, Point{ 970, 670 } });
}

// Populates scores to display on screen
void Game_window::load_scores() {
	scores.push_back(new Text(Point(600, 50), "TOP SCORES:"));
	for (auto i = 0; i < top_scores.size(); ++i) {
		if (i == top_scores.size() - 1) {
			scores.push_back(new Text(Point(600, i * 20 + 75),
				top_scores[i].get_initials()));
		}
		else {
			scores.push_back(new Text(Point(600, i * 20 + 75),
				top_scores[i].get_initials() + ": " + to_string(top_scores[i].get_score())));
		}
	}
}

// when Tile is clicked
void Game_window::cb_tile(Address p, Address pw) {
	reference_to<Game_window>(pw).move_button(p);
}

// Performs necessary actions after tile is clicked
void Game_window::move_button(Address i) {
	string clicked_number(reference_to<Fl_Button>(i).label());

	for (int i = 0; i <= board.size() - 1; ++i) {
		if (clicked_number == board[i].get_title() && board[i].has_space()) {
			swap_tile(board[i], board[empty_index], numbers[i], numbers[empty_index]);
			set_moveable(empty_index, false);
			empty_index = i;
			set_moveable(empty_index, true);

			update_information();

			if (game.get_moves_left() == 0) {
				export_scores();
				change_state();
			}
			redraw();
			break;
		}
	}
}

// Swaps two tiles using a temporary variable
void Game_window::swap_tile(Tile& tile1, Tile& tile2, Text& tile1_label, Text& tile2_label) {
	Tile temp_tile(Point(0, 0), 0, "", 0, false, cb_tile);

	temp_tile = tile1;

	tile1_label.set_label((tile2.get_title() != "16") ? tile2.get_title() : "");
	tile2_label.set_label((tile1.get_title() != "16") ? tile1.get_title() : "");

	tile1 = tile2;
	tile2 = temp_tile;
}

// Updates board after tile swap
void Game_window::update_information() {
	game.set_moves_left(game.get_moves_left() - 1);
	moves_left.set_label("Moves Remaining: " + to_string(game.get_moves_left()));
	find_incorrect_tiles();
	tiles_needed_move.set_label("Incorrect Tiles: " + to_string(game.get_num_tiles_incorrect_position()));
	game.set_move_count(game.get_move_count() + 1);
}

// Finds top 5 final scores and calls write_to_file()
void Game_window::export_scores() {
	top_scores[(int)top_scores.size() - 1].set_score((16 - game.get_num_tiles_incorrect_position()) * game.get_move_count());
	final_score = top_scores[(int)top_scores.size() - 1].get_score();
	sort(top_scores.rbegin(), top_scores.rend());
	if (top_scores.size() > 5) top_scores.pop_back();

	write_to_file();
}

// Writes scores to file
void Game_window::write_to_file() {
	ofstream score_file("Scores.txt", ios::out);
	for (int i = 0; i <= top_scores.size() - 1; ++i) {
		score_file << top_scores[i];
	}
	if (game.get_different_difficulties().size() > 0) {
		for (int i = 0; i <= game.get_different_difficulties().size() - 1; ++i) {
			score_file << game.get_different_difficulties()[i];
		}
	}
	score_file.close();
}

// Determines if a tile is moveable
void Game_window::set_moveable(int index, bool a) {
	if (index <= 3)
		board[index + 4].set_space(a);
	else if (index >= 12)
		board[index - 4].set_space(a);
	else {
		board[index + 4].set_space(a);
		board[index - 4].set_space(a);
	}

	if (index % 4 == 0)
		board[index + 1].set_space(a);
	else if (index % 4 == 3)
		board[index - 1].set_space(a);
	else {
		board[index + 1].set_space(a);
		board[index - 1].set_space(a);
	}
}

// Determines which tiles are out of order
void Game_window::find_incorrect_tiles() {
	int count = 0;
	for (int i = 0; i < board.size(); ++i) {
		if (board[i].get_number() != i + 1) {
			++count;
		}
	}
	game.set_num_tiles_incorrect_position(count);
}

// Displays hint message after button is clicked
void Game_window::create_hint_text() {
	Hint hint;
	for (unsigned i = 0; i < 4; ++i)
		for (unsigned j = 0; j < 4; ++j)
			matrix[i][j] = board[j + 4 * i].get_number();

	hint_text.set_label(hint.create_hint(matrix));
	attach(hint_text);
	redraw();
}

// Returns final score
int Game_window::get_final_score() {
	return final_score;
}
