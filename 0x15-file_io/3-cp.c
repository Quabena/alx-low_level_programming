#include "main.h"

/**
* main - A function that copies content from one file to another.
* @argc: The number of command-line arguments.
* @argv: Array of command-line arguments.
*
* Return: 0 on success.
*/

int main(int argc, char *argv[])
{
int src_fd, dest_fd;
ssize_t bytes_rd, bytes_wrtn;
char *buf;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buf = allocate_buffer(argv[2]);
src_fd = open(argv[1], O_RDONLY);

if (src_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
free(buf);
exit(98);
}
dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (dest_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buf);
close_descriptor(src_fd);
exit(99);
}
while ((bytes_rd = read(src_fd, buf, 1024)) > 0)
{
bytes_wrtn = write(dest_fd, buf, bytes_rd);
if (bytes_wrtn != bytes_rd)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buf);
close_descriptor(src_fd);
close_descriptor(dest_fd);
exit(99);
}
}
if (bytes_rd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
free(buf);
close_descriptor(src_fd);
close_descriptor(dest_fd);
exit(98);
}

free(buf);
close_descriptor(src_fd);
close_descriptor(dest_fd);
return (0);
}

/**
* allocate_buffer - Allocates 1024 bytes for a buffer.
* @file_name: The name of the file related to the buffer.
*
* Return: A pointer to the newly-allocated buffer.
*/

char *allocate_buffer(char *file_name)
{
char *buf;
buf = malloc(sizeof(char) * 1024);
if (buf == NULL)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_name);
exit(99);
}
return (buf);
}

/**
* close_descriptor - Closes file descriptors.
* @fd: The file descriptor to close.
*/

void close_descriptor(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}
