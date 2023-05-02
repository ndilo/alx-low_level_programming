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
	listint_t *temp;
	listint_t *new;

	if (!head || !*head)
		return (-1);
	if (index == 0)
	{
		new = (*head)->next;
		free(*head);
		*head = new;
		return (1);
	}
	temp = *head;
	for (j = 0; j < index - 1; j++)
	{
		if (temp->next == NULL)
			return (-1);
		temp = temp->next;
	}
	new = temp->next;
	temp->next = new->next;
	free(new);
	return (1);

}
