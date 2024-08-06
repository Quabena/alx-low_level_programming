#include "lists.h"

/**
 * free_listint_safe - A function that frees a listint_t linked list safely
 * @h: pointer to the first node in the linked list
 * Return: number of elements in the freed list
 */

size_t free_listint_safe(listint_t **h)
{
size_t count = 0;
int d_left;
listint_t *temp;

if (!h || !*h)
return (0);

while (*h)
{
d_left = *h - (*h)->next;
if (d_left > 0)
{
temp = (*h)->next;
free(*h);
*h = temp;
count++;
}
else
{
free(*h);
*h = NULL;
count++;
break;
}
}

*h = NULL;

return (count);
}
