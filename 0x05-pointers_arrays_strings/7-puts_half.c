#include "main.h"

/**
 * puts_half - prints half of a string, followed by a new line
 * @str: pointer to the string to print
 */
void puts_half(char *str)
{
int length = _strlen(str);
int start_index;

if (length % 2 == 0)
{
start_index = length / 2;
}
else
{
start_index = (length + 1) / 2;
}

while (str[start_index] != '\0')
{
_putchar(str[start_index]);
start_index++;
}

_putchar('\n');
}
