#include "function_pointers.h"

/**
 * array_iterator - a function given as a
 * parameter on each element of an array.
 *
 * @array: array to execute func
 * @size: size of array
 * @action: pointer to the function
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t j;

	if (array && action)
	{
		j = 0;
		while (j < size)
		{
			action(array[j]);
			j++;
		}
	}
}
