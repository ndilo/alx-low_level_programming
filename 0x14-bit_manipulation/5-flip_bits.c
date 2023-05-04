#include "main.h"

/**
 * flip_bits - flip to get from one number to another.
 * @n: first number
 * @m: second number
 * Return: the number of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int diff = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		if ((diff >> i) & 1)
			count++;
	}

	return (count);
}
