#include "main.h"
/**
 * factorial - factorial of int
 * @n: number to be factored
 * Return: factorial of a given number
 */
int factorial(int n)
{
	int x;

	if (n == 0)
	{
		return (1);
	}
	else if (n < 0)
	{
		return (-1);
	}
	else
	{
		x = n * factorial(n - 1);
	}
			return (x);
}
