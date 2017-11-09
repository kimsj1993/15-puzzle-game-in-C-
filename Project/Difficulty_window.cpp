#include "Difficulty_window.h"
#include "Graph.h"

Difficulty_window::Difficulty_window(Point xy, int w, int h, const string& title)
        :Window{ xy,w,h,title },
        background{ Point{0, 0}, Point{x_max(), y_max()} },
        difficulty_text{ Point{ 25, 40 }, "Select a difficulty:" },
        easy_button{ Point{ x_max() / 2 - 304, y_max() / 2 }, 140, 40, "Easy (10 Moves)", [](Address, Address pw) {reference_to<Difficulty_window>(pw).change_state(1); } },
        normal_button{ Point{ x_max() / 2 - 148, y_max() / 2 }, 140, 40, "Normal (20 Moves)", [](Address, Address pw) {reference_to<Difficulty_window>(pw).change_state(2); } },
        hard_button{ Point{ x_max() / 2 + 8, y_max() / 2}, 140, 40, "Hard (40 Moves)", [](Address, Address pw) {reference_to<Difficulty_window>(pw).change_state(3); } },
        expert_button{ Point{ x_max() / 2 + 164, y_max() / 2}, 140, 40, "Expert (80 Moves)", [](Address, Address pw) {reference_to<Difficulty_window>(pw).change_state(4); } },
        easy_button_cover{ Point{ x_max() / 2 - 304, y_max() / 2 }, Point{ x_max() / 2 - 304 + 140, y_max() / 2 + 40} },
        normal_button_cover{ Point{ x_max() / 2 - 148, y_max() / 2 }, Point{ x_max() / 2 - 148 + 140, y_max() / 2 + 40} },
        hard_button_cover{ Point{ x_max() / 2 + 8, y_max() / 2 }, Point{ x_max() / 2 + 8 + 140, y_max() / 2 + 40} },
        expert_button_cover{ Point{ x_max() / 2 + 164, y_max() / 2 }, Point{ x_max() / 2 + 164 + 140, y_max() / 2 + 40} },
        easy_button_text{ Point{ x_max() / 2 - 304 + 15, y_max() / 2 + 25}, "Easy (10 Moves)" },
        normal_button_text{ Point{ x_max() / 2 - 148 + 5, y_max() / 2 + 25}, "Normal (20 Moves)" },
        hard_button_text{ Point{ x_max() / 2 + 8 + 15, y_max() / 2 + 25}, "Hard (40 Moves)" },
        expert_button_text{ Point{ x_max() / 2 + 164 + 5, y_max() / 2 + 25}, "Expert (80 Moves)" },
        button_pushed{false},
        selection{0}
{
        stylize_objects();
        attach_objects();
}

void Difficulty_window::stylize_objects() {
        background.set_fill_color(Color::white);
        difficulty_text.set_font_size(35);
}

void Difficulty_window::attach_objects() {
        attach(background);
        attach(difficulty_text);
        attach(easy_button);
        attach(normal_button);
        attach(hard_button);
        attach(expert_button);
        attach(easy_button_cover);
        attach(normal_button_cover);
        attach(hard_button_cover);
        attach(expert_button_cover);
        attach(easy_button_text);
        attach(normal_button_text);
        attach(hard_button_text);
        attach(expert_button_text);
}

void Difficulty_window::quit() {
        hide();
}

int Difficulty_window::change_state(int choice) {
        button_pushed = true;
        selection = choice;
        return choice;
}

void Difficulty_window::wait_for_button() {
        show();
        while (!button_pushed) {
                Fl::wait();
        }
}
