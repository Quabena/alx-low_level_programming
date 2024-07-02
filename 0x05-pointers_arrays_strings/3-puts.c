#include "main.h"

/**
* _puts - A function that prints a string to stdout
* @str: pointer to the string
*/

void _puts(char *str)
{
for (; *str != '\0'; str++)
{
_putchar(*str);
}
_putchar('\n');
}
