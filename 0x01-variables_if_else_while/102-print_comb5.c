#include <stdio.h>

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/

int main(void)
{
int tens1 = 0;
int units1 = 0;

while (tens1 <= 9)
{
units1 = 0;
while (units1 <= 9)
{
int tens2 = tens1;

while (tens2 <= 9)
{
int units2 = units1 + 1;

while (units2 <= 9)
{
putchar(tens1 + '0');
putchar(units1 + '0');

putchar(' ');

putchar(tens2 + '0');
putchar(units2 + '0');

if (!(tens1 == 9 && units1 == 8 && tens2 == 9 && units2 == 9))
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
