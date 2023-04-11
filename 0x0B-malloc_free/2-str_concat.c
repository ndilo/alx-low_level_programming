#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * str_concat - concatenates two strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: a pointer to a newly allocated space in memory which
 * contains the contents of s1, followed by the contents of s2,
 * and null terminated. NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	int k, j, len1, len2, length;
	char *result;

	len1 = len2 = 0;

	if (s1 != NULL)
	{
		k = 0;
		while (s1[k++] != '\0')
			len1++;
	}

	if (s2 != NULL)
	{
		k = 0;
		while (s2[k++] != '\0')
			len2++;
	}

	length = len1 + len2;
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);

	for (k = 0; k < len1; k++)
		result[k] = s1[k];
	for (j = 0; j < len2; j++, k++)
		result[k] = s2[j];
	result[length] = '\0';

	return (result);
}
