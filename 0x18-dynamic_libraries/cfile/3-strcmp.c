#include "main.h"

/**
 * _strcmp - prints a compiled string
 * @s1: first string argument
 * @s2: second string argument
 *
 * Return: Always 0, otherwise 1 on error
 *
 **/

int _strcmp(char *s1, char *s2)
{
	int diff = 0;

	while (diff == 0)
	{
		diff = *s1 - *s2;

		/* break if one of the strings is empty */
		if (*s1 == '\0' || *s2 == '\0')
			break;

		s1++;
		s2++;
	}

	return (diff);
}
