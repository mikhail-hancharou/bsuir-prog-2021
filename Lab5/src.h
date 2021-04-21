#pragma once
#include <iostream>
#include <queue>
#include <list>
using namespace std;

struct Queue
{
    queue<char> element;
};

struct List
{
    list<int> intList;
    list<char> optionList;
    list<char> dataList;
};
int queuePush(List& my, int i, char letter, Queue& que, char data);

