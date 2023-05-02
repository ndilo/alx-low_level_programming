#include "lists.h"
#include <stdlib.h>
/**
  * add_nodeint_end - add node at end of a listint_t list.
  * @head: pointer to the first element in the list
  * @n: data to insert in the new element
  * Return: NULL if not successful
  */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *add;
	listint_t *temp;

	if (!head)
		return (NULL);
	add = malloc(sizeof(listint_t));
	if (!add)
		return (NULL);
	add->n = n;
	add->next = NULL;
	if (!*head)
	{
	*head = add;
		return (add);
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = add;
	return (add);
}
