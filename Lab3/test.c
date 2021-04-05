#include <stdio.h>
#include <stdlib.h>
#include "src.h"
#include <assert.h>

void test()
{
    int N = 10;
    int M = 10;
    int i;
    int j;
    int** A = set_array(N, M);  
    makeSnake(A, N, M); 
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%6d ", A[i][j]);
        }
        printf("\n");
    }
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

