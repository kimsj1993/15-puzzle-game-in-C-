//
//  User.cpp
//  TeamProject
//
//  Created by 김승진 on 11/12/17.
//  Copyright © 2017 SeugnJin Kim. All rights reserved.
//

#include "User_score.h"

User_score::User_score(string initials, int score, int difficulty)
	: initials{ initials }, score{ score }, difficulty{ difficulty }
{

}

string User_score::get_initials() {
	return initials;
}

void User_score::set_initials(string initials) {
	this->initials = initials;
}

int User_score::get_score() {
	return score;
}

void User_score::set_score(int score) {
	this->score = score;
}

int User_score::get_difficulty() {
	return difficulty;
}

void User_score::set_difficulty(int difficulty) {
	this->difficulty = difficulty;
}

ostream& operator<<(ostream & os, User_score const & x)
{
	return os << x.difficulty << x.initials << x.score;
}

istream& operator>>(istream & is, User_score & z) {
	int difficulty, score;
	string initial;

	is >> difficulty >> initial >> score;
	z = User_score(initial, score, difficulty);
	return is;
}
