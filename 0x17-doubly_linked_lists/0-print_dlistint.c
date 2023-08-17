#include "lists.h"

/**
 * print_dlistint - prints all elements of a doubly linked list
 * @h: Pointer to first node in the list.
 *
 * Return: Number of nodes in the list.
 */

size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *curr = h;
	int element = 0;

	while (curr)
	{
		printf("%d\n", curr->n);
		element++;
		curr = curr->next;
	}

	return (element);
}
