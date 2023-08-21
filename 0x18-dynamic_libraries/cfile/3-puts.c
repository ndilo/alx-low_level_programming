#include "main.h"

/**
 * _puts - prints out a string
 * @s: string
 *
 * Return: Alwyas 0
 *
 **/

void _puts(char *s)
{
	while (*s)
	{
		_putchar(*s);
		s++;
	}

	_putchar('\n');
}
