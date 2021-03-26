#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int GetInput()
{
    int x;
    char ch;
    while (scanf("%d%c", &x, &ch) != 2 || ch != '\n' || x < 0 || x > 1001)
    {
        printf("Digit must be more then 1 and less then 1001\nTry again\n");
        while (getchar() != '\n') {}
    }
    return x;
}

int ShowMenu()
{
	int wants;
	printf("1.Inter your preference\n2.Information\n3.Contact us\n4.Exit\n");
	wants = GetInput();
    while (wants > 4)
    {
        printf("Inter again\n");
        wants = GetInput();
    }
    return wants;
}

int rate(int gb, int min1, int min2, int sms)
{
    double inf[6][4] = { -1, 400, 400, 0, 50, -1, -1, 0, 10, 400, 400, 0, 25, -1, -1, 0, 1, 200, 0, 0, -1, 100, 0, 100 };
    double rate[24];
    int i;
    int n;
    for (i = 0; i < 6; i++)
    {
        for (n = 0; n < 4; n++)
        {
            if (n == 0)
            {
                if (inf[i][n] == gb)
                {
                    rate[i * 4 + n] = 1;
                }
                else if (inf[i][n] == -1 && gb != 0)
                {
                    rate[i * 4 + n] = 0.99;
                }
                else if ((inf[i][n] == -1 && gb == 0) || gb == 0)
                {
                    rate[i * 4 + n] = 0;
                }
                else
                {
                    rate[i * 4 + n] = inf[i][n] / gb;
                }
            }
            else if (n == 1)
            {
                if (inf[i][n] == min1)
                {
                    rate[i * 4 + n] = 1;
                }
                else if (inf[i][n] == -1 && min1 != 0)
                {
                    rate[i * 4 + n] = 0.99;
                }
                else if ((inf[i][n] == -1 && min1 == 0) || min1 == 0)
                {
                    rate[i * 4 + n] = 0;
                }
                else
                {
                    rate[i * 4 + n] = inf[i][n] / min1;
                }
            }
            else if (n == 2)
            {
                if (inf[i][n] == min2)
                {
                    rate[i * 4 + n] = 1;
                }
                else if (inf[i][n] == -1 && min2 != 0)
                {
                    rate[i * 4 + n] = 0.99;
                }
                else if ((inf[i][n] == -1 && min2 == 0) || min2 == 0)
                {
                    rate[i * 4 + n] = 0;
                }
                else
                {
                    rate[i * 4 + n] = inf[i][n] / min2;
                }
            }
            else if (n == 3)
            {
                if (inf[i][n] == sms)
                {
                    rate[i * 4 + n] = 1;
                }
                else if (inf[i][n] == -1 && sms != 0)
                {
                    rate[i * 4 + n] = 0.99;
                }
                else if ((inf[i][n] == -1 && sms == 0) || sms == 0)
                {
                    rate[i * 4 + n] = 0;
                }
                else
                {
                    rate[i * 4 + n] = inf[i][n] / sms;
                }
            }
        }
    }
    double final[6] = { 0 };
    for (i = 0; i < 6; ++i)
    {
        for (n = 0; n < 4; ++n)
        {
            final[i] += rate[i * 4 + n];
        }
        final[i] /= 4;
    }
    for (i = 0; i < 6; ++i)
    {
        final[i] -= 1;
        if (final[i] < 0)
        {
            final[i] *= -1;
        }
    }
    int index = 0;
    double digit = final[0];
    for (i = 0; i < 5; ++i)
    {
        if (digit > final[i + 1])
        {
            digit = final[i + 1];
            index = i + 1;
        }
    }
    return index + 1;
}