#include "lists.h"
#include <stdlib.h>  /* for free */

/**
 * free_dlistint - frees a doubly linked list
 * @head: pointer to the head of the list
 *
 * Return: void
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	/* Traverse the list and free each node */
	while (head != NULL)
	{
		temp = head;    /* Store current node in temp */
		head = head->next;  /* Move to the next node */
		free(temp);     /* Free the current node */
	}
}

