#pragma once
#include <string>
#include <vector>
#include <algorithm>

typedef unsigned int uni;

using namespace std;

class Industry
{
private:
	static uni indus_id;
	uni id;
	string name;
	float change;
	float value;
public:
	Industry(string name, float value);
	string getName();
	float getValue();
	uni getID();
	void setValue(float value);
	float getChange();
	void setChange(float newChange);

	friend ostream & operator<<(ostream & lhs, Industry & indu);
};

template<typename T>
uni count_digits_3(T number) //counts how many digits a number has
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
