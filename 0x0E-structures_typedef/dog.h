#ifndef DOG_H
#define DOG_H

/**
* struct dog - Structure for a dog
* @name: Pointer to the dog's name
* @age: The dog's age
* @owner: Pointer to the owner's name
* Description: This struct represents a dog with its name, age, and owner's
* name.
*/

struct dog
{
char *name;
float age;
char *owner;
};

typedef struct dog dog_t;

dog_t *new_dog(char *name, float age, char *owner);

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif
