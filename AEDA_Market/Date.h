#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
#include "util_funcs.cpp"

typedef unsigned int uni;

using namespace std;

class Date {
private:
	uni day;
	uni month;
	uni year;
	
public:
	Date(string date);
	Date();
	Date(uni day, uni month, uni year);
	bool operator<(Date* rhs); //checks if one date is more recent than the other. eg: 11-02-1997 < 21-11-1996
	bool operator==(Date* rhs);
	uni getDay();
	bool setDay(uni day);
	uni getMonth();
	bool setMonth(uni month);
	bool setYear(uni year);
	uni getYear();
};

class InvalidDate {
private:
	uni type;
public:
	InvalidDate(uni t);
	string what();
	uni getType();
};