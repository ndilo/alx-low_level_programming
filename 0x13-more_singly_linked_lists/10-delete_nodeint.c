#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at index
 * @head:  pointer to the first element in the list
 * @index: index of node
 *
 * Return: pointer to the index node
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int j;
	listint_t *temp, *new;

	if (!head || !*head)
		return (-1);
	if (index == 0)
	{
		new = (*head)->new;
		free(*head);
		*head = new;
		return (1);
	}
	temp = *head;
	for (j = 0; j < index - 1; j++)
	{
		if (temp->new == NULL)
			return (-1);
		temp = temp->new;
	}
	new = temp->new;
	temp->new = new->new;
	free(new);
	return (1);

}
