#include <iostream>
#include <queue>
#include <list>
#include <iterator>
#include "src.h"

using namespace std;

int queuePush(List& my, int i, char letter, Queue& que, char data = '\n')
{
    my.dataList.push_back(data);
    my.intList.push_back(i);
    my.optionList.push_back(letter);
    if (data == '\n')
    {
        que.element.pop();
        return 0;
    }
    else
    {
        que.element.push(data);
        if (que.element.size() > 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}