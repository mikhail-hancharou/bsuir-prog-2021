#include <iostream>
#include <queue>
#include <list>
#include <iterator>
#include "src.h"
#include <assert.h>

using namespace std;

void test(Queue kwekwe[])
{
    assert('F' == kwekwe[0].element.front());
    assert('l' == kwekwe[1].element.front());
    assert('0' == kwekwe[2].element.front());
    assert('p' == kwekwe[3].element.front());
    assert('p' == kwekwe[4].element.front());
    assert('a' == kwekwe[5].element.front());
    assert('g' == kwekwe[6].element.front());
    assert('0' == kwekwe[7].element.front());
    assert('0' == kwekwe[8].element.front());
    assert('d' == kwekwe[9].element.front());
}

int main()
{
    int n = 10;
    Queue* array = new Queue[n];
    List myList;
    int i = 1;
    char data = 'F';
    char option = 'A';
    queuePush(myList, i - 1, option, array[i - 1], data);
    i++;
    data = 'l';
    queuePush(myList, i - 1, option, array[i - 1], data);
    i++;
    data = '0';
    queuePush(myList, i - 1, option, array[i - 1], data);
    i++;
    data = 'p';
    queuePush(myList, i - 1, option, array[i - 1], data);
    i++;
    data = 'p';
    queuePush(myList, i - 1, option, array[i - 1], data);
    i++;
    data = 'a';
    queuePush(myList, i - 1, option, array[i - 1], data);
    i++;
    data = 'g';
    queuePush(myList, i - 1, option, array[i - 1], data);
    i++;
    data = '0';
    queuePush(myList, i - 1, option, array[i - 1], data);
    i++;
    data = '0';
    queuePush(myList, i - 1, option, array[i - 1], data);
    i++;
    data = 'd';
    queuePush(myList, i - 1, option, array[i - 1], data);
    return 0;
}