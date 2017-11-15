//
//  User.hpp
//  TeamProject
//
//  Created by 김승진 on 11/12/17.
//  Copyright © 2017 SeugnJin Kim. All rights reserved.

#ifndef USER_SCORE
#define USER_SCORE

#include "std_lib_facilities_5.h"

class User_score {

  string initials;
  int score;
  int difficulty;
  
  public:
  User_score(string initials, int score, int difficulty);

  string get_initials();
  void set_initials(string intials);
  int get_score();
  void set_score(int score);
  int get_difficulty();
  void set_difficulty(int difficulty);
  
  friend ostream & operator<<(ostream& os, User_score const& x);
  friend istream & operator>> (istream& is, User_score& z);
};

#endif


