#include "Share.h"

uni Share::share_ID = 0;

Share::Share( Industry * indus,  uni amount, uni owner_nif)
{
	this->id = 3 * pow(10, count_digits_2(Share::share_ID)) 
		+ Share::share_ID;
	this->indus = indus;
	try 
	{
		this->setAmount(amount);
	}
	catch (ShareError err) { throw; }
	this->NIF_owner = owner_nif;
	Share::share_ID++;
}

float Share::getValue()
{
	return this->value_each;
}

float Share::updateValue()
{
	return 0.0f;
}

uni Share::getID()
{
	return this->id;
}

uni Share::getAmount()
{
	return this->amount;
}

uni Share::getNIF()
{
	return this->NIF_owner;
}

Industry * Share::getIndus()
{
	return this->indus;
}

void Share::setAmount(uni amount)
{
	if (amount <= 0)
	{
		ShareError err("Share amount can't be 0 or below", 8);
		throw err;
	}
	this->amount = amount;
}

Share::~Share()
{
}

ShareError::ShareError(string des, uni type)
{
	this->des = des;
	this->type = type;
}

string ShareError::what()
{
	return this->des;
}

ostream & operator<<(ostream & lhs, Share & sh)
{
	(lhs << "Share id: " << sh.getID() << " Nif_owner: "
		<< sh.getNIF() << " Amount: "<< sh.getAmount()
		<< " " << *sh.getIndus());
	return lhs;
}
