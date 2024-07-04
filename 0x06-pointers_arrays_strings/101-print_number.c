#include "main.h"

/**
 * print_number - A function that prints an integer using only _putchar.
 * @n: The integer to print.
 */
void print_number(int n)
{
unsigned int n1;

n1 = n;

if (n < 0)
{
_putchar('-');
n = -n;
}

if (n1 / 10 != 0)
{
print_number(n1 / 10);
}

_putchar((num % 10) + '0');
}
