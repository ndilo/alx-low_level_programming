#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - function that frees a listint_t list
 * @head: pointer to the listint_t list to be freed
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *element;

	if (head == NULL)
		return;
	while (*head)
	{
		element = (*head)->next;
		free(*head);
		*head = element;
	}
}
