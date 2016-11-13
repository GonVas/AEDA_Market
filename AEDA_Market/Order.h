#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "Industry.h"
#include "Share.h"

typedef unsigned int uni;

using namespace std;

class Order
{
private:
	static uni order_id;
	uni id;
	uni amount;
	float price;
	uni NIF_owner;
	string industry;
public:
	Order(float price, uni new_NIF, string industry);
	virtual Share* operate() = 0;
};

class SellOrder
{


};

class BuyOrder
{


};
