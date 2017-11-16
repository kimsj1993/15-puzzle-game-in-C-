#ifndef HINT
#define HINT

#include "Simple_window.h"

class Hint : Graph_lib::Window {
	Rectangle background;
	Text hint_text;

	void stylize_objects();
	void attach_objects();
	string create_hint(vector<vector<int>> board);
	int simulate_valid_moves(vector<vector<int>> board);
	void find_16(int& x_loc, int& y_loc, vector<vector<int>> board);
	vector<vector<int>> swap(int num1, int num2, vector<vector<int>> board);
	int find_distance(const vector<vector<int>>& board);

public:
	Hint(Point xy, int w, int h, const string& title, vector<vector<int>> board);
	void wait();
};

#endif
