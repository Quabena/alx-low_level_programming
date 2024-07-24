#include "function_pointers.h"
#include <stddef.h>

/**
* print_name - Prints a name using the function pointed to by f.
* @name: The name to print.
* @f: The function pointer used to print the name.
*/

void print_name(char *name, void (*f)(char *))
{
if (name == NULL || f == NULL)
{
return;
}
f(name);
}
