#pragma once
#include "client.h"
#include "dataList.h"
#include <fstream>

int getData(string fileName);
int setData(string fileName);
int showGoods();
int showClients();
int pushAccount(string namee, string passportCode, string singData);
int pushGood(int yn, int id, string goodName, int allPrice, int deposit, string deliveryData, string storageTime);
int getGood(int idd, string namee);
int CalculatePrice();
int ProfitInBadCase();
int ProfitInGoodCase();

