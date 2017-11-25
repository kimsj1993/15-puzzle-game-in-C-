//
//  Hint.cpp
//  Team 4 - 'Please Compile'
//
//  Created by Luke Grammer
//  Copyright © 2017 Luke Grammer. All rights reserved.

#include "Hint.h"

Hint::Hint()
{
}

string Hint::create_hint(vector<vector<int>> board) { 
	// Finds manhattan dist. of all possible moves and recommends lowest
	return "Try moving " + to_string(simulate_valid_moves(board));
}

int Hint::simulate_valid_moves(vector<vector<int>> board) { 
	// Simulates all valid moves, and returns 
	// value corresponding to move which causes the smallest manhattan dist.
	int x_loc = 0, y_loc = 0, d1 = 1000000, d2 = d1, d3 = d1, d4 = d1;
	find_16(x_loc, y_loc, board); // Find coordinates of 16 tile

	if (x_loc + 1 < 4) // If swapping with tile below is valid
		d1 = find_distance(swap(board[x_loc + 1][y_loc], board[x_loc][y_loc], board));
	if (x_loc - 1 > 0) // If swapping with tile above is valid
		d2 = find_distance(swap(board[x_loc - 1][y_loc], board[x_loc][y_loc], board));
	if (y_loc + 1 < 4) // If swapping with tile left is valid
		d3 = find_distance(swap(board[x_loc][y_loc + 1], board[x_loc][y_loc], board));
	if (y_loc - 1 > 0) // If swapping with tile right is valid
		d4 = find_distance(swap(board[x_loc][y_loc - 1], board[x_loc][y_loc], board));

	if (min(d1, min(d2, min(d3, d4))) == d1) return board[x_loc + 1][y_loc];
	else if (min(d1, min(d2, min(d3, d4))) == d2) return board[x_loc - 1][y_loc];
	else if (min(d1, min(d2, min(d3, d4))) == d3) return board[x_loc][y_loc + 1];
	else return board[x_loc][y_loc - 1];
}

void Hint::find_16(int& x_loc, int& y_loc, const vector<vector<int>>& board) {
	// Finds tile on board with value 16 and gives coords to argument
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (board[i][j] == 16) {
				x_loc = i;
				y_loc = j;
			}
		}
	}
}

vector<vector<int>> Hint::swap(int num1, int num2, vector<vector<int>> board) {
	// Swaps two numbers in a 2-d vector of ints (a vector of vectors of ints)
	int num1_x, num1_y, num2_x, num2_y;
	for (unsigned i = 0; i < 4; ++i) {
		for (unsigned j = 0; j < 4; ++j) {
			if (board[i][j] == num1) {
				num1_x = i; // Find coords of first tile
				num1_y = j;
			}
			else if (board[i][j] == num2) {
				num2_x = i; // Find coords of second tile
				num2_y = j;
			}
		}
	}
	int temp = board[num1_x][num1_y]; // Swap with temporary variable
	board[num1_x][num1_y] = board[num2_x][num2_y];
	board[num2_x][num2_y] = temp;
	return board; // Return new board
}


int Hint::find_distance(const vector<vector<int>>& board) {
	// Finds manhattan distance of a board (a vector of vectors of integers 1-16)
	int m_dist = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			int targ_x = ((board[i][j] - 1) / 4);
			int targ_y = (board[i][j] - 1) % 4;
			int dist_x = abs(i - targ_x);
			int dist_y = abs(j - targ_y);
			m_dist += dist_x + dist_y;
		}
	}
	return m_dist;
}