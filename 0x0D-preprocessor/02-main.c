#include <stdlib.h>
#include <unistd.h>

/**
* _putchar - the prototype function
* @c: character to print
* Return: the printed name
*/

int _putchar(char c);

/**
* main - Entry point
* Return: Always 0 Success
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
* _putchar - function to print the name
* @c: the character to print
* Return: the printed name
*/

int _putchar(char c)
{
return (write(1, &c, 1));
}
