#pragma once
#include <list>
#include <string>
using namespace std;

struct dataList
{
	int amount = 0;
	int generalDeposit = 0;
	list<string> NameEtc;
	list<int> id;
	list<string> goodName;
	list<int> allPrice;
	list<int> deposit;
	list<string> deliveryData;
	list<string> storageTime;
};
