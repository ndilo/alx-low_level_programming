#include "main.h"

/**
 * *_strncat - prints some function
 * @dest: arg one
 * @src: arg two
 * @n: integer
 *
 * Return: Always 0
 **/

char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	char *new_dest = dest;

	/* navigate to the end of dest */
	while (*dest)
		dest++;

	/* append at most n characters to src */
	while (*src && (i < n))
	{
		*dest++ = *src++;
		i++;
	}

	/* add the terminating null byte */
	*dest = '\0';

	return (new_dest);
}
