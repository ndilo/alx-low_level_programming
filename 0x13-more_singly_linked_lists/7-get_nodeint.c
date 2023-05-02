#include "lists.h"

/**
 * get_nodeint_at_index - the nth node of a listint_t linked list.
 * @head: pointer to the first node
 * @index: index of the node
 * Return: pointer of Index
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int j;

	if (!head)
		return (NULL);
	for (j = 0; j < index; j++)
	{
		head = head->next;
		if (!head)
			return (NULL);
	}
	return (head);
}
