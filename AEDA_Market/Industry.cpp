#include "Industry.h"

using namespace std;

typedef unsigned int uni;

uni Industry::indus_id = 0;

Industry::Industry(string name, float value)
{
	this->id = 5 * pow(10, count_digits_3(Industry::indus_id)) + Industry::indus_id;
	this->name = name;
	this->value = value;
	Industry::indus_id++;
}

string Industry::getName()
{
	return this->name;
}

float Industry::getValue()
{
	return this->value;
}

uni Industry::getID()
{
	return this->id;
}

void Industry::setValue(float value)
{
	this->value = value;
}

float Industry::getChange()
{
	return this->change;
}

void Industry::setChange(float newChange)
{
	this->change = newChange;
}

ostream & operator<<(ostream & lhs, Industry & indu)
{
	(lhs << "Industry id: " << indu.getID() << " Name: " << indu.getName() << endl);
	return lhs;
}
