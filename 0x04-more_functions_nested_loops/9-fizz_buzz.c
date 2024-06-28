#include <stdio.h>

/**
* main - a program that prints numbers from 1 to 100;
*
* Description: For multiple lines of three, 'Fizz' is printed;
* instead of the number;
* for multiple lines of five, 'Buzz' in printed instead.
* Return: Always 0 (Success)
*/

int main(void)
{
int i;

for (i = 1; i <= 100; i++)
{
if ((i % 3) == 0 && (i % 5) == 0)
printf("FizzBuzz");

else if (i % 3 == 0)
printf("Fizz");

else if (i % 5 == 0)
printf("Buzz");

else
printf("%d", i);

if (i == 100)
continue;
printf(" ");
}
printf("\n");

return (0);
}
