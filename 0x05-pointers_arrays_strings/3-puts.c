#include "main.h"

/**
* _puts - A function that prints a string to stdout
* @str: pointer to the string
*/

void _puts(char *str)
{
while (*str != '\0')
{
_putchar(*str);
str++;
}
_putchar('\n');
}
