#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - frees a listint_t list
 * @head: head of the list
 * Return: NULL if fails
 */

void free_listint(listint_t *head)
{
	listint_t *element;

	while (head)
	{
		element = head->next;
		free(head);
		head = element;
	}
}
