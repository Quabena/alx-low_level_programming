#include "dog.h"
#include <stdlib.h>

/**
* free_dog - Frees a dog_t
* @d: Pointer to the dog_t to be freed
* Description: This function frees the memory allocated for the name, owner,
* and the dog_t structure itself. If the pointer is NULL, nothing is done.
*/

void free_dog(dog_t *d)
{
if (d != NULL)
{

if (d->name != NULL)
{
free(d->name);
}

if (d->owner != NULL)
{
free(d->owner);
}

free(d);
}
}
