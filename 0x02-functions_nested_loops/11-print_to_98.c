#include "main.h"

/**
* print_number - Prints all natural numbers from n to 98
*
* @n: The number to be printed
*
* Description: Handles the printing of negatives values
*/

void print_number(int n)
{
unsigned int num = n;

if (n < 0)
{
_putchar('-');
num = -num;
}

if (num / 10)
{
print_number(num / 10);

_putchar((num % 10) + '0');
}
}
/**
* print_to_98 - Prints all natural numbers from n to 98
* @n: The starting integer
*
* Description: Prints numbers from n to 98,
* separated by a comma and space
*/

void print_to_98(int n)
{
if (n <= 98)
{
while (n <= 98)
{
print_number(n);
if (n != 98)
{
_putchar(',');
_putchar(' ');
}
n++;
}
}
else
{
while (n >= 98)
{
print_number(n);
if (n != 98)
{
_putchar(',');
_putchar(' ');
}
n--;
}
}
_putchar('\n');
}
