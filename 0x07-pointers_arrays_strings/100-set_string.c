#include "main.h"
#include <stdio.h>

/**
 * set_string - A function sets the value of a pointer to a char
 * @s: pointer to the pointer to be set
 * @to: pointer to the string to set *s to
 */

void set_string(char **s, char *to)
{
if (s == NULL)
return;

*s = to;
}
