#include "main.h"

/**
 * print_number - A function that prints an integer using only _putchar.
 * @n: The integer to print.
 */
void print_number(int n)
{
unsigned int num;

num = n;

if (n < 0)
{
_putchar('-');
num = -n;
}

if (num / 10 != 0)
{
print_number(num / 10);
}

_putchar((num % 10) + '0');
}
