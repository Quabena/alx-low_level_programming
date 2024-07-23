#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
* new_dog - Creates a new dog
* @name: Pointer to the dog's name
* @age: The dog's age
* @owner: Pointer to the owner's name
* Return: Pointer to the newly created dog_t, or NULL if it fails
*/

dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *d;
char *name_copy;
char *owner_copy;

d = (dog_t *)malloc(sizeof(dog_t));
if (d == NULL)
{
return (NULL);
}

name_copy = (char *)malloc(strlen(name) + 1);
if (name_copy == NULL)
{
free(d);
return (NULL);
}
strcpy(name_copy, name);

owner_copy = (char *)malloc(strlen(owner) + 1);
if (owner_copy == NULL)
{
free(name_copy);
free(d);
return (NULL);
}
strcpy(owner_copy, owner);

d->name = name_copy;
d->age = age;
d->owner = owner_copy;

return (d);
}
