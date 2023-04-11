#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: width of array
 * @height: height of array
 *
 * Return: a pointer to a 2 dimensional array of integers.
 */
int **alloc_grid(int width, int height)
{
	int **array, k, j;
	int length = width * height;

	if (length <= 0)
		return (NULL);

	array = (int **)malloc(sizeof(int *) * height);
	if (array == NULL)
		return (NULL);

	for (k = 0; k < height; k++)
	{
		array[k] = (int *)malloc(sizeof(int) * width);
		if (array[k] == NULL)
		{
			for (k--; k >= 0; k--)
				free(array[k]);
			free(array);
			return (NULL);
		}
	}

	for (k = 0; k < height; k++)
		for (j = 0; j < width; j++)
			array[k][j] = 0;

	return (array);
}
