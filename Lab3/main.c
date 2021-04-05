#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "src.h"

int main()
{
    int N = getInput();
    int M = getInput();
    int** A = set_array(N, M);
    int i;
    int j;
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


