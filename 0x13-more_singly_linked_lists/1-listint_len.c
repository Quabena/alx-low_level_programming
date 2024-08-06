#include "lists.h"

/**
* listint_len - A function that returns the number of element
* in a linked list (listint_t) list
* @h: a pointer to the head of the list
* Return: Number of nodes
*/

size_t listint_len(const listint_t *h)
{
size_t count = 0;

while (h != NULL)
{
count++;

h = h->next;
}

return (count);
}
