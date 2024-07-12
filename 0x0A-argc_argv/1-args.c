#include <stdio.h>

/**
* main - Entry point
* @argc: The number of command-line arguments
* @argv: An array containing the program command-line arguments (unused)
* Return: Always 0 (Success)
*/

int main(int argc, char *argv[])
{
(void)argv;
printf("%d\n", argc - 1);
return (0);
}
