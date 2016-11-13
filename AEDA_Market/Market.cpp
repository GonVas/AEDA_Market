#include "Market.h"

using namespace std;

uni Market::market_ID = 1;

float Market::calc_newValue()
{
	return 0.0f;
}

Market::Market()
{
	this->id = 1 * pow(10, count_digits(Market::market_ID)) + Market::market_ID;
	this->value = calc_newValue();
	Market::market_ID++;
}

Market::Market(uni value_mul)
{
	this->id = 1 * pow(10, count_digits(Market::market_ID)) + Market::market_ID;
	this->value = value_mul * calc_newValue();
	Market::market_ID++;
}

bool Market::loadFile(string filename)
{
	return false;
}

bool Market::saveFile(string filename)
{
	return false;
}

Client * Market::getClient(string name)
{
	return nullptr;
}

Client * Market::getClient(uni NIF)
{
	return nullptr;
}

int Market::update_all()
{
	return 0;
}

float Market::getValue()
{
	return this->value;
}

void Market::setValue(float newVal)
{
	if (newVal <= 0)
	{
		MarketError neg(0, "Value can't be 0 or negative.");
		throw neg;
	}
	this->value = newVal;
}

void Market::addClient(Client * newCli)
{
	if( findCli( *newCli ) == -1)
		this->clients.push_back(newCli);
	else
	{
		ClientError err(5, "Client already exist.");
		throw err;
	}
}

void Market::removeClient(uni what, uni nif)
{
	if (nif == 0)
	{
		if (findCli(what, 0) == -1)
		{
			ClientError err(6, "Client doens´t exist.");
			throw err;
		}
		else
			this->clients.erase(this->clients.begin() + findCli(what, 0));
	}
	else
	{
		if (findCli(what, 1) == -1)
		{
			ClientError err(6, "Client doens´t exist.");
			throw err;
		}
		else
			this->clients.erase(this->clients.begin() + findCli(what, 1));
	}
	
}

void Market::addShare(Share * newShare)
{
	

}

void Market::removeShare(uni id)
{
}

void Market::addOrder(Order * newOrder)
{
}

void Market::removeOrder(uni id)
{
}

int Market::findCli(uni what, uni nif)
{
	if (nif == 0)
	{
		for (int i = 0; i < this->clients.size(); i++)
		{
			if (this->clients.at(i)->getId() == what)
				return i;
		}
	}
	else
	{

		for (int i = 0; i < this->clients.size(); i++)
		{
			if (this->clients.at(i)->getNif() == what)
				return i;
		}
	}
	return -1;
}

int Market::findCli(Client & cli)
{
	for (int i = 0; i < this->clients.size(); i++)
	{
		if (this->clients.at(i)->getId() == cli.getId())
			return i;
	}
	return -1;
}

vector<Client> Market::showClients()
{
	vector<Client> res;
	for (int i = 0; i < this->clients.size(); i++)
	{
		res.push_back(*this->clients.at(i));
		cout << *this->clients.at(i);
	}
	return res;
}

uni Market::getID()
{
	return this->id;
}

Market::~Market()
{
}

MarketError::MarketError(uni type, string name)
{
	this->type = type;
	this->des = name;
}

string MarketError::what()
{
	return des;
}

uni MarketError::geType()
{
	return type;
}
