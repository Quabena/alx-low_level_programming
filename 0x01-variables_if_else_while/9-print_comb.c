#include <stdio.h>
/**
* main - Entry point
*
* Return: Always 0 (Success)
*/

int main(void)
{
int numb = 48;

while (numb <= 57)
{
putchar(numb);

if (numb != 57)
{
putchar(',');
putchar(' ');
}
numb++;
}

putchar('\n');

return (0);
}
