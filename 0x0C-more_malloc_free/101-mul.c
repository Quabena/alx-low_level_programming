#include "main.h"
#include <stdlib.h>

/**
* main - Entry point. Multiplies two positive numbers.
* @argc: Number of command-line arguments.
* @argv: Array of command-line arguments.
* Return: 0 on success, 98 on error.
*/

int main(int argc, char *argv[])
{
int i, j;

if (argc != 3)
{
_print_error();
exit(98);
}
for (i = 1; i < 3; i++)
{
for (j = 0; argv[i][j]; j++)
{
if (!_isdigit(argv[i][j]))
{
_print_error();
exit(98);
}
}
}
_multiply(argv[1], argv[2]);
return (0);
}

/**
* _print_error - Prints "Error" and a new line.
*/

void _print_error(void)
{
char *error = "Error\n";
while (*error)
{
_putchar(*error);
error++;
}
}

/**
* _isdigit - Checks if a character is a digit.
* @c: The character to check.
* Return: 1 if the character is a digit, 0 otherwise.
*/

int _isdigit(char c)
{
return (c >= '0' && c <= '9');
}

/**
* _strlen - Calculates the length of a string.
* @s: The string.
* Return: The length of the string.
*/

int _strlen(char *s)
{
int len = 0;
while (s[len])
len++;
return (len);
}

/**
* _multiply - Multiplies two positive numbers.
* @num1: The first number (as a string).
* @num2: The second number (as a string).
*/

void _multiply(char *num1, char *num2)
{
int len1 = _strlen(num1);
int len2 = _strlen(num2);
int *result = calloc(len1 + len2, sizeof(int));
int i, j, n1, n2, sum, carry;

if (result == NULL)
{
_print_error();
exit(98);
}

for (i = len1 - 1; i >= 0; i--)
{
n1 = num1[i] - '0';
carry = 0;
for (j = len2 - 1; j >= 0; j--)
{
n2 = num2[j] - '0';
sum = n1 *n2 + result[i + j + 1] + carry;
carry = sum / 10;
result[i + j + 1] = sum % 10;
}
result[i + j + 1] += carry;
}
i = 0;
while (i < len1 + len2 && result[i] == 0)
i++;
if (i == len1 + len2)
_putchar('0');
else
{
for (; i < len1 + len2; i++)
_putchar(result[i] + '0');
}
_putchar('\n');
free(result);
}
