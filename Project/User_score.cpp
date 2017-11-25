//
//  User_score.cpp
//  Team 4 - 'Please Compile'
//
//  Created by 김승진 on 11/12/17.
//  Copyright © 2017 SeugnJin Kim. All rights reserved.

#include "User_score.h"

User_score::User_score(string initials, int score, int difficulty)
	: initials{ initials }, score{ score }, difficulty{ difficulty }
{
}

// Getters and Setters
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

// Swaps initials/score
User_score& User_score::swap(const User_score &user_score) { 
	// Swaps initials and score
	this->initials = user_score.initials;
	this->score = user_score.score;
	return *this;
}

// Operator definitions
ostream& operator<<(ostream & os, const User_score & x) {
	return os << endl << "Difficulty: " << x.difficulty << " User_Initial: " << x.initials << " Score: " << x.score;
}

istream& operator>>(istream & is, User_score & z) {
	int difficulty, score;
	string initial, d, i, s;
	is >> d >> difficulty >> i >> initial >> s >> score;
	z = User_score(initial, score, difficulty);
	return is;
}

bool User_score::operator<(const User_score& user_score) {
	if (this->score < user_score.score) return true;
	else return false;
}