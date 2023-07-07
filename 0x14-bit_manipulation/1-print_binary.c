#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int num;
	int counter = 0;
	unsigned long int curr;

	for (num = 63; num >= 0; num--)
	{
		curr = n >> num;

		if (curr & 1)
		{
			_putchar('1');
			counter++;
		}
		else if (counter)
			_putchar('0');
	}
	if (!counter)
		_putchar('0');
}
