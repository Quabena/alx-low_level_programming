#include "main.h"

/**
* print_number - Prints an integer using _putchar
* @n: The integer to be printed
*
* Description: Handles the printing of negative numbers.
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
print_number(num / 10);
_putchar((num % 10) + '0');
}
/**
* print_times_table - Prints the n times table, starting with 0
* @n: The table size
*
* Description: Prints the times table up to n, only if n is between 0 and 15.
*/

void print_times_table(int n)
{
int row, col, res;
if (n < 0 || n > 15)
{
return;
}
for (row = 0; row <= n; row++)
{
for (col = 0; col <= n; col++)
{
res = row * col;
if (col == 0)
{
print_number(res);
}
else
{
_putchar(',');
_putchar(' ');
if (res < 10)
{
_putchar(' ');
_putchar(' ');
print_number(res);
}
else if (res < 100)
{
_putchar(' ');
print_number(res);
}
else
{
print_number(res);
}
}
}
_putchar('\n');
}
}
