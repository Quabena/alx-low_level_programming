#include <stdio.h>

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/

int main(void)
{
int hundreds_value = 48;

while (hundreds_value <= 55)
{
int tens_value = hundreds_value + 1;

while (tens_value <= 56)
{
int units_value = tens_value + 1;

while (units_value <= 57)
{
putchar(hundreds_value);
putchar(tens_value);
putchar(units_value);

if (!(hundreds_value == 55 && tens_value == 56 && units_value == 57))
{
putchar(',');
putchar(' ');
}
units_value++;
}
tens_value++;
}
hundreds_value++;
}
putchar('\n');

return (0);
}
