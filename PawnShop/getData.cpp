#include <iostream>
#include "getData.h"
#include "client.h"
#include "dataList.h"
#include <fstream>

using namespace std;

dataList dList;
clientList cList;

int getData(string fileName)
{
    ifstream file(fileName);
    if (!file)
    {
        cout << "ERROR. File isn't opened\n";
        throw invalid_argument("No file");
        return 0;
    }
    else 
    {
        cout << "File opened successfully\n";       
    }
    file >> dList.amount;
    string NameEtc;
    int id;
    string goodName;
    int allPrice;
    int deposit;
    string deliveryData;
    string storageTime;
    string passport;
    string singUpData;
    string history;
    for (int i = 0; i < dList.amount; i++)
    {
        file >> NameEtc;
        dList.NameEtc.push_back(NameEtc);
        file >> id;
        dList.id.push_back(id);
        file >> goodName;
        dList.goodName.push_back(goodName);
        file >> allPrice;
        dList.allPrice.push_back(allPrice);
        file >> deposit;
        dList.deposit.push_back(deposit);
        file >> deliveryData;
        dList.deliveryData.push_back(deliveryData);
        file >> storageTime;
        dList.storageTime.push_back(storageTime);
        dList.generalDeposit += deposit;
    }
    file >> cList.amount;
    for (int i = 0; i < cList.amount; i++)
    {
        file >> NameEtc;
        cList.NameEtc.push_back(NameEtc);
        file >> passport;
        cList.passport.push_back(passport);
        file >> id;
        cList.id.push_back(id);
        file >> singUpData;
        cList.singUpData.push_back(singUpData);
        file >> history;
        cList.history.push_back(history);
    }
    file.close();
    return 1;
}

int showGoods()
{
    auto it1 = dList.NameEtc.begin();
    auto it2 = dList.id.begin();
    auto it3 = dList.goodName.begin();
    auto it4 = dList.allPrice.begin();
    auto it5 = dList.deposit.begin();
    auto it6 = dList.deliveryData.begin();
    auto it7 = dList.storageTime.begin();
    for (int i = 0; i < dList.amount; i++)
    {
        cout << "Name: " << *it1 << "; ";
        cout << "id: " <<  *it2 << "; ";
        cout << "Good name: "<< *it3 << "; ";
        cout << "Good price: " << *it4 << "; ";
        cout << "Deposit:" << *it5 << "; ";
        cout << "Delivery data: " << *it6 << "; ";
        cout << "Storage time: " << *it7 << "; ";
        cout << endl;
        it1++; it2++; it3++; it4++; it5++; it6++; it7++;
    }
    return dList.amount;
}

int showClients()
{
    auto it11 = cList.NameEtc.begin();
    auto it22 = cList.passport.begin();
    auto it33 = cList.singUpData.begin();
    auto it44 = cList.history.begin();
    auto id = cList.id.begin();
    for (int i = 0; i < cList.amount; i++)
    {
        cout << "Name: " << *it11 << "; ";
        cout << "Passport: " << *it22 << "; ";
        cout << "Id: " << *id << "; ";
        cout << "Sing up data: " << *it33 << "; ";
        cout << "History: " << *it44 << "; ";
        cout << endl;
        it11++; it22++; it33++; it44++; id++;
    }
    return cList.amount;
}

int setData(string fileName)
{
    ofstream file(fileName);
    if (!file)
    {
        cout << "ERROR. File isn't opened\n";
        throw invalid_argument("No file");
        return 0;
    }
    else
    {
        cout << "File opened successfully\n";
    }
    auto it1 = dList.NameEtc.begin();
    auto it2 = dList.id.begin();
    auto it3 = dList.goodName.begin();
    auto it4 = dList.allPrice.begin();
    auto it5 = dList.deposit.begin();
    auto it6 = dList.deliveryData.begin();
    auto it7 = dList.storageTime.begin();
    file << dList.amount << endl;
    for (int i = 0; i < dList.amount; i++)
    {
        file << *it1 << " ";
        file << *it2 << " ";
        file << *it3 << " ";
        file << *it4 << " ";
        file << *it5 << " ";
        file << *it6 << " ";
        file << *it7 << " ";
        file << endl;
        it1++; it2++; it3++; it4++; it5++; it6++; it7++;
    }
    file << cList.amount << endl;
    auto it11 = cList.NameEtc.begin();
    auto it22 = cList.passport.begin();
    auto it33 = cList.id.begin();
    auto it44 = cList.singUpData.begin();
    auto it55 = cList.history.begin();
    for (int i = 0; i < cList.amount; i++)
    {
        file << *it11 << " ";
        file << *it22 << " ";
        file << *it33 << " ";
        file << *it44 << " ";
        file << *it55 << " ";
        file << endl;
        it11++; it22++; it33++; it44++; it55++;
    }
    file.close();
}

