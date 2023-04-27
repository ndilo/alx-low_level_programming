#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * list_len - number of elements in a linked list_t list
 * @h: name of list
 * Return: number of nodes.
 */
size_t list_len(const list_t *h)
{
	int num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}
	return (num);
}
