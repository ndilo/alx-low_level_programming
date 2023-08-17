#include "lists.h"

void insert_middle(dlistint_t ***h, dlistint_t **new_node, dlistint_t **curr);

/**
 * insert_dnodeint_at_index - inserts a node at a given index of a list
 * @h: Pointer to first node in the list.
 * @idx: Index at which to insert the node, starting from 0.
 * @n: Data to be assigned to new node.
 *
 * Return: Address of new node, or NULL if it can't be added.
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *curr = *h;
	dlistint_t *new_;
	unsigned int index = 0;

	if (!h) /* Check if list is empty */
		return (NULL);

	if (idx == 0)
	{ /* Add node at the beginning if index is 0 */
		new_ = add_dnodeint(h, n);
		return (new_);
	}

	new_ = malloc(sizeof(dlistint_t));
	if (!new_)
		return (NULL);

	new_->n = n;

	while (curr)
	{
		if (index == idx)
		{ /* Find the node that is currently at the specified index */
			insert_middle(&h, &new_, &curr);
			return (new_);
		}

		curr = curr->next;
		index++;
	}

	if (index == idx)
	{ /* Add node at end if index is the last index of the list */
		new_ = add_dnodeint_end(h, n);
		return (new_);
	}

	free(new_);
	return (NULL);
}

/**
 * insert_middle - inserts a node at a given index in the middle of a list
 * @h: Pointer to first node in the list.
 * @new_: New node to be inserted at index.
 * @curr: Node that is currently at that index.
 *
 * Return: Nothing.
 */

void insert_middle(dlistint_t ***h, dlistint_t **new_, dlistint_t **curr)
{
	(*new_)->next = *curr;
	(*new_)->prev = (*curr)->prev;

	if ((*curr)->prev)
		(*curr)->prev->next = *new_;
	else /* If the current node is the first node */
		**h = *new_; /* Update the head of the list */

	(*curr)->prev = *new_;
}
