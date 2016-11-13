#pragma once
#include <vector>
#include <string>
#include "Order.h"
#include "Share.h"
//#include "Date.h"
#include <algorithm>
#include "util_funcs.cpp"
#include <ostream>

typedef unsigned int uni;

class Client
{
private:
	static uni cli_id;
	uni id;
	string name;
	uni nif;
	float money;
	//Date joinDate;
public:
	Client( string name, uni nif, float money = 0.0);
	string getName();
	void setName(string name);
	uni getNif();
	void setNif(uni nif);
	float getMoney();
	void setMoney(float money);

	void addShare(Share * newShare);
	void removeShare(uni id);

	void addOrder(Order * newOrder);
	void removeOrder(Order * reOrder);

	uni getId();
	bool operator()(Client & cli,  uni what, uni nif);
	friend ostream & operator<<(ostream & lhs, Client & cli);
	~Client();
};

class ClientError
{
private:
	string des;
	uni type;
public:
	ClientError(uni type, string name);
	string what();
	uni getType();
};
