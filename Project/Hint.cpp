
#include "Hint.h"

Hint::Hint(Point xy, int w, int h, const string& title, int board[][4])
	: Window{ xy,w,h,title },
	background{ Point{ 0, 0 }, Point{ x_max(), y_max() } },
	//board_ptr(board)
	hint_text{ Point{ 25, 65 }, create_hint(board) }

{
	stylize_objects();
	attach_objects();
}

void Hint::stylize_objects() {
	background.set_fill_color(Color::white);
	hint_text.set_font_size(15);
}

void Hint::attach_objects() {
	attach(background);
	attach(hint_text);
}

void Hint::wait() {
	show();
	Fl::run();
	hide();
}

string Hint::create_hint(int const board[][4]) { 
	// Need to find all valid moves, simulate them, find manhattan distance of board, and save the smallest distance with it's corresponding move 
	return to_string(1); // Will take value of tile whose movement will result in smallest manhattan distance and convert it to string to display
}

int Hint::find_distance(int const board[][4]) { // Finds manhattan distance of a board (a 4x4 matrix of integers 1-16)
	int mDist = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			int targX = ((board[i][j] - 1) / 4);
			int targY = (board[i][j] - 1) % 4;
			int distX = abs(i - targX);
			int distY = abs(j - targY);
			mDist += distX + distY;
		}
	}
	return mDist;
}