#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number to check bits in
 * @index: index at which to check bit
 *
 * Return: Value of the bit, or -1 on error
 *
 **/

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int div, mask;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	div = 1 << index;
	mask = n & div;
	if (mask == div)
		return (1);
	return (0);
}
