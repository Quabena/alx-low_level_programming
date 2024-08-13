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
void handle_open_error(int fd, char *file_name, int error_code,
		       char *error_msg);
void handle_write_error(ssize_t bytes_wrtn, ssize_t bytes_rd, char *file_name);

void validate_elf(unsigned char *identifier);
void print_magic_bytes(unsigned char *identifier);
void print_class_type(unsigned char *identifier);
void print_data_encoding(unsigned char *identifier);
void print_version_info(unsigned char *identifier);
void print_osabi_info(unsigned char *identifier);
void print_abi_version(unsigned char *identifier);
void print_file_type(uint16_t file_type);
void print_entry_address(uint64_t entry_address, unsigned char *identifier);
void close_elf_file(int elf_file_descriptor);

#endif
