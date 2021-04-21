#include <iostream>
#include <queue>
#include <list>
#include <iterator>
#include "src.h"

using namespace std;

void showQueues(Queue array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Size of " << i << " queue: " << array[i].element.size() << "; First element: " << array[i].element.front() << endl;
    }
}

void showList(List my, int n)
{
    list<char>::iterator it1 = my.dataList.begin();
    list<char>::iterator it2 = my.optionList.begin();
    list<int>::iterator it3 = my.intList.begin();
    for (int i = 0; i < n; i ++)
    {
        cout << "Number of processing queue: " << *it3 << "; Element: " << *it1 << "; Option: " << *it2 << endl;
        it1++;
        it2++;
        it3++;
    }
}

int main()
{
    cout << "Input amount of queues" << endl;
    int n;
    cin >> n;
    Queue* array = new Queue[n];
    List myList;
    int amount = 0;
    while (1)
    {
        bool flag = false;
        cout << "Enter 'A' to add or 'D' to delete or 'S' to stop or 'E' to exit: " << endl;
        char option;
        cin >> option;
        switch (option)
        {
            case 'A':
            {
                amount++;
                int i;
                char data;
                cout << "Inter number of processing queue and data(char)" << endl;
                cin >> i >> data;
                while (i > n || i < 1)
                {
                    cout << "Invalid input. Try again" << endl;
                    cin >> i;
                }
                amount -= queuePush(myList, i - 1, option, array[i - 1], data);
                break;
            }
            case 'D':
            {
                amount--;
                int i;
                cin >> i;
                cout << "Inter number of processing queue" << endl;
                while (i > n || i < 1)
                {
                    cout << "Invalid input. Try again" << endl;
                    cin >> i;
                }
                queuePush(myList, i - 1, option, array[i - 1], '\n');
                break;
            }
            case 'S':
            {
                flag = true;
                break;
            }
            case 'E':
            {
                delete[] array;
                return 0;
            }
            default:
            {
                cout << "Invalid input" << endl;
            }
        }
        if (flag == true)
        {
            break;
        }
    }
    showList(myList, amount);
    showQueues(array, amount);
}
