#include "main.h"

/**
 * *_strcat - prints a string
 * @dest: random argument
 * @src: argument two
 *
 * Return: Always 0 on success, otherwise 1
 *
 **/

char *_strcat(char *dest, char *src)
{
	char *new_dest = dest;

	/* navigate to the end of dest */
	while (*dest)
		dest++;

	/* copy all characters of src to dest */
	while (*src)
		*dest++ = *src++;

	/* add terminating null byte */
	*dest = '\0';

	return (new_dest);
}
