
#include "Main_menu.h"
#include "Graph.h"

Main_menu::Main_menu(Point xy, int w, int h, const string& title)
	:Window{ xy,w,h,title },
	background{ Point{0, 0}, Point{x_max(), y_max()} },
	splash_text1{ Point{ 25, 40 }, "PLEASE COMPILE - THE 16 GAME" },
	splash_text2{ Point{ 25, 65 }, "By Team 4 - Luke Grammer, Daniel Hain-Trevino, and Seungjin Kim" },
	start_button{ Point{ x_max() / 2 - 70, y_max() / 2 }, 140, 40, "Play", [](Address, Address pw) {reference_to<Main_menu>(pw).change_state(1); } },
	help_button{ Point{ x_max() / 2 - 35, y_max() / 2 + 80 }, 70, 20, "Help", [](Address, Address pw) {reference_to<Main_menu>(pw).change_state(2); } },
	quit_button{ Point{ x_max() / 2 - 35, y_max() / 2 + 140 }, 70, 20, "Quit", [](Address, Address pw) {reference_to<Main_menu>(pw).change_state(0); } },
	start_button_cover{ Point{ x_max() / 2 - 70, y_max() / 2 }, Point{ x_max() / 2 - 70 + 140, y_max() / 2 + 40} },
	help_button_cover{ Point{ x_max() / 2 - 35, y_max() / 2 + 80 }, Point{ x_max() / 2 - 35 + 70, y_max() / 2 + 80 + 20 } },
	quit_button_cover{ Point{ x_max() / 2 - 35, y_max() / 2 + 140 }, Point{ x_max() / 2 - 35 + 70, y_max() / 2 + 140 + 20 } },
	start_button_text{ Point{ x_max() / 2 - 70 + 55, y_max() / 2 + 25}, "Play" },
	help_button_text{ Point{ x_max() / 2 - 35 + 20, y_max() / 2 + 80 + 15 }, "Help"},
	quit_button_text{ Point{ x_max() / 2 - 35 + 20, y_max() / 2 + 140 + 15}, "Quit"},
	button_pushed{false},
	selection{0}
{
	stylize_objects();
	attach_objects();
}

void Main_menu::stylize_objects() {
	background.set_fill_color(Color::white);
	splash_text1.set_font_size(35);
	splash_text2.set_font_size(15);
}

void Main_menu::attach_objects() {
	attach(background);
	attach(splash_text1);
	attach(splash_text2);
	attach(start_button);
	attach(help_button);
	attach(quit_button);
	attach(start_button_cover);
	attach(help_button_cover);
	attach(quit_button_cover);
	attach(start_button_text);
	attach(help_button_text);
	attach(quit_button_text);
}

void Main_menu::quit() {
	hide();
}

int Main_menu::change_state(int choice) {
	button_pushed = true;
	selection = choice;
	return choice;
}

void Main_menu::wait_for_button() {
	show();
	while (!button_pushed) {
		Fl::wait();
	}
}
