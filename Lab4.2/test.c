#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "src.h"
#include <assert.h>

void test(FILE* fp)
{
    char answ[120];
    char wordd[15] = { 't', 'r', 'u', 'i', 'f' };
    search4u(fp, wordd, answ);
    assert("fruit" == answ);
    char worddd[15] = { 'l', 'e', 'p', 'p', 'a' };
    search4u(fp, worddd, answ);
    assert("apple" == answ);
    char wordddd[15] = { 'l', 'o', 'f', 'a', 'p', 'p' };
    search4u(fp, worddd, answ);
    assert("floppa" == answ);
}

#undef main

int main()
{
    FILE* fp;
    if ((fp = fopen("dict.txt", "r")) == NULL)
    {
        printf("Oh cringe, smth went wrong\n");
        return(-1);
    }
    test(fp);
}