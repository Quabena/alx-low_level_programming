#include "lists.h"

/**
* add_nodeint_end - A function that adds a new node at the end
* of a list (listint_t)
* @head: Double pointer to the head of the list
*
* @n: Integer to be added to the new node
*
* Return: The address of the new element, or
* NULL if failed.
*/

listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node, *temp;

new_node = malloc(sizeof(listint_t));

if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->next = NULL;

if (*head == NULL)
{
*head = new_node;
}
else
{
temp = *head;
while (temp->next != NULL)
temp = temp->next;
temp->next = new_node;
}

return (new_node);
}
