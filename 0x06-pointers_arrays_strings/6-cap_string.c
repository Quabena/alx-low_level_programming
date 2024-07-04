#include "main.h"
#include <stdbool.h> /* for boolean type */

/**
 * cap_string - A function that capitalizes the first letter of each
 * word in a string.
 * @str: Pointer to the string to capitalize.
 *
 * Return: Pointer to the modified string str.
 */
char *cap_string(char *str)
{
int i = 0;
bool new_word = true;

while (str[i] != '\0')
{

if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
str[i] == ',' || str[i] == ';' || str[i] == '.' ||
str[i] == '!' || str[i] == '?' || str[i] == '"' ||
str[i] == '(' || str[i] == ')' || str[i] == '{' ||
str[i] == '}')
{
new_word = true;
}
else if (new_word && str[i] >= 'a' && str[i] <= 'z')
{

str[i] = str[i] - ('a' - 'A');
new_word = false;
}
else
{
new_word = false;
}

i++;
}

return (str);
}
