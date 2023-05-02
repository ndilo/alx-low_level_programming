#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data in new node
 * Return: the address of new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int j;
	listint_t *add;
	listint_t *temp = *head;

	add = malloc(sizeof(listint_t));
	if (add == NULL || head == NULL)
		return (NULL);

	add->n = n;
	add->next = NULL;

	if (idx == 0)
	{
		add->next = *head;
		*head = add;
		return (add);
	}

	for (j = 0; temp && j < idx; j++)
	{
		if (j == idx - 1)
		{
			add->next = temp->next;
			temp->next = add;
			return (add);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}
