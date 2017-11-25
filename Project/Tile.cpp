//
//  Tile.cpp
//  Team 4 - 'Please Compile'
//
//  Created by 김승진 on 11/9/17.
//  Copyright © 2017 SeugnJin Kim. All rights reserved.
//

#include "Tile.h"

Tile::Tile(Point xy, int wh, const string& title, int number, bool has_space, Callback cb)
	: Button{ xy,wh,wh,title,cb }, number{ number }, space{ has_space }, title{ title }
{

}

// Getters and Setters
bool Tile::has_space() {
	return space;
}

void Tile::set_space(bool x) {
	space = x;
}

int Tile::get_number() {
	return number;
	cout << number;
}

void Tile::set_number(int n) {
	number = n;
}

string Tile::get_title() {
	return title;
}

void Tile::set_title(string n) {
	this->title = n;
}

// Operator definition
Tile& Tile::operator=(const Tile &tile) {
	this->loc.x = tile.loc.x;
	this->loc.y = tile.loc.y;
	this->height = tile.height;
	this->width = tile.width;
	this->title = tile.title;
	this->number = tile.number;
	this->space = tile.space;
	this->label = tile.title;

	return *this;
}