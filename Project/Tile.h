//
//  Tile.h
//  Team 4 - 'Please Compile'
//
//  Created by 김승진 on 11/9/17.
//  Copyright © 2017 SeugnJin Kim. All rights reserved.

#ifndef TILE
#define TILE

#include "GUI.h"

using namespace Graph_lib;

class Tile : public Graph_lib::Button {

  int number;
  bool space;
  string title;

  public:
  Tile(Point xy, int wh, const string& title, int number, bool has_space, Callback cb);
  
  bool has_space();
  void set_space(bool);
  int get_number();
  void set_number(int n);
  string get_title();
  void set_title(string);
  Tile& operator= (const Tile &tile);
};

#endif
