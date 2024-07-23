#include "dog.h"
#include <stdio.h>
#include <stddef.h>

/**
* print_dog - Prints the details of a struct dog
* @d: Pointer to the struct dog to be printed
* Description: This function prints the members of the struct dog. If a member
* is NULL, it prints (nil) instead. If the pointer to the struct dog is NULL,
* it prints nothing.
*/

void print_dog(struct dog *d)
{
if (d == NULL)
{
return;
}

printf("Name: %s\n", d->name ? d->name : "(nil)");
printf("Age: %.2f\n", d->age);
printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}
