#include "main.h"

/**
 * *_memcpy - prints some function
 * @dest: argument one
 * @src: arg two
 * @n: integer
 *
 * Return: Always 0
 *
 **/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
