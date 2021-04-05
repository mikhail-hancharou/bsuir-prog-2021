#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

void makeSnake(int** A, int N, int M)
{
    
    int digit = 1;
    int helpOneI = 0;
    int helpOneJ = 0;
    int i, j;
    while (digit > 0)
    {
        while (helpOneJ < M)
        {
            if (helpOneI == -1)
            {
                helpOneI++;
            }
            assert(helpOneI < N);
            assert(helpOneJ < M);
            A[helpOneI][helpOneJ] = digit++;
            if (helpOneJ + 1 < M && A[helpOneI][helpOneJ + 1] > 0 && A[helpOneI][helpOneJ + 1] < 10000)
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
            assert(helpOneI < N);
            assert(helpOneJ < M);
            A[helpOneI][helpOneJ] = digit++;
            if (helpOneI + 1 < N && A[helpOneI + 1][helpOneJ] > 0 && A[helpOneI + 1][helpOneJ] < 10000)
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
            assert(helpOneI < N);
            assert(helpOneJ < M);
            A[helpOneI][helpOneJ] = digit++;
            if (helpOneJ - 1 >= 0 && A[helpOneI][helpOneJ - 1] > 0 && A[helpOneI][helpOneJ - 1] < 10000)
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
            assert(helpOneI < N);
            assert(helpOneJ < M);
            A[helpOneI][helpOneJ] = digit++;
            if (helpOneI - 1 >= 0 && A[helpOneI - 1][helpOneJ] > 0 && A[helpOneI - 1][helpOneJ] < 10000)
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

int** set_array(int n, int m) 
{
    int** a;
    if (!(a = (int**)malloc(n * sizeof(int*)))) 
    {
        free(a);
        printf("Memory error");
        exit(1);
    }

    int i;
    for (i = 0; i < n; i++) {
        if (!(a[i] = (int*)malloc(m * sizeof(int))))
        {
            for (i; i >= 0; i--)
            {
                free(a[i]);
            }
            printf("Memory error");
            exit(1);
        }
    }
    return a;
}

