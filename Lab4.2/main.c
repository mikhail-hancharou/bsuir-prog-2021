#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "src.h"

int main()
{
    FILE* fp;
    if ((fp = fopen("dict.txt", "r")) == NULL)
    {
        printf("Oh cringe, smth went wrong\n");
        return(-1);
    }
    char word[15];
    gets(word);
    char ans[120];
    search4u(fp, word, ans);
    printf("%s\n", ans);
}
