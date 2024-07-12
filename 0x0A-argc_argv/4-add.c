#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
* is_number - Checks if a string is composed only of digits
* @str: The string to be checked
* Return: 1 if the string is a number, 0 otherwise
*/

int is_number(char *str)
{
int i;

for (i = 0; str[i] != '\0'; i++)
{
if (!isdigit((unsigned char)str[i]))
{
return (0);
}
}
return (1);
}

/**
* main - Entry point
* @argc: The number of command-line arguments
* @argv: An array containing the program command-line arguments
* Return: 0 on success, 1 on error
*/

int main(int argc, char *argv[])
{
int i, sum = 0;

if (argc == 1)
{
printf("0\n");
return (0);
}

for (i = 1; i < argc; i++)
{
if (!is_number(argv[i]))
{
printf("Error\n");
return (1);
}
sum += atoi(argv[i]);
}

printf("%d\n", sum);
return (0);
}
