
#include "Help_window.h"

Help_window::Help_window(Point xy, int w, int h, const string& title)
	:Window{ xy,w,h,title },
	background{ Point{ 0, 0 }, Point{ x_max(), y_max() } },
	help_text1{ Point{ 25, 40 }, "INSTRUCTIONS" },
	help_text2{ Point{ 25, 65 }, "In development, instructions not yet available" },
	back_button{ Point{ x_max() / 2 - 35, y_max() / 2 + 80 }, 70, 20, "Back", [](Address, Address pw) {reference_to<Help_window>(pw).change_state(); } },
	back_button_cover{ Point{ x_max() / 2 - 35, y_max() / 2 + 80 }, Point{ x_max() / 2 - 35 + 70, y_max() / 2 + 80 + 20 } },
	back_button_text{ Point{ x_max() / 2 - 35 + 20, y_max() / 2 + 80 + 15 }, "Back" },
	button_pushed{ false }
{
	stylize_objects();
	attach_objects();
}

void Help_window::stylize_objects() {
	background.set_fill_color(Color::white);
	help_text1.set_font_size(35);
	help_text2.set_font_size(15);
}

void Help_window::attach_objects() {
	attach(background);
	attach(help_text1);
	attach(help_text2);
	attach(back_button);
	attach(back_button_cover);
	attach(back_button_text);
}

void Help_window::quit() {
	hide();
}

void Help_window::change_state() {
	button_pushed = true;
}

void Help_window::wait_for_button() {
	show();
	while (!button_pushed) {
		Fl::wait();
	}
}