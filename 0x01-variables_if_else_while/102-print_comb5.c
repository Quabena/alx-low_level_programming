#include <stdio.h>

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/

int main(void)
{
int tens1 = 48;
while (tens1 <= 57)
{
int units1 = 48;
while (units1 <= 57)
{
int tens2 = tens1;
while (tens2 <= 57)
{
int units2 = units1 + 1;
while (units2 <= 57)
{
putchar(tens1);
putchar(units1);
putchar(' ');
putchar(tens2);
putchar(units2);
if (!(tens1 == 57 && units1 == 57 && tens2 == 57 && units2 == 57))
{
putchar(',');
putchar(' ');
}
units2++;
}
tens2++;
}
units1++;
}
tens1++;
}
putchar('\n');
return (0);
}
