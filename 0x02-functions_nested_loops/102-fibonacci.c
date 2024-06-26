#include <stdio.h>

/**
* main - Entry point
*
* Description: Prints the first 52 fibonacci numbers
*
* Return: Always 0 (Success)
*/

int main(void)
{
int i = 0;
long n = 1, p = 2;

while (i < 50)
{
if (i == 0)
printf("%ld", n);

else if (i == 1)
printf(", %ld", p);

else
{
p += n;
n = p - n;
printf(", %ld", p);
}
i++;
}
printf("\n");

return (0);
}
