#include "main.h"

/**
 * *_strncpy - copies a string
 * @dest: first arg
 * @src: second arg
 * @n: integer
 *
 * Return: Always 0, otherwise return error and new line with 1
 *
 **/

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;
	char *new_dest = dest;

	/* copy at most n characters to dest */
	while (*src && (i < n))
	{
		*dest++ = *src++;
		i++;
	}

	/* ensure than n bytes are written */
	while (i < n)
	{
		*dest++ = '\0';
		i++;
	}

	return (new_dest);
}
