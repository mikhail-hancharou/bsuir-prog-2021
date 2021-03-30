#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "main.h"

int get_input()
{
    int x;
    char ch;
    while (scanf("%d%c", &x, &ch) != 2 || ch != '\n' || x < 1000 || x > 9999)
    {
        printf("digit must be more then 999 and less then 10000\nTry again\n");
        while (getchar() != '\n') {};
    }
    return x;
}

int main()
{
    int digit;
    digit = get_input();
    digit = coup(digit);
    printf("%d", digit);
    return 0;
}
