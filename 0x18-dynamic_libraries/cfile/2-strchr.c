#include "main.h"

/**
 * *_strchr - prints string characters
 * @s: string
 * @c: character
 *
 * Return: Always 0
 *
 **/

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (c == s[i])
			return (s + i);
	}

	if (c == s[i])
		return (s + i);

	return (0);
}
