//
//  GameWindow.hpp
//  TeamProject
//
//  Created by 김승진 on 11/10/17.
//  Copyright © 2017 SeugnJin Kim. All rights reserved.

#ifndef GAME_WINDOW
#define GAME_WINDOW

#include "Tile.h"
#include "Game.h"
#include "Simple_window.h"

class Game_window : Graph_lib::Window {
	Vector_ref<Tile> board;	
	Vector_ref<Text> numbers;
	Vector_ref<Text> scores;
	Rectangle background;
	Button hint_button;
	Text hint_button_text;
	Button quit_button;
	Text quit_button_text;
	Text moves_left;
	Text tiles_in_position;
	vector<User_score> top_scores;
	bool button_pushed;
	Vector_ref<Rectangle> board_cover;
	vector<vector<int>> matrix;

	void change_state();
	void load_game(int difficulty);
	void load_scores();
	void stylize_objects();
	void attach_objects();

public:
	Game_window(Point xy, int w, int h, const string& title, Game game);
	void wait_for_button();
	void quit();
	void swap();
	//~Game_window();
};

#endif

