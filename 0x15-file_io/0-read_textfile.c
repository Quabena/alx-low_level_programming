#include "main.h"

/**
* read_textfile - A function that reads a text file and prints
* it to the POSIX standard output
* @filename: The name of the file to read
* @letters: The number of letters to read and print
*
* Return: The number of letters read and printed, 0 if failed.
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t bytes_rd, bytes_wrtn;
char *buf;

if (filename == NULL)
return (0);
fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
buf = malloc(sizeof(char) * letters);
if (buf == NULL)
{
close(fd);
return (0);
}
bytes_rd = read(fd, buf, letters);
if (bytes_rd == -1)
{
free(buf);
close(fd);
return (0);
}
bytes_wrtn = write(STDOUT_FILENO, buf, bytes_rd);
if (bytes_wrtn == -1 || bytes_wrtn != bytes_rd)
{
free(buf);
close(fd);
return (0);
}
free(buf);
close(fd);
return (bytes_wrtn);
}
