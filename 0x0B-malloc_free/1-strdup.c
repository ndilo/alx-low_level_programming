#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string
 *
 * Return: pointer to the duplicated string.
 * returns NULL if memory was enough
 */
char *_strdup(char *str)
{
	char *copy;
	int j, length = 0;

	if (str == NULL)
		return (NULL);

	while (str[length] != '\0')
		length++;

	copy = (char *)malloc((sizeof(char) * length) + 1);
	if (copy == NULL)
		return (NULL);

	for (j = 0; j < length; j++)
		copy[j] = str[j];
	copy[length] = '\0';

	return (copy);
}
