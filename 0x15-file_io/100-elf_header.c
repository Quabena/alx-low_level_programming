#include "main.h"

/**
* check_elf_header - Validates if a file is an ELF file.
* @e_ident: A pointer to an array containing ELF magic numbers.
*/

void check_elf_header(unsigned char *e_ident)
{
int index;

for (index = 0; index < 4; index++)
{
if (e_ident[index] != 127 && e_ident[index] != 'E' &&
e_ident[index] != 'L' && e_ident[index] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
* display_elf_info - Displays ELF header information.
* @header: A pointer to the ELF header structure.
*/

void display_elf_info(Elf64_Ehdr *header)
{
int i;
  
printf("ELF Header:\n");
printf(" Magic: ");
for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x", header->e_ident[i]);
if (i != EI_NIDENT - 1)
printf(" ");
}
printf("\n");

printf(" Class: ");
switch (header->e_ident[EI_CLASS])
{
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
}

printf(" Data: ");
switch (header->e_ident[EI_DATA])
{
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
}

printf(" Version: %d", header->e_ident[EI_VERSION]);
if (header->e_ident[EI_VERSION] == EV_CURRENT)
printf(" (current)\n");
else
printf("\n");

printf(" OS/ABI: ");
switch (header->e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
default:
printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
}

printf(" ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

printf(" Type: ");
switch (header->e_type)
{
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
default:
printf("<unknown: %x>\n", header->e_type);
}

printf(" Entry point address: ");
if (header->e_ident[EI_DATA] == ELFDATA2MSB)
header->e_entry = ((header->e_entry << 8) & 0xFF00FF00) |
                          ((header->e_entry >> 8) & 0xFF00FF);
if (header->e_ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)header->e_entry);
else
printf("%#lx\n", header->e_entry);
}

/**
* read_elf_header - Reads the ELF header from the file.
* @file: The filename to read.
* @header: Pointer to the ELF header structure.
*/

void read_elf_header(const char *file, Elf64_Ehdr **header)
{
int fd;
ssize_t bytes_read;

fd = open(file, O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", file);
exit(98);
}

*header = malloc(sizeof(Elf64_Ehdr));
if (*header == NULL)
{
close_file(fd);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", file);
exit(98);
}

bytes_read = read(fd, *header, sizeof(Elf64_Ehdr));
if (bytes_read == -1)
{
free(*header);
close_file(fd);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", file);
exit(98);
}
close_file(fd);
}

/**
* handle_file_open - Ensures correct number of arguments and opens file.
* @file: The filename to open.
*/

void handle_file_open(const char *file)
{
Elf64_Ehdr *header;

read_elf_header(file, &header);
check_elf_header(header->e_ident);
display_elf_info(header);
free(header);
}

/**
* close_file - Closes a file descriptor.
* @fd: The file descriptor to close.
*/

void close_file(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(98);
}
}

/**
* main - Displays ELF header information for an ELF file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
* Return: 0 on success.
*/

int main(int argc, char *argv[])
{
if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
exit(98);
}

handle_file_open(argv[1]);

return (0);
}
