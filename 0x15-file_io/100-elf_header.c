#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void verify_elf_header(unsigned char *e_ident);
void display_magic(unsigned char *e_ident);
void display_class(unsigned char *e_ident);
void display_data(unsigned char *e_ident);
void display_version(unsigned char *e_ident);
void display_osabi(unsigned char *e_ident);
void display_abi_version(unsigned char *e_ident);
void display_file_type(unsigned int e_type, unsigned char *e_ident);
void display_entry_point(unsigned long int e_entry, unsigned char *e_ident);
void close_file(int fd);

/**
 * verify_elf_header - Checks if the file is an ELF file.
 * @e_ident: A pointer to the array containing ELF magic numbers.
 *
 * Description: Exits with code 98 if the file is not an ELF file.
 */
void verify_elf_header(unsigned char *e_ident)
{
    if (e_ident[0] != 127 || e_ident[1] != 'E' || e_ident[2] != 'L' || e_ident[3] != 'F')
    {
        dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
        exit(98);
    }
}

/**
 * display_magic - Displays the magic numbers of the ELF header.
 * @e_ident: A pointer to the array containing ELF magic numbers.
 */
void display_magic(unsigned char *e_ident)
{
    int i;

    printf(" Magic: ");
    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x", e_ident[i]);
        if (i < EI_NIDENT - 1)
            printf(" ");
    }
    printf("\n");
}

/**
 * display_class - Displays the class of the ELF header.
 * @e_ident: A pointer to the array containing ELF class.
 */
void display_class(unsigned char *e_ident)
{
    printf(" Class: ");
    switch (e_ident[EI_CLASS])
    {
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("unknown: %x\n", e_ident[EI_CLASS]);
    }
}

/**
 * display_data - Displays the data encoding of the ELF header.
 * @e_ident: A pointer to the array containing ELF data encoding.
 */
void display_data(unsigned char *e_ident)
{
    printf(" Data: ");
    switch (e_ident[EI_DATA])
    {
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("unknown: %x\n", e_ident[EI_DATA]);
    }
}

/**
 * display_version - Displays the version of the ELF header.
 * @e_ident: A pointer to the array containing ELF version.
 */
void display_version(unsigned char *e_ident)
{
    printf(" Version: %d", e_ident[EI_VERSION]);
    if (e_ident[EI_VERSION] == EV_CURRENT)
        printf(" (current)\n");
    else
        printf("\n");
}

/**
 * display_osabi - Displays the OS/ABI of the ELF header.
 * @e_ident: A pointer to the array containing ELF OS/ABI.
 */
void display_osabi(unsigned char *e_ident)
{
    printf(" OS/ABI: ");
    switch (e_ident[EI_OSABI])
    {
    case ELFOSABI_NONE:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    default:
        printf("unknown: %x\n", e_ident[EI_OSABI]);
    }
}

/**
 * display_abi_version - Displays the ABI version of the ELF header.
 * @e_ident: A pointer to the array containing ELF ABI version.
 */
void display_abi_version(unsigned char *e_ident)
{
    printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * display_file_type - Displays the type of the ELF file.
 * @e_type: The ELF type.
 * @e_ident: A pointer to the array containing ELF class.
 */
void display_file_type(unsigned int e_type, unsigned char *e_ident)
{
    if (e_ident[EI_DATA] == ELFDATA2MSB)
        e_type >>= 8;

    printf(" Type: ");
    switch (e_type)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("unknown: %x\n", e_type);
    }
}

/**
 * display_entry_point - Displays the entry point of the ELF file.
 * @e_entry: The entry point address.
 * @e_ident: A pointer to the array containing ELF class.
 */
void display_entry_point(unsigned long int e_entry, unsigned char *e_ident)
{
    printf(" Entry point address: ");
    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
        e_entry = (e_entry << 16) | (e_entry >> 16);
    }

    if (e_ident[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)e_entry);
    else
        printf("%#lx\n", e_entry);
}

/**
 * close_file - Closes the ELF file.
 * @fd: The file descriptor of the ELF file.
 *
 * Description: Exits with code 98 if unable to close the file.
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
 * main - Displays the ELF header information.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with code 98 if file is not an ELF file or error occurs.
 */
int main(int argc, char *argv[])
{
    Elf64_Ehdr header;
    int fd;
    ssize_t bytes_read;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

    bytes_read = read(fd, &header, sizeof(Elf64_Ehdr));
    if (bytes_read == -1)
    {
        close_file(fd);
        dprintf(STDERR_FILENO, "Error: Read failed\n");
        exit(98);
    }
    if (bytes_read < (ssize_t)sizeof(Elf64_Ehdr))
    {
        close_file(fd);
        dprintf(STDERR_FILENO, "Error: `%s`: File too short\n", argv[1]);
        exit(98);
    }

    verify_elf_header(header.e_ident);
    printf("ELF Header:\n");
    display_magic(header.e_ident);
    display_class(header.e_ident);
    display_data(header.e_ident);
    display_version(header.e_ident);
    display_osabi(header.e_ident);
    display_abi_version(header.e_ident);
    display_file_type(header.e_type, header.e_ident);
    display_entry_point(header.e_entry, header.e_ident);

    close_file(fd);
    return (0);
}
