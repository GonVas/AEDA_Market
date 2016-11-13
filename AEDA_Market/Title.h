#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "Industry.h"
//#include "Client.h"
//#include "util_funcs.cpp"

typedef unsigned int uni;

using namespace std;

class Title
{
private:
	static uni title_ID;
	uni id;
	Industry * indus;
	uni amount;
	uni NIF_owner;
	float money;
public:
	Title(Industry * indus, uni amount, uni owner_nif);
	virtual float getMoney() = 0;
	virtual void setMoney(float value);
	uni getID();
	uni getAmount();
	uni getNIF();
	Industry * getIndus();
	void setAmount(uni amount);
	~Title();

	virtual friend ostream & operator<<(ostream & lhs, Title & sh);
};

class TitleError
{
private:
	string des;
	uni type;
public:
	TitleError(string des, uni type);
	string what();
};

class Share : public Title
{
public:
	Share(Industry * indus, uni amount, uni owner_nif);

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
