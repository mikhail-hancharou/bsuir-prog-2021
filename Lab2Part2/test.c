#include "header.h"
#include <math.h>
#include <assert.h>

void test()
{
	assert(Calculate(0.753, 0.0000000001) == 6);
	assert(Calculate(0.00789, 0.0000000001) == 2);
	assert(Calculate(0.01, 0.001) == 1);
}

#undef main

int main()
{
	test();
	return 0;
}