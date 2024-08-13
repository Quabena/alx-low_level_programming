#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <elf.h>
#include <sys/types.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);

size_t _strlen(const char *s);
char *allocate_buffer(char *file_name);
void close_descriptor(int fd);
void handle_open_error(int fd, char *file_name, int error_code, char *error_msg);
void handle_write_error(ssize_t bytes_wrtn, ssize_t bytes_rd, char *file_name);

void verify_elf_signature(unsigned char *e_ident);
void display_magic(unsigned char *e_ident);
void display_class(unsigned char *e_ident);
void display_data_encoding(unsigned char *e_ident);
void display_version(unsigned char *e_ident);
void display_osabi(unsigned char *e_ident);
void display_abi_version(unsigned char *e_ident);
void display_type(unsigned int e_type, unsigned char *e_ident);
void display_entry_point(unsigned long int e_entry, unsigned char *e_ident);
void close_elf_file(int elf_fd);

#endif
