#include "main.h"

/**
* puts2 - A function that prints other character of a string
* starting with the character.
* @str: pointer to the string print
*/

void puts2(char *str)
{
int i;
int c;

while (str[c] != '\0')
{
c++;
}

for (i = 0; i < c; i += 2)
{
_putchar(str[i]);
}
_putchar('\n');
}
