#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: Pointer to a string containing a binary number
 *
 * Return: unsigned int with a decimal value of binary number, or 0 on error
 *
 **/

unsigned int binary_to_uint(const char *b)
{
	int p;
	unsigned int k;

	k = 0;
	if (!b)
		return (0);
	for (p = 0; b[p] != '\0'; p++)
	{
		if (b[p] != '0' && b[p] != '1')
			return (0);
	}
	for (p = 0; b[p] != '\0'; p++)
	{
		k <<= 1;
		if (b[p] == '1')
			k += 1;
	}
	return (k);
}
