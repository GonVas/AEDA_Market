#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "Industry.h"
//#include "Client.h"
//#include "util_funcs.cpp"

typedef unsigned int uni;

using namespace std;

class Share
{
private:
	static uni share_ID;
	uni id;
	Industry * indus;
	float value_each;
	uni amount;
	uni NIF_owner;
public:
	Share( Industry * indus, uni amount, uni owner_nif);
	float getValue();
	float updateValue();
	uni getID();
	uni getAmount();
	uni getNIF();
	Industry * getIndus();
	void setAmount(uni amount);
	~Share();

	friend ostream & operator<<(ostream & lhs, Share & sh);
};

class ShareError
{
private:
	string des;
	uni type;
public:
	ShareError(string des, uni type);
	string what();
};

template<typename T>
uni count_digits_2(T number) //counts how many digits a number has
{
	if (number == 0)
		return 1;

	uni digits = 0;

	while (number != 0)
	{
		number /= 10;
		digits++;
	}

	return digits;
}
