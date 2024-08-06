#include "lists.h"

/**
* insert_nodeint_at_index - Insert a new node at a specific index
* @head: Pointer to the pointer to the head of the linked list
* @idx: Index where the new node should be inserted
* @n: The data to store in the new node.
* Return: The address of the new node, or NULL if failed,
* or index is out of bounds
*/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int i;
listint_t *new_node, *crnt = *head;

if (idx == 0)
{
new_node = (listint_t *)malloc(sizeof(listint_t));

if (new_node == NULL)
{
return (NULL);
}

new_node->n = n;
new_node->next = *head;
*head = new_node;

return (new_node);
}

for (i = 0; crnt != NULL && i < idx - 1; i++)
{
crnt = crnt->next;
}

if (crnt == NULL || i != idx - 1)
{
return (NULL);
}
new_node = (listint_t *)malloc(sizeof(listint_t));
if (new_node == NULL)
{
return (NULL);
}
new_node->n = n;
new_node->next = crnt->next;
crnt->next = new_node;
return (new_node);
}
