#include "Client.h"

uni Client::cli_id = 0;

Client::Client(string name, uni nif, float money)
{
	this->id = 2 * pow(10, count_digits(Client::cli_id)) + Client::cli_id;
	this->name = name;
	if (nif <= 0)
	{
		ClientError niff(2, "Invalid nif.");
		throw niff;
	}
	this->nif = nif;
	if (money <= 0)
	{
		ClientError neg(0, "Can't have negative money.");
		throw neg;
	}
	this->money = money;
	Client::cli_id = Client::cli_id+1;
}

string Client::getName()
{
	return this->name;
}

void Client::setName(string name)
{
	this->name = name;
	return;
}

uni Client::getNif()
{
	return this->nif;
}

void Client::setNif(uni nif)
{
	if (nif < 1)
	{
		ClientError niff(2, "Invalid Nif");
		throw niff;
	}
	return ;
}

float Client::getMoney()
{
	return this->money;
}

void Client::setMoney(float money)
{
	if (money <= 0)
	{
		ClientError mon(3, "Invalid money amount.");
		throw mon;
	}
	this->money = money;
}

void Client::addShare(Share * newShare)
{
}

void Client::removeShare(uni id)
{
}

void Client::addOrder(Order * newOrder)
{
}

void Client::removeOrder(Order * reOrder)
{
}

uni Client::getId()
{
	return this->id;
}

Client::~Client()
{
}

ClientError::ClientError(uni type, string name)
{
	this->type = type;
	this->des = name;
}

string ClientError::what()
{
	return this->des;
}

uni ClientError::getType()
{
	return this->type;
}

ostream & operator<<(ostream & lhs, Client & cli)
{
	(lhs << "Client name: " << cli.getName() << " id: " << cli.getId() << " Nif: " << cli.getNif() << " money: " << cli.getMoney() << endl);
	return lhs;
}
