#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index of a dlistint_t
 * linked list
 *
 * @head: first element
 * @index: elements number
 *
 * Return: error code
 *
 **/

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *before, *curr;
	unsigned int i = 0;

	curr = *head;

	if (curr == NULL)
		return (-1);

	if (index == 0)
	{
		*head = curr->next;
		curr->prev = NULL;
		free(curr);

		return (1);
	}

	while (i < index)
	{
		before = curr;
		if (curr->next == NULL)
			return (-1);

		curr = curr->next;
		i++;
	}
	before->next = curr->next;

	if (curr->next != NULL)
		curr->next->prev = before;
	free(curr);

	return (1);
}
