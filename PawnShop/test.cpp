#include <iostream>
#include <fstream>
#include "dataList.h"
#include "getData.h" 
#include <assert.h>

using namespace std;

int main()
{
	bool throwExep = false;
	try
	{
		getData("testDataa.txt");
	}
	catch (invalid_argument& ex)
	{
		throwExep = true;
	}
	assert(throwExep);
	throwExep = false;
	assert(getData("testData.txt"));
	assert(6 == showGoods());
	assert(4 == showClients());
	assert(0 == pushGood(-1, 1, "car", 100, 100, "ff", "ff"));
	assert(1 == pushGood(1, 1, "car", 100, 100, "ff", "ff"));
	assert(7 == showGoods());
	assert(56600 == CalculatePrice());
	assert(60125 == ProfitInGoodCase());
	assert(0 == pushAccount("Mikhail", "00000000HB00", "ff"));
	assert(1 == pushAccount("Michael", "00000000HB01", "ff"));
	assert(5 == showClients());
	assert(0 == getGood(10, "ff"));
	assert(1 == getGood(1, "car"));
	assert(56500 == CalculatePrice());
	assert(8500 == ProfitInBadCase());
	assert(60000 == ProfitInGoodCase());
	try
	{
		setData("testData.txt");
	}
	catch (invalid_argument& ex)
	{
		throwExep = true;
	}
	assert(!throwExep);
	return 0;
}