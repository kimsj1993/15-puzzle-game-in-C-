//
//  Tiles.cpp
//  TeamProject
//
//  Created by 김승진 on 11/9/17.
//  Copyright © 2017 SeugnJin Kim. All rights reserved.
//

#include "Tile.h"

Tile::Tile(Point xy, int wh, const string& title, int number,bool has_space, Callback cb)
	: Button{xy,wh,wh,"",cb}, number{number}, space{has_space}, title{title}
{

}

bool Tile::has_space() {
  return space;
}

void Tile::set_space(bool x) {
  space = x;
}

int Tile::get_number() {
  return number;
}

void Tile:: set_number(int n) {
  number = n;
}

string Tile::get_title() {
  return title;
}




