#include <stdio.h>
#include <math.h>
#include "header.h"

int main()
{
	double x, epsilon;
	int number;
	printf("Enter x (more then 0, less then pi/2:\n");
	x = GetDigit(0, 1.570);
	printf("Enter epsilon (more then 0, less then 1000):\n");
	epsilon = GetDigit(0, 1000);
	number = Calculate(x, epsilon);
	printf("%d\n", number);
	return 0;
}