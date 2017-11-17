#ifndef HINT
#define HINT

#include "Simple_window.h"

class Hint {
	
	int simulate_valid_moves(vector<vector<int>> board);
	void find_16(int& x_loc, int& y_loc, const vector<vector<int>>& board);
	vector<vector<int>> swap(int num1, int num2, vector<vector<int>> board);
	int find_distance(const vector<vector<int>>& board);

public:
	Hint();
	string create_hint(vector<vector<int>> board);
};

#endif
