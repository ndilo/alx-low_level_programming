#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: first element
 * @n: number
 * Return: new node
 *
 **/

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_;
	dlistint_t *tmp;

	new_ = NULL;
	tmp = *head;

	new_ = malloc(sizeof(dlistint_t));

	if (new_ == NULL)
	{
		return (NULL);
	}

	new_->n = n;
	new_->next = NULL;

	if (*head == NULL)
	{
		new_->prev = NULL;
		*head = new_;
	}
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		new_->prev = tmp;
		tmp->next = new_;
	}

	return (new_);
}
