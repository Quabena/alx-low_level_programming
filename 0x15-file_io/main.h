#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int _putchar(char c);
size_t _strlen(const char *s);

#endif
