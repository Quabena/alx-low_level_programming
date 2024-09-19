#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n)
 * in a dlistint_t linked list
 * @head: pointer to the head of the doubly linked list
 *
 * Return: the sum of all the data (n) in the list, or 0 if the list is empty
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	/* Traverse the list and sum the values of 'n' in each node */
	while (head != NULL)
	{
		sum += head->n;  /* Add the data of the current node to the sum */
		head = head->next;  /* Move to the next node */
	}

	/* Return the total sum */
	return (sum);
}

