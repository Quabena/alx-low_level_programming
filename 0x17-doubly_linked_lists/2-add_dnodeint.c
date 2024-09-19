#include "lists.h"
#include <stdlib.h>  /* for malloc and NULL */

/**
 * add_dnodeint - adds a new node at the beginning of a doubly linked list
 * @head: double pointer to the head of the list
 * @n: the integer to store in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);  /* Return NULL if malloc fails */

	/* Assign the value and set next and prev pointers */
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	/* If the list is not empty, update the previous head's prev pointer */
	if (*head != NULL)
		(*head)->prev = new_node;

	/* Move the head pointer to the new node */
	*head = new_node;

	return (new_node);  /* Return the new node */
}

