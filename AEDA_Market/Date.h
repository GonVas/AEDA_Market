#pragma once
#include <string>
#include <vector>
#include <algorithm>

typedef unsigned int uni;

using namespace std;

class Date
{
private:
	uni day;
	uni month;
	uni year;
	bool valid;
public:
	Date(string date);
	Date();
	Date(uni day, uni month, uni year);
	bool operator<(Date* rhs);
	bool operator==(Date* rhs);
	uni getDay();
	bool setDay();
	uni getMonth();
	bool setMonth();
	bool setYear();
	uni getYear();
};
