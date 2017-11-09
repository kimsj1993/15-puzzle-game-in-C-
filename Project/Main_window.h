#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include "Simple_window.h"

class Main_window : Graph_lib::Window {
	Rectangle background;
	Text splash_text1;
	Text splash_text2;
	Button start_button;
	Button help_button;
	Button quit_button;
	Rectangle start_button_cover;
	Rectangle help_button_cover;
	Rectangle quit_button_cover;
	Text start_button_text;
	Text help_button_text;
	Text quit_button_text;

	bool button_pushed;
	int selection;
	void stylize_objects();
	void attach_objects();
public:
	Main_window(Point xy, int w, int h, const string& title);
	void wait_for_button();
	int change_state(int choice);
	int get_choice() { return selection; }
	void quit();
};

#endif