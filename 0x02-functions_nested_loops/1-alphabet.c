#include "main.h"

/**
* main - Entry point
*
* Description: Uses _putchar function to print each character of the alphabet
*
* Return: Always 0 (Success)
*/
int main(void)
{
char letter = 'a';

while (letter <= 'z')
{
_putchar(letter);
letter++;
}
_putchar('\n');

return (0);
}
