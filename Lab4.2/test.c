#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "src.h"
#include <assert.h>

void test()
{
    FILE* f;
    if ((f = fopen("dict.txt", "r")) == NULL)
    {
        printf("Oh cringe, smth went wrong\n");
        exit(-1);
    }

    char answ[120];
    char wordd[15] = { 't', 'r', 'u', 'i', 'f' };
    char check[15] = { 'f', 'r', 'u', 'i', 't' };
    search4u(f, wordd, answ);
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        assert(check[i] == answ[i]);
    }
    char worddd[15] = { 'l', 'e', 'p', 'p', 'a' };
    char checkk[15] = { 'a', 'p', 'p', 'l', 'e' };
    search4u(f, worddd, answ);
    for (i = 0; i < 5; i++)
    {
        assert(checkk[i] == answ[i]);
    }
    char wordddd[15] = { 'l', 'o', 'f', 'a', 'p', 'p' };
    char checkkk[15] = { 'f', 'l', 'o', 'p', 'p', 'a' };
    search4u(f, wordddd, answ);
    for (i = 0; i < 6; i++)
    {
        assert(checkkk[i] == answ[i]);
    }
    fclose(f);
}

#undef main

int main()
{
    test();
}