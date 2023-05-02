#include "lists.h"

/**
 * reverse_listint - the function that reverses a listint_t
 * @head: pointer to the first node in the list
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev;
	listint_t *next;

	if (!head || !*head)
		return (NULL);
	if ((*head)->next == NULL)
		return (*head);
	prev = NULL;
	while (*head)
	{
		next = (*head)->next;
		(*head)->next = previous;
		prev = *head;
		*head = next;
	}
	*head = prev;
	return (*head);
}
