#include "stdafx.h"

bool IsPowerOf2(unsigned int value)
{
	return (value & (value - 1)) == 0;
}

int CountBit(int value)
{
	int count = 0;

	while (value != 0)
	{
		value &= value - 1;
		count++;
	}

	return count;
}