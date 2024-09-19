#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at a given position
 * in a dlistint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node to be deleted (starting from 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i = 0;

	/* If the list is empty or head is NULL */
	if (*head == NULL)
		return (-1);

	/* Case 1: Delete the head node */
	if (index == 0)
	{
		*head = current->next;
		if (current->next != NULL)
			current->next->prev = NULL;

		free(current);

		return (1);
	}

	/* Traverse to find the node at index */
	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}

	/* If the node does not exist */
	if (current == NULL)
		return (-1);

	/* Case 2: Update the pointers and delete the node */
	if (current->prev != NULL)
		current->prev->next = current->next;

	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current);

	return (1);
}

