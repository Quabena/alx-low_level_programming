#include "main.h"

/**
* main - Copies content from one file to another.
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
handle_open_error(src_fd, argv[1], 98, "Error: Can't read from file %s\n");

dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
handle_open_error(dest_fd, argv[2], 99, "Error: Can't write to %s\n");

while ((bytes_rd = read(src_fd, buf, 1024)) > 0)
{
bytes_wrtn = write(dest_fd, buf, bytes_rd);
handle_write_error(bytes_wrtn, bytes_rd, argv[2]);
}

if (bytes_rd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
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

/**
* handle_open_error - Handles errors related to file opening.
* @fd: The file descriptor to check.
* @file_name: The name of the file.
* @error_code: The error code to exit with.
* @error_msg: The error message to print.
*/

void handle_open_error(int fd, char *file_name, int error_code,
		       char *error_msg)
{
if (fd == -1)
{
dprintf(STDERR_FILENO, error_msg, file_name);
exit(error_code);
}
}

/**
* handle_write_error - Handles errors related to file writing.
* @bytes_wrtn: The number of bytes written.
* @bytes_rd: The number of bytes read.
* @file_name: The name of the file.
*/

void handle_write_error(ssize_t bytes_wrtn, ssize_t bytes_rd, char *file_name)
{
if (bytes_wrtn != bytes_rd)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_name);
exit(99);
}
}
