#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index.
 * @index: starting from 0 of the bit you want to set
 * @n: pointer to number
 * Return: 1 for success, -1 for failure
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	*n = *n | (1 << index);
	return (1);
}
