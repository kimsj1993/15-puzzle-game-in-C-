//
//  Game_window.h
//  Team 4 - 'Please Compile'
//
//  Created by 김승진 on 11/10/17.
//  Copyright © 2017 SeugnJin Kim. All rights reserved.

#ifndef GAME_WINDOW
#define GAME_WINDOW

#include "Tile.h"
#include "Game.h"
#include "Hint.h"
#include "Simple_window.h"
#include "FL/Fl_Button.H"

class Game_window : Graph_lib::Window {
	Vector_ref<Tile> board;
	Vector_ref<Text> numbers;
	Vector_ref<Text> scores;
	Game game;
	Rectangle background;
	Button hint_button;
	Text hint_button_text;
	Button quit_button;
	Text quit_button_text;
	Text hint_text;
	Text moves_left;
	Text tiles_needed_move;
	vector<User_score> top_scores;
	bool button_pushed;
	Vector_ref<Rectangle> board_cover;
	vector<vector<int>> matrix;
	int empty_index;
	int final_score;

	void change_state();
	void stylize_objects();
	void attach_objects();
	void load_game(int difficulty);
	void load_board(int difficulty);
	void load_scores();
	static void cb_tile(Address p, Address pw);
	void swap_tile(Tile& tile1, Tile& tile2, Text& tile1_label, Text& tile2_label);
	void update_information();
	void export_scores();
	void write_to_file();
	void set_moveable(int index, bool a);
	void find_incorrect_tiles();
	void create_hint_text();

public:
	Game_window(Point xy, int w, int h, const string& title, Game game);
	void move_button(Address);
	void wait_for_button();
	int get_final_score();
	void quit();
};

#endif