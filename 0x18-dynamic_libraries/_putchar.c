#include "main.h"

/**
* _putchar - A function that prints a character
* @c: the character to print
* Description: A program that prints "_putchar"
*
* Return: The character printed
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
