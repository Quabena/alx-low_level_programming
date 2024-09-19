#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a doubly linked list
 * @head: double pointer to the head of the list
 * @n: the integer to store in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *last_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);  /* Return NULL if malloc fails */

	/* Assign the value and set next and prev pointers */
	new_node->n = n;
	new_node->next = NULL;

	/* If the list is empty, the new node becomes the head */
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	/* Traverse to the last node of the list */
	last_node = *head;

	while (last_node->next != NULL)
		last_node = last_node->next;

	/* Link the new node at the end */
	last_node->next = new_node;
	new_node->prev = last_node;

	return (new_node);
}
