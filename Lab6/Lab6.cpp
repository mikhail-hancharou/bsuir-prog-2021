#include <iostream>
#include <fstream>
#include "src.h"

using namespace std;

ifstream input ("input.txt");

int main()
{
    Map<string, string> word;
    string exWord;
    string myString;
    while (!input.eof())
    {
        input >> exWord;
        word.insert(exWord, exWord);
        exWord = "";
    }
    Map<string, string>::iterator it;
    Map<string, string>::iterator en;
    en = word.end();
    it = word.begin();
    for (it; it != en; it++)
    {
        cout << *it << ' ' << it.GetAmount() << endl;
    }

    return 0;
}

