#include "main.h"
/**
 * _power - calculate (base and power)
 * @base: base the exponet
 * @pow: power the exponet
 * Return: base and power
 *
 */
unsigned long int _power(unsigned int base, unsigned int pow)
{
	unsigned long int num;
	unsigned int j;

	num = 1;
	for (j = 1; j <= pow; j++)
		num *= base;
	return (num);
}

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print in binary
 */

void print_binary(unsigned long int n)
{
	unsigned long int val, result;
	char c = 0;

	val = _power(2, 63;

	while (val)
	{
		result = n & val;
		if (result == val)
		{
			c = 1;
			_putchar('1');

		}
		else if (c == 1 || val == 1)
		{
			_putchar('0');
		}
		val >>= 1;
	}
}
