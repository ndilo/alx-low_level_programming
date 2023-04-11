#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars
 * and initializes a specific char.
 * @size: size of array
 * @c: initial value
 *
 * Return: a pointer to the array, or NULL if not successful
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int j;

	if (size == 0)
		return (NULL);

	array = (char *)malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);

	for (j = 0; j < size; j++)
		array[j] = c;

	return (array);
}
