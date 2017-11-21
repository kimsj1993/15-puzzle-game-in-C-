//Daniel Hain Trevino
//CSCE 121-513
//Game_over_window.h

#ifndef GAME_OVER_WINDOW
#define GAME_OVER_WINDOW

#include "Simple_window.h"

class Game_over_window : Graph_lib::Window {
        Rectangle background;
        Text game_over_text;
        Button play_button;
        Button quit_button;
        Rectangle play_button_cover;
        Rectangle quit_button_cover;
        Text play_button_text;
        Text quit_button_text;

        bool button_pushed;
        int selection;
        void stylize_objects();
        void attach_objects();
public:
        Game_over_window(Point xy, int w, int h, const string& title);
        void wait_for_button();
        bool change_state(bool choice);
        bool get_choice() { return selection; }
        void quit();
};

#endif
