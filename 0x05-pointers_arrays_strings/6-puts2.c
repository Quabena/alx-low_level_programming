#include "main.h"

/**
* puts2 - A function that prints other character of a string
* starting with the character.
* @str: pointer to the string print
*/

void puts2(char *str)
{
int i = 0;

while (str[i] != '\0')
{
_putchar(str[i]);
i += 2;
}
_putchar('\n');
}
