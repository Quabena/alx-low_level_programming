#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the head of the doubly linked list
 * @index: index of the node, starting from 0
 *
 * Return: pointer to the nth node, or NULL if the node does not exist
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	/* Traverse the list to find the node at the given index */
	while (head != NULL)
	{
		if (i == index)  /* If the current node is at the index, return it */
			return (head);

		head = head->next;  /* Move to the next node */
		i++;  /* Increment the current index */
	}

	/* If the index is out of range, return NULL */
	return (NULL);
}

