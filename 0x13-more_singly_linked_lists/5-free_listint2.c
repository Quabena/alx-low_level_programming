#include "lists.h"

/**
* free_listint2 - A function that frees a list (listint_t) and
* sets the head to NULL
* @head: A double pointer to the head of the list
*/

void free_listint2(listint_t **head)
{
listint_t *temp;

if (head == NULL)
return;

while (*head != NULL)
{
temp = *head;
*head = (*head)->next;
free(temp);
}

*head = NULL;
}
