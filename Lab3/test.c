#include <stdio.h>
#include <stdlib.h>
#include "src.h"
#include <assert.h>

void test()
{
    int N = 10;
    int M = 10;
    int** A = (int**)malloc(N * sizeof(int*));
    if (A == NULL)
    {
        printf("\nMemory error\n");
        exit(0);
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
            exit(0);
        }
    }
    makeSnake(A, N, M);
    int a = A[0][9], b = A[9][9], c = A[9][0], d = A[5][4];
    assert(a == 10);
    assert(b == 19);
    assert(c == 28);
    assert(d == 100);
}

#undef main

int main()
{
    test();
    return 0;
}
