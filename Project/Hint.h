#ifndef HINT_WINDOW
#define HINT_WINDOW

#include "Simple_window.h"

class Hint : Graph_lib::Window {
	Rectangle background;
	Text hint_text;

	void stylize_objects();
	void attach_objects();
	string create_hint(int const board[][4]);
	int find_distance(int const board[][4]);

public:
	Hint(Point xy, int w, int h, const string& title, int board[][4]);
	void wait();
};

#endif
