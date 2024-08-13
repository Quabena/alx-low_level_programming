#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

#define BUF_SIZE 1024

void handle_arguments_and_files(int argc, char *argv[], int *fd_from, int *fd_to);
void copy_and_close_files(int fd_from, int fd_to);

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);

size_t _strlen(const char *s);

#endif
