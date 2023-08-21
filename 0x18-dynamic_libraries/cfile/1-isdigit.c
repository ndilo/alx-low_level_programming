#include "main.h"

/**
 * _isdigit - prints characters to integers
 * @c: character given
 *
 * Return: Always (0)
 *
 **/

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
