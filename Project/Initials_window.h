//Daniel Hain Trevino
//CSCE 121-513
//Initials_window.h

#ifndef INITIALS_WINDOW
#define INITIALS_WINDOW

#include "Simple_window.h"

class Initials_window : Graph_lib::Window {
        Rectangle background_top;
        Rectangle background_left;
        Rectangle background_bottom;
        Rectangle background_right;
        Text initials_text;
        In_box initials_input;
        Button initials_button;
        Rectangle initials_button_cover;
        Rectangle initials_input_cover;
        Text initials_button_text;
        string initials_string;

        bool button_pushed;
        void stylize_objects();
        void attach_objects();
        void write_to_file();
public:
        Initials_window(Point xy, int w, int h, const string& title);
        void wait_for_button();
		string get_initials() { return initials_string; }
        void quit();
};

#endif
