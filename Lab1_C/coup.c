#include "main.h"
#include <stdio.h>

int coup(int digit)
{
	digit = (digit % 100) * 100 + (digit / 100);
	return digit;
}
