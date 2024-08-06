#include "lists.h"

/**
* delete_nodeint_at_index - A function deletes the node at a specific index.
* @head: Pointer to the pointer to the head of the linked list.
* @index: Index of the node to be deleted.
* Return: 1 if deletion succeeded, -1 if failed.
*/

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
unsigned int i;
listint_t *current = *head;
listint_t *temp;

if (head == NULL || *head == NULL)
{
return (-1);
}

if (index == 0)
{

temp = *head;
*head = (*head)->next;
free(temp);
return (1);
}

for (i = 0; current != NULL && i < index - 1; i++)
{
current = current->next;
}

if (current == NULL || current->next == NULL)
{
return (-1);
}

temp = current->next;
current->next = temp->next;
free(temp);

return (1);
}
