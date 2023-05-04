#include "main.h"
#include<stddef.h>

/**
 * print_binary - prints the binary representation of a number
 * @n: num of prented
 * @index: index of the bit
 * Return: 
 */

void print_binary(unsigned long int n)
{
	int j, count = 0;
	unsigned long int num;

	for (j = 63; j >= 0; j--)
	{
		num = n >> j;

		if (num & 1)
		{
			_putchar('1');
			num++;
		}
		else if (count != 0)
			_putchar('0');
	}
	if ((count = 0))
		_putchar('0');
}
