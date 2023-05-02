#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - deletes the head node
 * @head: a double pointer
 *Return: 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *element;
	int num;

	if (!head || !*head)
		return (0);
	element = *head;
	*head = element->next;
	num = element->n;
	free(element);
	return (num);
}
