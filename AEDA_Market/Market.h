#pragma once
#include <vector>
#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
#include "Client.h"
#include "Share.h"
#include "Order.h"
#include "Industry.h"
//#include "util_funcs.cpp"

using namespace std;

typedef unsigned int uni;

class Market
{
private:
	static uni market_ID;
	uni id;
	vector<Client *> clients;
	vector<Share *> shares;
	vector<Order *> orders;
	vector<Industry *> industries;
	float value;

	float calc_newValue();

public:
	Market();
	Market(uni value_mul);
	bool loadFile(string filename);
	bool saveFile(string filename);
	Client * getClient(string name);
	Client * getClient(uni NIF);
	int update_all();
	float getValue();
	void setValue(float newVal);
	void addClient(Client * newCli);
	void removeClient(uni what, uni nif);

	void addShare(Share* newShare);
	void removeShare(uni id);
	
	void addOrder(Order * newOrder);
	
	void removeOrder(uni id);
	int findCli(uni what, uni nif);
	
	int findCli(Client & cli);
	vector<Client> showClients();
	uni getID();
	~Market();
};

class MarketError
{
private:
	string des;
	uni type;
public:
	MarketError(uni type, string name);
	string what();
	uni geType();
};
