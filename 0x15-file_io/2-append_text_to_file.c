#include "main.h"

/**
* append_text_to_file - Appends text to the end of a file.
* @filename: The name of the file to append to.
* @text_content: The NULL terminated string to append to the file
*
* Return: 1 on success, -1 if failed.
*/

int append_text_to_file(const char *filename, char *text_content)
{
int fd;
ssize_t bytes_wrtn;

if (filename == NULL)
return (-1);

fd = open(filename, O_WRONLY | O_APPEND);

if (fd == -1)
return (-1);

if (text_content != NULL)
{
bytes_wrtn = write(fd, text_content, _strlen(text_content));

if (bytes_wrtn == -1 || (size_t)bytes_wrtn != _strlen(text_content))
{
close(fd);
return (-1);
}
}

close(fd);

return (1);
}


/**
* _strlen - Calculates the length of a string.
* @s: The string to calculate the length of.
*
* Return: The length of the string.
*/

size_t _strlen(const char *s)
{
size_t len = 0;

while (s[len] != '\0')
len++;

return (len);
}
