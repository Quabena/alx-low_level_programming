#include <stdio.h>
/**
* main - Entry point
*
* Return: Always 0 (Success)
*/

int main(void)
{
char figure = '0';

while (figure <= '9')
{
putchar(figure);
figure++;
}
putchar('\n');

return (0);
}
