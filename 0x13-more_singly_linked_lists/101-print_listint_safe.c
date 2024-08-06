#include "lists.h"

/**
* print_listint_safe - A function that prints a listint_t linked list safely.
* @head: Pointer to the head of the linked list.
* Return: Number of nodes in the list.
*/

size_t print_listint_safe(const listint_t *head)
{
size_t count = 0;
const listint_t *nodes[MAX_NODES];
size_t i;

for (i = 0; i < MAX_NODES; i++)
{
nodes[i] = NULL;
}

while (head != NULL)
{
for (i = 0; i < MAX_NODES; i++)
{
if (nodes[i] == head)
{
printf("-> [%p] %d\n", (void *)head, head->n);
return (count);
}
}
printf("[%p] %d\n", (void *)head, head->n);
for (i = 0; i < MAX_NODES; i++)
{
if (nodes[i] == NULL)
{
nodes[i] = head;
break;
}
}
if (i == MAX_NODES)
{
exit(98);
}

head = head->next;
count++;
}
return (count);
}
