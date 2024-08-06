#include "lists.h"

/**
* add_nodeint - A function that adds a new node at the beginning of
* a list (listint_t)
* @head: double pointer to the head of the list
* @n: The integer to be added to the new node
* Return: Address of the new element,or
* NULL if failed.
*/

listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_node;

new_node = malloc(sizeof(listint_t));

if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->next = *head;
*head = new_node;

return (new_node);
}
