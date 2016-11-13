#include "Title.h"

Title::Title(Industry * indus, uni amount, uni owner_nif)
{
	this->indus = indus;
	try
	{
		this->setAmount(amount);
	}
	catch (TitleError err) { throw; }
	this->NIF_owner = owner_nif;
}

void Title::setMoney(float value)
{
	if (value <= 0.0)
	{
		TitleError err("Money amount can't be 0 or below", 8);
		throw err;
	}
	this->amount = amount;
}

uni Title::getID()
{
	return this->id;
}

uni Title::getAmount()
{
	return this->amount
}

uni Title::getNIF()
{
	return this->NIF_owner;
}

Industry * Title::getIndus()
{
	return this->indus;
}

void Title::setAmount(uni amount)
{
	if (amount <= 0)
	{
		TitleError err("Title amount can't be 0 or below", 8);
		throw err;
	}
	this->amount = amount;
}

Title::~Title()
{
}

ostream & operator<<(ostream & lhs, Title & sh)
{
	// TODO: insert return statement here
}

TitleError::TitleError(string des, uni type)
{
	this->des = des;
	this->type = type;
}

string TitleError::what()
{
	return this->des;
}
