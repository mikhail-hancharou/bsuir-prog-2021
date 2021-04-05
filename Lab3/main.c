#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "src.h"

int main()
{
    int N = getInput();
    int M = getInput();
    int** A = (int**)malloc(N * sizeof(int*));
    if (A == NULL)
    {
        printf("\nMemory error\n");
        return 1;
    }
    int i;
    int j;
    for (i = 0; i < N; i++)
    {
        A[i] = (int*)malloc(M * sizeof(int));
        if (A[i] == NULL)
        {
            for (j = i; j >= 0; j--)
            {
                free(A[j]);
            }
            free(A);
            printf("\nMemory error\n");
            return 1;
        }
    }
    makeSnake(A, N, M);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%6d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}

