#include "main.h"

/**
 * _strlen - prints length of strings
 * @s: string
 *
 * Return: Always 0
 *
 **/

int _strlen(char *s)
{
	int length = 0;

	while (*s)
	{
		length++;
		s++;
	}

	return (length);
}
