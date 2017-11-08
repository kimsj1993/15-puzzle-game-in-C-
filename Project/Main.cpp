
#include "Window_manager.h"

int main()
try {
	Window_manager manager;
	manager.start_game_sequence();
	
	return gui_main();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
