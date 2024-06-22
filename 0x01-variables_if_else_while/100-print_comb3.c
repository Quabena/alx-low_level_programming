#include <stdio.h>

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/

int main(void)
{
int tens_value = 48;

while (tens_value <= 57)
{
int units_value = tens_value + 1;

while (units_value <= 57)
{
putchar(tens_value);
putchar(units_value);

if (!(tens_value == 56 && units_value == 57))
{
putchar(',');
putchar(' ');
}
units_value++;
}

tens_value++;
}
putchar('\n');

return (0);
}
