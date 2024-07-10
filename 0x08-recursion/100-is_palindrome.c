#include "main.h"

/**
* _strlen_recursion - returns the length of a string
* @s: the string to measure
* Return: the length of the string
*/

int _strlen_recursion(char *s)
{
if (*s == '\0')
return (0);
else
return (1 + _strlen_recursion(s + 1));
}

/**
* is_palindrome_helper_function - helper function to check if a
* string is palindrome
* @s: the string to check
* @len: the length of the string
*
* Return: 1 if palindrome, 0 otherwise
*/

int is_palindrome_helper_function(char *s, int len)
{
if (len <= 1)
return (1);

if (*s == *(s + len - 1))
return (is_palindrome_helper_function(s + 1, len - 2));

return (0);
}

/**
* is_palindrome - returns 1 if a string is a palindrome and 0 if not
* @s: the string to check
* Return: 1 if palindrome, 0 otherwise
*/

int is_palindrome(char *s)
{
int len = _strlen_recursion(s);
return (is_palindrome_helper_function(s, len));
}
