#include <stdio.h>
#include <assert.h>
#include "src.h"

void test_run()
{
	assert(1 == rate(30, 400, 400, 0));
	assert(2 == rate(50, 100, 200, 0));
	assert(3 == rate(10, 400, 400, 0));
	assert(4 == rate(25, 500, 300, 0));
	assert(5 == rate(1, 200, 0, 0));
	assert(6 == rate(50, 100, 0, 100));
}

#undef main

int main()
{
	test_run();
	return 0;
}
