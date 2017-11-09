#ifndef HELP_WINDOW
#define HELP_WINDOW

#include "Simple_window.h"

class Help_window : Graph_lib::Window {
	Rectangle background;
	Text help_text1;
	Text help_text2;
	Button back_button;
	Rectangle back_button_cover;
	Text back_button_text;
	bool button_pushed;

public:
	Help_window(Point xy, int w, int h, const string& title);
	void stylize_objects();
	void attach_objects();
	void change_state();
	void quit();
	void wait_for_button();

};
#endif
