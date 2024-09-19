#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position in a
 * dlistint_t list
 * @h: double pointer to the head of the doubly linked list
 * @idx: index where the new node should be added (starts at 0)
 * @n: data (integer) for the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current = *h;
	unsigned int i = 0;

	/* Case 1: Add node at the beginning */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* Traverse the list to find the position where the node should be inserted */
	while (current != NULL && i < idx - 1)
	{
		current = current->next;
		i++;
	}

	/* If the index is out of bounds */
	if (current == NULL || (current->next == NULL && i < idx - 1))
		return (NULL);

	/* Case 2: Add node at the end */
	if (current->next == NULL && i == idx - 1)
		return (add_dnodeint_end(h, n));

	/* Case 3: Insert node at the middle */
	new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = current->next;
	new_node->prev = current;

	if (current->next != NULL)
		current->next->prev = new_node;
	current->next = new_node;

	return (new_node);
}

