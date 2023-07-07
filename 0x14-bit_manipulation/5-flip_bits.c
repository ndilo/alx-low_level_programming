#include "main.h"

/**
 * flip_bits - number of different bits between two numbers
 * @n: first number
 * @m: second number
 *
 * Return: number of bits you wold need to flip
 * to get from one number to another
 *
 **/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int mult, mask;
	unsigned int count, i;

	count = 0;
	mask = 1;
	mult = n ^ m;
	for (i = 0; i < 63; i++)
	{
		if (mask == (mult & mask))
			count++;
		mask <<= 1;
	}
	return (count);
}
