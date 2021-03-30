#include <assert.h>
/*#include <conio.h>*/
#include "main.h"

int test_coup() 
{
    assert(coup(4566) == 6645);
    assert(coup(8811) == 1188);
    assert(coup(3429) == 2934);
    return 0;
}

#undef main

int main() 
{
    test_coup();
    /*getch();*/
    return 0;
}


