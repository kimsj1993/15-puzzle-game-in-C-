//
//  Main.cpp
//  Team 4 - 'Please Compile'
//
//  Created by Luke Grammer
//  Copyright © 2017 Luke Grammer. All rights reserved.

#include "Window_manager.h"

int main() {
	try {
		Window_manager manager;
		manager.start_game_sequence();

		return gui_main();
	}
	catch (exception& e) { // Catching natively defined errors
		cerr << "Exception: " << e.what() << '\n';
		return 1;
	}
	catch (...) { // Catching misc. errors
		cerr << "An error has occured and caused the program to close unexpectedly. \n";
		return 2;
	}
}
