#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - prints all the elements of a doubly linked list
 * @h: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	/* Traverse the list */
	while (h != NULL)
	{
		printf("%d\n", h->n);  /* Print the value of the current node */
		h = h->next;  /* Move to the next node */
		count++;  /* Increment the count of nodes */
	}

	return (count);  /* Return the total number of nodes */
}