int pushGood(int yn = 0, int idd = 0, string goodNamee = "", int allPricee = 0, int depositt = 0, string deliveryDataa = "", string storageTimee = "")
{
    bool g = true;
    int n;
    int id, allPrice, deposit;
    string goodName, deliveryData, storageTime;
    if (yn != 0 && idd != 0 && goodNamee != "" && allPricee != 0 && depositt != 0 && deliveryDataa != "" && storageTimee != "")
    {
        if (yn == 1)
        {
            g = false;
            n = yn; id = idd; goodName = goodNamee; allPrice = allPricee; deposit = depositt; deliveryData = deliveryDataa; storageTime = storageTimee;
        }
        else
        {
            return 0;
        }
    }
    while (g)
    {
        cout << "\nDo you have an account?(1.Yes 2.No)\n";
        cin >> n;
        if (n > 2 || n < 1)
        {
            cout << "Try again\n";
        }
        else break;
    }
    if (n == 1)
    {
        if (g)
        {
            cout << "\nEnter your id: ";
            cin >> id;
        }
        bool exist = false;
        string NameEtc;
        auto itName = cList.NameEtc.begin();
        auto itt = cList.history.begin();
        for (auto it = cList.id.begin(); it != cList.id.end(); it++)
        {
            if (*it == id)
            {
                exist = true;
                NameEtc = *itName;
                break;
            }
            itName++; itt++;
        }
        if (exist == false)
        {
            cout << "There is no such id\n";
            return 0;
        }
        if (g)
        {
            cout << "\nEnter good name: ";
            cin >> goodName;
            *itt += goodName + "/";
            cout << "\nEnter all price of good: ";
            cin >> allPrice;
            cout << "\nEnter deposit: ";
            cin >> deposit;
            cout << "\nEnter delivery data: ";
            cin >> deliveryData;
            cout << "\nEnter storage time: ";
            cin >> storageTime;
        }
        auto it2 = dList.id.begin();
        dList.NameEtc.push_back(NameEtc);
        dList.id.push_back(id);
        dList.goodName.push_back(goodName);
        dList.allPrice.push_back(allPrice);
        dList.deposit.push_back(deposit);
        dList.deliveryData.push_back(deliveryData);
        dList.storageTime.push_back(storageTime);
        dList.generalDeposit += deposit;
        dList.amount++;
        return 1;
    }
    else if (n == 2)
    {
        pushAccount("", "", "");
        return 1;
    }
    else
    {
        return 0;
    }
}

int pushAccount(string namee = "", string passportCode = "", string singData = "")
{
    bool g = true;
    string name; string passport; string singUpData;
    if (namee != "" && passportCode != "" && singData != "")
    {
        g = false;
        name = namee; passport = passportCode; singUpData = singData;
    }
    if (g)
    {
        cout << "\nEnter your name: ";
        cin >> name;
        cout << "\nEnter your passport code: ";
        cin >> passport;
    }
    for (auto it = cList.passport.begin(); it != cList.passport.end(); it++)
    {
        if (passport == *it)
        {
            cout << "\nThere is already an account with this passport\n";
            return 0;
        }
    }
    cList.NameEtc.push_back(name);
    cList.amount++;
    cList.passport.push_back(passport);
    if (g)
    {
        cout << "\nEnter sing up data: ";
        cin >> singUpData;
    }
    int id = cList.amount;
    cList.id.push_back(id);
    cList.singUpData.push_back(singUpData);
    cList.history.push_back("");
    return 1;
}

int getGood(int idd = 0, string namee = "")
{
    bool g = true;
    int id;
    string goodName;
    if (idd != 0 && namee != "")
    {
        g = false;
        id = idd; goodName = namee;
    }
    if (g)
    {
        cout << "Enter your id: ";
        cin >> id;
        cout << "Enter good name: ";
        cin >> goodName;
    }
    auto it1 = dList.NameEtc.begin();
    auto it2 = dList.id.begin();
    auto it3 = dList.goodName.begin();
    auto it4 = dList.allPrice.begin();
    auto it5 = dList.deposit.begin();
    auto it6 = dList.deliveryData.begin();
    auto it7 = dList.storageTime.begin();
    for (int i = 0; i < dList.amount; i++)
    {
        if (id == *it2 && goodName == *it3)
        {
            dList.NameEtc.erase(it1);
            dList.id.erase(it2);
            dList.goodName.erase(it3);
            dList.allPrice.erase(it4);
            dList.deposit.erase(it5);
            dList.deliveryData.erase(it6);
            dList.storageTime.erase(it7);
            dList.amount--;
            cout << "\nYour good was erased\n";
            return 1;
        }
        it1++; it2++; it3++; it4++; it5++; it6++; it7++;
    }
    cout << "\nThere is no such id";
    return 0;
}

int CalculatePrice()
{
    int price = 0;
    for (auto it = dList.allPrice.begin(); it != dList.allPrice.end(); it++)
    {
        price += *it;
    }
    return price;
}  

int ProfitInBadCase()
{
    int deposits = 0;
    for (auto it = dList.deposit.begin(); it != dList.deposit.end(); it++)
    {
        deposits += *it;
    }
    int profit = CalculatePrice() - deposits;
    return profit;
}

int ProfitInGoodCase()
{
    int deposits = 0;
    for (auto it = dList.deposit.begin(); it != dList.deposit.end(); it++)
    {
        deposits += *it;
    }
    return deposits * 1.25;
}