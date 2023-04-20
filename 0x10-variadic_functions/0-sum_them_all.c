#include "variadic_functions.h"

/**
 * sum_them_all - adds all the numbers
 * @n: the number of parameters passed
 * Return: Always 0
 */

int sum_them_all(const unsigned int n, ...)
{
	int sum;
	unsigned int j;
	va_list list;

	va_start(list, n);

	if (n == 0)
		return (0);

	for (j = 0; j < n; j++)
		sum += va_arg(list, int);

	va_end(list);

	return (sum);
}
