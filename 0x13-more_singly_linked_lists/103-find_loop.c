#include "lists.h"

/**
* find_listint_loop - A function that finds the starting
* node of a loop in a linked list.
* @head: Pointer to the first node in the linked list.
* Return: Address of the node where the loop starts, or
* NULL if there is no loop.
*/

listint_t *find_listint_loop(listint_t *head)
{
listint_t *slow_ptr = head;
listint_t *fast_ptr = head;

if (head == NULL)
{
return (NULL);
}

while (fast_ptr && fast_ptr->next)
{
slow_ptr = slow_ptr->next;
fast_ptr = fast_ptr->next->next;

if (slow_ptr == fast_ptr)
{
slow_ptr = head;
while (slow_ptr != fast_ptr)
{
slow_ptr = slow_ptr->next;
fast_ptr = fast_ptr->next;
}
return (slow_ptr);
}
}

return (NULL);
}
