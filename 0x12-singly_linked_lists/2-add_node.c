#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_node - to add a new node at beginning of a list_t list.
 * @head: head of list_t list.
 * @str: value to insert into element.
 * Return: number of nodes.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (mew == NULL)
		return (NULL);
	new->str = strdup(str);

	new->len = _strlen(str);
	new->next = *head;
	*head = new;

	return (new);
}
