#include "main.h"

/**
* print_alphabet - Prints alphabet in lowercase
*
* Description: Uses _putchar function to print each character of the alphabet
*
*/
void print_alphabet(void)
{
char letter = 'a';

while (letter <= 'z')
{
_putchar(letter);
letter++;
}
_putchar('\n');

}
