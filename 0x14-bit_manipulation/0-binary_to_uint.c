#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: pointer to string containing the binary numbe
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int k;
	unsigned int val = 0;

	if (!b)
		return (0);
	for (k = 0; b[k] != '\0'; k++)
	{
		if (b[k] != '0' && b[k] != '1')
			return (0);
	}
	for (k = 0; b[k] != '\0'; k++)
	{
		val <<= 1;
		if (b[k] == '1')
			val += 1;
	}
	return (val);
}
