#include "lists.h"

/**
* pop_listint - A function that deletes the head node of
* a list (listint_t)
* @head: Double pointer to the head of the list
* Return: The head node's data (n), or 0if the list
* is empty
*/

int pop_listint(listint_t **head)
{
listint_t *temp;
int data;

if (head == NULL || *head == NULL)
return (0);

temp = *head;
data = temp->n;
*head = (*head)->next;
free(temp);

return (data);
}
