#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int getInput()
{
	int digit;
	char ch;
	while (scanf("%d%c", &digit, &ch) != 2 || ch != '\n' || digit < 1 || digit > 100) {
		printf("Inter digit more then %d and less then %d ", 0, 100);
		while (getchar() != '\n');
	}
	return digit;
}

void makeSnake(int* A[], int N, int M)
{
    int digit = 1;
    int helpOneI = 0;
    int helpOneJ = 0;
    while (digit > 0)
    {
        while (helpOneJ < M)
        {
            if (helpOneI == -1)
            {
                helpOneI++;
            }
            A[helpOneI][helpOneJ] = digit++;
            if (helpOneJ + 1 < M && A[helpOneI][helpOneJ + 1] > 0)
            {
                helpOneI++;
                break;
            }
            helpOneJ++;
            if (helpOneJ == M)
            {
                helpOneI++;
            }
        }
        if (digit >= N * M + 1)
        {
            break;
        }
        while (helpOneI < N)
        {
            if (helpOneJ == M)
            {
                helpOneJ--;
            }
            A[helpOneI][helpOneJ] = digit++;
            if (helpOneI + 1 < N && A[helpOneI + 1][helpOneJ] > 0)
            {
                helpOneJ--;
                break;
            }
            helpOneI++;
            if (helpOneI == N && helpOneJ != 0)
            {
                helpOneJ--;
            }
        }
        if (digit >= N * M + 1)
        {
            break;
        }
        while (helpOneJ >= 0)
        {
            if (helpOneI == N)
            {
                helpOneI--;
            }
            A[helpOneI][helpOneJ] = digit++;
            if (helpOneJ - 1 >= 0 && A[helpOneI][helpOneJ - 1] > 0)
            {
                helpOneI--;
                break;
            }
            helpOneJ--;
            if (helpOneJ == -1)
            {
                helpOneI--;
            }
        }
        if (digit >= N * M + 1)
        {
            break;
        }
        while (helpOneI >= 0)
        {
            if (helpOneJ == -1)
            {
                helpOneJ++;
            }
            A[helpOneI][helpOneJ] = digit++;
            if (helpOneI - 1 >= 0 && A[helpOneI - 1][helpOneJ] > 0)
            {
                helpOneJ++;
                break;
            }
            helpOneI--;
        }
        if (digit >= N * M + 1)
        {
            break;
        }
    }
}
