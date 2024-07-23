#include <stdlib.h>
#include <unistd.h>

/* Prototype for _putchar */
int _putchar(char c);

/**
* main - Entry point of the program
* Return: Always 0 (Success)
*/

int main(void)
{
const char *filename = __FILE__;
int i = 0;

while (filename[i] != '\0')
{
_putchar(filename[i]);
i++;
}

_putchar('\n');

return (EXIT_SUCCESS);
}

/**
* _putchar - Writes a character to stdout
* @c: The character to print
* Return: On success 1.
* On error, -1 is returned.
*/

int _putchar(char c)
{
return (write(1, &c, 1));
}
