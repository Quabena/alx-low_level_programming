#include "lists.h"

/**
* list_len - Returns the number of elements in linked list_t
* @h: Pointer to the head of the list
*
* Return: Number of elements in the list
*/

size_t list_len(const list_t *h)
{
size_t node_cnt = 0;

while (h != NULL)
{
node_cnt++;
h = h->next;
}

return (node_cnt);
}
