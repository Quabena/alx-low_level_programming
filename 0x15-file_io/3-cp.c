#include "main.h"

/**
* main - A function that copies the content of a file
* to another file.
* @argc: The number of command-line arguments.
* @argv: The array of command-line arguments.
*
* Return: Always 0 on success
*/

int main(int argc, char *argv[])
{
int fd_from, fd_to;
ssize_t bytes_rd, bytes_wrtn;
char buffer[1024];
mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(fd_from);
exit(99);
}
while ((bytes_rd = read(fd_from, buffer, sizeof(buffer))) > 0)
{
bytes_wrtn = write(fd_to, buffer, bytes_rd);
if (bytes_wrtn != bytes_rd)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(fd_from);
close(fd_to);
exit(99);
}
}
if (bytes_rd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
close(fd_from);
close(fd_to);
exit(98);
}
if (close(fd_from) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
close(fd_to);
exit(100);
}
if (close(fd_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
exit(100);
}
return (0);
}
