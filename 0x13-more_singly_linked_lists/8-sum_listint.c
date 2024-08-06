#include "lists.h"

/**
* sum_listint - A function that calculates the sum of
* all the data (n) in a list (listint_t)
* @head: Pointer to the head of the list
* Return: Sum of all the data in teh linked list, or
* 0 if the list is empty.
*/

int sum_listint(listint_t *head)
{
int sum = 0;
listint_t *current = head;

while (current != NULL)
{
sum += current->n;
current = current->next;
}

return (sum);
}
