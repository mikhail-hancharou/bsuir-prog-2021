#include <iostream>
#include <fstream>
#include "dataList.h"
#include "getData.h"

using namespace std;

int PrintMenu()
{
    while (1)
    {
        cout << "\n Inter one of digit:\n"
            "1. Show all clients info\n"
            "2. Show all goods info\n"
            "3. Add good\n"
            "4. Add account\n"
            "5. Delete Good\n"
            "6. Calculate Lambard Profit\n"
            "7. Calculate price of all Goods\n"
            "8. Close session\n";
        int digit;
        cin >> digit;
        if (digit > 8 || digit < 1)
        {
            cout << "\nTry again\n";
        }
        else
        {
            return digit;
        }
    }
}
/*
int main()
{
    getData("data.txt");
    while (1) 
    {
        switch (int choise = PrintMenu())
        {
        case 1:
            showClients();
            break;
        case 2:
            showGoods();
            break;
        case 3:
            pushGood(0, 0, "", 0, 0, "", "");
            break;
        case 4:
            pushAccount("", "", "");
            break;
        case 5:
            getGood(0, "");
            break;
        case 6:
            cout << CalculatePrice() << endl;
            break;
        case 7:
            cout << "Profit in bad case: " << ProfitInBadCase();
            cout << "\nProfit in good case: " << ProfitInGoodCase() << endl;
            break;
        case 8:
            setData("data.txt");
            return 0;
        default:
            cout << "\nSomething goes bad\n";
            return 0;
        }
    }
}


*/