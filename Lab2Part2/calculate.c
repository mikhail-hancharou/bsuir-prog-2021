#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"
#include <math.h>

double GetDigit(double min, double max) 
{
	double input;
	char ch;
	while (scanf("%lf%c", &input, &ch) != 2 || ch != '\n' || input < min || input > max) 
	{
		printf("Try again (more then %lf, less then %lf)\n", min, max);
		while (getchar() != '\n') {}
	}
	return input;
}

int Calculate(double x, double epsilon)
{
    double sinx = sin(x);
    int n = 1;
    double fact = 2;
    double denominator = 1;
    double numerator = x;
    double finalResult = x;

    while (fabs(finalResult - sinx) >= epsilon) {
        numerator *= x * x;
        denominator *= fact * (fact + 1);
        finalResult += (n % 2 == 0 ? 1 : -1) * (numerator / denominator);
        fact += 2;
        n++;
    }
    return n;
}