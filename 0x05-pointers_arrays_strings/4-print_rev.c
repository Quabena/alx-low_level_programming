#include "main.h"

/**
* print_rev - A function that prints a string in reverse
* @s: pointer to the string to print
*/

void print_rev(char *s)
{
int len = 0;

while (s[len] != '\0')
{
len++;
}

for (len -= 1; len >= 0; len--)
{
_putchar(s[len]);
}

_putchar('\n');
}
